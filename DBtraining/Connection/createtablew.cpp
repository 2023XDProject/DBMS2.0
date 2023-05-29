#include "createtablew.h"
#include "ui_createtablew.h"

CreateTableW::CreateTableW(Function* fun,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateTableW)
{
    ui->setupUi(this);
    fun_=fun;
}

CreateTableW::~CreateTableW()
{
    delete ui;
}

void CreateTableW::on_pushButton_clicked()
{
    QString m = ui->lineEdit->text(); //获取行编辑器内容
    QString n = ui->textEdit->toPlainText();//获取文本编辑器内容
    sendData(fun_->CreateTables(m,n));
}

void CreateTableW::on_pushButton_2_clicked()
{
    this->close();
}

