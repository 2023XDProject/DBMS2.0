#ifndef CREATEDB_H
#define CREATEDB_H

#include <QWidget>
#include "function.h"

namespace Ui {
class createDB;
}

class CreateDB : public QWidget
{
    Q_OBJECT

public:
    explicit CreateDB(Function* fun,QWidget *parent = nullptr);
    ~CreateDB();

signals:
    void sendData(QString);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::createDB *ui;
    Function* fun_;
};

#endif // CREATEDB_H
