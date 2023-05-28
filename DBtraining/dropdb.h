#ifndef DROPDB_H
#define DROPDB_H

#include <QWidget>
#include "function.h"

namespace Ui {
class dropDB;
}

class dropDB : public QWidget
{
    Q_OBJECT

public:
    explicit dropDB(Function* fun_,QWidget *parent = nullptr);
    ~dropDB();

signals:
    void sendData(QString);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::dropDB *ui;
    Function* fun_;
};

#endif // DROPDB_H
