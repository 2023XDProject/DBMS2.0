/********************************************************************************
** Form generated from reading UI file 'createtablew.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATETABLEW_H
#define UI_CREATETABLEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CreateTableW
{
public:
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *CreateTableW)
    {
        if (CreateTableW->objectName().isEmpty())
            CreateTableW->setObjectName(QString::fromUtf8("CreateTableW"));
        CreateTableW->resize(480, 640);
        CreateTableW->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        textEdit = new QTextEdit(CreateTableW);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(70, 130, 321, 351));
        textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        lineEdit = new QLineEdit(CreateTableW);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(220, 50, 161, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        label = new QLabel(CreateTableW);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 40, 131, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(12);
        font.setBold(false);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(CreateTableW);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 530, 111, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(16);
        pushButton->setFont(font1);
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        pushButton_2 = new QPushButton(CreateTableW);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 530, 101, 61));
        pushButton_2->setFont(font1);
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));

        retranslateUi(CreateTableW);

        QMetaObject::connectSlotsByName(CreateTableW);
    } // setupUi

    void retranslateUi(QWidget *CreateTableW)
    {
        CreateTableW->setWindowTitle(QCoreApplication::translate("CreateTableW", "Form", nullptr));
        label->setText(QCoreApplication::translate("CreateTableW", "\350\241\250\345\220\215\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("CreateTableW", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CreateTableW", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CreateTableW: public Ui_CreateTableW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATETABLEW_H
