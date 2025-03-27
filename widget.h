#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QMessageBox>
#include <QFile>
#include <QTcpSocket>
#include <QHostAddress>
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

    void clientTnfoSlot();

    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void connectTCP();

    void on_comboBox_activated(int index);

    void updateTime();

private:
    Ui::Widget *ui;
    QTcpSocket *socket;
    QWidget *scrollWidget;
    QVBoxLayout *scrollLayout;
    QTimer *timer;
    QTimer *Tcptimer;
    QList<QPair<QDateTime, qreal>> readDataFromCSV(int index);
};
#endif // WIDGET_H
