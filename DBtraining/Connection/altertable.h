#ifndef ALTERTABLE_H
#define ALTERTABLE_H

#include <QWidget>
#include "function.h"

namespace Ui {
class alterTable;
}

class alterTable : public QWidget
{
    Q_OBJECT

public:
    explicit alterTable(Function* fun,QWidget *parent = 0);
    ~alterTable();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::alterTable *ui;
    Function* fun_;

signals:
    void sendData(QString);
};

#endif // ALTERTABLE_H
