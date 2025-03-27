#include "moduleconfig.h"
#include "ui_moduleconfig.h"

ModuleConfig::ModuleConfig(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ModuleConfig)
{
    ui->setupUi(this);
    //插入背景图
    QPixmap bgimg(":/imgs/chun.png");
    ui->bg_label->setPixmap(bgimg);
    ui->bg_label->lower();
    ui->lineEdit_1->setReadOnly(true);
    ui->lineEdit_2->setReadOnly(true);
    ui->lineEdit_3->setReadOnly(true);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QFile ModelFile(ModelPath);
    ModelFile.setPermissions(QFileDevice::ReadOwner);
    if(!ModelFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"警告",ModelPath+"文件打开失败");
        qDebug() << "Could not open the file for writing:" << ModelFile.errorString();
    }
    else
    {
        //创建一个模型
        QTextStream stream(&ModelFile);
        //创建一个模型
        model = new QStandardItemModel(this);
        //把模型浇给视图
        ui->tableView->setModel(model);
        //读取文件:
        //1.表头
        QStringList headers = stream.readLine().split(",");
        model->setHorizontalHeaderLabels(headers);
        //2.数据
        while(!stream.atEnd())
        {
            QStringList lineData = stream.readLine().split(",");
            //生成元素项
            QList<QStandardItem*> items;
            for(QString data :lineData)
            {
                items.push_back(new QStandardItem(data));
            }
            model->appendRow(items);
        }
        ModelFile.close();
    }
}

ModuleConfig::~ModuleConfig()
{
    delete ui;
}

void ModuleConfig::on_SaveButton_clicked()
{
    //打开文件
    QFile ModelFile(ModelPath);
    ModelFile.setPermissions(QFileDevice::WriteOwner);
    if(!ModelFile.open(QIODevice::Truncate | QIODevice::WriteOnly))
    {
        qInfo()<<"saveDataToFile open file failed";
    }
    QTextStream stream(&ModelFile);
    //1.保存表头
    QString headers;
    int colnum = model->columnCount();
    for(int i=0;i<colnum;i++)
    {
        //格式化成一个字符串，然后写入到文件里面
        headers.push_back (model->horizontalHeaderItem(i)->text());
        if(i!=colnum-1)
            headers.push_back(",");
    }
    stream<<headers<<"\n";
    //2.保存数据
    for(int r=0;r<model->rowCount();r++)
    {
        QString lineData;
        for(int i=0;i<colnum;i++)
        {
            lineData.push_back(model->item(r,i)->text());
            if(!model->item(r,i))
            {
                goto end;
            }
            if(i!=colnum-1)
                lineData.push_back(",");
        }
        stream<<lineData<<"\n";
    }
    end:;
    QMessageBox::information(this,"保存数据","数据已保存");
}

