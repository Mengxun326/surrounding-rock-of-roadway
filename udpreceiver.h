#ifndef UDPRECEIVER_H
#define UDPRECEIVER_H

#include <QUdpSocket>
#include <QTimer>
#include <QByteArray>
#include <QDataStream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class UdpReceiver : public QObject
{
    Q_OBJECT

public:
    explicit UdpReceiver(QObject *parent = nullptr);
    ~UdpReceiver();
    
    bool startReceiver(quint16 port = 6666);
    void stopReceiver();
    
    // 数据库操作
    bool initDatabase();
    bool storeVibrationData(const QByteArray &data);

signals:
    void dataReceived(const QByteArray &data);
    void vibrationDataReceived(int channel, int sensorId, double wavelength, double frequency);
    void deviceConnected();
    void deviceDisconnected();

private slots:
    void onDataReceived();
    void onStartDataTransmission();

private:
    QUdpSocket *m_udpSocket;
    QSqlDatabase m_database;
    bool m_isReceiving;
    QByteArray m_spectrumBuffer;
    int m_totalPackets;
    int m_currentPacket;
    bool m_isDeviceConnected;
    
    // 数据处理
    void processRealtimeData(const QByteArray &data);
    void processSpectrumData(const QByteArray &data);
    void processStartCommand(const QByteArray &data);
    
    // 字节序转换
    quint32 bytesToUint32(const QByteArray &data, int offset, bool bigEndian = true);
    quint16 bytesToUint16(const QByteArray &data, int offset, bool bigEndian = true);
    
    // 数据库表创建
    void createTables();
};

#endif // UDPRECEIVER_H
