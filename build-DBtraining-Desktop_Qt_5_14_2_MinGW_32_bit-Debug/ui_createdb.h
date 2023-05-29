/********************************************************************************
** Form generated from reading UI file 'createdb.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEDB_H
#define UI_CREATEDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_createDB
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label;

    void setupUi(QWidget *createDB)
    {
        if (createDB->objectName().isEmpty())
            createDB->setObjectName(QString::fromUtf8("createDB"));
        createDB->resize(494, 288);
        createDB->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        pushButton = new QPushButton(createDB);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 190, 121, 61));
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
        pushButton_2 = new QPushButton(createDB);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 190, 121, 61));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        lineEdit = new QLineEdit(createDB);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(180, 90, 251, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        lineEdit->setFont(font1);
        lineEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        label = new QLabel(createDB);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 70, 231, 81));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton->raise();
        pushButton_2->raise();
        label->raise();
        lineEdit->raise();

        retranslateUi(createDB);

        QMetaObject::connectSlotsByName(createDB);
    } // setupUi

    void retranslateUi(QWidget *createDB)
    {
        createDB->setWindowTitle(QCoreApplication::translate("createDB", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("createDB", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("createDB", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("createDB", "\346\225\260\346\215\256\345\272\223\345\220\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class createDB: public Ui_createDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEDB_H
