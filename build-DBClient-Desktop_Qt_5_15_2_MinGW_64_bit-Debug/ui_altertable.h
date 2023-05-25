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
    QLineEdit *line_operate;
    QLineEdit *line_table;
    QLineEdit *line_column;
    QLineEdit *line_DataType;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *alterTable)
    {
        if (alterTable->objectName().isEmpty())
            alterTable->setObjectName(QString::fromUtf8("alterTable"));
        alterTable->resize(400, 300);
        line_operate = new QLineEdit(alterTable);
        line_operate->setObjectName(QString::fromUtf8("line_operate"));
        line_operate->setGeometry(QRect(130, 50, 113, 20));
        line_table = new QLineEdit(alterTable);
        line_table->setObjectName(QString::fromUtf8("line_table"));
        line_table->setGeometry(QRect(130, 90, 113, 20));
        line_column = new QLineEdit(alterTable);
        line_column->setObjectName(QString::fromUtf8("line_column"));
        line_column->setGeometry(QRect(130, 130, 113, 20));
        line_DataType = new QLineEdit(alterTable);
        line_DataType->setObjectName(QString::fromUtf8("line_DataType"));
        line_DataType->setGeometry(QRect(130, 170, 113, 20));
        label = new QLabel(alterTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 50, 51, 16));
        label_2 = new QLabel(alterTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 90, 51, 16));
        label_3 = new QLabel(alterTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 130, 51, 21));
        label_4 = new QLabel(alterTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(60, 170, 51, 16));
        pushButton = new QPushButton(alterTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(50, 230, 81, 31));
        pushButton_2 = new QPushButton(alterTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(190, 230, 81, 31));

        retranslateUi(alterTable);

        QMetaObject::connectSlotsByName(alterTable);
    } // setupUi

    void retranslateUi(QWidget *alterTable)
    {
        alterTable->setWindowTitle(QCoreApplication::translate("alterTable", "Form", nullptr));
        label->setText(QCoreApplication::translate("alterTable", "operate", nullptr));
        label_2->setText(QCoreApplication::translate("alterTable", "table", nullptr));
        label_3->setText(QCoreApplication::translate("alterTable", "column", nullptr));
        label_4->setText(QCoreApplication::translate("alterTable", "dataType", nullptr));
        pushButton->setText(QCoreApplication::translate("alterTable", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("alterTable", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class alterTable: public Ui_alterTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALTERTABLE_H
