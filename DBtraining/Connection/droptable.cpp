#include "droptable.h"
#include "ui_droptable.h"

DropTable::DropTable(Function* fun,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DropTable)
{
    ui->setupUi(this);
    fun_=fun;
}

DropTable::~DropTable()
{
    delete ui;
}

void DropTable::on_pushButton_clicked()
{
    QString table=ui->lineEdit->text();
    sendData(fun_->DropTables(table));
}

void DropTable::on_pushButton_2_clicked()
{
    this->close();
}

