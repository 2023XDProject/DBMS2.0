/********************************************************************************
** Form generated from reading UI file 'fuctioncombining.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUCTIONCOMBINING_H
#define UI_FUCTIONCOMBINING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FuctionCombining
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *FuctionCombining)
    {
        if (FuctionCombining->objectName().isEmpty())
            FuctionCombining->setObjectName(QString::fromUtf8("FuctionCombining"));
        FuctionCombining->resize(400, 300);
        pushButton = new QPushButton(FuctionCombining);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 180, 81, 31));
        pushButton_2 = new QPushButton(FuctionCombining);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 180, 91, 31));
        pushButton_3 = new QPushButton(FuctionCombining);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(280, 180, 91, 31));
        pushButton_4 = new QPushButton(FuctionCombining);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(90, 230, 81, 41));
        pushButton_5 = new QPushButton(FuctionCombining);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(230, 230, 81, 41));
        textBrowser = new QTextBrowser(FuctionCombining);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(90, 20, 221, 141));

        retranslateUi(FuctionCombining);

        QMetaObject::connectSlotsByName(FuctionCombining);
    } // setupUi

    void retranslateUi(QWidget *FuctionCombining)
    {
        FuctionCombining->setWindowTitle(QCoreApplication::translate("FuctionCombining", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("FuctionCombining", "select", nullptr));
        pushButton_2->setText(QCoreApplication::translate("FuctionCombining", "update", nullptr));
        pushButton_3->setText(QCoreApplication::translate("FuctionCombining", "delete", nullptr));
        pushButton_4->setText(QCoreApplication::translate("FuctionCombining", "insert", nullptr));
        pushButton_5->setText(QCoreApplication::translate("FuctionCombining", "alter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FuctionCombining: public Ui_FuctionCombining {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUCTIONCOMBINING_H
