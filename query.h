#ifndef QUERY_H
#define QUERY_H

#include <QWidget>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QStandardItemModel>
#include <QFileDialog>
#include "variate.h"

namespace Ui {
class query;
}

class query : public QWidget
{
    Q_OBJECT

public:
    explicit query(QWidget *parent = nullptr);
    ~query();

private slots:
    void on_QueryButton_clicked();

    void on_SaveButton_clicked();

    void on_comboBox_1_activated(int index);

    void on_comboBox_2_activated(int index);

private:
    Ui::query *ui;
    int QType=0;
    int QFrom=0;
    QStandardItemModel* model;
    bool TimePK(QString time);
    bool ExaInput(QString inputstring);
};

#endif // QUERY_H
