QT       += core gui network charts
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    combodelegate.cpp \
    main.cpp \
    moduleconfig.cpp \
    query.cpp \
    sensorconfig.cpp \
    sensordesign.cpp \
    setup.cpp \
    tishi.cpp \
    tcpserver.cpp \
    udpreceiver.cpp \
    variate.cpp \
    warning.cpp \
    widget.cpp

HEADERS += \
    combodelegate.h \
    connection.h \
    moduleconfig.h \
    query.h \
    sensorconfig.h \
    sensordesign.h \
    setup.h \
    tishi.h \
    tcpserver.h \
    udpreceiver.h \
    variate.h \
    warning.h \
    widget.h

FORMS += \
    moduleconfig.ui \
    query.ui \
    sensorconfig.ui \
    sensordesign.ui \
    setup.ui \
    tishi.ui \
    warning.ui \
    widget.ui

TRANSLATIONS += \
    surrounding-rock-of-roadway_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    res.qrc

RC_ICONS = logo.ico
