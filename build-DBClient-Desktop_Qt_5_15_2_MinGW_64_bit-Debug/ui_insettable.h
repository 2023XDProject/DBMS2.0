/********************************************************************************
** Form generated from reading UI file 'insettable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSETTABLE_H
#define UI_INSETTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_insetTable
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_table;
    QLineEdit *lineEdit_value;

    void setupUi(QWidget *insetTable)
    {
        if (insetTable->objectName().isEmpty())
            insetTable->setObjectName(QString::fromUtf8("insetTable"));
        insetTable->resize(400, 300);
        pushButton = new QPushButton(insetTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 230, 81, 31));
        pushButton_2 = new QPushButton(insetTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 230, 81, 31));
        label = new QLabel(insetTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 90, 41, 21));
        label_2 = new QLabel(insetTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 130, 41, 21));
        lineEdit_table = new QLineEdit(insetTable);
        lineEdit_table->setObjectName(QString::fromUtf8("lineEdit_table"));
        lineEdit_table->setGeometry(QRect(140, 90, 113, 20));
        lineEdit_value = new QLineEdit(insetTable);
        lineEdit_value->setObjectName(QString::fromUtf8("lineEdit_value"));
        lineEdit_value->setGeometry(QRect(140, 130, 113, 20));

        retranslateUi(insetTable);

        QMetaObject::connectSlotsByName(insetTable);
    } // setupUi

    void retranslateUi(QWidget *insetTable)
    {
        insetTable->setWindowTitle(QCoreApplication::translate("insetTable", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("insetTable", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("insetTable", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("insetTable", "table", nullptr));
        label_2->setText(QCoreApplication::translate("insetTable", "value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class insetTable: public Ui_insetTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSETTABLE_H
