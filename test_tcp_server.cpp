#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>

class TestTcpServer : public QObject
{
    Q_OBJECT

public:
    TestTcpServer(QObject *parent = nullptr) : QObject(parent)
    {
        m_server = new QTcpServer(this);
        connect(m_server, &QTcpServer::newConnection, this, &TestTcpServer::onNewConnection);
    }

    bool startServer(quint16 port)
    {
        if (!m_server->listen(QHostAddress::Any, port)) {
            qCritical() << "无法启动TCP服务器:" << m_server->errorString();
            return false;
        }
        qInfo() << "TCP服务器已启动，监听端口:" << port;
        return true;
    }

private slots:
    void onNewConnection()
    {
        QTcpSocket *clientSocket = m_server->nextPendingConnection();
        qInfo() << "客户端已连接:" << clientSocket->peerAddress().toString();
        
        connect(clientSocket, &QTcpSocket::readyRead, this, &TestTcpServer::onDataReceived);
        connect(clientSocket, &QTcpSocket::disconnected, clientSocket, &QTcpSocket::deleteLater);
    }

    void onDataReceived()
    {
        QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender());
        if (!clientSocket) return;

        QByteArray data = clientSocket->readAll();
        QString jsonString = QString::fromUtf8(data);
        
        qDebug() << "接收到数据:" << jsonString;
        
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
        
        if (error.error != QJsonParseError::NoError) {
            qWarning() << "JSON解析错误:" << error.errorString();
            return;
        }
        
        QJsonObject jsonObj = doc.object();
        qInfo() << "解析的JSON对象:" << jsonObj;
    }

private:
    QTcpServer *m_server;
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    
    TestTcpServer server;
    if (!server.startServer(5555)) {
        return 1;
    }
    
    qInfo() << "测试TCP服务器正在运行，按Ctrl+C退出";
    
    return app.exec();
}

#include "test_tcp_server.moc"
