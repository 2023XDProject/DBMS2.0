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
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
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
    QAction *createBDAction;
    QAction *DropDBAction;
    QAction *actAction;
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
    QTableView *view_;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTreeView *treeView;
    QPushButton *pushButton_3;
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
        font.setPointSize(8);
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
        createBDAction = new QAction(MainWindow);
        createBDAction->setObjectName(QString::fromUtf8("createBDAction"));
        createBDAction->setFont(font);
        DropDBAction = new QAction(MainWindow);
        DropDBAction->setObjectName(QString::fromUtf8("DropDBAction"));
        DropDBAction->setFont(font);
        actAction = new QAction(MainWindow);
        actAction->setObjectName(QString::fromUtf8("actAction"));
        actAction->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        createUser_pushButton = new QPushButton(centralWidget);
        createUser_pushButton->setObjectName(QString::fromUtf8("createUser_pushButton"));
        createUser_pushButton->setGeometry(QRect(1430, 820, 93, 28));
        authorization_pushButton = new QPushButton(centralWidget);
        authorization_pushButton->setObjectName(QString::fromUtf8("authorization_pushButton"));
        authorization_pushButton->setGeometry(QRect(1430, 790, 93, 28));
        alterTable_pushButton = new QPushButton(centralWidget);
        alterTable_pushButton->setObjectName(QString::fromUtf8("alterTable_pushButton"));
        alterTable_pushButton->setGeometry(QRect(1430, 640, 93, 28));
        select_pushButton = new QPushButton(centralWidget);
        select_pushButton->setObjectName(QString::fromUtf8("select_pushButton"));
        select_pushButton->setGeometry(QRect(1430, 730, 93, 28));
        update_pushButton = new QPushButton(centralWidget);
        update_pushButton->setObjectName(QString::fromUtf8("update_pushButton"));
        update_pushButton->setGeometry(QRect(1430, 670, 93, 28));
        insert_pushButton = new QPushButton(centralWidget);
        insert_pushButton->setObjectName(QString::fromUtf8("insert_pushButton"));
        insert_pushButton->setGeometry(QRect(1430, 760, 93, 28));
        createTable_pushButton = new QPushButton(centralWidget);
        createTable_pushButton->setObjectName(QString::fromUtf8("createTable_pushButton"));
        createTable_pushButton->setGeometry(QRect(1430, 810, 93, 28));
        dropTable_pushButton = new QPushButton(centralWidget);
        dropTable_pushButton->setObjectName(QString::fromUtf8("dropTable_pushButton"));
        dropTable_pushButton->setGeometry(QRect(1430, 610, 93, 28));
        delete_pushButton = new QPushButton(centralWidget);
        delete_pushButton->setObjectName(QString::fromUtf8("delete_pushButton"));
        delete_pushButton->setGeometry(QRect(1430, 700, 93, 28));
        view_ = new QTableView(centralWidget);
        view_->setObjectName(QString::fromUtf8("view_"));
        view_->setGeometry(QRect(320, 550, 1271, 331));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Arial"));
        font1.setPointSize(10);
        view_->setFont(font1);
        view_->setStyleSheet(QString::fromUtf8("QTableView {  \n"
"        background: rgb(57, 58, 60);\n"
"        gridline-color: rgb(60, 60, 60);\n"
"        border:2px solid rgb(20, 128, 211);\n"
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
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(323, 3, 1271, 541));
        textEdit->setFont(font1);
        textEdit->setStyleSheet(QString::fromUtf8("background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"color: white;\n"
"\n"
""));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1440, 850, 80, 18));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1340, 850, 80, 18));
        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setGeometry(QRect(10, 0, 301, 881));
        treeView->setStyleSheet(QString::fromUtf8("\n"
"QTreeView{\n"
"\n"
"background: rgb(68, 69, 73);\n"
"border-radius:4px;\n"
"border:2px solid rgb(20, 128, 211);\n"
"\n"
"\n"
"color:rgb(255,255,255);\n"
"\n"
"font-size:20px;\n"
"\n"
"}\n"
"\n"
"QTreeView::item{\n"
"\n"
"height:35px;\n"
"\n"
"}\n"
"\n"
"QTreeView::item:hover{\n"
"\n"
"background:transparent;\n"
"\n"
"color:rgb(19,154,230);\n"
"\n"
"}\n"
"\n"
"QTreeView::item:selected{\n"
"\n"
"color:rgb(255,255,255);\n"
"\n"
"background-color:rgba(3,155,252,50);\n"
"\n"
"border-radius:4px;\n"
"\n"
"}\n"
"\n"
"QTreeView QHeaderView::section{\n"
"\n"
"background:transparent;\n"
"\n"
"height:0px;\n"
"\n"
"}\n"
"\n"
"QTreeView::branch:has-siblings:!adjoins-item {\n"
"\n"
" }\n"
"\n"
" QTreeView::branch:has-siblings:adjoins-item {\n"
"\n"
" }\n"
"\n"
"  QTreeView::branch:!has-children:!has-siblings:adjoins-item {\n"
"\n"
" }\n"
"\n"
" QTreeView::branch:has-children:!has-siblings:closed,\n"
"\n"
" QTreeView::branch:closed:has-children:has-siblings {\n"
"\n"
"         border-image: none;\n"
" }\n"
"\n"
" QTreeVi"
                        "ew::branch:open:has-children:!has-siblings,\n"
"\n"
" QTreeView::branch:open:has-children:has-siblings  {\n"
"\n"
"         border-image: none;\n"
" }\n"
""));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(790, 130, 80, 18));
        MainWindow->setCentralWidget(centralWidget);
        pushButton_3->raise();
        pushButton->raise();
        pushButton_2->raise();
        createTable_pushButton->raise();
        createUser_pushButton->raise();
        authorization_pushButton->raise();
        alterTable_pushButton->raise();
        select_pushButton->raise();
        update_pushButton->raise();
        insert_pushButton->raise();
        dropTable_pushButton->raise();
        delete_pushButton->raise();
        view_->raise();
        textEdit->raise();
        treeView->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1600, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMinimumSize(QSize(1600, 70));
        mainToolBar->setMaximumSize(QSize(1600, 70));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\271\274\345\234\206"));
        font2.setPointSize(9);
        mainToolBar->setFont(font2);
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

        mainToolBar->addAction(createBDAction);
        mainToolBar->addAction(DropDBAction);
        mainToolBar->addAction(createAction);
        mainToolBar->addAction(dropAction);
        mainToolBar->addAction(alterAction);
        mainToolBar->addAction(creatUserAction);
        mainToolBar->addAction(authorityAction);
        mainToolBar->addAction(deleteAction);
        mainToolBar->addAction(selectAction);
        mainToolBar->addAction(updateAction);
        mainToolBar->addAction(insertAction);
        mainToolBar->addAction(actAction);

        retranslateUi(MainWindow);
        QObject::connect(creatUserAction, SIGNAL(triggered()), createUser_pushButton, SLOT(click()));
        QObject::connect(alterAction, SIGNAL(triggered()), alterTable_pushButton, SLOT(click()));
        QObject::connect(dropAction, SIGNAL(triggered()), dropTable_pushButton, SLOT(click()));
        QObject::connect(authorityAction, SIGNAL(triggered()), authorization_pushButton, SLOT(click()));
        QObject::connect(deleteAction, SIGNAL(triggered()), delete_pushButton, SLOT(click()));
        QObject::connect(selectAction, SIGNAL(triggered()), select_pushButton, SLOT(click()));
        QObject::connect(updateAction, SIGNAL(triggered()), update_pushButton, SLOT(click()));
        QObject::connect(insertAction, SIGNAL(triggered()), insert_pushButton, SLOT(click()));
        QObject::connect(createAction, SIGNAL(triggered()), createTable_pushButton, SLOT(click()));
        QObject::connect(createBDAction, SIGNAL(triggered()), pushButton, SLOT(click()));
        QObject::connect(DropDBAction, SIGNAL(triggered()), pushButton_2, SLOT(click()));
        QObject::connect(actAction, SIGNAL(triggered()), pushButton_3, SLOT(click()));

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
        createBDAction->setText(QCoreApplication::translate("MainWindow", "\346\226\260\345\273\272\346\225\260\346\215\256\345\272\223", nullptr));
        DropDBAction->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\346\225\260\346\215\256\345\272\223", nullptr));
        actAction->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214", nullptr));
        createUser_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\347\224\250\346\210\267", nullptr));
        authorization_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\235\203\351\231\220\347\256\241\347\220\206", nullptr));
        alterTable_pushButton->setText(QCoreApplication::translate("MainWindow", "\344\277\256\346\224\271\350\241\250\347\273\223\346\236\204", nullptr));
        select_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\237\245\350\257\242", nullptr));
        update_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\233\264\346\226\260", nullptr));
        insert_pushButton->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245", nullptr));
        createTable_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\210\233\345\273\272\350\241\250", nullptr));
        dropTable_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244\350\241\250", nullptr));
        delete_pushButton->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
