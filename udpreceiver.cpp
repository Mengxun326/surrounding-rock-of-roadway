#include "udpreceiver.h"
#include <QSqlError>

UdpReceiver::UdpReceiver(QObject *parent)
    : QObject(parent)
    , m_udpSocket(new QUdpSocket(this))
    , m_isReceiving(false)
    , m_totalPackets(0)
    , m_currentPacket(0)
    , m_isDeviceConnected(false)
{
    initDatabase();
    
    connect(m_udpSocket, &QUdpSocket::readyRead, this, &UdpReceiver::onDataReceived);
}

UdpReceiver::~UdpReceiver()
{
    stopReceiver();
    if (m_database.isOpen()) {
        m_database.close();
    }
}

bool UdpReceiver::startReceiver(quint16 port)
{
    if (m_udpSocket->state() == QUdpSocket::BoundState) {
        qWarning() << "UDP接收器已经在运行";
        return true;
    }
    
    if (!m_udpSocket->bind(QHostAddress::Any, port)) {
        qCritical() << "无法绑定UDP端口:" << port << m_udpSocket->errorString();
        return false;
    }
    
    qInfo() << "UDP接收器监听所有网络接口，设备可从192.168.3.69发送数据到192.168.3.90:" << port;
    
    m_isReceiving = true;
    qInfo() << "UDP接收器已启动，监听端口:" << port;
    return true;
}

void UdpReceiver::stopReceiver()
{
    if (m_udpSocket->state() == QUdpSocket::BoundState) {
        m_udpSocket->close();
        qInfo() << "UDP接收器已停止";
    }
    m_isReceiving = false;
    m_isDeviceConnected = false;
}

bool UdpReceiver::initDatabase()
{
    m_database = QSqlDatabase::addDatabase("QSQLITE", "vibration_data");
    m_database.setDatabaseName("vibration_data.db");
    
    if (!m_database.open()) {
        qCritical() << "无法打开振动数据库:" << m_database.lastError().text();
        return false;
    }
    
    createTables();
    qInfo() << "振动数据库初始化成功";
    return true;
}

void UdpReceiver::createTables()
{
    QSqlQuery query(m_database);
    
    // 创建振动数据表
    QString createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS vibration_data (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
            channel_number INTEGER,
            sensor_id INTEGER,
            wavelength REAL,
            frequency REAL
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qCritical() << "创建振动数据表失败:" << query.lastError().text();
    }
    
    // 创建频谱数据表
    createTableSQL = R"(
        CREATE TABLE IF NOT EXISTS spectrum_data (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
            channel_number INTEGER,
            sensor_id INTEGER,
            sample_rate INTEGER,
            data_size INTEGER,
            packet_number INTEGER,
            total_packets INTEGER,
            spectrum_value REAL
        )
    )";
    
    if (!query.exec(createTableSQL)) {
        qCritical() << "创建频谱数据表失败:" << query.lastError().text();
    }
}

void UdpReceiver::onDataReceived()
{
    while (m_udpSocket->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(m_udpSocket->pendingDatagramSize());
        QHostAddress sender;
        quint16 senderPort;
        
        m_udpSocket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);
        
        qDebug() << "收到UDP数据，大小:" << datagram.size() << "来自:" << sender.toString();
        
        // 只在第一次连接时发出设备连接信号
        if (!m_isDeviceConnected) {
            m_isDeviceConnected = true;
            emit deviceConnected();
        }
        
        // 检查是否是启动命令
        if (datagram == QByteArray::fromHex("FFFFFFEEEEEEEE")) {
            processStartCommand(datagram);
            return;
        }
        
        // 检查数据长度
        if (datagram.size() < 4) {
            qWarning() << "UDP数据太短，忽略";
            return;
        }
        
        // 检查包头
        QByteArray header = datagram.left(4);
        if (header != QByteArray::fromHex("FFFFFFFF")) {
            qWarning() << "无效的UDP包头";
            return;
        }
        
        // 获取帧类型
        if (datagram.size() < 5) {
            qWarning() << "UDP数据不完整";
            return;
        }
        
        quint8 frameType = static_cast<quint8>(datagram[4]);
        
        switch (frameType) {
        case 0x03: // 实时数据
            processRealtimeData(datagram);
            break;
        case 0x04: // 频谱数据
            processSpectrumData(datagram);
            break;
        default:
            qWarning() << "未知的帧类型:" << frameType;
            break;
        }
        
        emit dataReceived(datagram);
    }
}

void UdpReceiver::processStartCommand(const QByteArray &data)
{
    qInfo() << "收到启动数据发送命令";
    emit onStartDataTransmission();
}

