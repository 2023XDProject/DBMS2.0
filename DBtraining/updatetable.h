#ifndef UPDATETABLE_H
#define UPDATETABLE_H

#include <QWidget>
#include"function.h"

namespace Ui {
class updateTable;
}

class updateTable : public QWidget
{
    Q_OBJECT

public:
    explicit updateTable(Function* fun,QWidget *parent = nullptr);
    ~updateTable();

    QString table_name;
    QString set;
    QString where;

private slots:
    void on_update_pushButton_clicked();

    void on_back_pushButton_clicked();

private:
    Ui::updateTable *ui;
    Function* fun_;

signals:
    void sendsignal();//这个函数用户向主界面通知关闭的消息

    void sendData(QString);   //用来传递数据的信号

};

#endif // UPDATETABLE_H
