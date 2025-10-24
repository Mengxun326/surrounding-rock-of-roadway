#include <QCoreApplication>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>

// 测试TCP客户端连接
class TestTcpClient : public QObject
{
    Q_OBJECT

public:
    TestTcpClient(QObject *parent = nullptr) : QObject(parent)
    {
        m_socket = new QTcpSocket(this);
        connect(m_socket, &QTcpSocket::connected, this, &TestTcpClient::onConnected);
        connect(m_socket, &QTcpSocket::disconnected, this, &TestTcpClient::onDisconnected);
        connect(m_socket, &QTcpSocket::readyRead, this, &TestTcpClient::onDataReceived);
        
        // 定时发送心跳
        m_heartbeatTimer = new QTimer(this);
        connect(m_heartbeatTimer, &QTimer::timeout, this, &TestTcpClient::sendHeartbeat);
        
        // 定时发送测试数据
        m_dataTimer = new QTimer(this);
        connect(m_dataTimer, &QTimer::timeout, this, &TestTcpClient::sendTestData);
    }
    
    void connectToServer()
    {
        qDebug() << "尝试连接到TCP服务器...";
        m_socket->connectToHost(QHostAddress::LocalHost, 5555);
    }
    
    void disconnectFromServer()
    {
        m_socket->disconnectFromHost();
    }

private slots:
    void onConnected()
    {
        qDebug() << "已连接到TCP服务器";
        m_heartbeatTimer->start(30000); // 30秒心跳
        m_dataTimer->start(5000); // 5秒发送一次测试数据
    }
    
    void onDisconnected()
    {
        qDebug() << "与TCP服务器断开连接";
        m_heartbeatTimer->stop();
        m_dataTimer->stop();
    }
    
    void onDataReceived()
    {
        QByteArray data = m_socket->readAll();
        qDebug() << "收到服务器响应:" << data;
    }
    
    void sendHeartbeat()
    {
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
        
        m_socket->write(data);
        m_socket->flush();
        
        qDebug() << "发送心跳:" << data;
    }
    
    void sendTestData()
    {
        QJsonObject message;
        message["type"] = 0;
        message["sync"] = "sync header date";
        
        QJsonObject body;
        body["VER"] = "1.0";
        body["MSG"] = "REALTIME";
        body["ERR"] = 0;
        
        QJsonObject param;
        
        // 应变数据
        QJsonArray strainArray;
        QJsonObject strain1;
        strain1["ChNum"] = 1;
        strain1["ID"] = "00101";
        strain1["Name"] = "应变传感器1";
        strain1["Val"] = "15.24";
        strainArray.append(strain1);
        
        QJsonObject strain2;
        strain2["ChNum"] = 2;
        strain2["ID"] = "00201";
        strain2["Name"] = "应变传感器2";
        strain2["Val"] = "18.56";
        strainArray.append(strain2);
        
        param["Strain"] = strainArray;
        
        // 位移数据
        QJsonArray moveArray;
        QJsonObject move1;
        move1["ChNum"] = 1;
        move1["ID"] = "00102";
        move1["Name"] = "位移传感器1";
        move1["Val"] = "2.35";
        moveArray.append(move1);
        
        param["Move"] = moveArray;
        
        // 温度数据
        QJsonArray tempArray;
        QJsonObject temp1;
        temp1["ChNum"] = 1;
        temp1["ID"] = "00103";
        temp1["Name"] = "温度传感器1";
        temp1["Val"] = "25.6";
        tempArray.append(temp1);
        
        param["Temp"] = tempArray;
        
        body["PARAM"] = param;
        message["body"] = body;
        
        QJsonDocument doc(message);
        QByteArray data = doc.toJson(QJsonDocument::Compact);
        
        m_socket->write(data);
        m_socket->flush();
        
        qDebug() << "发送测试数据:" << data;
    }

private:
    QTcpSocket *m_socket;
    QTimer *m_heartbeatTimer;
    QTimer *m_dataTimer;
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    
    TestTcpClient client;
    
    // 延迟1秒后连接，给服务器启动时间
    QTimer::singleShot(1000, &client, &TestTcpClient::connectToServer);
    
    // 30秒后断开连接
    QTimer::singleShot(30000, &client, &TestTcpClient::disconnectFromServer);
    
    // 35秒后退出
    QTimer::singleShot(35000, &app, &QCoreApplication::quit);
    
    return app.exec();
}

#include "test_communication.moc"
