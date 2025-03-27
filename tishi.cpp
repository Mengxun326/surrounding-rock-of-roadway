#include "tishi.h"
#include "ui_tishi.h"

Tishi::Tishi(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Tishi)
{
    ui->setupUi(this);
    QWidget *contentWidget = new QWidget();
    QTextEdit *TextEdit = new QTextEdit(contentWidget);
    QVBoxLayout *layout = new QVBoxLayout(contentWidget);
    layout->addWidget(TextEdit);
    ui->scrollArea->setWidget(contentWidget);
    ui->scrollArea->setWidgetResizable(true);
    QFile file(":/data/tishi.txt");
    file.open(QIODevice::ReadOnly);
    QByteArray ba = file.readAll();
    TextEdit->setText(QString(ba));
    file.close();
}

Tishi::~Tishi()
{
    delete ui;
}
