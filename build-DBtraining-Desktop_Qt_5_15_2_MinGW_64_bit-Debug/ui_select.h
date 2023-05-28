/********************************************************************************
** Form generated from reading UI file 'select.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_H
#define UI_SELECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Select
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *confirm_pushButton;
    QPushButton *back_pushButton;
    QTextEdit *attribute_textEdit;
    QTextEdit *tablename_textEdit;
    QTextEdit *order__textEdit;
    QTextEdit *condition_textEdit;

    void setupUi(QWidget *Select)
    {
        if (Select->objectName().isEmpty())
            Select->setObjectName(QString::fromUtf8("Select"));
        Select->resize(871, 637);
        Select->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        label = new QLabel(Select);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(220, 110, 111, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(12);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(Select);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(220, 200, 111, 51));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(Select);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 380, 101, 51));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(Select);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 280, 101, 51));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        confirm_pushButton = new QPushButton(Select);
        confirm_pushButton->setObjectName(QString::fromUtf8("confirm_pushButton"));
        confirm_pushButton->setGeometry(QRect(190, 510, 131, 71));
        confirm_pushButton->setFont(font);
        confirm_pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        back_pushButton = new QPushButton(Select);
        back_pushButton->setObjectName(QString::fromUtf8("back_pushButton"));
        back_pushButton->setGeometry(QRect(520, 510, 141, 71));
        back_pushButton->setFont(font);
        back_pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        attribute_textEdit = new QTextEdit(Select);
        attribute_textEdit->setObjectName(QString::fromUtf8("attribute_textEdit"));
        attribute_textEdit->setGeometry(QRect(360, 110, 301, 61));
        attribute_textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        tablename_textEdit = new QTextEdit(Select);
        tablename_textEdit->setObjectName(QString::fromUtf8("tablename_textEdit"));
        tablename_textEdit->setGeometry(QRect(360, 190, 301, 61));
        tablename_textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        order__textEdit = new QTextEdit(Select);
        order__textEdit->setObjectName(QString::fromUtf8("order__textEdit"));
        order__textEdit->setGeometry(QRect(360, 370, 301, 61));
        order__textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        condition_textEdit = new QTextEdit(Select);
        condition_textEdit->setObjectName(QString::fromUtf8("condition_textEdit"));
        condition_textEdit->setGeometry(QRect(360, 280, 301, 61));
        condition_textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));

        retranslateUi(Select);

        QMetaObject::connectSlotsByName(Select);
    } // setupUi

    void retranslateUi(QWidget *Select)
    {
        Select->setWindowTitle(QCoreApplication::translate("Select", "Form", nullptr));
        label->setText(QCoreApplication::translate("Select", "\345\261\236\346\200\247\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("Select", "\350\241\250\345\220\215\357\274\232", nullptr));
        label_3->setText(QCoreApplication::translate("Select", "\351\241\272\345\272\217\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("Select", "\346\235\241\344\273\266:", nullptr));
        confirm_pushButton->setText(QCoreApplication::translate("Select", "\347\241\256\350\256\244", nullptr));
        back_pushButton->setText(QCoreApplication::translate("Select", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Select: public Ui_Select {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_H
