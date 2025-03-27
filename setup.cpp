#include "setup.h"
#include "ui_setup.h"
int TD[17]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
SetUp::SetUp(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SetUp)
{
    ui->setupUi(this);
    //插入背景图
    QPixmap bgimg(":/imgs/chun.png");
    ui->bg_label->setPixmap(bgimg);
    ui->bg_label->lower();
    //加载原配置
    // ui->lineEdit_1_0->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    // ui->lineEdit_1_1->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    // ui->lineEdit_1_2->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    // ui->lineEdit_1_3->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    // ui->lineEdit_1_4->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    // ui->lineEdit_1_5->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    // ui->lineEdit_2_1->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    // ui->lineEdit_2_2->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    // ui->lineEdit_2_3->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    // ui->lineEdit_3_1->setStyleSheet("background-color:rgb(102,102,102);color:rgb(255,255,255);");
    ui->lineEdit_1_0->setText(ConfigData[8][1]);
    ui->lineEdit_1_1->setText(ConfigData[9][1]);
    ui->lineEdit_1_2->setText(ConfigData[0][1]);
    ui->lineEdit_1_3->setText(ConfigData[1][1]);
    ui->lineEdit_1_4->setText(ConfigData[2][1]);
    ui->lineEdit_1_5->setText(ConfigData[3][1]);
    ui->lineEdit_2_1->setText(ConfigData[4][1]);
    ui->lineEdit_2_2->setText(ConfigData[5][1]);
    ui->lineEdit_2_3->setText(ConfigData[6][1]);
    ui->lineEdit_3_1->setText(ConfigData[7][1]);
    ui->lineEdit_3_1->setReadOnly(true);
    //通道复选框
    for(int i =0 ; i<16 ; i++)
    {
        QListWidgetItem *item = new QListWidgetItem();
        QCheckBox *checkBox = new QCheckBox(QString("通道 %1").arg(i + 1),this);
        checkBox->setChecked(true);

        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item,checkBox);

        connect(checkBox,SIGNAL(stateChanged(int)), this, SLOT(anyStateChanged()));
    }
    // 设置 ui->scrollArea_2 背景透明
    //ui->scrollArea->setStyleSheet("background: transparent;");
}

SetUp::~SetUp()
{
    delete ui;
}

void SetUp::on_SetButton_clicked()
{
    ui->lineEdit_3_1->setReadOnly(false);
}


void SetUp::on_SaveButton_clicked()
{
    ConfigData[8][1] = ui->lineEdit_1_0->text();
    ConfigData[9][1] = ui->lineEdit_1_1->text();
    ConfigData[0][1] = ui->lineEdit_1_2->text();
    ConfigData[1][1] = ui->lineEdit_1_3->text();
    ConfigData[2][1] = ui->lineEdit_1_4->text();
    ConfigData[3][1] = ui->lineEdit_1_5->text();
    ConfigData[4][1] = ui->lineEdit_2_1->text();
    ConfigData[5][1] = ui->lineEdit_2_2->text();
    ConfigData[6][1] = ui->lineEdit_2_3->text();
    ConfigData[7][1] = ui->lineEdit_3_1->text();
    SaveConfigFile(ConfigFilePath);
}

void SetUp::SaveConfigFile(const QString& ConfigFileName)
{
    QFile ConfigFile(ConfigFileName);
    ConfigFile.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
    //判断文件是否打开成功
    if(!ConfigFile.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"警告",ConfigFilePath+"文件打开失败");
        qDebug() << "Could not open the file for writing:" << ConfigFile.errorString();
    }
    else
    {
        QTextStream stream(&ConfigFile);
        for(int r=0;r<10;r++)
        {
            QString lineData;
            for(int i=0;i<2;i++)
            {
                lineData.push_back(ConfigData[r][i]);
                if(i==0)
                {
                    lineData.push_back(",");
                }
            }
            stream<<lineData<<"\n";
        }
        ConfigFile.close();
        QMessageBox::information(this,"信息管理","已保存");
    }
}

