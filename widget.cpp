#include "widget.h"
#include "ui_widget.h"

// 旧的TCPflag变量已移除，现在使用新的TCP服务端

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , m_tcpServer(nullptr)
    , m_udpReceiver(nullptr)
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
    ui->label_2_4->setStyleSheet(";border-image:url(:/icons/fuwuqi.png);");
    ui->label_2_7->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_7->setText("连接失败");
    // ui->label_2_5->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);"); // 注释掉，避免覆盖测试设置
    ui->label_2_8->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_8->setText("未知");
    ui->label_2_6->setStyleSheet("border-image:url(:/icons/fuwuqi0.png);");
    ui->label_2_9->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_9->setText("未知");
    // 旧的TCP客户端连接代码已移除，现在使用新的TCP服务端
    // 设置初始状态
    ui->label_2_4->setStyleSheet(";border-image:url(:/icons/fuwuqi.png);");
    ui->label_2_7->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_7->setText("等待连接");

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

    //4.初始化实时数据图表
    initRealtimeChart();

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
    
    // 初始化通信服务
    initCommunicationServices();
}

Widget::~Widget()
{
    if (m_tcpServer) {
        m_tcpServer->stopServer();
        delete m_tcpServer;
    }
    if (m_udpReceiver) {
        m_udpReceiver->stopReceiver();
        delete m_udpReceiver;
    }
    delete ui;
}

// 窗口关闭事件处理
void Widget::closeEvent(QCloseEvent *event)
{
    qInfo() << "程序正在关闭...";
    
    // 停止通信服务
    if (m_tcpServer) {
        m_tcpServer->stopServer();
    }
    if (m_udpReceiver) {
        m_udpReceiver->stopReceiver();
    }
    
    // 停止定时器
    if (m_dataUpdateTimer) {
        m_dataUpdateTimer->stop();
    }
    if (timer) {
        timer->stop();
    }
    
    qInfo() << "程序已正常关闭";
    event->accept();
}

// 旧的connectTCP函数已移除，现在使用新的TCP服务端

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

// 旧的clientTnfoSlot函数已移除，现在使用新的TCP服务端数据接收处理

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

// 初始化通信服务
void Widget::initCommunicationServices()
{
    // 初始化TCP服务端
    m_tcpServer = new TcpServer(this);
    connect(m_tcpServer, &TcpServer::dataReceived, this, &Widget::onTcpDataReceived, Qt::QueuedConnection);
    connect(m_tcpServer, &TcpServer::clientConnected, this, &Widget::onTcpClientConnected, Qt::QueuedConnection);
    connect(m_tcpServer, &TcpServer::clientDisconnected, this, &Widget::onTcpClientDisconnected, Qt::QueuedConnection);
    connect(m_tcpServer, &TcpServer::connectionError, this, &Widget::onTcpConnectionError, Qt::QueuedConnection);
    
    // 启动TCP服务端
    if (m_tcpServer->startServer(5555)) {
        qInfo() << "TCP服务端启动成功，监听端口5555";
    } else {
        qCritical() << "TCP服务端启动失败";
    }
    
    // 初始化UDP接收器
    m_udpReceiver = new UdpReceiver(this);
    connect(m_udpReceiver, &UdpReceiver::dataReceived, this, &Widget::onUdpDataReceived);
    connect(m_udpReceiver, &UdpReceiver::vibrationDataReceived, this, &Widget::onVibrationDataReceived);
    connect(m_udpReceiver, &UdpReceiver::deviceConnected, this, &Widget::onUdpDeviceConnected);
    connect(m_udpReceiver, &UdpReceiver::deviceDisconnected, this, &Widget::onUdpDeviceDisconnected);
    
    // 启动UDP接收器
    if (m_udpReceiver->startReceiver(6666)) {
        qInfo() << "UDP接收器启动成功，监听端口6666";
    } else {
        qCritical() << "UDP接收器启动失败";
    }
    
    // 初始化数据更新定时器
    
    // 不进行模拟设备连接测试，等待真实设备连接
    qDebug() << "通信服务初始化完成，等待真实设备连接";
    m_dataUpdateTimer = new QTimer(this);
    connect(m_dataUpdateTimer, &QTimer::timeout, this, &Widget::updateRealtimeDisplay);
    m_dataUpdateTimer->start(1000); // 每秒更新一次显示
}

