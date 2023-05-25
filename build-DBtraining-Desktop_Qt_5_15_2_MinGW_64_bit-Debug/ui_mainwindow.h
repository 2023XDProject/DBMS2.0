/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *createAction;
    QAction *dropAction;
    QAction *alterAction;
    QAction *creatUserAction;
    QAction *authorityAction;
    QAction *deleteAction;
    QAction *selectAction;
    QAction *updateAction;
    QAction *insertAction;
    QWidget *centralWidget;
    QPushButton *createUser_pushButton;
    QPushButton *authorization_pushButton;
    QPushButton *alterTable_pushButton;
    QPushButton *select_pushButton;
    QPushButton *update_pushButton;
    QPushButton *insert_pushButton;
    QPushButton *createTable_pushButton;
    QPushButton *dropTable_pushButton;
    QPushButton *delete_pushButton;
    QTextBrowser *textBrowser_2;
    QTableView *view_;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1600, 1000);
        MainWindow->setStyleSheet(QString::fromUtf8("background: rgb(50, 50, 50);"));
        createAction = new QAction(MainWindow);
        createAction->setObjectName(QString::fromUtf8("createAction"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font.setPointSize(16);
        createAction->setFont(font);
        dropAction = new QAction(MainWindow);
        dropAction->setObjectName(QString::fromUtf8("dropAction"));
        dropAction->setFont(font);
        alterAction = new QAction(MainWindow);
        alterAction->setObjectName(QString::fromUtf8("alterAction"));
        alterAction->setFont(font);
        creatUserAction = new QAction(MainWindow);
        creatUserAction->setObjectName(QString::fromUtf8("creatUserAction"));
        creatUserAction->setFont(font);
        authorityAction = new QAction(MainWindow);
        authorityAction->setObjectName(QString::fromUtf8("authorityAction"));
        authorityAction->setFont(font);
        deleteAction = new QAction(MainWindow);
        deleteAction->setObjectName(QString::fromUtf8("deleteAction"));
        deleteAction->setFont(font);
        selectAction = new QAction(MainWindow);
        selectAction->setObjectName(QString::fromUtf8("selectAction"));
        selectAction->setFont(font);
        updateAction = new QAction(MainWindow);
        updateAction->setObjectName(QString::fromUtf8("updateAction"));
        updateAction->setFont(font);
        insertAction = new QAction(MainWindow);
        insertAction->setObjectName(QString::fromUtf8("insertAction"));
        insertAction->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        createUser_pushButton = new QPushButton(centralWidget);
        createUser_pushButton->setObjectName(QString::fromUtf8("createUser_pushButton"));
        createUser_pushButton->setGeometry(QRect(810, 680, 93, 28));
        authorization_pushButton = new QPushButton(centralWidget);
        authorization_pushButton->setObjectName(QString::fromUtf8("authorization_pushButton"));
        authorization_pushButton->setGeometry(QRect(610, 620, 93, 28));
        alterTable_pushButton = new QPushButton(centralWidget);
        alterTable_pushButton->setObjectName(QString::fromUtf8("alterTable_pushButton"));
        alterTable_pushButton->setGeometry(QRect(910, 530, 93, 28));
        select_pushButton = new QPushButton(centralWidget);
        select_pushButton->setObjectName(QString::fromUtf8("select_pushButton"));
        select_pushButton->setGeometry(QRect(700, 430, 93, 28));
        update_pushButton = new QPushButton(centralWidget);
        update_pushButton->setObjectName(QString::fromUtf8("update_pushButton"));
        update_pushButton->setGeometry(QRect(760, 510, 93, 28));
        insert_pushButton = new QPushButton(centralWidget);
        insert_pushButton->setObjectName(QString::fromUtf8("insert_pushButton"));
        insert_pushButton->setGeometry(QRect(850, 610, 93, 28));
        createTable_pushButton = new QPushButton(centralWidget);
        createTable_pushButton->setObjectName(QString::fromUtf8("createTable_pushButton"));
        createTable_pushButton->setGeometry(QRect(450, 630, 93, 28));
        dropTable_pushButton = new QPushButton(centralWidget);
        dropTable_pushButton->setObjectName(QString::fromUtf8("dropTable_pushButton"));
        dropTable_pushButton->setGeometry(QRect(440, 490, 93, 28));
        delete_pushButton = new QPushButton(centralWidget);
        delete_pushButton->setObjectName(QString::fromUtf8("delete_pushButton"));
        delete_pushButton->setGeometry(QRect(610, 510, 93, 28));
        textBrowser_2 = new QTextBrowser(centralWidget);
        textBrowser_2->setObjectName(QString::fromUtf8("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(0, 0, 311, 921));
        textBrowser_2->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
""));
        textBrowser_2->setReadOnly(false);
        view_ = new QTableView(centralWidget);
        view_->setObjectName(QString::fromUtf8("view_"));
        view_->setGeometry(QRect(315, 1, 1291, 411));
        view_->setStyleSheet(QString::fromUtf8("QTableView {\n"
"        border: 1px solid rgb(45, 45, 45);\n"
"        background: rgb(57, 58, 60);\n"
"        gridline-color: rgb(60, 60, 60);\n"
"}\n"
"QTableView::item {\n"
"        padding-left: 5px;\n"
"        padding-right: 5px;\n"
"        border: none;\n"
"        background: rgb(72, 72, 74);\n"
"        border-right: 1px solid rgb(45, 45, 45);\n"
"        border-bottom: 1px solid rgb(45, 45, 45);\n"
"         color: white;\n"
"}\n"
"QTableView::item:selected {\n"
"        background: rgba(255, 255, 255, 40);\n"
"        color: green;\n"
"}\n"
"QTableView::item:selected:!active {\n"
"       color: white;\n"
"}\n"
"QTableView::indicator {\n"
"        width: 20px;\n"
"        height: 20px;\n"
"}\n"
""));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(1600, 70));
        mainToolBar->setMaximumSize(QSize(1600, 70));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font1.setPointSize(14);
        mainToolBar->setFont(font1);
        mainToolBar->setStyleSheet(QString::fromUtf8("QToolButton{\n"
"                                   border: none;\n"
"                                   color: white;\n"
"                                   background: transparent;\n"
"                                   padding: 10px;\n"
"                                   qproperty-toolButtonStyle: ToolButtonTextUnderIcon;\n"
"}"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addAction(createAction);
        mainToolBar->addAction(dropAction);
        mainToolBar->addAction(alterAction);
        mainToolBar->addAction(creatUserAction);
        mainToolBar->addAction(authorityAction);
        mainToolBar->addAction(deleteAction);
        mainToolBar->addAction(selectAction);
        mainToolBar->addAction(updateAction);
        mainToolBar->addAction(insertAction);

        retranslateUi(MainWindow);
        QObject::connect(creatUserAction, SIGNAL(triggered()), createUser_pushButton, SLOT(click()));
        QObject::connect(alterAction, SIGNAL(triggered()), alterTable_pushButton, SLOT(click()));
        QObject::connect(createAction, SIGNAL(triggered()), createTable_pushButton, SLOT(click()));
        QObject::connect(dropAction, SIGNAL(triggered()), dropTable_pushButton, SLOT(click()));
        QObject::connect(authorityAction, SIGNAL(triggered()), authorization_pushButton, SLOT(click()));
        QObject::connect(deleteAction, SIGNAL(triggered()), delete_pushButton, SLOT(click()));
        QObject::connect(selectAction, SIGNAL(triggered()), select_pushButton, SLOT(click()));
        QObject::connect(updateAction, SIGNAL(triggered()), update_pushButton, SLOT(click()));
        QObject::connect(insertAction, SIGNAL(triggered()), insert_pushButton, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        createAction->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\350\241\250", nullptr));
#if QT_CONFIG(shortcut)
        createAction->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        dropAction->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\250\n"
"", nullptr));
        alterAction->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\350\241\250", nullptr));
        creatUserAction->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\347\224\250\346\210\267", nullptr));
        authorityAction->setText(QCoreApplication::translate("MainWindow", "\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        deleteAction->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\260\345\275\225", nullptr));
        selectAction->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242\350\256\260\345\275\225", nullptr));
        updateAction->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260\350\256\260\345\275\225", nullptr));
        insertAction->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\350\256\260\345\275\225", nullptr));
        createUser_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\347\224\250\346\210\267", nullptr));
        authorization_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        alterTable_pushButton->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\350\241\250\347\273\223\346\236\204", nullptr));
        select_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        update_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260", nullptr));
        insert_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245", nullptr));
        createTable_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\350\241\250", nullptr));
        dropTable_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\250", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
