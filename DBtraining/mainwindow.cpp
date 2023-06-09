#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),fun_(new Function()),selectWindow_(new Select(fun_)),
    updateWindow_(new updateTable(fun_)),deleteWindow_(new deleteTable(fun_)),
    insertTable_(new insertTable(fun_)),alterTable_(new alterTable(fun_)),
    createUserTable_(new createUserTable(fun_)),opereteRightTable_(new OperateRightTable(fun_)),
    createTableW_(new CreateTableW(fun_)),dropTable_(new DropTable(fun_)),
    createDB_(new CreateDB(fun_)),dropDB_(new dropDB(fun_)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //获取绝对路径
    QDir *dir =new QDir(QDir::currentPath());
    dir->cdUp();
    rootAddress_=dir->path().replace(QString("/"),QString("\\"))+"\\data";

    dirinfo_=new QDir(rootAddress_),
            updateItemInfo();
    server=new QTcpServer;
    server->listen(QHostAddress::AnyIPv4,PORT);
    connect(server,&QTcpServer::newConnection,this,&MainWindow::newClientHandle);
    //connect(fun_,SIGNAL(matchSqlType(QString)),this,SLOT(isFinish(QString)));
    connect(fun_,SIGNAL(sendData(QString)),this,SLOT(isFinish(QString)));
    connect(fun_,SIGNAL(sendTable(QString)),this,SLOT(receiveTable(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete toolbar;
    delete btn1,btn2,btn3,btn4,btn5;
    delete btn6,btn7,btn8,btn9,btn10;
    delete Dock1_;
    delete treeView_;
    delete dirinfo_;
    delete model_,model2_;
    delete item_;
    delete fun_;
    delete selectWindow_,updateWindow_,deleteWindow_;
    delete insertTable_,alterTable_,createUserTable_;
    delete opereteRightTable_,createTableW_,dropTable_;
    delete createDB_,dropDB_;
}

void MainWindow::newClientHandle()
{
    socket=server->nextPendingConnection();
    connect(socket,&QTcpSocket::readyRead,this,&MainWindow::clientInfoSlot);
}

//客户端连接
void MainWindow::clientInfoSlot()
{
    QString Info=QString(socket->readAll());
    QStringList InfoList;
    if(Info[0]=="L")
    {
        InfoList=Info.split("%",QString::SkipEmptyParts);
        QFile userFile(rootAddress_+"\\user.txt");
        if(!userFile.open(QIODevice::ReadOnly|QIODevice::Text))
            qDebug()<<"文件打开失败";
        qDebug(qPrintable(InfoList[1]));
        QString InfoCheck;
        QTextStream InfoIn(&userFile);
        bool checkInfo=false;
        while(!InfoIn.atEnd())
        {
            InfoIn>>InfoCheck;
            //qDebug(qPrintable(InfoCheck));
            if(InfoCheck==InfoList[1])
            {
                checkInfo=true;
                break;
            }
        }
        QByteArray ba;
        if(checkInfo)
        {ba.append("correct");
            qDebug()<<"right";}
        else ba.append("wrong");
        socket->write(ba);
        userFile.close();
    }
    else
    {
        InfoList=Info.split("|",QString::SkipEmptyParts);
        qDebug()<<"wula";
        qDebug("%s",qPrintable(Info));
        QString secondInfo=InfoList[0];
        QStringList secondInfoList=secondInfo.split("%",QString::SkipEmptyParts);
        QString table=secondInfoList[1];
        QStringList tableList=table.split(",",QString::SkipEmptyParts);
        QFile rightfile(rootAddress_+"//right.txt");
        if(!rightfile.open(QIODevice::ReadOnly|QIODevice::Text))
            qDebug()<<"open failed";
        QTextStream in(&rightfile);
        QSet<QString> rightSet;
        while(!in.atEnd())
        {
            QString s;
            in>>s;
            rightSet.insert(s);

        }
        bool HaveRight=true;
        foreach(QString rightTable,tableList)
        {
            QString right=secondInfoList[0]+"%"+rightTable+"%"+secondInfoList[2];
            if(!rightSet.contains(right))
            {
                HaveRight=false;
                break;
            }
        }
        if(!HaveRight)
        {
            QByteArray ba;
            socket->write(ba.append("NoRight"));
            return;
        }
        else
        {
            if(secondInfoList[2]=="insert")
            {
                qDebug()<<"insert";
                QByteArray ba;
                QStringList valueList=InfoList[1].split("%",QString::SkipEmptyParts);
                socket->write(ba.append(fun_->insert(valueList[0],valueList[1])));
            }
            else if(secondInfoList[2]=="update")
            {
                qDebug()<<"update";
                QByteArray ba;
                QStringList valueList=InfoList[1].split("%",QString::SkipEmptyParts);
                socket->write(ba.append(fun_->update_function(valueList[0],valueList[1],valueList[2])));
            }
            else if(secondInfoList[2]=="delete")
            {
                qDebug()<<"delete";
                QByteArray ba;
                QStringList valueList=InfoList[1].split("%",QString::SkipEmptyParts);
                socket->write(ba.append(fun_->delete_function(valueList[0],valueList[1])));
            }
            else if(secondInfoList[2]=="select")
            {
                qDebug()<<"select";
                QByteArray ba;
                QStringList valueList=InfoList[1].split("%");
                QString result=fun_->select(valueList[0],valueList[1],valueList[2],valueList[3]);
                QString returnResult="";
                QFile resultFile(result);
                qDebug("%s",qPrintable(result));
                if(!resultFile.open(QIODevice::ReadOnly|QIODevice::Text))
                    qDebug()<<"open Wrong";
                QTextStream resultIn(&resultFile);
                while(!resultIn.atEnd())
                {
                    QString tmpString;
                    resultIn>>tmpString;
                    if(tmpString=="")break;
                    returnResult+=tmpString+"#";
                }
                ba.append(returnResult);
                socket->write(ba);
                resultFile.close();
                resultFile.remove();
            }
            else
            {
                qDebug()<<"alter";
                QByteArray ba;
                QStringList valueList=InfoList[1].split("%",QString::SkipEmptyParts);
                //socket->write(ba.append(fun_->AlterTable(valueList[0],valueList[1],valueList[2],valueList[3],"")));
            }
        }
    }

}

void MainWindow::reshow(){
    this->show();
}

//查询数据
void MainWindow::on_select_pushButton_clicked()
{
    selectWindow_->show();//updateItemInfo()
    connect(selectWindow_, SIGNAL(sendData(QString)), this, SLOT(receiveTable(QString)));
}

//更新记录
void MainWindow::on_update_pushButton_clicked()
{
    updateWindow_->show();
    connect(updateWindow_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//删除数据
void MainWindow::on_delete_pushButton_clicked()
{
    deleteWindow_->show();
    connect(deleteWindow_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//插入数据
void MainWindow::on_insert_pushButton_clicked()
{
    insertTable_->show();
    connect(insertTable_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//修改表
void MainWindow::on_alterTable_pushButton_clicked()
{
    alterTable_->show();
    connect(alterTable_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//创建用户
void MainWindow::on_createUser_pushButton_clicked()
{
    createUserTable_->show();
    connect(createUserTable_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//用户权限
void MainWindow::on_authorization_pushButton_clicked()
{
    opereteRightTable_->show();
    connect(opereteRightTable_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//建表
void MainWindow::on_createTable_pushButton_clicked()
{
    createTableW_->show();
    connect(createTableW_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//删除表
void MainWindow::on_dropTable_pushButton_clicked()
{
    dropTable_->show();
    connect(dropTable_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//新建数据库
void MainWindow::on_pushButton_clicked()
{
    createDB_->show();
    connect(createDB_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
    qDebug()<<"新建数据库";
}

//删除数据库
void MainWindow::on_pushButton_2_clicked()
{
    dropDB_->show();
    connect(dropDB_, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
    qDebug()<<"删除数据库";
}


void MainWindow::isFinish(QString data){
    if(!data.contains(".")&&!data.isEmpty()){
        QMessageBox tempBox(QMessageBox::Information,"消息","<font size='12' color='white'>"+data,QMessageBox::Ok);

        tempBox.setStyleSheet("QMessageBox{background: rgb(50, 50, 50);}");
        tempBox.exec();

        QFile resultFile(rootAddress_+"\\result.txt");
        if(!resultFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }
        updateItemInfo();
        resultFile.remove();
    }
}



//接收传递过来的数据的槽
void MainWindow::receiveTable(QString data){
    qDebug("%s",qPrintable(data));
    //查询失败
    if(!data.contains(".")){
        //ui->textBrowser->setText(data);
        QMessageBox tempBox(QMessageBox::Information,"消息","<font size='12' color='white'>"+data,QMessageBox::Ok);

        tempBox.setStyleSheet("QMessageBox{background: rgb(50, 50, 50);\"}"
                              );
        tempBox.exec();

        QFile resultFile("D:\\temp\\DBMS_BJTU_2022-main\\project1-dbms\\result.txt");
        if(!resultFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }
        updateItemInfo();
        resultFile.remove();
    }
    else{
        //查询成功
        updateItemInfo();
        reShowTable(data);
    }
}

//更新左侧连接信息(完成)
void MainWindow::updateItemInfo(){

    //导入模型
    if(model2_!=nullptr){
        model2_=nullptr;
    }
    model2_ = new QStandardItemModel(ui->treeView);//创建模型
    if (!dirinfo_->exists()) {
        delete dirinfo_, dirinfo_ = nullptr;
        return;
    }

    QStringList dirList = dirinfo_->entryList(QDir::Dirs);
    dirList.removeOne(".");
    dirList.removeOne("..");
    for(int i=0;i<dirList.size();++i)
    {
        qDebug()<<dirList[i];
        QStandardItem *item = new QStandardItem(dirList[i]);
        QString temp=dirList[i];
        QDir* dirinfo2 = new QDir(rootAddress_+"\\"+temp);
        if (!dirinfo2->exists()) {
            delete dirinfo2, dirinfo2 = nullptr;
            return;
        }

        //dirinfo->setNameFilters(QStringList("*.png"));过滤器
        QStringList fileList = dirinfo2->entryList(QDir::Files);
        fileList.removeOne(".");
        fileList.removeOne("..");

        for(int j=0;j<fileList.size();++j){
            qDebug()<<fileList[j];
            item->appendRow(new QStandardItem(fileList[j]));
        }
        model2_->appendRow(item);
    }

    ui->treeView->setModel(model2_);
}

//更新表格
void MainWindow::reShowTable(QString data){
    //释放指针
    model_=nullptr;
    item_=nullptr;

    QString temp;
    QFile resultFile(data);
    if(!resultFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }
    //打开文件成功
    model_ = new QStandardItemModel(this);
    QStringList temp_column;
    QTextStream out(&resultFile);
    //QTextCursor tc = ui->textBrowser->textCursor();
    out >> temp;
    temp_column = temp.split("%");
    //属性
    temp_column.removeLast();
    model_->setHorizontalHeaderLabels(temp_column);
    int j=0;
    //从文件读取记录
    while(!out.atEnd()){
        out >> temp;
        if(temp==""){
            break;
        }
        temp_column = temp.split("%");
        for(int i=0;i<temp_column.size()-1;++i){
            item_ = new QStandardItem(temp_column.at(i));
            model_->setItem(j,i,item_);
        }
        ++j;
    }
    resultFile.close();
    resultFile.remove();
    ui->view_->setModel(model_);
}

void MainWindow::on_pushButton_3_clicked()
{
    QString text=ui->textEdit->toPlainText();
    //qDebug()<<text;
    if(text.isEmpty()){
        sendData("sql语句不能为空！");
    }else{
        fun_->matchSqlType(text);
    }
}
