/********************************************************************************
** Form generated from reading UI file 'updatetable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATETABLE_H
#define UI_UPDATETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_updateTable
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *update_textEdit;
    QTextEdit *set_textEdit;
    QTextEdit *where_textEdit;
    QPushButton *update_pushButton;
    QPushButton *back_pushButton;

    void setupUi(QWidget *updateTable)
    {
        if (updateTable->objectName().isEmpty())
            updateTable->setObjectName(QString::fromUtf8("updateTable"));
        updateTable->resize(954, 574);
        updateTable->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        label = new QLabel(updateTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 110, 121, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(updateTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 200, 121, 41));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(updateTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(240, 300, 101, 41));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        update_textEdit = new QTextEdit(updateTable);
        update_textEdit->setObjectName(QString::fromUtf8("update_textEdit"));
        update_textEdit->setGeometry(QRect(410, 110, 351, 51));
        update_textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        set_textEdit = new QTextEdit(updateTable);
        set_textEdit->setObjectName(QString::fromUtf8("set_textEdit"));
        set_textEdit->setGeometry(QRect(410, 200, 351, 51));
        set_textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        where_textEdit = new QTextEdit(updateTable);
        where_textEdit->setObjectName(QString::fromUtf8("where_textEdit"));
        where_textEdit->setGeometry(QRect(410, 290, 351, 51));
        where_textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        update_pushButton = new QPushButton(updateTable);
        update_pushButton->setObjectName(QString::fromUtf8("update_pushButton"));
        update_pushButton->setGeometry(QRect(230, 470, 121, 71));
        update_pushButton->setFont(font);
        update_pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        back_pushButton = new QPushButton(updateTable);
        back_pushButton->setObjectName(QString::fromUtf8("back_pushButton"));
        back_pushButton->setGeometry(QRect(620, 470, 121, 71));
        back_pushButton->setFont(font);
        back_pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));

        retranslateUi(updateTable);

        QMetaObject::connectSlotsByName(updateTable);
    } // setupUi

    void retranslateUi(QWidget *updateTable)
    {
        updateTable->setWindowTitle(QCoreApplication::translate("updateTable", "Form", nullptr));
        label->setText(QCoreApplication::translate("updateTable", "\350\241\250\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("updateTable", "set :", nullptr));
        label_3->setText(QCoreApplication::translate("updateTable", "\346\235\241\344\273\266\357\274\232", nullptr));
        update_pushButton->setText(QCoreApplication::translate("updateTable", "\346\233\264\346\226\260", nullptr));
        back_pushButton->setText(QCoreApplication::translate("updateTable", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updateTable: public Ui_updateTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATETABLE_H
