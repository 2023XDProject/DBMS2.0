#ifndef CREATETABLEW_H
#define CREATETABLEW_H

#include <QWidget>
#include "function.h"

namespace Ui {
class CreateTableW;
}

class CreateTableW : public QWidget
{
    Q_OBJECT

public:
    explicit CreateTableW(Function* fun,QWidget *parent = 0);
    ~CreateTableW();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreateTableW *ui;
    Function* fun_;

signals:
    void sendData(QString);
};

#endif // CREATETABLEW_H