// TCP数据接收处理
void Widget::onTcpDataReceived(const QJsonObject &data)
{
    qDebug() << "收到TCP数据:" << data;
    
    // 更新系统状态显示（只有在真实TCP连接时才更新）
    ui->label_2_5->setStyleSheet("border-image:url(:/icons/fuwuqi.png); background:transparent;");
    ui->label_2_5->update();
    ui->label_2_8->setStyleSheet("color:rgb(102,178,255);");
    ui->label_2_8->setText("数据接收中");
    // 强制刷新UI
    ui->label_2_5->repaint();
    ui->label_2_8->repaint();
    // 延迟再次设置，确保样式生效
    QTimer::singleShot(100, [this]() {
        ui->label_2_5->setStyleSheet("border-image:url(:/icons/fuwuqi.png); background:transparent;");
        ui->label_2_5->update();
    });
    qDebug() << "UI状态已更新为数据接收中";
    
    // 处理传感器数据
    if (data.contains("body")) {
        QJsonObject body = data["body"].toObject();
        if (body.contains("PARAM")) {
            QJsonObject param = body["PARAM"].toObject();
            
            // 更新实时数据用于图表显示
            QDateTime currentTime = QDateTime::currentDateTime();
            
            // 处理应变数据
            if (param.contains("Strain")) {
                QJsonArray strainArray = param["Strain"].toArray();
                for (const QJsonValue &value : strainArray) {
                    if (value.isObject()) {
                        QJsonObject sensor = value.toObject();
                        double val = sensor["Val"].toString().toDouble();
                        // 应变数据标记为正数
                        m_realtimeData.append(qMakePair(currentTime, val));
                        qDebug() << "应变数据:" << val;
                    }
                }
            }
            
            // 处理位移数据
            if (param.contains("Move")) {
                QJsonArray moveArray = param["Move"].toArray();
                for (const QJsonValue &value : moveArray) {
                    if (value.isObject()) {
                        QJsonObject sensor = value.toObject();
                        double val = sensor["Val"].toString().toDouble();
                        // 位移数据标记为负数（-1到-10范围）
                        m_realtimeData.append(qMakePair(currentTime, -val));
                        qDebug() << "位移数据:" << val;
                    }
                }
            }
            
            // 处理温度数据
            if (param.contains("Temp")) {
                QJsonArray tempArray = param["Temp"].toArray();
                for (const QJsonValue &value : tempArray) {
                    if (value.isObject()) {
                        QJsonObject sensor = value.toObject();
                        double val = sensor["Val"].toString().toDouble();
                        // 温度数据标记为更小的负数（-10以下）
                        m_realtimeData.append(qMakePair(currentTime, -val - 10));
                        qDebug() << "温度数据:" << val;
                    }
                }
            }
        }
    }
    
    // 立即更新图表显示
    qDebug() << "准备更新图表显示，当前数据点数:" << m_realtimeData.size();
    updateRealtimeDisplay();
    
    // 强制刷新UI
    this->update();
    ui->chartContainer->update();
    qDebug() << "UI刷新完成";
}

// TCP客户端连接处理
void Widget::onTcpClientConnected()
{
    qInfo() << "光纤光栅分析软件已连接";
    // 更新服务器状态图标和文字
    ui->label_2_5->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
    ui->label_2_8->setStyleSheet("color:rgb(102,178,255);");
    ui->label_2_8->setText("已连接");
    // 更新传感器状态图标和文字
    ui->label_2_6->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
    ui->label_2_9->setStyleSheet("color:rgb(102,178,255);");
    ui->label_2_9->setText("已连接");
    // 更新设备状态图标和文字
    ui->label_2_7->setStyleSheet("color:rgb(102,178,255);");
    ui->label_2_7->setText("已连接");
}

