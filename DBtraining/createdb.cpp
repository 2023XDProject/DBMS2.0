#include "createdb.h"
#include "ui_createdb.h"

CreateDB::CreateDB(Function* fun,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createDB)
{
    fun_=fun;
    ui->setupUi(this);
}

CreateDB::~CreateDB()
{
    delete ui;
}

void CreateDB::on_pushButton_clicked()
{
    QString m = ui->lineEdit->text(); //获取行编辑器内容
    sendData(fun_->CreateDB(m));
}


void CreateDB::on_pushButton_2_clicked()
{
    this->close();
}

