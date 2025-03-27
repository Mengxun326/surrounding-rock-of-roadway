#ifndef SENSORCONFIG_H
#define SENSORCONFIG_H

#include <QWidget>
#include <combodelegate.h>
#include <variate.h>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QStandardItemModel>
#include <QDebug>
#include <QFileDialog>
#include <tishi.h>
namespace Ui {
class SensorConfig;
}

class SensorConfig : public QWidget
{
    Q_OBJECT

public:
    explicit SensorConfig(QWidget *parent = nullptr);
    ~SensorConfig();
private slots:
    void on_DeleteButton_clicked();

    void on_SaveButton_clicked();

    void on_AddButton_clicked();

    void on_TishiButton_clicked();

private:
    Ui::SensorConfig *ui;
    QStandardItemModel* model;
    QStandardItemModel* TDmodel;
    int countTD[17]={};
};

#endif // SENSORCONFIG_H
