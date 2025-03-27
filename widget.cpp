#include "widget.h"
#include "ui_widget.h"

bool TCPflag = false;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //插入背景图
    QPixmap bgimg(":/imgs/bg.jpg");
    ui->BgTabel->setPixmap(bgimg);
    ui->BgTabel->lower();
    //插入标题框
    QPixmap tietlebg(":/imgs/bg_title.png");
    QPixmap tietleimg(":/imgs/head_bg.png");
    ui->TieTle_img_label->setPixmap(tietleimg);
    ui->titlebg_label->setPixmap(tietlebg);
    //标题字体
    int fontId = QFontDatabase::addApplicationFont(":/fonts/FZMoFHJW.TTF");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font;
    font.setFamily(fontName);
    ui->TieTle_label->setFont(font);
    QPixmap aust(":/imgs/aust.png");
    QPixmap logo(":/imgs/logo.png");
    ui->logo->setPixmap(logo);
    ui->aust->setPixmap(aust);
    ui->logotxt->setFont(font);
    ui->austtxt->setFont(font);
    //设置导航栏样式表
    ui->pushButton_1->setStyleSheet(QString("QPushButton{border-image:url(:/icons/anniu);color:rgb(64,64,64);text-align:top;padding-top:53px;font-size:11pt;}QPushButton:hover{border-image:url(:/icons/anniu1.png);}"));
    ui->pushButton_1->setFont(font);
    ui->pushButton_2->setStyleSheet(QString("QPushButton{border-image:url(:/icons/anniu);color:rgb(64,64,64);text-align:top;padding-top:53px;font-size:11pt;}QPushButton:hover{border-image:url(:/icons/anniu1.png);}"));
    ui->pushButton_2->setFont(font);
    ui->pushButton_3->setStyleSheet(QString("QPushButton{border-image:url(:/icons/anniu);color:rgb(64,64,64);text-align:top;padding-top:53px;font-size:11pt;}QPushButton:hover{border-image:url(:/icons/anniu1.png);}"));
    ui->pushButton_3->setFont(font);
    ui->pushButton_4->setStyleSheet(QString("QPushButton{border-image:url(:/icons/anniu);color:rgb(64,64,64);text-align:top;padding-top:53px;font-size:11pt;}QPushButton:hover{border-image:url(:/icons/anniu1.png);}"));
    ui->pushButton_4->setFont(font);
    ui->pushButton_5->setStyleSheet(QString("QPushButton{border-image:url(:/icons/anniu);color:rgb(64,64,64);text-align:top;padding-top:53px;font-size:11pt;}QPushButton:hover{border-image:url(:/icons/anniu1.png);}"));
    ui->pushButton_5->setFont(font);
    ui->pushButton_6->setStyleSheet(QString("QPushButton{border-image:url(:/icons/anniu);color:rgb(64,64,64);text-align:top;padding-top:53px;font-size:11pt;}QPushButton:hover{border-image:url(:/icons/anniu1.png);}"));
    ui->pushButton_6->setFont(font);
    //读取系统设置信息
    // 资源文件路径
    QString ConfigResourcePath = ":/data/config.csv";//配置文件
    QString BCDataResourcePath = ":/data/bcdata.csv";//波长数据
    QString GPDataResourcePath = ":/data/gpdata.csv";//光谱数据
    QString WLDataResourcePath = ":/data/wldata.csv";//物理数据
    QString GJDataResourcePath = ":/data/gjdata.csv";//告警数据
    QString DBDataResourcePath = ":/data/dbdata.csv";//告警数据
    QString SensorConfigResourcePath = ":/data/sensorconfig.csv";//传感器配置
    QString ModelResourcePath = ":/data/model.csv";//模块参数配置
    QString MapResourcePath = ":/data/map.csv";//传感器组配置
    QString TeamsResourcePath = ":/data/teams.csv";//传感器设
    // 获取用户数据目录
    dataDir = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    // 创建目录（如果不存在）
    QDir().mkpath(dataDir);
    // 构建可写文件路径
    ConfigFilePath = dataDir + "/" + QFileInfo(ConfigResourcePath).fileName();
    BCDataPath = dataDir + "/" + QFileInfo(BCDataResourcePath).fileName();
    GPDataPath = dataDir + "/" + QFileInfo(GPDataResourcePath).fileName();
    WLDataPath = dataDir + "/" + QFileInfo(WLDataResourcePath).fileName();
    GJDataPath = dataDir + "/" + QFileInfo(GJDataResourcePath).fileName();
    SensorConfigPath = dataDir + "/" + QFileInfo(SensorConfigResourcePath).fileName();
    ModelPath = dataDir + "/" + QFileInfo(ModelResourcePath).fileName();
    MapPath = dataDir + "/" + QFileInfo(MapResourcePath).fileName();
    TeamsPath = dataDir + "/" + QFileInfo(TeamsResourcePath).fileName();
    DBDataPath = dataDir + "/" + QFileInfo(DBDataResourcePath).fileName();

    ReadConfigFile(ConfigFilePath);

    //1.系统信息
    //设置样式表
    ui->title_label_1->setStyleSheet("color:rgb(255,255,255)");
    ui->KQMC_label->setStyleSheet("color:rgb(102,178,255);padding-left:20px;");
    ui->title_label_2->setStyleSheet("color:rgb(255,255,255)");
    ui->XDMC_label->setStyleSheet("color:rgb(102,178,255);padding-left:20px;");
    ui->title_label_3->setStyleSheet("color:rgb(255,255,255)");
    ui->GSD_label->setStyleSheet("color:rgb(102,178,255);padding-left:20px;");

    ui->KQMC_label->setText(ConfigData[0][1]);
    ui->XDMC_label->setText(ConfigData[1][1]);
    ui->GSD_label->setText(ConfigData[4][1]);

    QPixmap icon1_1(":/icons/icons1-1.png");
    ui->icon_label_1_1->setPixmap(icon1_1);
    QPixmap icon1_2(":/icons/icons1-2.png");
    ui->icon_label_1_2->setPixmap(icon1_2);
    QPixmap icon1_3(":/icons/icons1-3.png");
    ui->icon_label_1_3->setPixmap(icon1_3);

    //2.系统状态
    //设置初始状态
    ui->label_2_4->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);");
    ui->label_2_7->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_7->setText("连接失败");
    ui->label_2_5->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);");
    ui->label_2_8->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_8->setText("未知");
    ui->label_2_6->setStyleSheet("border-image:url(:/icons/fuwuqi0.png);");
    ui->label_2_9->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_9->setText("未知");
    //连接TCP服务端
    socket = new QTcpSocket;//创建socket对象
    connectTCP();
    //链接服务器成功，socket对象会发出信号

    if(!TCPflag)
    {
        Tcptimer = new QTimer(this);
        connect(Tcptimer, &QTimer::timeout,[this](){
            QString IP = ConfigData[7][1];
            QString port = TcpPort;
            socket->connectToHost(QHostAddress(IP),port.toShort());});
        Tcptimer->start(3000); // 10 秒 = 10000 毫秒
    }
    connect(socket,&QTcpSocket::connected,[this](){
        TCPflag = true;
        ui->label_2_4->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
        ui->label_2_7->setStyleSheet("color:rgb(102,178,255);");
        ui->label_2_7->setText("连接成功");
    });
    //断开链接，socket对象会发出信号
    connect(socket,&QTcpSocket::disconnected,[this]{
        TCPflag = false;
        ui->label_2_4->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);");
        ui->label_2_7->setStyleSheet("color:rgb(255,0,0);");
        ui->label_2_7->setText("连接失败");
        ui->label_2_5->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);");
        ui->label_2_8->setStyleSheet("color:rgb(255,0,0);");
        ui->label_2_8->setText("未知");
        ui->label_2_6->setStyleSheet("border-image:url(:/icons/fuwuqi0.png);");
        ui->label_2_9->setStyleSheet("color:rgb(255,0,0);");
        ui->label_2_9->setText("未知");
        QMessageBox::warning(this,"连接提示","连接异常，网络断开");
        connectTCP();
    });
    //服务端收到客户端发送的信息,socket发出readyread信号
    connect(socket, &QTcpSocket::readyRead,this,&Widget::clientTnfoSlot);

    //3.日志
    ui->scrollArea->setStyleSheet("QScrollArea { background - color: #E0ECFF; border: 1px solid #80B3FF; border - radius: 5px; } QScrollArea::corner { background - color: #E0ECFF; } QScrollBar:vertical { width: 10px; background - color: #E0ECFF; margin: 0px 0px 0px 0px; } QScrollBar::handle:vertical { background - color: #80B3FF; min - height: 20px; border - radius: 5px; } QScrollBar::handle:vertical:hover { background - color: #4093FF; } QScrollBar::add - line:vertical { height: 0px; width: 0px; sub - control - position: bottom; sub - control - origin: margin; } QScrollBar::sub - line:vertical { height: 0px; width: 0px; sub - control - position: top; sub - control - origin: margin; } QScrollBar:horizontal { height: 10px; background - color: #E0ECFF; margin: 0px 0px 0px 0px; } QScrollBar::handle:horizontal { background - color: #80B3FF; min - width: 20px; border - radius: 5px; } QScrollBar::handle:horizontal:hover { background - color: #4093FF; } QScrollBar::add - line:horizontal { width: 0px; height: 0px; sub - control - position: right; sub - control - origin: margin; } QScrollBar::sub - line:horizontal { width: 0px; height: 0px; sub - control - position: left; sub - control - origin: margin; }");
    // 创建一个用于容纳 QTextEdit 的容器部件
    scrollWidget = new QWidget(ui->scrollArea);
    scrollLayout = new QVBoxLayout(scrollWidget);

    // 将容器部件设置到滚动区域中
    ui->scrollArea->setWidget(scrollWidget);
    ui->scrollArea->setWidgetResizable(true);
    ui->scrollArea->setStyleSheet("background: transparent;");

    // 创建一个定时器，每隔 10 秒触发一次 readLogFile 槽函数
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Widget::readLogFile);
    timer->start(10000); // 10 秒 = 10000 毫秒

    // 初始读取日志文件
    readLogFile();
    QPixmap pic1(":/imgs/pic1.png");
    ui->pic1_label->setPixmap(pic1);

    //4.map
    QPixmap map(":/imgs/map.png");
    ui->map_label->setPixmap(map);

    //5.显示折线图
    on_comboBox_activated(0);
    // 设置 ui->scrollArea_2 背景透明
    ui->scrollArea_2->setStyleSheet("background: transparent;");

    ui->textEdit->setStyleSheet("background: transparent;");
    ui->textEdit_2->setStyleSheet("background: transparent;");
    ui->textEdit_3->setStyleSheet("background: transparent;");

    //6.实时时间
    // 获取当前本地时间
    ui->time->setStyleSheet("color:rgb(102,178,255);");
    QDateTime now = QDateTime::currentDateTime();

    // 转换为字符串
    QString dateTimeString = now.toString(Qt::ISODate);
    qDebug() << "ISO格式的当前本地时间：" << dateTimeString;

    // 使用自定义格式
    QString customFormat = now.toString("yyyy-MM-dd HH:mm:ss");
    ui->time->setText("当前时间："+ customFormat);

    QTimer *timetimer = new QTimer(this);
    connect(timetimer, &QTimer::timeout, this, &Widget::updateTime);
    timetimer->start(1000); // 每秒更新一次时间
}