void UdpReceiver::processRealtimeData(const QByteArray &data)
{
    // 解析实时数据包
    // 包头(4) + 帧类型(1) + 数据部分
    
    int offset = 5; // 跳过包头和帧类型
    
    while (offset < data.size() - 4) { // 预留包尾空间
        if (offset + 40 > data.size()) break; // 每个传感器数据40字节
        
        // 通道编号
        quint8 channel = static_cast<quint8>(data[offset]);
        offset++;
        
        // 传感器ID
        quint8 sensorId = static_cast<quint8>(data[offset]);
        offset++;
        
        // 波长 (4字节，高位在前)
        quint32 wavelengthRaw = bytesToUint32(data, offset, true);
        double wavelength = wavelengthRaw / 1000.0;
        offset += 4;
        
        // 主频 (4字节，高位在前)
        quint32 frequencyRaw = bytesToUint32(data, offset, true);
        double frequency = frequencyRaw / 1000.0;
        offset += 4;
        
        // 预留32字节
        offset += 32;
        
        qDebug() << QString("振动数据 - 通道:%1 ID:%2 波长:%3 频率:%4")
                    .arg(channel).arg(sensorId).arg(wavelength).arg(frequency);
        
        // 存储到数据库
        QSqlQuery query(m_database);
        query.prepare("INSERT INTO vibration_data (channel_number, sensor_id, wavelength, frequency) VALUES (?, ?, ?, ?)");
        query.addBindValue(channel);
        query.addBindValue(sensorId);
        query.addBindValue(wavelength);
        query.addBindValue(frequency);
        query.exec();
        
        emit vibrationDataReceived(channel, sensorId, wavelength, frequency);
    }
}

void UdpReceiver::processSpectrumData(const QByteArray &data)
{
    // 解析频谱数据包
    int offset = 5; // 跳过包头和帧类型
    
    if (data.size() < offset + 8) {
        qWarning() << "频谱数据包不完整";
        return;
    }
    
    // 通道号
    quint8 channel = static_cast<quint8>(data[offset]);
    offset++;
    
    // ID
    quint8 sensorId = static_cast<quint8>(data[offset]);
    offset++;
    
    // 采样率 (2字节，高位在前)
    quint16 sampleRate = bytesToUint16(data, offset, true);
    offset += 2;
    
    // 有效数据大小 (2字节，高位在前)
    quint16 dataSize = bytesToUint16(data, offset, true);
    offset += 2;
    
    // 总包数量
    quint8 totalPackets = static_cast<quint8>(data[offset]);
    offset++;
    
    // 当前帧
    quint8 currentPacket = static_cast<quint8>(data[offset]);
    offset++;
    
    // 有效频谱数据 (4字节，高位在前)
    quint32 spectrumValue = bytesToUint32(data, offset, true);
    double spectrumData = spectrumValue / 100000000.0;
    offset += 4;
    
    qDebug() << QString("频谱数据 - 通道:%1 ID:%2 采样率:%3 数据大小:%4 包:%5/%6 值:%7")
                .arg(channel).arg(sensorId).arg(sampleRate).arg(dataSize)
                .arg(currentPacket).arg(totalPackets).arg(spectrumData);
    
    // 存储到数据库
    QSqlQuery query(m_database);
    query.prepare("INSERT INTO spectrum_data (channel_number, sensor_id, sample_rate, data_size, packet_number, total_packets, spectrum_value) VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(channel);
    query.addBindValue(sensorId);
    query.addBindValue(sampleRate);
    query.addBindValue(dataSize);
    query.addBindValue(currentPacket);
    query.addBindValue(totalPackets);
    query.addBindValue(spectrumData);
    query.exec();
    
    // 如果是分包传输，需要组包
    if (totalPackets > 1) {
        if (currentPacket == 1) {
            // 第一包，初始化缓冲区
            m_spectrumBuffer.clear();
            m_totalPackets = totalPackets;
            m_currentPacket = 1;
        }
        
        // 添加到缓冲区
        m_spectrumBuffer.append(data.mid(offset));
        
        if (currentPacket == totalPackets) {
            // 最后一包，完成组包
            qInfo() << "频谱数据组包完成，总大小:" << m_spectrumBuffer.size();
            m_spectrumBuffer.clear();
        }
    }
}

quint32 UdpReceiver::bytesToUint32(const QByteArray &data, int offset, bool bigEndian)
{
    if (offset + 4 > data.size()) return 0;
    
    if (bigEndian) {
        return (static_cast<quint32>(static_cast<quint8>(data[offset])) << 24) |
               (static_cast<quint32>(static_cast<quint8>(data[offset + 1])) << 16) |
               (static_cast<quint32>(static_cast<quint8>(data[offset + 2])) << 8) |
               static_cast<quint32>(static_cast<quint8>(data[offset + 3]));
    } else {
        return static_cast<quint32>(static_cast<quint8>(data[offset])) |
               (static_cast<quint32>(static_cast<quint8>(data[offset + 1])) << 8) |
               (static_cast<quint32>(static_cast<quint8>(data[offset + 2])) << 16) |
               (static_cast<quint32>(static_cast<quint8>(data[offset + 3])) << 24);
    }
}

quint16 UdpReceiver::bytesToUint16(const QByteArray &data, int offset, bool bigEndian)
{
    if (offset + 2 > data.size()) return 0;
    
    if (bigEndian) {
        return (static_cast<quint16>(static_cast<quint8>(data[offset])) << 8) |
               static_cast<quint16>(static_cast<quint8>(data[offset + 1]));
    } else {
        return static_cast<quint16>(static_cast<quint8>(data[offset])) |
               (static_cast<quint16>(static_cast<quint8>(data[offset + 1])) << 8);
    }
}

bool UdpReceiver::storeVibrationData(const QByteArray &data)
{
    // 这个方法已经在processRealtimeData中实现了
    return true;
}

void UdpReceiver::onStartDataTransmission()
{
    qInfo() << "开始接收振动数据";
    m_isReceiving = true;
}
