#include "dropdb.h"
#include "ui_dropdb.h"

dropDB::dropDB(Function* fun,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dropDB)
{
    fun_=fun;
    ui->setupUi(this);
}

dropDB::~dropDB()
{
    delete ui;
}

void dropDB::on_pushButton_clicked()
{
    QString m = ui->lineEdit->text(); //获取行编辑器内容
    sendData(fun_->DropDB(m));
}


void dropDB::on_pushButton_2_clicked()
{
    this->close();
}

