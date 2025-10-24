/********************************************************************************
** Form generated from reading UI file 'sensordesign.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SENSORDESIGN_H
#define UI_SENSORDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SensorDesign
{
public:
    QLabel *Tietlel;
    QLabel *bg_label;
    QLabel *label;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QTableView *tableView_1;
    QPushButton *SaveButton1;
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QTableView *tableView_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QComboBox *comboBox;
    QPushButton *DeleteButton;
    QPushButton *AddButton;
    QPushButton *SaveButton2;

    void setupUi(QWidget *SensorDesign)
    {
        if (SensorDesign->objectName().isEmpty())
            SensorDesign->setObjectName("SensorDesign");
        SensorDesign->resize(900, 600);
        SensorDesign->setMinimumSize(QSize(900, 600));
        SensorDesign->setMaximumSize(QSize(900, 600));
        Tietlel = new QLabel(SensorDesign);
        Tietlel->setObjectName("Tietlel");
        Tietlel->setGeometry(QRect(360, 0, 181, 31));
        Tietlel->setMinimumSize(QSize(181, 31));
        Tietlel->setMaximumSize(QSize(181, 31));
        bg_label = new QLabel(SensorDesign);
        bg_label->setObjectName("bg_label");
        bg_label->setGeometry(QRect(0, 0, 901, 601));
        bg_label->setMinimumSize(QSize(901, 601));
        bg_label->setMaximumSize(QSize(901, 601));
        bg_label->setScaledContents(true);
        label = new QLabel(SensorDesign);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 0, 100, 25));
        label->setMinimumSize(QSize(100, 25));
        label->setMaximumSize(QSize(80, 25));
        groupBox = new QGroupBox(SensorDesign);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 30, 881, 231));
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
        gridLayoutWidget_2 = new QWidget(groupBox);
        gridLayoutWidget_2->setObjectName("gridLayoutWidget_2");
        gridLayoutWidget_2->setGeometry(QRect(15, 21, 876, 201));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        tableView_1 = new QTableView(gridLayoutWidget_2);
        tableView_1->setObjectName("tableView_1");
        tableView_1->setMinimumSize(QSize(874, 0));
        tableView_1->setMaximumSize(QSize(874, 191));
        tableView_1->setStyleSheet(QString::fromUtf8("QTableView {\n"
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

        gridLayout_2->addWidget(tableView_1, 1, 0, 1, 1);

        SaveButton1 = new QPushButton(gridLayoutWidget_2);
        SaveButton1->setObjectName("SaveButton1");
        SaveButton1->setMinimumSize(QSize(121, 45));
        SaveButton1->setMaximumSize(QSize(184, 45));
        SaveButton1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout_2->addWidget(SaveButton1, 0, 0, 1, 1, Qt::AlignmentFlag::AlignRight);

        groupBox_2 = new QGroupBox(SensorDesign);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 270, 881, 321));
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
        gridLayoutWidget_3 = new QWidget(groupBox_2);
        gridLayoutWidget_3->setObjectName("gridLayoutWidget_3");
        gridLayoutWidget_3->setGeometry(QRect(10, 20, 861, 291));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        tableView_2 = new QTableView(gridLayoutWidget_3);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setStyleSheet(QString::fromUtf8("QTableView {\n"
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

        gridLayout_3->addWidget(tableView_2, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        comboBox = new QComboBox(gridLayoutWidget_3);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setMinimumSize(QSize(115, 45));
        comboBox->setMaximumSize(QSize(16777215, 45));
        comboBox->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    border: 2px solid #f3f3f3;/*\350\256\276\347\275\256\347\272\277\345\256\275*/\n"
"	background-color: rgb(237, 242, 255);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 1px 2px 1px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
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
"/*QCombobox\345\217\263\344\276\247\346\214\211"
                        "\351\222\256*/\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;/*\346\224\276\344\272\216\345\217\263\346\226\271\351\241\266\351\203\250*/\n"
"    width: 50px;/*\350\256\276\347\275\256\346\214\211\351\222\256\350\214\203\345\233\264\345\256\275\345\272\246*/\n"
" 	/*border-radius: 15px;\n"
"    border-left-width: 1px;\n"
"    border-left-color: darkgray;\n"
"    border-left-style: solid;*/\n"
"\n"
"    border-top-right-radius: 3px;/*\350\256\276\347\275\256\350\276\271\346\241\206\345\234\206\350\247\222*/\n"
"    border-bottom-right-radius: 3px;\n"
"/*padding-right: 50px;*/\n"
"}\n"
"/*QCombobox\345\217\263\344\276\247\346\214\211\351\222\256\347\232\204\347\256\255\345\244\264\345\233\276\346\240\207*/\n"
"QComboBox::down-arrow {\n"
"	border-image: url(:/image/down_list.png);/*\350\207\252\345\256\232\344\271\211\345\233\276\347\211\207\345\241\253\345\205\205*/\n"
"	width: 10px;/*\350\256\276\347\275\256\350\257\245\345\233\276\346\240\207\347\232\204\345"
                        "\256\275\351\253\230*/\n"
