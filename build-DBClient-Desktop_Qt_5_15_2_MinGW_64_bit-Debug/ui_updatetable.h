/********************************************************************************
** Form generated from reading UI file 'updatetable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATETABLE_H
#define UI_UPDATETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_updateTable
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *line_tableName;
    QLineEdit *line_condition;
    QLineEdit *line_contain;

    void setupUi(QWidget *updateTable)
    {
        if (updateTable->objectName().isEmpty())
            updateTable->setObjectName(QString::fromUtf8("updateTable"));
        updateTable->resize(400, 300);
        pushButton = new QPushButton(updateTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(60, 230, 91, 31));
        pushButton_2 = new QPushButton(updateTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 230, 91, 31));
        label = new QLabel(updateTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 90, 51, 16));
        label_2 = new QLabel(updateTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 120, 51, 21));
        label_3 = new QLabel(updateTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 160, 51, 16));
        line_tableName = new QLineEdit(updateTable);
        line_tableName->setObjectName(QString::fromUtf8("line_tableName"));
        line_tableName->setGeometry(QRect(120, 90, 113, 20));
        line_condition = new QLineEdit(updateTable);
        line_condition->setObjectName(QString::fromUtf8("line_condition"));
        line_condition->setGeometry(QRect(120, 150, 113, 20));
        line_contain = new QLineEdit(updateTable);
        line_contain->setObjectName(QString::fromUtf8("line_contain"));
        line_contain->setGeometry(QRect(120, 120, 113, 20));

        retranslateUi(updateTable);

        QMetaObject::connectSlotsByName(updateTable);
    } // setupUi

    void retranslateUi(QWidget *updateTable)
    {
        updateTable->setWindowTitle(QCoreApplication::translate("updateTable", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("updateTable", "\347\241\256\350\256\244", nullptr));
        pushButton_2->setText(QCoreApplication::translate("updateTable", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("updateTable", "tablename", nullptr));
        label_2->setText(QCoreApplication::translate("updateTable", "set", nullptr));
        label_3->setText(QCoreApplication::translate("updateTable", "where", nullptr));
    } // retranslateUi

};

namespace Ui {
    class updateTable: public Ui_updateTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATETABLE_H
