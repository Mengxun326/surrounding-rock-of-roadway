#include "warning.h"
#include "ui_warning.h"

Warning::Warning(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Warning)
{
    ui->setupUi(this);
    QPixmap bgimg(":/imgs/chun.png");
    ui->bg_label->setPixmap(bgimg);
    ui->bg_label->lower();
    ui->change_label->setStyleSheet("color:rgb(102,178,255);font-weight: bold;font-size: 14px;");
}

Warning::~Warning()
{
    delete ui;
}

bool Warning::TimePK(QString time)
{
    QDateTime tim = QDateTime::fromString(time, "yyyy-MM-dd hh:mm:ss");
    return tim>=(ui->BeginTimeEdit->dateTime())&&tim<=(ui->EndTimeEdit->dateTime());
}

bool Warning::ExaInput(QString inputstring)
{
    return ui->InputEdit->text().isEmpty() || inputstring == ui->InputEdit->text();
}


void Warning::on_comboBox_1_activated(int index)
{
    if(index==1)
    {
        QType = 1 ;//高限
    }
    else if(index == 2)
    {
        QType = 2 ;//低限
    }
}


void Warning::on_comboBox_2_activated(int index)
{
    if(index==1)
    {
        ui->change_label->setText("传感器类别");
        QFrom = 1 ;
    }
    else if(index == 2)
    {
        ui->change_label->setText("传感器ID");
        QFrom = 2 ;
    }
}

//查询
void Warning::on_QueryButton_clicked()
{
    if(QType != 0)//高限
    {
        QFile GJFile(GJDataPath);
        GJFile.setPermissions(QFileDevice::ReadOwner);
        if(!GJFile.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QMessageBox::warning(this,"警告",GJDataPath+"文件打开失败");
            qDebug() << "Could not open the file for writing:" << GJFile.errorString();
        }
        else
        {
            //创建一个模型
            QTextStream stream(&GJFile);
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
                if((QType==1&&lineData[4]=="高限报警")||(QType==2&&lineData[4]=="低限报警"))
                {
                    if( TimePK(lineData[0]) && (ui->TD_lineEdit->text().isEmpty() || lineData[1] == ui->TD_lineEdit->text()))
                    {
                        if(QFrom == 1 && ExaInput(lineData[3]))//传感器类别
                        {
                            model->appendRow(items);
                        }
                        else if(QFrom == 2 && ExaInput(lineData[2]))//传感器ID
                        {
                            model->appendRow(items);
                        }
                    }
                }
            }
            GJFile.close();
            QMessageBox::information(this,"获取告警信息","已获取告警信息");
        }
    }
    else
    {
        QMessageBox::warning(this,"警告","未选择查找类型");
    }
}

//导出
void Warning::on_SaveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,"选择一个文件",QCoreApplication::applicationFilePath()+ "/" + ui->SaveNamelineEdit->text(),"*.csv");
    if(fileName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请选择一个文件");
    }
    else
    {
        QFile file(fileName);
        file.open(QIODevice::WriteOnly);
        QTextStream stream(&file);
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
        QMessageBox::information(this,"保存文件","已保存");
    end:;
    }
}

