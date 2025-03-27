#ifndef WARNING_H
#define WARNING_H

#include <QWidget>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QStandardItemModel>
#include <QFileDialog>
#include "variate.h"
namespace Ui {
class Warning;
}

class Warning : public QWidget
{
    Q_OBJECT

public:
    explicit Warning(QWidget *parent = nullptr);
    ~Warning();

private slots:
    void on_comboBox_1_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_QueryButton_clicked();

    void on_SaveButton_clicked();

private:
    Ui::Warning *ui;
    int QType=0;
    int QFrom=0;
    QStandardItemModel* model;
    bool TimePK(QString time);
    bool ExaInput(QString inputstring);
};

#endif // WARNING_H