//获取光谱
void SetUp::on_GPButton_clicked()
{
    QList<QPair<QDateTime, qreal>> data;
    QString filePath= GPDataPath;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        // 跳过表头
        in.readLine();
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(',');
            if (fields.size() >= 6) {
                if(TD[fields[1].trimmed().toInt()]==1){
                    QDateTime time = QDateTime::fromString(fields[0].trimmed(), "yyyy-MM-dd HH:mm:ss");
                    bool ok;
                    qreal value = fields[5].trimmed().toDouble(&ok);
                    if (time.isValid() && ok) {
                        data.append(qMakePair(time, value));
                }
                }
            }
        }
        file.close();
    }
    // 创建折线图系列
    QLineSeries *series = new QLineSeries();
    for (const auto& pair : data) {
        series->append(pair.first.toMSecsSinceEpoch(), pair.second);
    }

    // 设置折线颜色为白色
    QPen pen(Qt::white);
    pen.setWidth(2); // 设置线宽
    series->setPen(pen);

    // 创建图表
    QChart *chart = new QChart();
    chart->addSeries(series);

    // 隐藏图例
    chart->legend()->hide();

    // 设置 X 轴为日期时间轴
    QDateTimeAxis *axisX = new QDateTimeAxis();
    axisX->setTitleText("时间/s");
    axisX->setFormat("HH:mm");

    // 计算 X 轴的范围
    if (!data.isEmpty()) {
        QDateTime minTime = data.first().first;
        QDateTime maxTime = data.last().first;

        // 扩展 X 轴范围，这里在两端各扩展 5% 的时间间隔
        qint64 timeSpan = maxTime.toMSecsSinceEpoch() - minTime.toMSecsSinceEpoch();
        qint64 extraTime = static_cast<qint64>(timeSpan * 0.05);
        minTime = minTime.addMSecs(-extraTime);
        maxTime = maxTime.addMSecs(extraTime);

        axisX->setRange(minTime, maxTime);
    }

    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    // 设置 Y 轴为数值轴
    QValueAxis *axisY = new QValueAxis();
    //axisY->setTitleText("值");

    // 计算 Y 轴的范围
    if (!data.isEmpty()) {
        qreal minValue = data.first().second;
        qreal maxValue = data.first().second;
        for (const auto& pair : data) {
            if (pair.second < minValue) {
                minValue = pair.second;
            }
            if (pair.second > maxValue) {
                maxValue = pair.second;
            }
        }

        // 扩展 Y 轴范围，这里在两端各扩展 10% 的数值间隔
        qreal valueSpan = maxValue - minValue;
        qreal extraValue = valueSpan * 0.5;
        minValue -= extraValue;
        maxValue += extraValue;

        axisY->setRange(minValue, maxValue);
    }

    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置 X 轴和 Y 轴颜色为蓝色
    QPen axisPen(Qt::blue);
    axisPen.setWidth(2); // 设置轴的线宽
    axisX->setLinePen(axisPen);
    axisY->setLinePen(axisPen);

    // 设置刻度线颜色为蓝色
    axisX->setGridLinePen(axisPen);
    axisY->setGridLinePen(axisPen);

    //设置轴单位颜色为蓝色
    QBrush LabelBrush(Qt::blue);
    axisX->setTitleBrush(LabelBrush);
    axisY->setTitleBrush(LabelBrush);

    //设置文字为蓝色
    axisX->setLabelsColor(QColorConstants::Blue);
    axisY->setLabelsColor(QColorConstants::Blue);

    //设置刻度线标尺为10
    //axisX->setTickCount(10);
    //axisY->setTickCount(10);

    // 设置图表背景透明
    chart->setBackgroundVisible(false);
    chart->setPlotAreaBackgroundVisible(false);

    // 创建图表视图
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 设置 QChartView 的大小策略
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartView->setSizePolicy(sizePolicy);

    // 将图表视图添加到 ui->scrollArea_2 中
    ui->scrollArea_2->setWidget(chartView);
    ui->scrollArea_2->setWidgetResizable(true);
    QMessageBox::information(this,"获取光谱","已获取光谱信息");
}

//获取波长
void SetUp::on_BCButton_clicked()
{
    QFile BCFile(BCDataPath);
    BCFile.setPermissions(QFileDevice::ReadOwner);
    if(!BCFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QMessageBox::warning(this,"警告",BCDataPath+"文件打开失败");
        qDebug() << "Could not open the file for writing:" << BCFile.errorString();
    }
    else
    {
        //创建一个模型
        QTextStream stream(&BCFile);
        //创建一个模型
        QStandardItemModel* model = new QStandardItemModel(this);
        //把模型浇给视图
        ui->BCTable->setModel(model);
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
        BCFile.close();
        QMessageBox::information(this,"获取波长","已获取波长信息");
    }
}

void SetUp::anyStateChanged()
{
    for(int i =0;i<17;i++)
    {
        TD[i]=0;
    }
    for(int i =0;i<ui->listWidget->count();i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        QCheckBox *checkBox = static_cast<QCheckBox *>(ui->listWidget->itemWidget(item));
        if(checkBox->isChecked())
        {
            TD[i+1]=1;
        }
    }
}

//全选
void SetUp::on_pushButton_clicked()
{
    for(int i =0;i<17;i++)
    {
        TD[i]=1;
    }
    for(int i =0;i<ui->listWidget->count();i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        QCheckBox *checkBox = static_cast<QCheckBox *>(ui->listWidget->itemWidget(item));
        if(!checkBox->isChecked())
        {
            checkBox->setChecked(true);
        }
    }
}


void SetUp::on_pushButton_2_clicked()
{
    for(int i =0;i<17;i++)
    {
        TD[i]=0;
    }
    for(int i =0;i<ui->listWidget->count();i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        QCheckBox *checkBox = static_cast<QCheckBox *>(ui->listWidget->itemWidget(item));
        if(checkBox->isChecked())
        {
            checkBox->setChecked(false);
        }
    }
}

