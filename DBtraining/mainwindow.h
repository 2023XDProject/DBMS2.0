#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QToolButton>
#include <QTreeView>
#include <QDir>
#include <QStandardItemModel>
#include <QTableView>
#include"select.h"
#include"deleteTable.h"
#include"inserttable.h"
#include"function.h"
#include"altertable.h"
#include "updatetable.h"
#include"createusertable.h"
#include"operaterighttable.h"
#include"createtablew.h"
#include"droptable.h"
#include<QTcpServer>
#include<QTcpSocket>
#define PORT 8000

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    QTcpServer *server;
    //QString rootAddress="D:\\temp\\DBMS_BJTU_2022-main\\project1-dbms";
    QString rootAddress_;
    QTcpSocket *socket;

    void sendStringData();
    void setActionStyle();

private slots:
    void on_select_pushButton_clicked();

    void on_update_pushButton_clicked();

    void on_delete_pushButton_clicked();

    void newClientHandle();

    void clientInfoSlot();

    void on_insert_pushButton_clicked();

    void on_alterTable_pushButton_clicked();

    void on_createUser_pushButton_clicked();

    void on_authorization_pushButton_clicked();

    void on_createTable_pushButton_clicked();

    void on_dropTable_pushButton_clicked();

    void reShowTable(QString data);//更新表格



public slots:
    void reshow();
    void isFinish(QString data);//接收传递过来的(操作是否完成)数据的槽
    void receiveTable(QString data);   //接收传递过来的数据的槽
    //    void readFile(QString filePath);

private:
    Ui::MainWindow *ui;
    //工具栏组件
    QToolBar * toolbar;
    QToolButton * btn1,* btn2,* btn3,* btn4,* btn5;
    QToolButton * btn6,* btn7,* btn8,* btn9,* btn10;
    //左侧组件
    QDockWidget* Dock1_;
    QTreeView *treeView_;
    QDir* dirinfo_;
    QStandardItemModel *model_;
    QStandardItem *item_;

    Function *fun_;

    //其他窗口
    Select *selectWindow_;
    updateTable *updateWindow_;
    deleteTable *deleteWindow_;
    insertTable *insertTable_;
    alterTable *alterTable_;
    createUserTable *createUserTable_;
    OperateRightTable *opereteRightTable_;
        CreateTableW *createTableW_;
            DropTable *dropTable_;
    //QTableView  *view_;
};

#endif // MAINWINDOW_H
