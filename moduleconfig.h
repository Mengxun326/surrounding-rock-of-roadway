#ifndef MODULECONFIG_H
#define MODULECONFIG_H

#include <QWidget>
#include <variate.h>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <QStandardItemModel>

namespace Ui {
class ModuleConfig;
}

class ModuleConfig : public QWidget
{
    Q_OBJECT

public:
    explicit ModuleConfig(QWidget *parent = nullptr);
    ~ModuleConfig();

private slots:
    void on_SaveButton_clicked();

private:
    Ui::ModuleConfig *ui;
    QStandardItemModel* model;
};

#endif // MODULECONFIG_H
