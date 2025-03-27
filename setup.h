#ifndef SETUP_H
#define SETUP_H

#include <QWidget>
#include <variate.h>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QCheckBox>
#include <QStandardItemModel>
#include <QDateTimeAxis>
#include <QtCharts>

namespace Ui {
class SetUp;
}

class SetUp : public QWidget
{
    Q_OBJECT

public:
    explicit SetUp(QWidget *parent = nullptr);
    ~SetUp();
    void SaveConfigFile(const QString& ConfigFileName);

private slots:
    void on_SetButton_clicked();

    void on_SaveButton_clicked();

    void on_GPButton_clicked();

    void on_BCButton_clicked();

    void anyStateChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::SetUp *ui;
};

#endif // SETUP_H
