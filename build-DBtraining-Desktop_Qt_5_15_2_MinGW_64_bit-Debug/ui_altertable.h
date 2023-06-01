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
    QLineEdit *line_newColumn;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *line_newType;

    void setupUi(QWidget *alterTable)
    {
        if (alterTable->objectName().isEmpty())
            alterTable->setObjectName(QString::fromUtf8("alterTable"));
        alterTable->resize(544, 561);
        alterTable->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        pushButton = new QPushButton(alterTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 480, 121, 71));
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
        pushButton_2 = new QPushButton(alterTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 480, 121, 71));
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
        line_operate->setGeometry(QRect(220, 40, 241, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        line_operate->setFont(font1);
        line_operate->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        line_table = new QLineEdit(alterTable);
        line_table->setObjectName(QString::fromUtf8("line_table"));
        line_table->setGeometry(QRect(220, 110, 241, 41));
        line_table->setFont(font1);
        line_table->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        line_column = new QLineEdit(alterTable);
        line_column->setObjectName(QString::fromUtf8("line_column"));
        line_column->setGeometry(QRect(220, 180, 241, 41));
        line_column->setFont(font1);
        line_column->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        line_dataType = new QLineEdit(alterTable);
        line_dataType->setObjectName(QString::fromUtf8("line_dataType"));
        line_dataType->setGeometry(QRect(220, 250, 241, 41));
        line_dataType->setFont(font1);
        line_dataType->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        label = new QLabel(alterTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 30, 131, 71));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_2 = new QLabel(alterTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(70, 100, 141, 61));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3 = new QLabel(alterTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(70, 170, 141, 61));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_4 = new QLabel(alterTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(70, 240, 141, 71));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line_newColumn = new QLineEdit(alterTable);
        line_newColumn->setObjectName(QString::fromUtf8("line_newColumn"));
        line_newColumn->setGeometry(QRect(220, 320, 241, 41));
        line_newColumn->setFont(font1);
        line_newColumn->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        label_5 = new QLabel(alterTable);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(70, 300, 131, 71));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_6 = new QLabel(alterTable);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(70, 380, 121, 71));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        line_newType = new QLineEdit(alterTable);
        line_newType->setObjectName(QString::fromUtf8("line_newType"));
        line_newType->setGeometry(QRect(220, 390, 241, 41));
        line_newType->setFont(font1);
        line_newType->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));
        pushButton->raise();
        pushButton_2->raise();
        line_operate->raise();
        line_table->raise();
        line_column->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        line_newColumn->raise();
        line_dataType->raise();
        label_6->raise();
        line_newType->raise();

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
        label_3->setText(QCoreApplication::translate("alterTable", "\345\255\227\346\256\265\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("alterTable", "\347\261\273\345\236\213", nullptr));
        label_5->setText(QCoreApplication::translate("alterTable", "\346\226\260\345\255\227\346\256\265\345\220\215", nullptr));
        label_6->setText(QCoreApplication::translate("alterTable", "\346\226\260\347\261\273\345\236\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alterTable: public Ui_alterTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTERTABLE_H