// TCP客户端断开处理
void Widget::onTcpClientDisconnected()
{
    qInfo() << "光纤光栅分析软件已断开";
    // 更新服务器状态图标和文字
    ui->label_2_5->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);");
    ui->label_2_8->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_8->setText("已断开");
    // 更新传感器状态图标和文字
    ui->label_2_6->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);");
    ui->label_2_9->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_9->setText("已断开");
    // 更新设备状态图标和文字
    ui->label_2_7->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_7->setText("已断开");
}

// TCP连接错误处理
void Widget::onTcpConnectionError(const QString &error)
{
    qCritical() << "TCP连接错误:" << error;
    ui->label_2_5->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);");
    ui->label_2_8->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_8->setText("连接错误");
}

// UDP数据接收处理
void Widget::onUdpDataReceived(const QByteArray &data)
{
    qDebug() << "收到UDP数据，大小:" << data.size();
    
    // 只更新设备状态为"数据接收中"，不覆盖连接状态
    ui->label_2_7->setStyleSheet("color:rgb(102,178,255);");
    ui->label_2_7->setText("数据接收中");
}

// UDP设备连接处理
void Widget::onUdpDeviceConnected()
{
    qInfo() << "UDP设备已连接";
    qDebug() << "开始更新服务器状态图标";
    qDebug() << "设置前服务器状态图标样式:" << ui->label_2_5->styleSheet();
    // 更新服务器状态图标和文字（UDP连接也意味着服务器工作正常）
    // 先清除所有样式和文本
    ui->label_2_5->setStyleSheet("");
    ui->label_2_5->setText("");  // 清除HTML文本
    ui->label_2_5->update();
    ui->label_2_5->repaint();
    
    // 尝试多种方法设置图标
    ui->label_2_5->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
    qDebug() << "使用border-image设置蓝色图标";
    
    // 备用方法：使用QPixmap
    QPixmap blueIcon(":/icons/fuwuqi.png");
    if (!blueIcon.isNull()) {
        ui->label_2_5->setPixmap(blueIcon);
        qDebug() << "同时使用QPixmap设置蓝色图标";
    }
    
    // 强制设置样式
    ui->label_2_5->setStyleSheet("border-image:url(:/icons/fuwuqi.png); background:transparent;");
    qDebug() << "强制设置样式";
    ui->label_2_5->update();
    ui->label_2_8->setStyleSheet("color:rgb(102,178,255);");
    ui->label_2_8->setText("已连接");
    qDebug() << "设置后服务器状态图标样式:" << ui->label_2_5->styleSheet();
    qDebug() << "设置后服务器状态文字:" << ui->label_2_8->text();
    qDebug() << "服务器状态图标已设置为蓝色";
    
    // 强制刷新UI - 多种方法
    ui->label_2_5->repaint();
    ui->label_2_5->update();
    ui->label_2_8->repaint();
    ui->label_2_8->update();
    
    // 延迟检查最终状态
    QTimer::singleShot(1000, [this]() {
        qDebug() << "1秒后检查最终状态:";
        qDebug() << "服务器状态图标样式:" << ui->label_2_5->styleSheet();
        qDebug() << "服务器状态文字:" << ui->label_2_8->text();
    });
    
    // 延迟多次设置，确保样式生效
    QTimer::singleShot(50, [this]() {
        qDebug() << "第一次延迟设置服务器状态图标";
        ui->label_2_5->setText("");  // 清除HTML文本
        ui->label_2_5->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
        ui->label_2_5->update();
        ui->label_2_5->repaint();
    });
    
    QTimer::singleShot(200, [this]() {
        qDebug() << "第二次延迟设置服务器状态图标";
        ui->label_2_5->setText("");  // 清除HTML文本
        ui->label_2_5->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
        ui->label_2_5->update();
        ui->label_2_5->repaint();
    });
    
    QTimer::singleShot(500, [this]() {
        qDebug() << "第三次延迟设置服务器状态图标";
        ui->label_2_5->setText("");  // 清除HTML文本
        ui->label_2_5->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
        ui->label_2_5->update();
        ui->label_2_5->repaint();
        qDebug() << "最终服务器状态图标样式:" << ui->label_2_5->styleSheet();
    });
    // 更新传感器状态图标和文字
    ui->label_2_6->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
    ui->label_2_9->setStyleSheet("color:rgb(102,178,255);");
    ui->label_2_9->setText("已连接");
    // 更新设备状态图标和文字
    ui->label_2_7->setStyleSheet("color:rgb(102,178,255);");
    ui->label_2_7->setText("已连接");
}

