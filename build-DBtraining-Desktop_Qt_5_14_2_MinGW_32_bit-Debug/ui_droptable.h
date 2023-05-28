/********************************************************************************
** Form generated from reading UI file 'droptable.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DROPTABLE_H
#define UI_DROPTABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DropTable
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QWidget *DropTable)
    {
        if (DropTable->objectName().isEmpty())
            DropTable->setObjectName(QString::fromUtf8("DropTable"));
        DropTable->resize(413, 314);
        DropTable->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        pushButton = new QPushButton(DropTable);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 210, 121, 51));
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
        pushButton_2 = new QPushButton(DropTable);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 210, 151, 51));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("border: none;\n"
"        color: rgb(175, 175, 175);\n"
"        background: transparent;\n"
"        padding: 10px;\n"
"        qproperty-icon: url(:/Black/nscc);\n"
"        qproperty-iconSize: 32px 32px;\n"
"        qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
""));
        label = new QLabel(DropTable);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 110, 101, 41));
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        lineEdit = new QLineEdit(DropTable);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(160, 100, 171, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"color: white;\n"
""));

        retranslateUi(DropTable);

        QMetaObject::connectSlotsByName(DropTable);
    } // setupUi

    void retranslateUi(QWidget *DropTable)
    {
        DropTable->setWindowTitle(QCoreApplication::translate("DropTable", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("DropTable", "\347\241\256\345\256\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DropTable", "\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("DropTable", "\350\241\250\345\220\215\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DropTable: public Ui_DropTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DROPTABLE_H