Widget::~Widget()
{
    delete ui;
}

void Widget::connectTCP()
{
    if(!TCPflag)
    {
        Tcptimer = new QTimer(this);
        connect(Tcptimer, &QTimer::timeout,[this](){
            QString IP = ConfigData[7][1];
            QString port = TcpPort;
            socket->connectToHost(QHostAddress(IP),port.toShort());});
        Tcptimer->start(10000); // 10 秒 = 10000 毫秒
    }
}

void Widget::ReadConfigFile(const QString& ConfigFileName)
{

    QFile ConfigFile(ConfigFileName);
    //判断文件是否打开成功
    if(!ConfigFile.open(QIODevice::ReadOnly))
    {
        QFileInfo fi(ConfigFilePath);
        if(fi.isFile())
        {
            QMessageBox::warning(this,"警告","config.csv文件打开失败");
        }
        else
        {
            // 资源文件路径
            QString resourcePath = ":/data/config.csv";
            ConfigFilePath = dataDir + "/" + QFileInfo(resourcePath).fileName();
            // 复制资源文件到可写路径
            QFile::copy(resourcePath, ConfigFilePath);
            QTextStream stream(&ConfigFile);//创建模型
            int i=0;
            while(!stream.atEnd())
            {
                QStringList DataLine = stream.readLine().split(",");
                ConfigData[i][0] = DataLine[0];
                ConfigData[i][1] = DataLine[1];
                i++;
            }
            ConfigFile.close();
        }
    }
    else
    {
        QTextStream stream(&ConfigFile);//创建模型
        int i=0;
        while(!stream.atEnd())
        {
            QStringList DataLine = stream.readLine().split(",");
            ConfigData[i][0] = DataLine[0];
            ConfigData[i][1] = DataLine[1];
            i++;
        }
        ConfigFile.close();
    }
}

