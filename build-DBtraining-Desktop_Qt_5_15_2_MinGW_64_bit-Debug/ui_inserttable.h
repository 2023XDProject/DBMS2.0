/********************************************************************************
** Form generated from reading UI file 'inserttable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTTABLE_H
#define UI_INSERTTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insertTable
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *insertTable)
    {
        if (insertTable->objectName().isEmpty())
            insertTable->setObjectName(QString::fromUtf8("insertTable"));
        insertTable->resize(400, 300);
        insertTable->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        pushButton = new QPushButton(insertTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 220, 101, 51));
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
        pushButton_2 = new QPushButton(insertTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 220, 101, 51));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        lineEdit = new QLineEdit(insertTable);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 60, 161, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        lineEdit_2 = new QLineEdit(insertTable);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 130, 161, 41));
        lineEdit_2->setFont(font1);
        lineEdit_2->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        label = new QLabel(insertTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 60, 71, 41));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(insertTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 130, 91, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        retranslateUi(insertTable);

        QMetaObject::connectSlotsByName(insertTable);
    } // setupUi

    void retranslateUi(QWidget *insertTable)
    {
        insertTable->setWindowTitle(QCoreApplication::translate("insertTable", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("insertTable", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("insertTable", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("insertTable", "\350\241\250\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("insertTable", "\345\200\274", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insertTable: public Ui_insertTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTTABLE_H
