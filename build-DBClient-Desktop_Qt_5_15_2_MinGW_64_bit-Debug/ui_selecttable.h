/********************************************************************************
** Form generated from reading UI file 'selecttable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTTABLE_H
#define UI_SELECTTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectTable
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *line_attribute;
    QLineEdit *line_from;
    QLineEdit *line_where;
    QLineEdit *line_order;

    void setupUi(QWidget *selectTable)
    {
        if (selectTable->objectName().isEmpty())
            selectTable->setObjectName(QString::fromUtf8("selectTable"));
        selectTable->resize(400, 300);
        pushButton = new QPushButton(selectTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 220, 81, 31));
        pushButton_2 = new QPushButton(selectTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 220, 81, 31));
        label = new QLabel(selectTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 60, 51, 21));
        label_2 = new QLabel(selectTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 100, 51, 16));
        label_3 = new QLabel(selectTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 130, 41, 16));
        label_4 = new QLabel(selectTable);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(50, 170, 41, 9));
        line_attribute = new QLineEdit(selectTable);
        line_attribute->setObjectName(QString::fromUtf8("line_attribute"));
        line_attribute->setGeometry(QRect(130, 60, 113, 20));
        line_from = new QLineEdit(selectTable);
        line_from->setObjectName(QString::fromUtf8("line_from"));
        line_from->setGeometry(QRect(130, 100, 113, 20));
        line_where = new QLineEdit(selectTable);
        line_where->setObjectName(QString::fromUtf8("line_where"));
        line_where->setGeometry(QRect(130, 140, 113, 20));
        line_order = new QLineEdit(selectTable);
        line_order->setObjectName(QString::fromUtf8("line_order"));
        line_order->setGeometry(QRect(130, 170, 113, 20));

        retranslateUi(selectTable);

        QMetaObject::connectSlotsByName(selectTable);
    } // setupUi

    void retranslateUi(QWidget *selectTable)
    {
        selectTable->setWindowTitle(QCoreApplication::translate("selectTable", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("selectTable", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("selectTable", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("selectTable", "attribute", nullptr));
        label_2->setText(QCoreApplication::translate("selectTable", "from", nullptr));
        label_3->setText(QCoreApplication::translate("selectTable", "where", nullptr));
        label_4->setText(QCoreApplication::translate("selectTable", "order", nullptr));
    } // retranslateUi

};

namespace Ui {
    class selectTable: public Ui_selectTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTTABLE_H
