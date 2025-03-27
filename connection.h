#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>

#define HostName "127.0.0.1" //（若要远程链接，输入相应的地址）
#define Port 3306
#define SqlName "QMYSQL"
#define UserName "root"
#define UserPassword "12345"

static bool createConnection() //此函数在main.cpp里面运行
{
    QSqlDatabase db;
    if(QSqlDatabase::contains("qt_sql_default_connection"))
        db = QSqlDatabase::database("qt_sql_default_connection");
    else
        db = QSqlDatabase::addDatabase("QMYSQL"); //创建一个数据库

    db.setHostName(HostName);                            //本地地址
    db.setPort(Port);                                    //设置端口号
    db.setDatabaseName(SqlName);                         //设置数据库的名字
    db.setUserName(UserName);                            //设置用户名字
    db.setPassword(UserPassword);                        //设置密码

    if(!db.open())
    {
        qCritical("Can't open database: %s(%s)",
                  db.lastError().text().toLocal8Bit().data(),
                  qt_error_string().toLocal8Bit().data());

        return false;
    }
    return true;
}

static bool closeConnection()
{
    QSqlDatabase::database().close();
    return 1;
}
#endif // CONNECTION_H