// UDP设备断开处理
void Widget::onUdpDeviceDisconnected()
{
    qInfo() << "UDP设备已断开";
    // 更新服务器状态图标和文字
    ui->label_2_5->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);");
    ui->label_2_8->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_8->setText("已断开");
    // 更新传感器状态图标和文字
    ui->label_2_6->setStyleSheet(";border-image:url(:/icons/fuwuqi0.png);");
    ui->label_2_9->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_9->setText("已断开");
    // 更新设备状态图标和文字
    ui->label_2_7->setStyleSheet("color:rgb(255,0,0);");
    ui->label_2_7->setText("已断开");
}

// 振动数据接收处理
void Widget::onVibrationDataReceived(int channel, int sensorId, double wavelength, double frequency)
{
    qDebug() << QString("振动数据 - 通道:%1 ID:%2 波长:%3 频率:%4")
                .arg(channel).arg(sensorId).arg(wavelength).arg(frequency);
    
    // 更新系统状态显示
    ui->label_2_6->setStyleSheet("border-image:url(:/icons/fuwuqi.png);");
    ui->label_2_9->setStyleSheet("color:rgb(102,178,255);");
    ui->label_2_9->setText("振动数据接收中");
}

// 初始化实时图表
void Widget::initRealtimeChart()
{
    // 创建图表
    m_realtimeChart = new QChart();
    m_realtimeChart->setTitle("实时传感器数据");
    m_realtimeChart->setTitleFont(QFont("Arial", 14, QFont::Bold));
    m_realtimeChart->setTitleBrush(QBrush(QColor(255, 255, 255)));
    
    // 设置图表主题和背景
    m_realtimeChart->setTheme(QChart::ChartThemeDark);
    m_realtimeChart->setBackgroundBrush(QBrush(QColor(26, 26, 26)));
    m_realtimeChart->setPlotAreaBackgroundBrush(QBrush(QColor(40, 40, 40)));
    m_realtimeChart->setPlotAreaBackgroundVisible(true);
    
    // 创建数据系列
    m_strainSeries = new QLineSeries();
    m_strainSeries->setName("应变数据");
    m_strainSeries->setColor(QColor(255, 0, 0));  // 纯红色
    m_strainSeries->setPen(QPen(QColor(255, 0, 0), 3));  // 更粗的线条
    
    m_moveSeries = new QLineSeries();
    m_moveSeries->setName("位移数据");
    m_moveSeries->setColor(QColor(0, 255, 0));  // 纯绿色
    m_moveSeries->setPen(QPen(QColor(0, 255, 0), 3));  // 更粗的线条
    
    m_tempSeries = new QLineSeries();
    m_tempSeries->setName("温度数据");
    m_tempSeries->setColor(QColor(0, 0, 255));  // 纯蓝色
    m_tempSeries->setPen(QPen(QColor(0, 0, 255), 3));  // 更粗的线条
    
    // 添加系列到图表
    m_realtimeChart->addSeries(m_strainSeries);
    m_realtimeChart->addSeries(m_moveSeries);
    m_realtimeChart->addSeries(m_tempSeries);
    
    // 创建时间轴 - 使用QValueAxis而不是QDateTimeAxis
    m_timeAxis = new QValueAxis();
    m_timeAxis->setTitleText("时间(秒)");
    m_timeAxis->setTitleBrush(QBrush(QColor(255, 255, 255)));
    m_timeAxis->setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_timeAxis->setGridLineColor(QColor(100, 100, 100));
    m_timeAxis->setTickCount(10);
    
    qDebug() << "时间轴类型:" << m_timeAxis->type();
    
    // 创建数值轴
    m_axisY = new QValueAxis();
    m_axisY->setTitleText("数值");
    m_axisY->setTitleBrush(QBrush(QColor(255, 255, 255)));
    m_axisY->setLabelsBrush(QBrush(QColor(255, 255, 255)));
    m_axisY->setGridLineColor(QColor(100, 100, 100));
    m_axisY->setRange(-60, 60);  // 设置应变数据的Y轴范围
    
    // 设置轴
    m_realtimeChart->addAxis(m_timeAxis, Qt::AlignBottom);
    m_realtimeChart->addAxis(m_axisY, Qt::AlignLeft);
    
    // 系列已经在上面添加到图表了，这里不需要重复添加
    
    // 只附加一次轴，避免重复附加
    m_strainSeries->attachAxis(m_timeAxis);
    m_strainSeries->attachAxis(m_axisY);
    m_moveSeries->attachAxis(m_timeAxis);
    m_moveSeries->attachAxis(m_axisY);
    m_tempSeries->attachAxis(m_timeAxis);
    m_tempSeries->attachAxis(m_axisY);
    
    qDebug() << "实时图表轴设置完成";
    
    // 创建图表视图
    m_chartView = new QChartView(m_realtimeChart);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    m_chartView->setRenderHint(QPainter::SmoothPixmapTransform);
    m_chartView->setBackgroundBrush(QBrush(QColor(26, 26, 26)));
    m_chartView->setMinimumSize(600, 400);
    m_chartView->setMaximumSize(1000, 800);
    
    // 确保图表被正确设置到视图中
    m_chartView->setChart(m_realtimeChart);
    
    // 将图表视图添加到容器中
    QVBoxLayout *chartLayout = new QVBoxLayout(ui->chartContainer);
    chartLayout->addWidget(m_chartView);
    chartLayout->setContentsMargins(5, 5, 5, 5);
    
    // 确保图表视图和其容器可见
    m_chartView->setVisible(true);
    m_chartView->show();
    ui->chartContainer->setVisible(true);
    ui->chartContainer->show();
    
    // 强制更新布局
    ui->chartContainer->update();
    m_chartView->update();
    
    // 检查父级容器的可见性
    QWidget *parent = ui->chartContainer->parentWidget();
    while (parent) {
        qDebug() << "父级容器:" << parent->objectName() << "可见性:" << parent->isVisible();
        if (parent->objectName() == "Widget") {
            // 强制设置主窗口可见
            parent->setVisible(true);
            parent->show();
            qDebug() << "已强制设置主窗口可见";
        }
        parent = parent->parentWidget();
    }
    
    qDebug() << "图表视图已创建并添加到容器，尺寸:" << m_chartView->size();
    qDebug() << "图表容器尺寸:" << ui->chartContainer->size();
    qDebug() << "图表视图可见性:" << m_chartView->isVisible();
    qDebug() << "图表容器可见性:" << ui->chartContainer->isVisible();
    
    // 设置图例
    m_realtimeChart->legend()->setVisible(true);
    m_realtimeChart->legend()->setAlignment(Qt::AlignTop);
    m_realtimeChart->legend()->setLabelColor(QColor(255, 255, 255));
    m_realtimeChart->legend()->setBackgroundVisible(false);
    
    // 记录开始时间
    m_startTime = QDateTime::currentDateTime();
    
    // 不添加测试数据，等待真实数据
    qDebug() << "实时图表初始化完成，等待真实数据";
}

