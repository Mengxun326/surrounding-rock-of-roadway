#include "widget.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <connection.h>

// 日志消息的处理函数
    void logMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &message)
{
    // 获取格式化的日志信息
    QString typeStr = qFormatLogMessage(type, context, message);
    // 可以根据日志的级别进行过滤（比如不想要 Debug 输出，可以直接 return）
    QString levelText;
    switch (type)
    {
    case QtDebugMsg:
        levelText = "Debug";
        // return;	// 加上 return 之后就不会打印 debug 日志了
        break;
    case QtInfoMsg:
        levelText = "Info";
        break;
    case QtWarningMsg:
        levelText = "Warning";
        break;
    case QtCriticalMsg:
        levelText = "Critical";
        break;
    case QtFatalMsg:
        levelText = "Fatal";
        break;
    }
    QFile file("log.log");
    file.setPermissions(QFileDevice::WriteOwner);
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream textStream(&file);
    textStream << typeStr << "\n";
}



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //加载字符
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "surrounding-rock-of-roadway_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    Widget w;
    qSetMessagePattern("%{time yyyy-MM-dd hh:mm:ss} [%{type}]%{if-warning}[%{function}]%{endif}%{if-fatal}[%{function}--%{line}]%{endif}:%{message}");
    qInstallMessageHandler(logMessageHandler);
    qDebug() << "This is a debug message";
    qInfo() << "This is an info message";
    qWarning() << "This is a warning message";
    qCritical() << "This is a critical message";
    createConnection();
//  closeConnection();
    w.show();
    return a.exec();
}
