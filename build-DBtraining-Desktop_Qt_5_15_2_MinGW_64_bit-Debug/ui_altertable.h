/********************************************************************************
** Form generated from reading UI file 'altertable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALTERTABLE_H
#define UI_ALTERTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_alterTable
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *line_operate;
    QLineEdit *line_table;
    QLineEdit *line_column;
    QLineEdit *line_dataType;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *alterTable)
    {
        if (alterTable->objectName().isEmpty())
            alterTable->setObjectName(QString::fromUtf8("alterTable"));
        alterTable->resize(536, 390);
        alterTable->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        pushButton = new QPushButton(alterTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 300, 121, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(16);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        pushButton_2 = new QPushButton(alterTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 300, 121, 71));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        line_operate = new QLineEdit(alterTable);
        line_operate->setObjectName(QString::fromUtf8("line_operate"));
        line_operate->setGeometry(QRect(220, 40, 241, 31));
        line_operate->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        line_table = new QLineEdit(alterTable);
        line_table->setObjectName(QString::fromUtf8("line_table"));
        line_table->setGeometry(QRect(220, 100, 241, 31));
        line_table->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        line_column = new QLineEdit(alterTable);
        line_column->setObjectName(QString::fromUtf8("line_column"));
        line_column->setGeometry(QRect(220, 160, 241, 31));
        line_column->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        line_dataType = new QLineEdit(alterTable);
        line_dataType->setObjectName(QString::fromUtf8("line_dataType"));
        line_dataType->setGeometry(QRect(220, 220, 241, 31));
        line_dataType->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        label = new QLabel(alterTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 20, 131, 71));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(alterTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 80, 141, 61));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(alterTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 150, 141, 61));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(alterTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 200, 201, 71));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        pushButton->raise();
        pushButton_2->raise();
        line_operate->raise();
        line_table->raise();
        line_column->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        line_dataType->raise();

        retranslateUi(alterTable);

        QMetaObject::connectSlotsByName(alterTable);
    } // setupUi

    void retranslateUi(QWidget *alterTable)
    {
        alterTable->setWindowTitle(QCoreApplication::translate("alterTable", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("alterTable", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("alterTable", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("alterTable", "\346\223\215\344\275\234", nullptr));
        label_2->setText(QCoreApplication::translate("alterTable", "\350\241\250\345\220\215", nullptr));
        label_3->setText(QCoreApplication::translate("alterTable", "\345\210\227\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("alterTable", "\346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alterTable: public Ui_alterTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTERTABLE_H
