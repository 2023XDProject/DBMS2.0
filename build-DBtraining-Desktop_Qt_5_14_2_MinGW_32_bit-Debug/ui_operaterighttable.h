/********************************************************************************
** Form generated from reading UI file 'operaterighttable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPERATERIGHTTABLE_H
#define UI_OPERATERIGHTTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OperateRightTable
{
public:
    QLineEdit *operate;
    QLineEdit *userName;
    QLineEdit *table;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *right;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *OperateRightTable)
    {
        if (OperateRightTable->objectName().isEmpty())
            OperateRightTable->setObjectName(QString::fromUtf8("OperateRightTable"));
        OperateRightTable->resize(616, 426);
        OperateRightTable->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        operate = new QLineEdit(OperateRightTable);
        operate->setObjectName(QString::fromUtf8("operate"));
        operate->setGeometry(QRect(240, 30, 241, 51));
        operate->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        userName = new QLineEdit(OperateRightTable);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setGeometry(QRect(240, 110, 241, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(16);
        userName->setFont(font);
        userName->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        table = new QLineEdit(OperateRightTable);
        table->setObjectName(QString::fromUtf8("table"));
        table->setGeometry(QRect(240, 190, 241, 51));
        table->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        label = new QLabel(OperateRightTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(110, 30, 121, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(OperateRightTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 100, 131, 61));
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(OperateRightTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 180, 91, 61));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(OperateRightTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(100, 260, 101, 61));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        right = new QLineEdit(OperateRightTable);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(240, 270, 241, 51));
        right->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        pushButton = new QPushButton(OperateRightTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 350, 111, 61));
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        pushButton_2 = new QPushButton(OperateRightTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(370, 360, 111, 51));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));

        retranslateUi(OperateRightTable);

        QMetaObject::connectSlotsByName(OperateRightTable);
    } // setupUi

    void retranslateUi(QWidget *OperateRightTable)
    {
        OperateRightTable->setWindowTitle(QCoreApplication::translate("OperateRightTable", "Form", nullptr));
        label->setText(QCoreApplication::translate("OperateRightTable", "\346\223\215\344\275\234", nullptr));
        label_2->setText(QCoreApplication::translate("OperateRightTable", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("OperateRightTable", "\350\241\250\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("OperateRightTable", "\346\235\203\351\231\220", nullptr));
        pushButton->setText(QCoreApplication::translate("OperateRightTable", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("OperateRightTable", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OperateRightTable: public Ui_OperateRightTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPERATERIGHTTABLE_H
