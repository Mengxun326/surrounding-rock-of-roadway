#include "sensorconfig.h"
#include "ui_sensorconfig.h"

SensorConfig::SensorConfig(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SensorConfig)
{
    ui->setupUi(this);
    QPixmap bgimg(":/imgs/chun.png");
    ui->bg_label->setPixmap(bgimg);
    ui->bg_label->lower();
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    QStringList sensorTypes;//传感器类型
    sensorTypes << ""
                << "温度"
                << "锚索测力计"
                << "顶板离层计"
                << "智能锚杆计"
                << "温度补偿";
    ComboDelegate* delegateSensorTypes = new ComboDelegate(sensorTypes, this);
    ui->tableView->setItemDelegateForColumn(4, delegateSensorTypes);  // 第4列表格设置为下拉框形式代表类型
    QStringList isUse;//是否使用
    isUse << ""
          << "是"
          << "否";
    ComboDelegate* delegateisUse = new ComboDelegate(isUse, this);
    ui->tableView->setItemDelegateForColumn(15, delegateisUse);// 第15列表格设置为下拉框形式代表类型

    TDmodel = new QStandardItemModel(this);
    ui->TD_tableView->setModel(TDmodel);
    QStringList table_h_headers;
    table_h_headers <<"传感器数量";
    TDmodel->setHorizontalHeaderLabels(table_h_headers);
    QStringList table_v_headers;
    table_v_headers << "通道1"
                    << "通道2"
                    << "通道3"
                    << "通道4"
                    << "通道5"
                    << "通道6"
                    << "通道7"
                    << "通道8"
                    << "通道9"
                    << "通道10"
                    << "通道11"
                    << "通道12"
                    << "通道13"
                    << "通道14"
                    << "通道15"
                    << "通道16";
    TDmodel->setVerticalHeaderLabels(table_v_headers);
    QFile SensorConfigFile(SensorConfigPath);
    SensorConfigFile.setPermissions(QFileDevice::ReadOwner);
    if(!SensorConfigFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"警告",SensorConfigPath+"文件打开失败");
        qDebug() << "Could not open the file for writing:" << SensorConfigFile.errorString();
    }
    else
    {
        //创建一个模型
        QTextStream stream(&SensorConfigFile);
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
            countTD[lineData[0].toInt()]++;
            model->appendRow(items);
        }
        for(int i = 1 ; i < 17 ;i++)
        {
            TDmodel->setItem(i-1,0,new QStandardItem(QString::number(countTD[i])));
        }
        SensorConfigFile.close();
    }
}

SensorConfig::~SensorConfig()
{
    delete ui;
}

//删除
void SensorConfig::on_DeleteButton_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    model->removeRow(index.row());
    QMessageBox::information(this,"删除","已成功删除，请及时保存");
}
//保存
void SensorConfig::on_SaveButton_clicked()
{
    for(int i=0;i<17;i++)
    {
        countTD[i]=0;
    }
    //打开文件
    QFile SensorConfigFile(SensorConfigPath);
    SensorConfigFile.setPermissions(QFileDevice::WriteOwner);
    if(!SensorConfigFile.open(QIODevice::Truncate | QIODevice::WriteOnly))
    {
        qInfo()<<"saveDataToFile open file failed";
    }
    QTextStream stream(&SensorConfigFile);
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
        if(!model->item(r,0)->text().isEmpty())
            countTD[model->item(r,0)->text().toInt()]++;
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
        for(int i = 1 ; i < 17 ;i++)
        {
            TDmodel->setItem(i-1,0,new QStandardItem(QString::number(countTD[i])));
        }
        stream<<lineData<<"\n";
    }
    end:;
    QMessageBox::information(this,"保存数据","数据已保存");
}

//添加
void SensorConfig::on_AddButton_clicked()
{
    model->setRowCount(model->rowCount()+1);
    //把表格视图滚动到最下面
    ui->tableView->scrollToBottom();
}

//提示
void SensorConfig::on_TishiButton_clicked()
{
    Tishi *c = new Tishi();
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

