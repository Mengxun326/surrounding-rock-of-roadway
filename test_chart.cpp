#include <QCoreApplication>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTcpSocket>
#include <QHostAddress>
#include <QTimer>

// 测试TCP客户端连接并发送传感器数据
class TestChartClient : public QObject
{
    Q_OBJECT

public:
    TestChartClient(QObject *parent = nullptr) : QObject(parent)
    {
        m_socket = new QTcpSocket(this);
        connect(m_socket, &QTcpSocket::connected, this, &TestChartClient::onConnected);
        connect(m_socket, &QTcpSocket::disconnected, this, &TestChartClient::onDisconnected);
        connect(m_socket, &QTcpSocket::readyRead, this, &TestChartClient::onDataReceived);
        
        // 定时发送测试数据
        m_dataTimer = new QTimer(this);
        connect(m_dataTimer, &QTimer::timeout, this, &TestChartClient::sendTestData);
        
        m_dataCounter = 0;
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
        qDebug() << "已连接到TCP服务器，开始发送测试数据";
        m_dataTimer->start(2000); // 每2秒发送一次数据
    }
    
    void onDisconnected()
    {
        qDebug() << "与TCP服务器断开连接";
        m_dataTimer->stop();
    }
    
    void onDataReceived()
    {
        QByteArray data = m_socket->readAll();
        qDebug() << "收到服务器响应:" << data;
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
        
        // 应变数据 - 模拟正弦波
        QJsonArray strainArray;
        QJsonObject strain1;
        strain1["ChNum"] = 1;
        strain1["ID"] = "00101";
        strain1["Name"] = "应变传感器1";
        strain1["Val"] = QString::number(15 + 5 * qSin(m_dataCounter * 0.3));
        strainArray.append(strain1);
        
        QJsonObject strain2;
        strain2["ChNum"] = 2;
        strain2["ID"] = "00201";
        strain2["Name"] = "应变传感器2";
        strain2["Val"] = QString::number(18 + 3 * qCos(m_dataCounter * 0.4));
        strainArray.append(strain2);
        
        param["Strain"] = strainArray;
        
        // 位移数据 - 模拟余弦波
        QJsonArray moveArray;
        QJsonObject move1;
        move1["ChNum"] = 1;
        move1["ID"] = "00102";
        move1["Name"] = "位移传感器1";
        move1["Val"] = QString::number(2 + 1.5 * qSin(m_dataCounter * 0.2));
        moveArray.append(move1);
        
        param["Move"] = moveArray;
        
        // 温度数据 - 模拟缓慢变化
        QJsonArray tempArray;
        QJsonObject temp1;
        temp1["ChNum"] = 1;
        temp1["ID"] = "00103";
        temp1["Name"] = "温度传感器1";
        temp1["Val"] = QString::number(25 + 2 * qSin(m_dataCounter * 0.1));
        tempArray.append(temp1);
        
        param["Temp"] = tempArray;
        
        body["PARAM"] = param;
        message["body"] = body;
        
        QJsonDocument doc(message);
        QByteArray data = doc.toJson(QJsonDocument::Compact);
        
        m_socket->write(data);
        m_socket->flush();
        
        qDebug() << "发送测试数据 #" << m_dataCounter << ":" << data;
        m_dataCounter++;
    }

private:
    QTcpSocket *m_socket;
    QTimer *m_dataTimer;
    int m_dataCounter;
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    
    TestChartClient client;
    
    // 延迟2秒后连接，给服务器启动时间
    QTimer::singleShot(2000, &client, &TestChartClient::connectToServer);
    
    // 60秒后断开连接
    QTimer::singleShot(60000, &client, &TestChartClient::disconnectFromServer);
    
    // 65秒后退出
    QTimer::singleShot(65000, &app, &QCoreApplication::quit);
    
    return app.exec();
}

#include "test_chart.moc"

