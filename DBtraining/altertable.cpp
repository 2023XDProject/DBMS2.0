#include "altertable.h"
#include "ui_altertable.h"

alterTable::alterTable(Function* fun,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::alterTable)
{
    ui->setupUi(this);
    fun_=fun;
}

alterTable::~alterTable()
{
    delete ui;
}

void alterTable::on_pushButton_clicked()
{
    QString operate=ui->line_operate->text();
    QString table=ui->line_table->text();
    QString column=ui->line_column->text();
    QString dataType=ui->line_dataType->text();
    QString newcolum=ui->line_newColumn->text();
    QString newtype=ui->line_newType->text();
    sendData(fun_->AlterTable(operate,table,column,dataType,newcolum,newtype));
    //OperateRights()
}

void alterTable::on_pushButton_2_clicked()
{
    this->close();
}
