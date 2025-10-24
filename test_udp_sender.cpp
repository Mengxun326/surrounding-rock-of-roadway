#include <QCoreApplication>
#include <QDebug>
#include <QUdpSocket>
#include <QHostAddress>
#include <QTimer>
#include <QByteArray>

// 测试UDP发送器
class TestUdpSender : public QObject
{
    Q_OBJECT

public:
    TestUdpSender(QObject *parent = nullptr) : QObject(parent)
    {
        m_udpSocket = new QUdpSocket(this);
        
        // 定时发送测试数据
        m_timer = new QTimer(this);
        connect(m_timer, &QTimer::timeout, this, &TestUdpSender::sendTestData);
    }
    
    void startSending()
    {
        qDebug() << "开始发送UDP测试数据...";
        
        // 发送启动命令
        sendStartCommand();
        
        // 延迟1秒后开始发送数据
        QTimer::singleShot(1000, this, &TestUdpSender::startDataTransmission);
    }
    
    void stopSending()
    {
        m_timer->stop();
        qDebug() << "停止发送UDP测试数据";
    }

private slots:
    void sendTestData()
    {
        // 发送实时振动数据
        sendRealtimeData();
        
        // 偶尔发送频谱数据
        static int counter = 0;
        if (++counter % 5 == 0) {
            sendSpectrumData();
        }
    }
    
    void startDataTransmission()
    {
        m_timer->start(2000); // 每2秒发送一次数据
    }

private:
    void sendStartCommand()
    {
        QByteArray startCmd = QByteArray::fromHex("FFFFFFEEEEEEEE");
        m_udpSocket->writeDatagram(startCmd, QHostAddress::LocalHost, 6666);
        qDebug() << "发送启动命令";
    }
    
    void sendRealtimeData()
    {
        QByteArray data;
        
        // 包头
        data.append(QByteArray::fromHex("FFFFFFFF"));
        
        // 帧类型 (0x03 = 实时数据)
        data.append(static_cast<char>(0x03));
        
        // 通道1数据
        data.append(static_cast<char>(1)); // 通道编号
        data.append(static_cast<char>(1)); // 传感器ID
        
        // 波长 (1535.9597 * 1000 = 1535959)
        quint32 wavelength = 1535959;
        data.append(static_cast<char>((wavelength >> 24) & 0xFF));
        data.append(static_cast<char>((wavelength >> 16) & 0xFF));
        data.append(static_cast<char>((wavelength >> 8) & 0xFF));
        data.append(static_cast<char>(wavelength & 0xFF));
        
        // 主频 (1897.055 * 1000 = 1897055)
        quint32 frequency = 1897055;
        data.append(static_cast<char>((frequency >> 24) & 0xFF));
        data.append(static_cast<char>((frequency >> 16) & 0xFF));
        data.append(static_cast<char>((frequency >> 8) & 0xFF));
        data.append(static_cast<char>(frequency & 0xFF));
        
        // 预留32字节
        data.append(QByteArray(32, 0));
        
        // 通道2数据
        data.append(static_cast<char>(2)); // 通道编号
        data.append(static_cast<char>(2)); // 传感器ID
        
        // 波长 (1553.1787 * 1000 = 1553178)
        wavelength = 1553178;
        data.append(static_cast<char>((wavelength >> 24) & 0xFF));
        data.append(static_cast<char>((wavelength >> 16) & 0xFF));
        data.append(static_cast<char>((wavelength >> 8) & 0xFF));
        data.append(static_cast<char>(wavelength & 0xFF));
        
        // 主频 (2000.123 * 1000 = 2000123)
        frequency = 2000123;
        data.append(static_cast<char>((frequency >> 24) & 0xFF));
        data.append(static_cast<char>((frequency >> 16) & 0xFF));
        data.append(static_cast<char>((frequency >> 8) & 0xFF));
        data.append(static_cast<char>(frequency & 0xFF));
        
        // 预留32字节
        data.append(QByteArray(32, 0));
        
        // 包尾
        data.append(QByteArray::fromHex("E0EEE0EEEEE"));
        
        m_udpSocket->writeDatagram(data, QHostAddress::LocalHost, 6666);
        qDebug() << "发送实时振动数据，大小:" << data.size();
    }
    
    void sendSpectrumData()
    {
        QByteArray data;
        
        // 包头
        data.append(QByteArray::fromHex("FFFFFFFF"));
        
        // 帧类型 (0x04 = 频谱数据)
        data.append(static_cast<char>(0x04));
        
        // 通道号
        data.append(static_cast<char>(1));
        
        // ID
        data.append(static_cast<char>(1));
        
        // 采样率 (1000)
        quint16 sampleRate = 1000;
        data.append(static_cast<char>((sampleRate >> 8) & 0xFF));
        data.append(static_cast<char>(sampleRate & 0xFF));
        
        // 有效数据大小 (1024)
        quint16 dataSize = 1024;
        data.append(static_cast<char>((dataSize >> 8) & 0xFF));
        data.append(static_cast<char>(dataSize & 0xFF));
        
        // 总包数量
        data.append(static_cast<char>(1));
        
        // 当前帧
        data.append(static_cast<char>(1));
        
        // 有效频谱数据 (12345678 / 100000000 = 0.12345678)
        quint32 spectrumValue = 12345678;
        data.append(static_cast<char>((spectrumValue >> 24) & 0xFF));
        data.append(static_cast<char>((spectrumValue >> 16) & 0xFF));
        data.append(static_cast<char>((spectrumValue >> 8) & 0xFF));
        data.append(static_cast<char>(spectrumValue & 0xFF));
        
        // 包尾
        data.append(QByteArray::fromHex("0EEE0EEE0EEE0EEE"));
        
        m_udpSocket->writeDatagram(data, QHostAddress::LocalHost, 6666);
        qDebug() << "发送频谱数据，大小:" << data.size();
    }

private:
    QUdpSocket *m_udpSocket;
    QTimer *m_timer;
};

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    
    TestUdpSender sender;
    
    // 延迟1秒后开始发送
    QTimer::singleShot(1000, &sender, &TestUdpSender::startSending);
    
    // 30秒后停止发送
    QTimer::singleShot(30000, &sender, &TestUdpSender::stopSending);
    
    // 35秒后退出
    QTimer::singleShot(35000, &app, &QCoreApplication::quit);
    
    return app.exec();
}

#include "test_udp_sender.moc"
