#ifndef TISHI_H
#define TISHI_H

#include <QWidget>
#include <QTextEdit>
#include <QFile>
#include <QVBoxLayout>

namespace Ui {
class Tishi;
}

class Tishi : public QWidget
{
    Q_OBJECT

public:
    explicit Tishi(QWidget *parent = nullptr);
    ~Tishi();

private:
    Ui::Tishi *ui;
};

#endif // TISHI_H
