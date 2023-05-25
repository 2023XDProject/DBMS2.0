/********************************************************************************
** Form generated from reading UI file 'deletetable.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETETABLE_H
#define UI_DELETETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deleteTable
{
public:
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *line_from;
    QLineEdit *line_where;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *deleteTable)
    {
        if (deleteTable->objectName().isEmpty())
            deleteTable->setObjectName(QString::fromUtf8("deleteTable"));
        deleteTable->resize(400, 300);
        label_2 = new QLabel(deleteTable);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 110, 41, 9));
        label_3 = new QLabel(deleteTable);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 140, 41, 9));
        line_from = new QLineEdit(deleteTable);
        line_from->setObjectName(QString::fromUtf8("line_from"));
        line_from->setGeometry(QRect(110, 110, 113, 20));
        line_where = new QLineEdit(deleteTable);
        line_where->setObjectName(QString::fromUtf8("line_where"));
        line_where->setGeometry(QRect(110, 140, 113, 20));
        pushButton = new QPushButton(deleteTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 220, 81, 31));
        pushButton_2 = new QPushButton(deleteTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 220, 91, 31));

        retranslateUi(deleteTable);

        QMetaObject::connectSlotsByName(deleteTable);
    } // setupUi

    void retranslateUi(QWidget *deleteTable)
    {
        deleteTable->setWindowTitle(QCoreApplication::translate("deleteTable", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("deleteTable", "from", nullptr));
        label_3->setText(QCoreApplication::translate("deleteTable", "where", nullptr));
        pushButton->setText(QCoreApplication::translate("deleteTable", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("deleteTable", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class deleteTable: public Ui_deleteTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETETABLE_H
