/********************************************************************************
** Form generated from reading UI file 'deletetable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETETABLE_H
#define UI_DELETETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteTable
{
public:
    QLabel *delete_Lable;
    QLabel *label_2;
    QTextEdit *delete_textEdit;
    QTextEdit *where_textEdit;
    QPushButton *delete_pushButton;
    QPushButton *back_pushButton;

    void setupUi(QWidget *deleteTable)
    {
        if (deleteTable->objectName().isEmpty())
            deleteTable->setObjectName(QString::fromUtf8("deleteTable"));
        deleteTable->resize(854, 555);
        deleteTable->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        delete_Lable = new QLabel(deleteTable);
        delete_Lable->setObjectName(QString::fromUtf8("delete_Lable"));
        delete_Lable->setGeometry(QRect(150, 95, 131, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(12);
        delete_Lable->setFont(font);
        delete_Lable->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(deleteTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 200, 151, 51));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        delete_textEdit = new QTextEdit(deleteTable);
        delete_textEdit->setObjectName(QString::fromUtf8("delete_textEdit"));
        delete_textEdit->setGeometry(QRect(300, 80, 271, 61));
        delete_textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        where_textEdit = new QTextEdit(deleteTable);
        where_textEdit->setObjectName(QString::fromUtf8("where_textEdit"));
        where_textEdit->setGeometry(QRect(300, 190, 271, 61));
        where_textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        delete_pushButton = new QPushButton(deleteTable);
        delete_pushButton->setObjectName(QString::fromUtf8("delete_pushButton"));
        delete_pushButton->setGeometry(QRect(170, 370, 151, 51));
        delete_pushButton->setFont(font);
        delete_pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        back_pushButton = new QPushButton(deleteTable);
        back_pushButton->setObjectName(QString::fromUtf8("back_pushButton"));
        back_pushButton->setGeometry(QRect(520, 370, 121, 51));
        back_pushButton->setFont(font);
        back_pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));

        retranslateUi(deleteTable);

        QMetaObject::connectSlotsByName(deleteTable);
    } // setupUi

    void retranslateUi(QWidget *deleteTable)
    {
        deleteTable->setWindowTitle(QCoreApplication::translate("deleteTable", "Form", nullptr));
        delete_Lable->setText(QCoreApplication::translate("deleteTable", "\350\241\250\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("deleteTable", "where\346\235\241\344\273\266", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("deleteTable", "\345\210\240\351\231\244", nullptr));
        back_pushButton->setText(QCoreApplication::translate("deleteTable", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteTable: public Ui_deleteTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETETABLE_H
