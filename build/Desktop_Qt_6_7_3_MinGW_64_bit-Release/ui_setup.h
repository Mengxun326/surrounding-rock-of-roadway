/********************************************************************************
** Form generated from reading UI file 'setup.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETUP_H
#define UI_SETUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetUp
{
public:
    QPushButton *SaveButton;
    QLabel *bg_label;
    QLabel *label_16;
    QPushButton *GPButton;
    QPushButton *BCButton;
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QListWidget *listWidget;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QTableView *BCTable;
    QGroupBox *groupBox_3;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QLineEdit *lineEdit_1_1;
    QLabel *label_5;
    QLineEdit *lineEdit_1_2;
    QLabel *label_13;
    QLabel *label_2;
    QLineEdit *lineEdit_1_3;
    QLabel *label_4;
    QLineEdit *lineEdit_1_0;
    QLabel *label_3;
    QLineEdit *lineEdit_1_4;
    QLabel *label_6;
    QLineEdit *lineEdit_1_5;
    QGroupBox *groupBox_4;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_9;
    QLabel *label_8;
    QLineEdit *lineEdit_2_2;
    QLineEdit *lineEdit_2_1;
    QLabel *label_10;
    QLineEdit *lineEdit_2_3;
    QGroupBox *groupBox_5;
    QWidget *gridLayoutWidget_6;
    QGridLayout *gridLayout_6;
    QLabel *label_12;
    QLineEdit *lineEdit_3_1;
    QPushButton *SetButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SetUp)
    {
        if (SetUp->objectName().isEmpty())
            SetUp->setObjectName("SetUp");
        SetUp->resize(900, 600);
        SetUp->setMinimumSize(QSize(900, 600));
        SetUp->setMaximumSize(QSize(900, 600));
        SetUp->setSizeIncrement(QSize(1200, 900));
        SaveButton = new QPushButton(SetUp);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setGeometry(QRect(20, 10, 121, 45));
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
        bg_label = new QLabel(SetUp);
        bg_label->setObjectName("bg_label");
        bg_label->setGeometry(QRect(0, 0, 900, 600));
        bg_label->setMinimumSize(QSize(900, 600));
        bg_label->setMaximumSize(QSize(900, 600));
        bg_label->setScaledContents(true);
        label_16 = new QLabel(SetUp);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(360, 10, 181, 31));
        label_16->setMinimumSize(QSize(181, 31));
        label_16->setMaximumSize(QSize(181, 31));
        GPButton = new QPushButton(SetUp);
        GPButton->setObjectName("GPButton");
        GPButton->setGeometry(QRect(520, 10, 121, 45));
        GPButton->setMinimumSize(QSize(121, 45));
        GPButton->setMaximumSize(QSize(121, 45));
        GPButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        BCButton = new QPushButton(SetUp);
        BCButton->setObjectName("BCButton");
        BCButton->setGeometry(QRect(710, 10, 121, 45));
        BCButton->setMinimumSize(QSize(121, 45));
        BCButton->setMaximumSize(QSize(121, 45));
        BCButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        groupBox = new QGroupBox(SetUp);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(280, 60, 611, 261));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid white;\n"
"    border-radius: 5px;\n"
"    margin-top: 1.5ex;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 3px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 20, 591, 231));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea_2 = new QScrollArea(layoutWidget);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setMaximumSize(QSize(463, 229));
        scrollArea_2->setStyleSheet(QString::fromUtf8("background-color: rgb(216, 215, 222)"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 461, 227));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout->addWidget(scrollArea_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName("gridLayout_3");
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName("pushButton");

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        listWidget = new QListWidget(layoutWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setMinimumSize(QSize(120, 0));
        listWidget->setMaximumSize(QSize(120, 205));
        listWidget->setStyleSheet(QString::fromUtf8(""));

        gridLayout_3->addWidget(listWidget, 1, 0, 1, 2, Qt::AlignmentFlag::AlignHCenter);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_3->addWidget(pushButton_2, 0, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);

        groupBox_2 = new QGroupBox(SetUp);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(280, 330, 611, 261));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid white;\n"
"    border-radius: 5px;\n"
"    margin-top: 1.5ex;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 3px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}"));
        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(10, 10, 591, 241));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        BCTable = new QTableView(gridLayoutWidget_2);
        BCTable->setObjectName("BCTable");
        BCTable->setMinimumSize(QSize(0, 220));
        BCTable->setMaximumSize(QSize(16777215, 220));
        BCTable->setStyleSheet(QString::fromUtf8("QTableView {\n"
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

        gridLayout_2->addWidget(BCTable, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(SetUp);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 60, 261, 231));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid white;\n"
"    border-radius: 5px;\n"
"    margin-top: 1.5ex;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 3px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}"));
        gridLayoutWidget_4 = new QWidget(groupBox_3);
        gridLayoutWidget_4->setObjectName("gridLayoutWidget_4");
        gridLayoutWidget_4->setGeometry(QRect(10, 20, 241, 201));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        lineEdit_1_1 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_1_1->setObjectName("lineEdit_1_1");
        lineEdit_1_1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_4->addWidget(lineEdit_1_1, 1, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget_4);
        label_5->setObjectName("label_5");

        gridLayout_4->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_1_2 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_1_2->setObjectName("lineEdit_1_2");
        lineEdit_1_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_4->addWidget(lineEdit_1_2, 2, 1, 1, 1);

        label_13 = new QLabel(gridLayoutWidget_4);
        label_13->setObjectName("label_13");

        gridLayout_4->addWidget(label_13, 1, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_4);
        label_2->setObjectName("label_2");

        gridLayout_4->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_1_3 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_1_3->setObjectName("lineEdit_1_3");
        lineEdit_1_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_4->addWidget(lineEdit_1_3, 3, 1, 1, 1);

        label_4 = new QLabel(gridLayoutWidget_4);
        label_4->setObjectName("label_4");
        label_4->setMinimumSize(QSize(45, 0));

        gridLayout_4->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_1_0 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_1_0->setObjectName("lineEdit_1_0");
        lineEdit_1_0->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_4->addWidget(lineEdit_1_0, 0, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget_4);
        label_3->setObjectName("label_3");

        gridLayout_4->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_1_4 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_1_4->setObjectName("lineEdit_1_4");
        lineEdit_1_4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_4->addWidget(lineEdit_1_4, 4, 1, 1, 1);

        label_6 = new QLabel(gridLayoutWidget_4);
        label_6->setObjectName("label_6");

        gridLayout_4->addWidget(label_6, 5, 0, 1, 1);

        lineEdit_1_5 = new QLineEdit(gridLayoutWidget_4);
        lineEdit_1_5->setObjectName("lineEdit_1_5");
        lineEdit_1_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_4->addWidget(lineEdit_1_5, 5, 1, 1, 1);

        groupBox_4 = new QGroupBox(SetUp);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 330, 261, 121));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid white;\n"
"    border-radius: 5px;\n"
"    margin-top: 1.5ex;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 3px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}"));
        gridLayoutWidget_5 = new QWidget(groupBox_4);
        gridLayoutWidget_5->setObjectName("gridLayoutWidget_5");
        gridLayoutWidget_5->setGeometry(QRect(10, 20, 241, 91));
        gridLayout_5 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_5->setObjectName("gridLayout_5");
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(gridLayoutWidget_5);
        label_9->setObjectName("label_9");

        gridLayout_5->addWidget(label_9, 1, 0, 1, 1);

        label_8 = new QLabel(gridLayoutWidget_5);
        label_8->setObjectName("label_8");

        gridLayout_5->addWidget(label_8, 0, 0, 1, 1);

        lineEdit_2_2 = new QLineEdit(gridLayoutWidget_5);
        lineEdit_2_2->setObjectName("lineEdit_2_2");
        lineEdit_2_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_5->addWidget(lineEdit_2_2, 1, 1, 1, 1);

        lineEdit_2_1 = new QLineEdit(gridLayoutWidget_5);
        lineEdit_2_1->setObjectName("lineEdit_2_1");
        lineEdit_2_1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_5->addWidget(lineEdit_2_1, 0, 1, 1, 1);

        label_10 = new QLabel(gridLayoutWidget_5);
        label_10->setObjectName("label_10");
        label_10->setMinimumSize(QSize(45, 0));

        gridLayout_5->addWidget(label_10, 2, 0, 1, 1);

        lineEdit_2_3 = new QLineEdit(gridLayoutWidget_5);
        lineEdit_2_3->setObjectName("lineEdit_2_3");
        lineEdit_2_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_5->addWidget(lineEdit_2_3, 2, 1, 1, 1);

        groupBox_5 = new QGroupBox(SetUp);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(10, 480, 261, 111));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 2px solid white;\n"
"    border-radius: 5px;\n"
"    margin-top: 1.5ex;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 0 3px;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}"));
        gridLayoutWidget_6 = new QWidget(groupBox_5);
        gridLayoutWidget_6->setObjectName("gridLayoutWidget_6");
        gridLayoutWidget_6->setGeometry(QRect(10, 20, 241, 80));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_6);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        label_12 = new QLabel(gridLayoutWidget_6);
        label_12->setObjectName("label_12");
        label_12->setMinimumSize(QSize(45, 0));

        gridLayout_6->addWidget(label_12, 0, 0, 1, 1);

        lineEdit_3_1 = new QLineEdit(gridLayoutWidget_6);
        lineEdit_3_1->setObjectName("lineEdit_3_1");
        lineEdit_3_1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 2px 8px 5px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"	text-align:bottom;\n"
"    min-width: 5em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"    /*min-height: 5em;*/\n"
"\n"
"	border-style:solid;/*\350\276\271\346\241\206\344\270\272\345\256\236\347\272\277\345\236\213*/\n"
"	border-width:2px;/*\350\276\271\346\241\206\345\256\275\345\272\246*/\n"
"	border-color:rgb(77, 123, 255);/*\350\276\271\346\241\206\351\242\234\350\211\262*/\n"
"\n"
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout_6->addWidget(lineEdit_3_1, 0, 1, 1, 1);

        SetButton = new QPushButton(gridLayoutWidget_6);
        SetButton->setObjectName("SetButton");
        SetButton->setMinimumSize(QSize(110, 45));
        SetButton->setMaximumSize(QSize(121, 45));
        SetButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_6->addWidget(SetButton, 1, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout_6->addItem(verticalSpacer, 1, 0, 1, 1);

        bg_label->raise();
        SaveButton->raise();
        label_16->raise();
        GPButton->raise();
        BCButton->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        groupBox_5->raise();

        retranslateUi(SetUp);

        QMetaObject::connectSlotsByName(SetUp);
    } // setupUi

    void retranslateUi(QWidget *SetUp)
    {
        SetUp->setWindowTitle(QCoreApplication::translate("SetUp", "\345\237\272\346\234\254\344\277\241\346\201\257\347\256\241\347\220\206", nullptr));
        SaveButton->setText(QCoreApplication::translate("SetUp", "\344\277\235\345\255\230", nullptr));
        bg_label->setText(QString());
        label_16->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#00aaff;\">\345\237\272\346\234\254\344\277\241\346\201\257\347\256\241\347\220\206</span></p></body></html>", nullptr));
        GPButton->setText(QCoreApplication::translate("SetUp", "\350\216\267\345\217\226\345\205\211\350\260\261", nullptr));
        BCButton->setText(QCoreApplication::translate("SetUp", "\350\216\267\345\217\226\346\263\242\351\225\277", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SetUp", "\345\205\211\350\260\261", nullptr));
        pushButton->setText(QCoreApplication::translate("SetUp", "\345\205\250\351\200\211", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SetUp", "\345\205\250\344\270\215\351\200\211", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SetUp", "\346\263\242\351\225\277", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("SetUp", "\345\234\260\347\220\206\344\277\241\346\201\257", nullptr));
        label_5->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00aaff;\">\347\274\226\345\217\267</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00aaff;\">\347\272\254\345\272\246</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00aaff;\">\347\273\217\345\272\246</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00aaff;\">\345\267\267\351\201\223\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00aaff;\">\347\237\277\345\214\272\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00aaff;\">\351\225\277\345\272\246</span></p></body></html>", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("SetUp", "\347\256\241\347\220\206\345\275\222\345\261\236\344\272\272", nullptr));
        label_9->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00aaff;\">\345\214\272\345\217\267</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00aaff;\">\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p align=\"center\"><span style=\" font-weight:700; color:#00aaff;\">\347\255\211\347\272\247</span></p></body></html>", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("SetUp", "\344\270\273\346\234\272\350\256\276\347\275\256", nullptr));
        label_12->setText(QCoreApplication::translate("SetUp", "<html><head/><body><p><span style=\" font-weight:700; color:#00aaff;\">\350\277\234\347\250\213IP\345\234\260\345\235\200</span></p></body></html>", nullptr));
        SetButton->setText(QCoreApplication::translate("SetUp", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetUp: public Ui_SetUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETUP_H
