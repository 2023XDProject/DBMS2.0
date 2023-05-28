/********************************************************************************
** Form generated from reading UI file 'dropdb.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROPDB_H
#define UI_DROPDB_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dropDB
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *dropDB)
    {
        if (dropDB->objectName().isEmpty())
            dropDB->setObjectName(QString::fromUtf8("dropDB"));
        dropDB->resize(536, 390);
        dropDB->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        label = new QLabel(dropDB);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 100, 211, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(16);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(dropDB);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(190, 120, 281, 41));
        lineEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        pushButton = new QPushButton(dropDB);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 270, 131, 61));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        pushButton_2 = new QPushButton(dropDB);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 270, 131, 61));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));

        retranslateUi(dropDB);

        QMetaObject::connectSlotsByName(dropDB);
    } // setupUi

    void retranslateUi(QWidget *dropDB)
    {
        dropDB->setWindowTitle(QCoreApplication::translate("dropDB", "Form", nullptr));
        label->setText(QCoreApplication::translate("dropDB", "\346\225\260\346\215\256\345\272\223\345\220\215\357\274\232", nullptr));
        pushButton->setText(QCoreApplication::translate("dropDB", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("dropDB", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dropDB: public Ui_dropDB {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROPDB_H
