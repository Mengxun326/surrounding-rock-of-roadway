#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDateTime>
#include <QDebug>

class TcpServer : public QTcpServer
{
    Q_OBJECT

public:
    explicit TcpServer(QObject *parent = nullptr);
    ~TcpServer();
    
    bool startServer(quint16 port = 5555);
    void stopServer();
    
    // 数据库操作
    bool initDatabase();
    bool storeSensorData(const QJsonObject &data);
    
signals:
    void dataReceived(const QJsonObject &data);
    void clientConnected();
    void clientDisconnected();
    void connectionError(const QString &error);

private slots:
    void onNewConnection();
    void onClientDisconnected();
    void onDataReceived();
    void sendHeartbeat();
    void onHeartbeatTimeout();

private:
    QTcpSocket *m_clientSocket;
    QTimer *m_heartbeatTimer;
    QTimer *m_heartbeatTimeoutTimer;
    QSqlDatabase m_database;
    bool m_isClientConnected;
    QString m_syncHeader;
    
    // 心跳相关
    void sendHeartbeatMessage();
    void processHeartbeatResponse(const QJsonObject &response);
    
    // 数据处理
    void processRealtimeData(const QJsonObject &data);
    void processSensorData(const QString &sensorType, const QJsonArray &sensorArray);
    
    // 数据库表创建
    void createTables();
};

#endif // TCPSERVER_H
