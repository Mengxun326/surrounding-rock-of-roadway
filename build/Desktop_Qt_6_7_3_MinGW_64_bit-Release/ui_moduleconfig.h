/********************************************************************************
** Form generated from reading UI file 'moduleconfig.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODULECONFIG_H
#define UI_MODULECONFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ModuleConfig
{
public:
    QTableView *tableView;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_1;
    QLineEdit *lineEdit_3;
    QPushButton *SaveButton;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *verticalSpacer;
    QLabel *Tietlel;
    QLabel *bg_label;

    void setupUi(QWidget *ModuleConfig)
    {
        if (ModuleConfig->objectName().isEmpty())
            ModuleConfig->setObjectName("ModuleConfig");
        ModuleConfig->resize(900, 600);
        ModuleConfig->setMinimumSize(QSize(900, 600));
        ModuleConfig->setMaximumSize(QSize(900, 600));
        tableView = new QTableView(ModuleConfig);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 40, 650, 530));
        tableView->setMinimumSize(QSize(650, 530));
        tableView->setMaximumSize(QSize(650, 530));
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
        gridLayoutWidget = new QWidget(ModuleConfig);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(680, 40, 193, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");
        label->setMinimumSize(QSize(25, 25));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");
        label_3->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(label_3, 4, 0, 1, 1);

        lineEdit_1 = new QLineEdit(gridLayoutWidget);
        lineEdit_1->setObjectName("lineEdit_1");
        lineEdit_1->setMinimumSize(QSize(191, 25));
        lineEdit_1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 9em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 80px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout->addWidget(lineEdit_1, 1, 0, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setMinimumSize(QSize(191, 25));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 9em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 80px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout->addWidget(lineEdit_3, 5, 0, 1, 1);

        SaveButton = new QPushButton(gridLayoutWidget);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setMinimumSize(QSize(121, 45));
        SaveButton->setMaximumSize(QSize(121, 45));
        SaveButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 15px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 9em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
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

        gridLayout->addWidget(SaveButton, 7, 0, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(0, 25));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setMinimumSize(QSize(191, 25));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 9em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 80px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout->addWidget(lineEdit_2, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 6, 0, 1, 1);

        Tietlel = new QLabel(ModuleConfig);
        Tietlel->setObjectName("Tietlel");
        Tietlel->setGeometry(QRect(360, 10, 181, 31));
        Tietlel->setMinimumSize(QSize(181, 31));
        Tietlel->setMaximumSize(QSize(181, 31));
        bg_label = new QLabel(ModuleConfig);
        bg_label->setObjectName("bg_label");
        bg_label->setGeometry(QRect(0, 0, 901, 601));
        bg_label->setMinimumSize(QSize(901, 601));
        bg_label->setMaximumSize(QSize(901, 601));
        bg_label->setScaledContents(true);
        bg_label->raise();
        tableView->raise();
        gridLayoutWidget->raise();
        Tietlel->raise();

        retranslateUi(ModuleConfig);

        QMetaObject::connectSlotsByName(ModuleConfig);
    } // setupUi

    void retranslateUi(QWidget *ModuleConfig)
    {
        ModuleConfig->setWindowTitle(QCoreApplication::translate("ModuleConfig", "\346\250\241\345\235\227\351\205\215\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("ModuleConfig", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\350\265\267\345\247\213\346\263\242\351\225\277\357\274\232</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("ModuleConfig", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\346\263\242\351\225\277\346\255\245\350\277\233\357\274\232</span></p></body></html>", nullptr));
        lineEdit_1->setText(QCoreApplication::translate("ModuleConfig", "1527", nullptr));
        lineEdit_3->setText(QCoreApplication::translate("ModuleConfig", "0.02", nullptr));
        SaveButton->setText(QCoreApplication::translate("ModuleConfig", "\350\256\276\347\275\256", nullptr));
        label_2->setText(QCoreApplication::translate("ModuleConfig", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\347\273\210\346\255\242\346\263\242\351\225\277\357\274\232</span></p></body></html>", nullptr));
        lineEdit_2->setText(QCoreApplication::translate("ModuleConfig", "1568", nullptr));
        Tietlel->setText(QCoreApplication::translate("ModuleConfig", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#00aaff;\">\346\250\241\345\235\227\345\217\202\346\225\260\351\205\215\347\275\256</span></p></body></html>", nullptr));
        bg_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ModuleConfig: public Ui_ModuleConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODULECONFIG_H
