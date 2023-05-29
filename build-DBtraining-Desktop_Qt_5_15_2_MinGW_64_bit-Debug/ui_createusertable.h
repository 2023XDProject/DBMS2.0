/********************************************************************************
** Form generated from reading UI file 'createusertable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEUSERTABLE_H
#define UI_CREATEUSERTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createUserTable
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *userName;
    QLineEdit *pwd;

    void setupUi(QWidget *createUserTable)
    {
        if (createUserTable->objectName().isEmpty())
            createUserTable->setObjectName(QString::fromUtf8("createUserTable"));
        createUserTable->resize(440, 318);
        createUserTable->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        pushButton = new QPushButton(createUserTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 220, 101, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        pushButton_2 = new QPushButton(createUserTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 220, 111, 51));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        label = new QLabel(createUserTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 70, 141, 31));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(createUserTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 150, 71, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        userName = new QLineEdit(createUserTable);
        userName->setObjectName(QString::fromUtf8("userName"));
        userName->setGeometry(QRect(170, 70, 171, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        userName->setFont(font1);
        userName->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        pwd = new QLineEdit(createUserTable);
        pwd->setObjectName(QString::fromUtf8("pwd"));
        pwd->setGeometry(QRect(170, 150, 171, 41));
        pwd->setFont(font1);
        pwd->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));

        retranslateUi(createUserTable);

        QMetaObject::connectSlotsByName(createUserTable);
    } // setupUi

    void retranslateUi(QWidget *createUserTable)
    {
        createUserTable->setWindowTitle(QCoreApplication::translate("createUserTable", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("createUserTable", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("createUserTable", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("createUserTable", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("createUserTable", "\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createUserTable: public Ui_createUserTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEUSERTABLE_H
