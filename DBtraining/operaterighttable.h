#ifndef OPERATERIGHTTABLE_H
#define OPERATERIGHTTABLE_H

#include <QWidget>
#include"function.h"

namespace Ui {
class OperateRightTable;
}

class OperateRightTable : public QWidget
{
    Q_OBJECT

public:
    explicit OperateRightTable(Function* fun,QWidget *parent = 0);
    ~OperateRightTable();

private:
    Ui::OperateRightTable *ui;
    Function* fun_;
signals:
    void sendData(QString);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // OPERATERIGHTTABLE_H
