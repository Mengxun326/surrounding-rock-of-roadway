/********************************************************************************
** Form generated from reading UI file 'sensorconfig.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORCONFIG_H
#define UI_SENSORCONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SensorConfig
{
public:
    QTableView *tableView;
    QTableView *TD_tableView;
    QLabel *Tietlel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *DeleteButton;
    QPushButton *SaveButton;
    QPushButton *AddButton;
    QPushButton *TishiButton;
    QLabel *bg_label;

    void setupUi(QWidget *SensorConfig)
    {
        if (SensorConfig->objectName().isEmpty())
            SensorConfig->setObjectName("SensorConfig");
        SensorConfig->resize(900, 600);
        SensorConfig->setMinimumSize(QSize(900, 600));
        SensorConfig->setMaximumSize(QSize(900, 600));
        tableView = new QTableView(SensorConfig);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(170, 50, 721, 491));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #ffffff;\n"
"    gridline-color: #d0d0d0;\n"
"    border: 1px solid #999999;\n"
"    selection-background-color: #66aaff;\n"
"    selection-color: white;\n"
"    alternate-background-color: #f0f0f5;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"    font-size: 12px;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #66aaff;\n"
"    color: white;\n"
"}\n"
"\n"
"QTableView::horizontalHeader {\n"
"    background-color: #e0e0e0;\n"
"    border-bottom: 1px solid #999999;\n"
"}\n"
"\n"
"QTableView::horizontalHeader::section {\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"    border-right: 1px solid #d0d0d0;\n"
"}\n"
"\n"
"QTableView::verticalHeader {\n"
"    background-color: #e0e0e0;\n"
"    border-right: 1px solid #999999;\n"
"}\n"
"\n"
"QTableView::verticalHeader::section {\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"    border-bottom: 1px solid #d0d0d0;\n"
"}"));
        TD_tableView = new QTableView(SensorConfig);
        TD_tableView->setObjectName("TD_tableView");
        TD_tableView->setGeometry(QRect(10, 51, 151, 541));
        TD_tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #ffffff;\n"
"    gridline-color: #d0d0d0;\n"
"    border: 1px solid #999999;\n"
"    selection-background-color: #66aaff;\n"
"    selection-color: white;\n"
"    alternate-background-color: #f0f0f5;\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"    font-size: 12px;\n"
"    color: #333333;\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #66aaff;\n"
"    color: white;\n"
"}\n"
"\n"
"QTableView::horizontalHeader {\n"
"    background-color: #e0e0e0;\n"
"    border-bottom: 1px solid #999999;\n"
"}\n"
"\n"
"QTableView::horizontalHeader::section {\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"    border-right: 1px solid #d0d0d0;\n"
"}\n"
"\n"
"QTableView::verticalHeader {\n"
"    background-color: #e0e0e0;\n"
"    border-right: 1px solid #999999;\n"
"}\n"
"\n"
"QTableView::verticalHeader::section {\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"    border-bottom: 1px solid #d0d0d0;\n"
"}"));
        Tietlel = new QLabel(SensorConfig);
        Tietlel->setObjectName("Tietlel");
        Tietlel->setGeometry(QRect(360, 10, 181, 31));
        Tietlel->setMinimumSize(QSize(181, 31));
        Tietlel->setMaximumSize(QSize(181, 31));
        layoutWidget = new QWidget(SensorConfig);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(240, 520, 581, 93));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        DeleteButton = new QPushButton(layoutWidget);
        DeleteButton->setObjectName("DeleteButton");
        DeleteButton->setMinimumSize(QSize(110, 45));
        DeleteButton->setMaximumSize(QSize(121, 45));
        DeleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 15px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 8em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"		color:#f"
                        "3f3f3;\n"
"	background-color:rgb(102,178,255); /*\346\224\271\345\217\230\350\203\214\346\231\257\350\211\262*/\n"
"	border-style:inset;/*\346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"	padding-left:6px;\n"
"	padding-top:6px;\n"
"}"));

        horizontalLayout->addWidget(DeleteButton);

        SaveButton = new QPushButton(layoutWidget);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setMinimumSize(QSize(110, 45));
        SaveButton->setMaximumSize(QSize(121, 45));
        SaveButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 15px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 8em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"		color:#f"
                        "3f3f3;\n"
"	background-color:rgb(102,178,255); /*\346\224\271\345\217\230\350\203\214\346\231\257\350\211\262*/\n"
"	border-style:inset;/*\346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"	padding-left:6px;\n"
"	padding-top:6px;\n"
"}"));

        horizontalLayout->addWidget(SaveButton);

        AddButton = new QPushButton(layoutWidget);
        AddButton->setObjectName("AddButton");
        AddButton->setMinimumSize(QSize(110, 45));
        AddButton->setMaximumSize(QSize(121, 45));
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 15px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 8em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"		color:#f"
                        "3f3f3;\n"
"	background-color:rgb(102,178,255); /*\346\224\271\345\217\230\350\203\214\346\231\257\350\211\262*/\n"
"	border-style:inset;/*\346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"	padding-left:6px;\n"
"	padding-top:6px;\n"
"}"));

        horizontalLayout->addWidget(AddButton);

        TishiButton = new QPushButton(layoutWidget);
        TishiButton->setObjectName("TishiButton");
        TishiButton->setMinimumSize(QSize(110, 45));
        TishiButton->setMaximumSize(QSize(121, 45));
        TishiButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 15px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 8em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"		color:#f"
                        "3f3f3;\n"
"	background-color:rgb(102,178,255); /*\346\224\271\345\217\230\350\203\214\346\231\257\350\211\262*/\n"
"	border-style:inset;/*\346\224\271\345\217\230\350\276\271\346\241\206\351\243\216\346\240\274*/\n"
"	padding-left:6px;\n"
"	padding-top:6px;\n"
"}"));

        horizontalLayout->addWidget(TishiButton);

        bg_label = new QLabel(SensorConfig);
        bg_label->setObjectName("bg_label");
        bg_label->setGeometry(QRect(0, 0, 901, 601));
        bg_label->setMinimumSize(QSize(901, 601));
        bg_label->setMaximumSize(QSize(901, 601));
        bg_label->setScaledContents(true);
        bg_label->raise();
        tableView->raise();
        TD_tableView->raise();
        Tietlel->raise();
        layoutWidget->raise();

        retranslateUi(SensorConfig);

        QMetaObject::connectSlotsByName(SensorConfig);
    } // setupUi

    void retranslateUi(QWidget *SensorConfig)
    {
        SensorConfig->setWindowTitle(QCoreApplication::translate("SensorConfig", "\344\274\240\346\204\237\345\231\250\351\205\215\347\275\256", nullptr));
        Tietlel->setText(QCoreApplication::translate("SensorConfig", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#00aaff;\">\344\274\240\346\204\237\345\231\250\351\205\215\347\275\256</span></p></body></html>", nullptr));
        DeleteButton->setText(QCoreApplication::translate("SensorConfig", "\345\210\240\351\231\244", nullptr));
        SaveButton->setText(QCoreApplication::translate("SensorConfig", "\344\277\235\345\255\230", nullptr));
        AddButton->setText(QCoreApplication::translate("SensorConfig", "\346\267\273\345\212\240", nullptr));
        TishiButton->setText(QCoreApplication::translate("SensorConfig", "\346\217\220\347\244\272", nullptr));
        bg_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SensorConfig: public Ui_SensorConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORCONFIG_H
