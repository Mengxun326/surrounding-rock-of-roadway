/********************************************************************************
** Form generated from reading UI file 'tishi.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TISHI_H
#define UI_TISHI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tishi
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Tishi)
    {
        if (Tishi->objectName().isEmpty())
            Tishi->setObjectName("Tishi");
        Tishi->resize(450, 350);
        Tishi->setMinimumSize(QSize(450, 350));
        Tishi->setMaximumSize(QSize(450, 350));
        scrollArea = new QScrollArea(Tishi);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(10, 10, 431, 331));
        scrollArea->setMinimumSize(QSize(431, 331));
        scrollArea->setMaximumSize(QSize(431, 331));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 429, 329));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Tishi);

        QMetaObject::connectSlotsByName(Tishi);
    } // setupUi

    void retranslateUi(QWidget *Tishi)
    {
        Tishi->setWindowTitle(QCoreApplication::translate("Tishi", "\346\217\220\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Tishi: public Ui_Tishi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TISHI_H
