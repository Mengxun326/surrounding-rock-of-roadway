/********************************************************************************
** Form generated from reading UI file 'query.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUERY_H
#define UI_QUERY_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_query
{
public:
    QLabel *Tietlel;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_5;
    QLabel *change_label;
    QLabel *label_3;
    QComboBox *comboBox_2;
    QLineEdit *InputEdit;
    QDateTimeEdit *BeginTimeEdit;
    QLineEdit *SaveNamelineEdit;
    QLineEdit *TD_lineEdit;
    QPushButton *QueryButton;
    QLabel *label_4;
    QLabel *label_2;
    QComboBox *comboBox_1;
    QPushButton *SaveButton;
    QTableView *tableView;
    QDateTimeEdit *EndTimeEdit;
    QLabel *label_1;
    QLabel *bg_label;

    void setupUi(QWidget *query)
    {
        if (query->objectName().isEmpty())
            query->setObjectName("query");
        query->resize(900, 600);
        query->setMinimumSize(QSize(900, 600));
        query->setMaximumSize(QSize(900, 600));
        Tietlel = new QLabel(query);
        Tietlel->setObjectName("Tietlel");
        Tietlel->setGeometry(QRect(360, 10, 181, 31));
        Tietlel->setMinimumSize(QSize(181, 31));
        Tietlel->setMaximumSize(QSize(181, 31));
        gridLayoutWidget = new QWidget(query);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(10, 40, 881, 552));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 6, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName("label_5");
        label_5->setMinimumSize(QSize(175, 17));
        label_5->setMaximumSize(QSize(175, 17));

        gridLayout->addWidget(label_5, 13, 1, 1, 1);

        change_label = new QLabel(gridLayoutWidget);
        change_label->setObjectName("change_label");

        gridLayout->addWidget(change_label, 10, 1, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 4, 1, 1, 1);

        comboBox_2 = new QComboBox(gridLayoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setMinimumSize(QSize(115, 25));
        comboBox_2->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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

        gridLayout->addWidget(comboBox_2, 9, 1, 1, 1);

        InputEdit = new QLineEdit(gridLayoutWidget);
        InputEdit->setObjectName("InputEdit");
        InputEdit->setMinimumSize(QSize(121, 25));
        InputEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout->addWidget(InputEdit, 11, 1, 1, 1);

        BeginTimeEdit = new QDateTimeEdit(gridLayoutWidget);
        BeginTimeEdit->setObjectName("BeginTimeEdit");
        BeginTimeEdit->setMinimumSize(QSize(121, 25));
        BeginTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit {\n"
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
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));
        BeginTimeEdit->setDateTime(QDateTime(QDate(2023, 12, 21), QTime(0, 0, 0)));
        BeginTimeEdit->setDate(QDate(2023, 12, 21));

        gridLayout->addWidget(BeginTimeEdit, 1, 1, 1, 1);

        SaveNamelineEdit = new QLineEdit(gridLayoutWidget);
        SaveNamelineEdit->setObjectName("SaveNamelineEdit");
        SaveNamelineEdit->setMinimumSize(QSize(121, 25));
        SaveNamelineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout->addWidget(SaveNamelineEdit, 14, 1, 1, 1);

        TD_lineEdit = new QLineEdit(gridLayoutWidget);
        TD_lineEdit->setObjectName("TD_lineEdit");
        TD_lineEdit->setMinimumSize(QSize(121, 25));
        TD_lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));

        gridLayout->addWidget(TD_lineEdit, 7, 1, 1, 1);

        QueryButton = new QPushButton(gridLayoutWidget);
        QueryButton->setObjectName("QueryButton");
        QueryButton->setMinimumSize(QSize(121, 45));
        QueryButton->setMaximumSize(QSize(131, 45));
        QueryButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        gridLayout->addWidget(QueryButton, 12, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 8, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        comboBox_1 = new QComboBox(gridLayoutWidget);
        comboBox_1->addItem(QString());
        comboBox_1->addItem(QString());
        comboBox_1->addItem(QString());
        comboBox_1->setObjectName("comboBox_1");
        comboBox_1->setMinimumSize(QSize(115, 25));
        comboBox_1->setStyleSheet(QString::fromUtf8("QComboBox {\n"
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

        gridLayout->addWidget(comboBox_1, 5, 1, 1, 1);

        SaveButton = new QPushButton(gridLayoutWidget);
        SaveButton->setObjectName("SaveButton");
        SaveButton->setMinimumSize(QSize(121, 45));
        SaveButton->setMaximumSize(QSize(131, 45));
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

        gridLayout->addWidget(SaveButton, 15, 1, 1, 1, Qt::AlignmentFlag::AlignHCenter);

        tableView = new QTableView(gridLayoutWidget);
        tableView->setObjectName("tableView");
        tableView->setMinimumSize(QSize(650, 550));
        tableView->setMaximumSize(QSize(650, 550));
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

        gridLayout->addWidget(tableView, 0, 0, 16, 1);

        EndTimeEdit = new QDateTimeEdit(gridLayoutWidget);
        EndTimeEdit->setObjectName("EndTimeEdit");
        EndTimeEdit->setMinimumSize(QSize(121, 25));
        EndTimeEdit->setStyleSheet(QString::fromUtf8("QDateTimeEdit {\n"
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
"	padding-left: 10px;/*\345\267\246\344\276\247\350\276\271\350\267\235*/\n"
"}"));
        EndTimeEdit->setDate(QDate(2025, 1, 1));

        gridLayout->addWidget(EndTimeEdit, 3, 1, 1, 1);

        label_1 = new QLabel(gridLayoutWidget);
        label_1->setObjectName("label_1");

        gridLayout->addWidget(label_1, 0, 1, 1, 1);

        bg_label = new QLabel(query);
        bg_label->setObjectName("bg_label");
        bg_label->setGeometry(QRect(0, 0, 901, 601));
        bg_label->setMinimumSize(QSize(901, 601));
        bg_label->setMaximumSize(QSize(901, 601));
        bg_label->setScaledContents(true);
        bg_label->raise();
        Tietlel->raise();
        gridLayoutWidget->raise();

        retranslateUi(query);

        QMetaObject::connectSlotsByName(query);
    } // setupUi

    void retranslateUi(QWidget *query)
    {
        query->setWindowTitle(QCoreApplication::translate("query", "\346\225\260\346\215\256\346\237\245\350\257\242", nullptr));
        Tietlel->setText(QCoreApplication::translate("query", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:700; color:#00aaff;\">\346\225\260\346\215\256\346\237\245\350\257\242</span></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("query", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\351\200\232\351\201\223\345\217\267</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("query", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\345\257\274\345\207\272\345\220\215\347\247\260</span></p></body></html>", nullptr));
        change_label->setText(QCoreApplication::translate("query", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\346\237\245\346\211\276\350\276\223\345\205\245</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("query", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\346\237\245\350\257\242\351\200\211\346\213\251</span></p></body></html>", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("query", "\350\257\267\351\200\211\346\213\251", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("query", "\346\214\211\347\205\247\344\274\240\346\204\237\345\231\250\347\261\273\345\236\213\346\237\245\350\257\242", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("query", "\346\214\211\347\205\247 ID \346\237\245\350\257\242", nullptr));

        BeginTimeEdit->setDisplayFormat(QCoreApplication::translate("query", "yyyy-MM-dd HH:mm:ss", nullptr));
        TD_lineEdit->setText(QString());
        QueryButton->setText(QCoreApplication::translate("query", "\346\237\245\350\257\242", nullptr));
        label_4->setText(QCoreApplication::translate("query", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\346\237\245\346\211\276\347\261\273\345\236\213</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("query", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\347\273\223\346\235\237\346\227\266\351\227\264</span></p></body></html>", nullptr));
        comboBox_1->setItemText(0, QCoreApplication::translate("query", "\350\257\267\351\200\211\346\213\251", nullptr));
        comboBox_1->setItemText(1, QCoreApplication::translate("query", "\346\263\242\351\225\277\346\237\245\350\257\242", nullptr));
        comboBox_1->setItemText(2, QCoreApplication::translate("query", "\347\211\251\347\220\206\351\207\217\346\237\245\350\257\242", nullptr));

        SaveButton->setText(QCoreApplication::translate("query", "\345\257\274\345\207\272", nullptr));
        EndTimeEdit->setDisplayFormat(QCoreApplication::translate("query", "yyyy-MM-dd HH:mm:ss", nullptr));
        label_1->setText(QCoreApplication::translate("query", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:700; color:#00aaff;\">\350\265\267\345\247\213\346\227\266\351\227\264</span></p></body></html>", nullptr));
        bg_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class query: public Ui_query {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUERY_H