void Widget::clientTnfoSlot()
{
    //获取信号的发出者
    QTcpSocket *s = (QTcpSocket * )sender();
    QStringList data = QString(s->readAll()).split(",");
    if(!QString::compare("1",data[0])){
        ui->label_2_5->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
        ui->label_2_8->setStyleSheet("color:rgb(102,178,255);");
        ui->label_2_8->setText("正常");
    }
    if(!QString::compare("1",data[1])){
        ui->label_2_6->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
        ui->label_2_9->setStyleSheet("color:rgb(102,178,255);");
        ui->label_2_9->setText("正常");
    }
}

//1.基本信息管理
void Widget::on_pushButton_1_clicked()
{
//    this->hide();
    SetUp *c = new SetUp(); //堆空间创建
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//2.数据查询
void Widget::on_pushButton_2_clicked()
{
    query *c = new query(); //堆空间创建
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//3.警告查询
void Widget::on_pushButton_3_clicked()
{
    Warning *c = new Warning();
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//4.传感器配置
void Widget::on_pushButton_4_clicked()
{
    SensorConfig *c = new SensorConfig();
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//5.模块配置
void Widget::on_pushButton_5_clicked()
{
    ModuleConfig *c = new ModuleConfig();
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//6.传感器设计
void Widget::on_pushButton_6_clicked()
{
    SensorDesign *c = new SensorDesign();
    c->setWindowModality(Qt::ApplicationModal);
    c->show();
}

//日志
void Widget::readLogFile()
{
    // 清除之前的 QTextEdit 控件
    QLayoutItem *item;
    while ((item = scrollLayout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    QFile file("log.log");
    file.setPermissions(QFileDevice::ReadOwner);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open log file";
        return;
    }
    else{
        QTextStream in(&file);
        QStringList allLines;
        // 读取文件的所有行
        while (!in.atEnd()) {
            allLines.append(in.readLine());
        }
        file.close();
        // 提取最新的三十条日志信息
        QStringList latestLines;
        int startIndex = qMax(0, allLines.size() - 30);
        for (int i = startIndex; i < allLines.size(); ++i) {
            latestLines.append(allLines[i]);
        }

        // 为每条日志创建一个 QTextEdit 并添加到滚动布局中
        for (const QString &line : latestLines) {
            QTextEdit *textEdit = new QTextEdit(line, scrollWidget);
            textEdit->setReadOnly(true);
            textEdit->setStyleSheet("QTextEdit {background-color: rgba(0, 0, 0, 0.3);color: #00BFFF;border: 2px solid rgba(0, 191, 255, 0.5);border-radius: 5px;padding: 8px;font-size: 12px;}QTextEdit:focus {border: 2px solid #00BFFF;outline: none;}");
            textEdit->setFixedHeight(60); // 设置一个固定的合理高度，方便调试
            scrollLayout->addWidget(textEdit);
        }
    }
}

QList<QPair<QDateTime, qreal>> Widget::readDataFromCSV(int index)
{
    QString filePath;
    if(index == 1)
        filePath = DBDataPath;//锚索测力计
    else if(index == 2)
        filePath = WLDataPath;//顶板离层计物理量
    else if(index == 3)
        filePath = GPDataPath;//智能锚杆计
    else
        filePath = NULL;
    QList<QPair<QDateTime, qreal>> data;
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        // 跳过表头
        in.readLine();
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList fields = line.split(',');
            if (fields.size() >= 6) {
                QDateTime time = QDateTime::fromString(fields[0].trimmed(), "yyyy-MM-dd HH:mm:ss");
                bool ok;
                qreal value = fields[5].trimmed().toDouble(&ok);
                if (time.isValid() && ok) {
                    data.append(qMakePair(time, value));
                }
            }
        }
        file.close();
    }
    return data;
    //}
}

void Widget::on_comboBox_activated(int index)
{
    // 从 CSV 文件中读取数据
    QList<QPair<QDateTime, qreal>> data = readDataFromCSV(index);

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
        qreal extraValue = valueSpan * 0.1;
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
}

//定时器超时调用的更新时间函数
void Widget::updateTime()
{
    // 获取当前时间并转换为字符串
    QString currentTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    //显示时间的QLabel更新其文本
    ui->time->setText("当前时间："+currentTime);
}
