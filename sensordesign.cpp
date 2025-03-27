#include "sensordesign.h"
#include "ui_sensordesign.h"

SensorDesign::SensorDesign(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SensorDesign)
{
    ui->setupUi(this);
    //插入背景图
    QPixmap bgimg(":/imgs/chun.png");
    ui->bg_label->setPixmap(bgimg);
    ui->bg_label->lower();
    ui->tableView_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    QFile MapFile(MapPath);
    MapFile.setPermissions(QFileDevice::ReadOwner);
    if(!MapFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"警告",MapPath+"文件打开失败");
        qDebug() << "Could not open the file for writing:" << MapFile.errorString();
    }
    else
    {
        //创建一个模型
        QTextStream stream(&MapFile);
        //创建一个模型
        model1 = new QStandardItemModel(this);
        //把模型浇给视图
        ui->tableView_1->setModel(model1);
        //读取文件:
        //1.表头
        QStringList headers = stream.readLine().split(",");
        model1->setHorizontalHeaderLabels(headers);
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
            model1->appendRow(items);
        }
        MapFile.close();
    }
}

SensorDesign::~SensorDesign()
{
    delete ui;
}

void SensorDesign::on_SaveButton1_clicked()
{
    //打开文件
    QFile MapFile(MapPath);
    MapFile.setPermissions(QFileDevice::WriteOwner);
    if(!MapFile.open(QIODevice::Truncate | QIODevice::WriteOnly))
    {
        qInfo()<<"saveDataToFile open file failed";
    }
    QTextStream stream(&MapFile);
    //1.保存表头
    QString headers;
    int colnum = model1->columnCount();
    for(int i=0;i<colnum;i++)
    {
        //格式化成一个字符串，然后写入到文件里面
        headers.push_back (model1->horizontalHeaderItem(i)->text());
        if(i!=colnum-1)
            headers.push_back(",");
    }
    stream<<headers<<"\n";
    //2.保存数据
    for(int r=0;r<model1->rowCount();r++)
    {
        QString lineData;
        for(int i=0;i<colnum;i++)
        {
            lineData.push_back(model1->item(r,i)->text());
            if(!model1->item(r,i))
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


void SensorDesign::on_comboBox_activated(int index)
{
    if(index != 0)
    {
        ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        QFile TeamsFile(TeamsPath);
        TeamsFile.setPermissions(QFileDevice::ReadOwner);
        if(!TeamsFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this,"警告",TeamsPath+"文件打开失败");
            qDebug() << "Could not open the file for writing:" << TeamsFile.errorString();
        }
        else
        {
            //创建一个模型
            QTextStream stream(&TeamsFile);
            //创建一个模型
            model2 = new QStandardItemModel(this);
            model3 = new QStandardItemModel(this);
            //把模型浇给视图
            ui->tableView_2->setModel(model2);
            //读取文件:
            //1.表头
            QStringList headers = stream.readLine().split(",");
            model2->setHorizontalHeaderLabels(headers);
            model3->setHorizontalHeaderLabels(headers);
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
                if(lineData[0].toInt()==index)
                model2->appendRow(items);
                model3->appendRow(items);
            }
            TeamsFile.close();
        }
    }
}


void SensorDesign::on_DeleteButton_clicked()
{
    QModelIndex index = ui->tableView_2->currentIndex();
    model2->removeRow(index.row());
    QMessageBox::information(this,"删除","已成功删除，请及时保存");
}


void SensorDesign::on_AddButton_clicked()
{
    model2->setRowCount(model2->rowCount()+1);
    //把表格视图滚动到最下面
    ui->tableView_2->scrollToBottom();
}


void SensorDesign::on_SaveButton2_clicked()
{
    // 打开文件
    QFile TeamsFile(TeamsPath);
    TeamsFile.setPermissions(QFileDevice::WriteOwner);
    if (!TeamsFile.open(QIODevice::Truncate | QIODevice::WriteOnly))
    {
        qInfo() << "saveDataToFile open file failed";
        return; // 直接返回，避免后续操作出错
    }

    QTextStream stream(&TeamsFile);

    // 1. 保存表头
    QString headers;
    int colnum1 = model3->columnCount();
    for (int i = 0; i < colnum1; ++i)
    {
        // 格式化成一个字符串，然后写入到文件里面
        headers.append(model3->horizontalHeaderItem(i)->text());
        if (i != colnum1 - 1)
            headers.append(",");
    }
    stream << headers << "\n";

    // 2. 保存 model3 数据
    for (int r = 0; r < model3->rowCount(); ++r)
    {
        QStandardItem* firstItem = model3->item(r, 0);
        if (firstItem && firstItem->text().toInt() == ui->comboBox->count())
            continue;

        QString lineData;
        for (int i = 0; i < colnum1; ++i)
        {
            QStandardItem* item = model3->item(r, i);
            if (item)
            {
                lineData.append(item->text());
                if (i != colnum1 - 1)
                    lineData.append(",");
            }
        }
        if (!lineData.isEmpty())
            stream << lineData << "\n";
    }

    // 3. 保存 model2 数据
    int colnum2 = model2->columnCount();
    for (int r = 0; r < model2->rowCount(); ++r)
    {
        QString lineData;
        for (int i = 0; i < colnum2; ++i)
        {
            QStandardItem* item = model2->item(r, i);
            if (item)
            {
                lineData.append(item->text());
                if (i != colnum2 - 1)
                    lineData.append(",");
            }
        }
        if (!lineData.isEmpty())
            stream << lineData << "\n";
    }

    // 显式关闭文件
    TeamsFile.close();

    QMessageBox::information(this, "保存数据", "数据已保存");
}