// 更新实时显示
void Widget::updateRealtimeDisplay()
{
    if (!m_realtimeChart || !m_strainSeries || !m_moveSeries || !m_tempSeries) {
        return;
    }
    
    // 限制数据量，只保留最近100个数据点
    if (m_realtimeData.size() > 100) {
        m_realtimeData = m_realtimeData.mid(m_realtimeData.size() - 100);
    }
    
    // 更新图表显示
    if (!m_realtimeData.isEmpty()) {
        qDebug() << "开始更新图表显示，数据点数:" << m_realtimeData.size();
        
        // 清空现有数据
        m_strainSeries->clear();
        m_moveSeries->clear();
        m_tempSeries->clear();
        
        // 添加数据到图表
        qreal minTimeValue = 0, maxTimeValue = 0;
        qreal minValue = 0, maxValue = 0;
        
        for (int i = 0; i < m_realtimeData.size(); ++i) {
            const auto &dataPoint = m_realtimeData[i];
            qreal timeValue = m_startTime.msecsTo(dataPoint.first) / 1000.0; // 转换为秒
            qreal value = dataPoint.second;
            
            // 更新时间范围
            if (i == 0) {
                minTimeValue = maxTimeValue = timeValue;
            } else {
                minTimeValue = qMin(minTimeValue, timeValue);
                maxTimeValue = qMax(maxTimeValue, timeValue);
            }
            
            // 更新数值范围
            minValue = qMin(minValue, value);
            maxValue = qMax(maxValue, value);
            
            // 根据数据值分配到不同的系列
            if (value > 0) {
                m_strainSeries->append(timeValue, value);
                qDebug() << "应变数据添加到图表:" << timeValue << value;
            } else if (value > -10) {
                m_moveSeries->append(timeValue, value);
                qDebug() << "位移数据添加到图表:" << timeValue << value;
            } else {
                m_tempSeries->append(timeValue, value);
                qDebug() << "温度数据添加到图表:" << timeValue << value;
            }
        }
        
        // 设置时间轴范围（使用秒数）
        if (m_realtimeData.size() > 1) {
            m_timeAxis->setRange(minTimeValue, maxTimeValue);
            qDebug() << "时间轴范围设置为:" << minTimeValue << "到" << maxTimeValue;
        }
        
        // 自动调整Y轴范围，确保应变数据能正确显示
        if (maxValue > minValue) {
            // 为应变数据设置合适的Y轴范围
            qreal range = maxValue - minValue;
            if (range < 10) range = 10;  // 最小范围
            m_axisY->setRange(minValue - range * 0.1, maxValue + range * 0.1);
            qDebug() << "Y轴范围设置为:" << (minValue - range * 0.1) << "到" << (maxValue + range * 0.1);
        } else {
            // 如果没有数据变化，使用默认的应变数据范围
            m_axisY->setRange(-60, 60);
            qDebug() << "使用默认Y轴范围: -60 到 60";
        }
        
        qDebug() << "实时数据点数:" << m_realtimeData.size() << "最新值:" << m_realtimeData.last().second;
        
        // 强制刷新图表
        m_realtimeChart->update();
        m_chartView->update();
        m_chartView->repaint();
        
        // 检查系列是否真的附加到图表
        qDebug() << "图表中的系列数量:" << m_realtimeChart->series().size();
        for (int i = 0; i < m_realtimeChart->series().size(); ++i) {
            QAbstractSeries *series = m_realtimeChart->series().at(i);
            if (QLineSeries *lineSeries = qobject_cast<QLineSeries*>(series)) {
                qDebug() << "系列" << i << "名称:" << series->name() << "数据点数:" << lineSeries->count();
            }
        }
        
        qDebug() << "图表刷新完成，系列数据点数 - 应变:" << m_strainSeries->count() 
                 << "位移:" << m_moveSeries->count() 
                 << "温度:" << m_tempSeries->count();
        
        // 检查图表和视图的可见性
        qDebug() << "图表可见性 - 图表:" << m_realtimeChart->isVisible() 
                 << "视图:" << m_chartView->isVisible()
                 << "容器:" << ui->chartContainer->isVisible();
        qDebug() << "图表尺寸 - 图表:" << m_realtimeChart->size() 
                 << "视图:" << m_chartView->size()
                 << "容器:" << ui->chartContainer->size();
    }
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

// 测试设备连接函数
void Widget::testDeviceConnection()
{
    qDebug() << "=== 延迟调用设备连接测试 ===";
    qDebug() << "当前服务器状态图标样式:" << ui->label_2_5->styleSheet();
    qDebug() << "当前服务器状态文字:" << ui->label_2_8->text();
    onUdpDeviceConnected();
    qDebug() << "调用onUdpDeviceConnected后，服务器状态图标样式:" << ui->label_2_5->styleSheet();
    qDebug() << "调用onUdpDeviceConnected后，服务器状态文字:" << ui->label_2_8->text();
    qDebug() << "=== 设备连接测试完成 ===";
}