"	height: 10px;\n"
"}\n"
"\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid #f3f3f3;/*\350\276\271\346\241\206\345\256\275\345\272\246\343\200\201\347\272\277\345\275\242\343\200\201\351\242\234\350\211\262*/\n"
"	background-color: rgba(237, 242, 255, 1);/*\350\203\214\346\231\257\351\242\234\350\211\262*/\n"
"    border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    padding: 1px 2px 1px 2px;  /*\351\222\210\345\257\271\344\272\216\347\273\204\345\220\210\346\241\206\344\270\255\347\232\204\346\226\207\346\234\254\345\206\205\345\256\271*/\n"
"    min-width: 9em;   /*# \347\273\204\345\220\210\346\241\206\347\232\204\346\234\200\345\260\217\345\256\275\345\272\246*/\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\346\257\217"
                        "\351\241\271\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView::item {\n"
"	border-radius: 15px;/*\345\234\206\350\247\222*/\n"
"    height: 30px;   /* \351\241\271\347\232\204\351\253\230\345\272\246\357\274\210\350\256\276\347\275\256pComboBox->setView(new QListView());\345\220\216\357\274\214\350\257\245\351\241\271\346\211\215\350\265\267\344\275\234\347\224\250\357\274\211 */\n"
"	background-color: rgb(237, 242, 255);\n"
"\n"
"}\n"
"\n"
"/*\344\273\245\344\270\213\351\203\250\345\210\206\344\270\215\347\237\245\344\270\272\344\275\225\344\270\215\347\224\237\346\225\210\357\274\214\346\234\211\345\276\205\350\260\203\350\257\225*/\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\350\266\212\350\277\207\346\257\217\351\241\271\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView::item:hover {\n"
"    color: #FFFFF0;\n"
"       /* \346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344"
                        "\275\223\350\266\212\350\277\207\346\257\217\351\241\271\347\232\204\350\203\214\346\231\257\350\211\262 */\n"
"	background-color: rgb(98, 0, 255);\n"
"}\n"
"\n"
"/* \344\270\213\346\213\211\345\220\216\357\274\214\346\225\264\344\270\252\344\270\213\346\213\211\347\252\227\344\275\223\350\242\253\351\200\211\346\213\251\347\232\204\346\257\217\351\241\271\347\232\204\346\240\267\345\274\217 */\n"
"QComboBox QAbstractItemView::item:selected {\n"
"    color: #FFFFF0;\n"
"	background-color: rgb(0, 85, 200);\n"
"}"));

        horizontalLayout->addWidget(comboBox);

        DeleteButton = new QPushButton(gridLayoutWidget_3);
        DeleteButton->setObjectName("DeleteButton");
        DeleteButton->setMinimumSize(QSize(121, 45));
        DeleteButton->setMaximumSize(QSize(16777215, 45));
        DeleteButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(DeleteButton);

        AddButton = new QPushButton(gridLayoutWidget_3);
        AddButton->setObjectName("AddButton");
        AddButton->setMinimumSize(QSize(121, 45));
        AddButton->setMaximumSize(QSize(16777215, 45));
        AddButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(AddButton);

        SaveButton2 = new QPushButton(gridLayoutWidget_3);
        SaveButton2->setObjectName("SaveButton2");
        SaveButton2->setMinimumSize(QSize(121, 0));
        SaveButton2->setMaximumSize(QSize(184, 45));
        SaveButton2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(SaveButton2);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        bg_label->raise();
        Tietlel->raise();
        label->raise();
        groupBox->raise();
        groupBox_2->raise();

        retranslateUi(SensorDesign);

        QMetaObject::connectSlotsByName(SensorDesign);
    } // setupUi

    void retranslateUi(QWidget *SensorDesign)
    {
        SensorDesign->setWindowTitle(QCoreApplication::translate("SensorDesign", "\344\274\240\346\204\237\345\231\250\350\256\276\350\256\241", nullptr));
        Tietlel->setText(QCoreApplication::translate("SensorDesign", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#00aaff;\">\344\274\240\346\204\237\345\231\250\350\256\276\350\256\241</span></p></body></html>", nullptr));
        bg_label->setText(QString());
        label->setText(QCoreApplication::translate("SensorDesign", "<html><head/><body><p align=\"center\"><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\344\274\240\346\204\237\345\231\250\347\273\204\350\256\276\347\275\256</span></p></body></html>", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SensorDesign", "\344\274\240\346\204\237\345\231\250\347\273\204\350\256\276\347\275\256", nullptr));
        SaveButton1->setText(QCoreApplication::translate("SensorDesign", "\344\277\235\345\255\230", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SensorDesign", "\344\274\240\346\204\237\345\231\250\350\256\276\347\275\256", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("SensorDesign", "\350\257\267\351\200\211\346\213\251", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("SensorDesign", "\344\274\240\346\204\237\345\231\250\347\273\2041", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("SensorDesign", "\344\274\240\346\204\237\345\231\250\347\273\2042", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("SensorDesign", "\344\274\240\346\204\237\345\231\250\347\273\2043", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("SensorDesign", "\344\274\240\346\204\237\345\231\250\347\273\2044", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("SensorDesign", "\344\274\240\346\204\237\345\231\250\347\273\2045", nullptr));

        DeleteButton->setText(QCoreApplication::translate("SensorDesign", "\345\210\240\351\231\244", nullptr));
        AddButton->setText(QCoreApplication::translate("SensorDesign", "\345\242\236\345\212\240", nullptr));
        SaveButton2->setText(QCoreApplication::translate("SensorDesign", "\344\277\235\345\255\230", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SensorDesign: public Ui_SensorDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SENSORDESIGN_H
