#ifndef SENSORDESIGN_H
#define SENSORDESIGN_H

#include <QWidget>
#include <variate.h>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QStandardItemModel>
namespace Ui {
class SensorDesign;
}

class SensorDesign : public QWidget
{
    Q_OBJECT

public:
    explicit SensorDesign(QWidget *parent = nullptr);
    ~SensorDesign();

private slots:
    void on_SaveButton1_clicked();

    void on_comboBox_activated(int index);

    void on_DeleteButton_clicked();

    void on_AddButton_clicked();

    void on_SaveButton2_clicked();

private:
    Ui::SensorDesign *ui;
    QStandardItemModel* model1;
    QStandardItemModel* model2;
    QStandardItemModel* model3;
};

#endif // SENSORDESIGN_H
