#ifndef CREATEUSERTABLE_H
#define CREATEUSERTABLE_H

#include <QWidget>
#include"function.h"

namespace Ui {
class createUserTable;
}

class createUserTable : public QWidget
{
    Q_OBJECT

public:
    explicit createUserTable(Function* fun,QWidget *parent = 0);
    ~createUserTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::createUserTable *ui;
    Function* fun_;

signals:
    void sendData(QString);
};

#endif // CREATEUSERTABLE_H
