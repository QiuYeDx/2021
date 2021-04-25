/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLabel *label;

    void setupUi(QWidget *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QString::fromUtf8("StartWindow"));
        StartWindow->resize(581, 376);
        pushButton_1 = new QPushButton(StartWindow);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(50, 140, 121, 61));
        pushButton_2 = new QPushButton(StartWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 140, 121, 61));
        pushButton_3 = new QPushButton(StartWindow);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 140, 121, 61));
        pushButton_4 = new QPushButton(StartWindow);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 250, 121, 61));
        label = new QLabel(StartWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 30, 161, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\347\253\231\351\205\267\351\253\230\347\253\257\351\273\221"));
        font.setPointSize(48);
        font.setUnderline(false);
        label->setFont(font);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QWidget *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "StartWindow", nullptr));
        pushButton_1->setText(QCoreApplication::translate("StartWindow", "\347\254\254\344\270\200\345\205\263", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StartWindow", "\347\254\254\344\272\214\345\205\263", nullptr));
        pushButton_3->setText(QCoreApplication::translate("StartWindow", "\347\254\254\344\270\211\345\205\263", nullptr));
        pushButton_4->setText(QCoreApplication::translate("StartWindow", "\347\254\254\345\233\233\345\205\263", nullptr));
        label->setText(QCoreApplication::translate("StartWindow", "\345\241\224\351\230\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
