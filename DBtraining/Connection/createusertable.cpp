#include "createusertable.h"
#include "ui_createusertable.h"

createUserTable::createUserTable(Function* fun,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::createUserTable)
{
    ui->setupUi(this);
    fun_=fun;
}

createUserTable::~createUserTable()
{
    delete ui;
}

void createUserTable::on_pushButton_clicked()
{
    QString userName=ui->userName->text();
    QString pwd=ui->pwd->text();

    sendData(fun_->CreateUsers(userName,pwd));
}

void createUserTable::on_pushButton_2_clicked()
{
    this->close();
}

