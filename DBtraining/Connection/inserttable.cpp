#include "inserttable.h"
#include "ui_inserttable.h"

insertTable::insertTable(Function* fun,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::insertTable)
{
    ui->setupUi(this);
    fun_=fun;
}

insertTable::~insertTable()
{
    delete ui;
}

void insertTable::on_pushButton_clicked()
{
    QString tableName=ui->lineEdit->text();
    QString value=ui->lineEdit_2->text();
    qDebug(qPrintable(tableName+"|"+value+"|"));
    QString status=fun_->insert(tableName,value);
    qDebug()<<"hello";
    //qDebug(qPrintable(status));
    sendData(status);
}

void insertTable::on_pushButton_2_clicked()
{
    this->close();
}


