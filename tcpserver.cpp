#include "tcpserver.h"
#include <QSqlError>

TcpServer::TcpServer(QObject *parent)
    : QTcpServer(parent)
    , m_clientSocket(nullptr)
    , m_heartbeatTimer(new QTimer(this))
    , m_heartbeatTimeoutTimer(new QTimer(this))
    , m_isClientConnected(false)
{
    // 初始化数据库
    initDatabase();
    
    // 连接newConnection信号
    connect(this, &QTcpServer::newConnection, this, &TcpServer::onNewConnection);
    
    // 设置心跳定时器
    connect(m_heartbeatTimer, &QTimer::timeout, this, &TcpServer::sendHeartbeat);
    connect(m_heartbeatTimeoutTimer, &QTimer::timeout, this, &TcpServer::onHeartbeatTimeout);
    
    // 每30秒发送心跳
    m_heartbeatTimer->setInterval(30000);
    // 心跳超时时间设为35秒
    m_heartbeatTimeoutTimer->setSingleShot(true);
    m_heartbeatTimeoutTimer->setInterval(35000);
}

TcpServer::~TcpServer()
{
    stopServer();
    if (m_database.isOpen()) {
        m_database.close();
    }
}

bool TcpServer::startServer(quint16 port)
{
    if (isListening()) {
        qWarning() << "服务器已经在运行";
        return true;
    }
    
    if (!listen(QHostAddress::Any, port)) {
        qCritical() << "无法启动TCP服务器:" << errorString();
        emit connectionError(QString("无法启动TCP服务器: %1").arg(errorString()));
        return false;
    }
    
    qInfo() << "TCP服务器监听所有网络接口，设备可从192.168.3.69连接到192.168.3.90:" << port;
    
    qInfo() << "TCP服务器已启动，监听端口:" << port;
    return true;
}

void TcpServer::stopServer()
{
    if (isListening()) {
        close();
        qInfo() << "TCP服务器已停止";
    }
    
    if (m_clientSocket) {
        m_clientSocket->disconnectFromHost();
        m_clientSocket->deleteLater();
        m_clientSocket = nullptr;
    }
    
    m_heartbeatTimer->stop();
    m_heartbeatTimeoutTimer->stop();
    m_isClientConnected = false;
}

bool TcpServer::initDatabase()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE", "sensor_data");
    m_database.setDatabaseName("sensor_data.db");
    
    if (!m_database.open()) {
        qCritical() << "无法打开数据库:" << m_database.lastError().text();
        return false;
    }
    
    createTables();
    qInfo() << "数据库初始化成功";
    return true;
}

void TcpServer::createTables()
{
    QSqlQuery query(m_database);
    
    // 创建传感器数据表
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS sensor_data (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
            sensor_type TEXT NOT NULL,
            channel_number INTEGER,
            sensor_id TEXT,
            sensor_name TEXT,
            value REAL,
            unit TEXT
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qCritical() << "创建传感器数据表失败:" << query.lastError().text();
    }
    
    // 创建波长数据表
    createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS wavelength_data (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
            channel_number INTEGER,
            wavelength REAL
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qCritical() << "创建波长数据表失败:" << query.lastError().text();
    }
    
    // 创建连接日志表
    createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS connection_log (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
            event_type TEXT,
            message TEXT
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qCritical() << "创建连接日志表失败:" << query.lastError().text();
    }
}

void TcpServer::onNewConnection()
{
    QTcpSocket *clientSocket = nextPendingConnection();
    
    if (m_clientSocket) {
        qWarning() << "已有客户端连接，拒绝新连接";
        clientSocket->disconnectFromHost();
        return;
    }
    
    m_clientSocket = clientSocket;
    m_isClientConnected = true;
    
    connect(m_clientSocket, &QTcpSocket::disconnected, this, &TcpServer::onClientDisconnected);
    connect(m_clientSocket, &QTcpSocket::readyRead, this, &TcpServer::onDataReceived);
    
    // 记录连接日志
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO connection_log (event_type, message) VALUES (?, ?)");
    query.addBindValue("CLIENT_CONNECTED");
    query.addBindValue(QString("客户端连接: %1").arg(clientSocket->peerAddress().toString()));
    query.exec();
    
    qInfo() << "客户端已连接:" << clientSocket->peerAddress().toString();
    emit clientConnected();
    
    // 开始心跳
    m_heartbeatTimer->start();
}

void TcpServer::onClientDisconnected()
{
    if (m_clientSocket) {
        qInfo() << "客户端已断开连接";
        
        // 记录断开日志
        QSqlQuery query(m_database);
        query.prepare("INSERT INTO connection_log (event_type, message) VALUES (?, ?)");
        query.addBindValue("CLIENT_DISCONNECTED");
        query.addBindValue("客户端断开连接");
        query.exec();
        
        m_clientSocket->deleteLater();
        m_clientSocket = nullptr;
    }
    
    m_isClientConnected = false;
    m_heartbeatTimer->stop();
    m_heartbeatTimeoutTimer->stop();
    
    emit clientDisconnected();
}

