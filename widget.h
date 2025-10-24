#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
#include <QTcpSocket>
#include <QHostAddress>
#include <QCloseEvent>
#include <setup.h>
#include <QStandardPaths>
#include <QFileInfo>
#include <QDir>
#include <QTimer>
#include <QScrollArea>
#include <QFont>
#include <QFontDatabase>
#include <QVBoxLayout>
#include <QtCharts>
#include <QDateTimeAxis>
#include "variate.h"
#include "query.h"
#include "sensorconfig.h"
#include "sensordesign.h"
#include "warning.h"
#include "moduleconfig.h"
#include "connection.h"
#include "tcpserver.h"
#include "udpreceiver.h"

#define TIMEOUT 3*1000//超时时间
#define TcpPort "8000"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void ReadConfigFile(const QString& ConfigFileName);

private slots:
    void readLogFile();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_comboBox_activated(int index);

    void updateTime();
    
    // 新增：通信服务槽函数
    void onTcpDataReceived(const QJsonObject &data);
    void onTcpClientConnected();
    void onTcpClientDisconnected();
    void onTcpConnectionError(const QString &error);
    void onUdpDataReceived(const QByteArray &data);
    void onVibrationDataReceived(int channel, int sensorId, double wavelength, double frequency);
    void onUdpDeviceConnected();
    void onUdpDeviceDisconnected();
    void updateRealtimeDisplay();
    void initCommunicationServices();
    void initRealtimeChart();
    
    // 窗口关闭事件处理
    void closeEvent(QCloseEvent *event) override;
    
    // 测试设备连接
    void testDeviceConnection();

private:
    Ui::Widget *ui;
    QWidget *scrollWidget;
    QVBoxLayout *scrollLayout;
    QTimer *timer;
    QList<QPair<QDateTime, qreal>> readDataFromCSV(int index);
    
    // 新增：通信服务
    TcpServer *m_tcpServer;
    UdpReceiver *m_udpReceiver;
    
    // 新增：数据存储和显示
    QList<QPair<QDateTime, qreal>> m_realtimeData;
    QTimer *m_dataUpdateTimer;
    
    // 新增：实时图表
    QChart *m_realtimeChart;
    QChartView *m_chartView;
    QLineSeries *m_strainSeries;
    QLineSeries *m_moveSeries;
    QLineSeries *m_tempSeries;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    QValueAxis *m_timeAxis;
    QDateTime m_startTime;
};
#endif // WIDGET_H