void TcpServer::onDataReceived()
{
    if (!m_clientSocket) return;
    
    QByteArray data = m_clientSocket->readAll();
    QString jsonString = QString::fromUtf8(data);
    
    qDebug() << "接收到数据:" << jsonString;
    
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
    
    if (error.error != QJsonParseError::NoError) {
        qWarning() << "JSON解析错误:" << error.errorString();
        return;
    }
    
    QJsonObject jsonObj = doc.object();
    
    // 处理心跳响应
    if (jsonObj.contains("body")) {
        QJsonObject body = jsonObj["body"].toObject();
        if (body.contains("MSG")) {
            QString msg = body["MSG"].toString();
            if (msg == "ACK-HEARTBEAT") {
                processHeartbeatResponse(jsonObj);
                return;
            }
        }
    }
    
    // 处理实时数据
    if (jsonObj.contains("body")) {
        QJsonObject body = jsonObj["body"].toObject();
        if (body.contains("MSG") && body["MSG"].toString() == "REALTIME") {
            processRealtimeData(jsonObj);
            storeSensorData(jsonObj);
            emit dataReceived(jsonObj);
        }
    }
}

void TcpServer::sendHeartbeat()
{
    if (!m_clientSocket || !m_isClientConnected) return;
    
    sendHeartbeatMessage();
}

void TcpServer::sendHeartbeatMessage()
{
    if (!m_clientSocket || !m_isClientConnected) return;
    
    QJsonObject heartbeat;
    heartbeat["type"] = 0;
    heartbeat["sync"] = "sync header date";
    
    QJsonObject body;
    body["VER"] = "1.0";
    body["MSG"] = "HEARTBEAT";
    body["PARAM"] = QString::number(QDateTime::currentMSecsSinceEpoch());
    
    heartbeat["body"] = body;
    
    QJsonDocument doc(heartbeat);
    QByteArray data = doc.toJson(QJsonDocument::Compact);
    
    m_clientSocket->write(data);
    m_clientSocket->flush();
    
    qDebug() << "发送心跳:" << data;
    
    // 启动心跳超时定时器
    m_heartbeatTimeoutTimer->start();
}

void TcpServer::processHeartbeatResponse(const QJsonObject &response)
{
    qDebug() << "收到心跳响应";
    m_heartbeatTimeoutTimer->stop();
}

void TcpServer::onHeartbeatTimeout()
{
    qWarning() << "心跳超时，断开客户端连接";
    if (m_clientSocket) {
        m_clientSocket->disconnectFromHost();
    }
}

void TcpServer::processRealtimeData(const QJsonObject &data)
{
    if (!data.contains("body")) return;
    
    QJsonObject body = data["body"].toObject();
    if (!body.contains("PARAM")) return;
    
    QJsonObject param = body["PARAM"].toObject();
    
    // 处理各种传感器数据
    if (param.contains("Strain")) {
        processSensorData("Strain", param["Strain"].toArray());
    }
    if (param.contains("Move")) {
        processSensorData("Move", param["Move"].toArray());
    }
    if (param.contains("Temp")) {
        processSensorData("Temp", param["Temp"].toArray());
    }
    if (param.contains("WLG")) {
        processSensorData("WLG", param["WLG"].toArray());
    }
    if (param.contains("a")) {
        processSensorData("Acceleration", param["a"].toArray());
    }
    if (param.contains("P")) {
        processSensorData("Pressure", param["P"].toArray());
    }
    if (param.contains("WL")) {
        // 处理波长数据
        QJsonArray wlArray = param["WL"].toArray();
        for (const QJsonValue &value : wlArray) {
            if (value.isArray()) {
                QJsonArray channelData = value.toArray();
                if (channelData.size() >= 2) {
                    int channelNum = channelData[0].toInt();
                    for (int i = 1; i < channelData.size(); ++i) {
                        double wavelength = channelData[i].toString().toDouble();
                        
                        QSqlQuery query(m_database);
                        query.prepare("INSERT INTO wavelength_data (channel_number, wavelength) VALUES (?, ?)");
                        query.addBindValue(channelNum);
                        query.addBindValue(wavelength);
                        query.exec();
                    }
                }
            }
        }
    }
}

void TcpServer::processSensorData(const QString &sensorType, const QJsonArray &sensorArray)
{
    for (const QJsonValue &value : sensorArray) {
        if (value.isObject()) {
            QJsonObject sensor = value.toObject();
            
            int channelNum = sensor["ChNum"].toInt();
            QString sensorId = sensor["ID"].toString();
            QString sensorName = sensor["Name"].toString();
            double sensorValue = sensor["Val"].toString().toDouble();
            
            QSqlQuery query(m_database);
            query.prepare("INSERT INTO sensor_data (sensor_type, channel_number, sensor_id, sensor_name, value) VALUES (?, ?, ?, ?, ?)");
            query.addBindValue(sensorType);
            query.addBindValue(channelNum);
            query.addBindValue(sensorId);
            query.addBindValue(sensorName);
            query.addBindValue(sensorValue);
            query.exec();
            
            qDebug() << QString("存储传感器数据: %1 通道%2 值%3").arg(sensorType).arg(channelNum).arg(sensorValue);
        }
    }
}

bool TcpServer::storeSensorData(const QJsonObject &data)
{
    // 这个方法已经在processRealtimeData中实现了
    return true;
}
