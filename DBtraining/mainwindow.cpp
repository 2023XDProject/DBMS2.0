#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"select.h"
#include"updatetable.h"
#include"deleteTable.h"

#include"iostream"
#include"qdebug.h"
#include"qdir.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    server=new QTcpServer;

    server->listen(QHostAddress::AnyIPv4,PORT);
    connect(server,&QTcpServer::newConnection,this,&MainWindow::newClientHandle);

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
    delete model_;
    delete item_;
    //delete view_;
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
        QFile userFile(rootAddress+"\\user.txt");
        if(!userFile.open(QIODevice::ReadOnly|QIODevice::Text))
            qDebug()<<"文件打开失败";
        qDebug(qPrintable(InfoList[1]));
        QString InfoCheck;
        QTextStream InfoIn(&userFile);
        bool checkInfo=false;
        while(!InfoIn.atEnd())
        {
            InfoIn>>InfoCheck;
            qDebug(qPrintable(InfoCheck));
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
        QFile rightfile(rootAddress+"//right.txt");
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
                socket->write(ba.append(insert(valueList[0],valueList[1])));
            }
            else if(secondInfoList[2]=="update")
            {
                qDebug()<<"update";
                QByteArray ba;
                QStringList valueList=InfoList[1].split("%",QString::SkipEmptyParts);
                socket->write(ba.append(update_function(valueList[0],valueList[1],valueList[2])));
            }
            else if(secondInfoList[2]=="delete")
            {
                qDebug()<<"delete";
                QByteArray ba;
                QStringList valueList=InfoList[1].split("%",QString::SkipEmptyParts);
                socket->write(ba.append(delete_function(valueList[0],valueList[1])));
            }
            else if(secondInfoList[2]=="select")
            {
                qDebug()<<"select";
                QByteArray ba;
                QStringList valueList=InfoList[1].split("%");
                QString result=select(valueList[0],valueList[1],valueList[2],valueList[3]);
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
                socket->write(ba.append(AlterTable(valueList[0],valueList[1],valueList[2],valueList[3])));
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
    //    this->hide();
    Select *selectWindow = new Select;
    selectWindow->show();//updateItemInfo()
    //    connect(selectWindow,SIGNAL(sendsignal()), this,SLOT(reshow()));
    //connect(selectWindow, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    connect(selectWindow, SIGNAL(sendData(QString)), this, SLOT(receiveTable(QString)));
}

//更新记录
void MainWindow::on_update_pushButton_clicked()
{
    //    this->hide();
    updateTable *updateWindow = new updateTable;
    updateWindow->show();
    //    connect(updateWindow,SIGNAL(sendsignal()), this,SLOT(reshow()));
    //connect(updateWindow, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    connect(updateWindow, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//删除数据
void MainWindow::on_delete_pushButton_clicked()
{
    //    this->hide();
    deleteTable *deleteWindow = new deleteTable;
    deleteWindow->show();
    //    connect(deleteWindow,SIGNAL(sendsignal()), this,SLOT(reshow()));
    //connect(deleteWindow, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    connect(deleteWindow, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//插入数据
void MainWindow::on_insert_pushButton_clicked()
{
    insertTable *i=new insertTable;
    i->show();
    //connect(i, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    connect(i, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//修改表
void MainWindow::on_alterTable_pushButton_clicked()
{
    alterTable *a=new alterTable;
    a->show();
    //connect(a, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    connect(a, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//创建用户
void MainWindow::on_createUser_pushButton_clicked()
{
    createUserTable *c=new createUserTable;
    c->show();
    //connect(c, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    connect(c, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//用户权限
void MainWindow::on_authorization_pushButton_clicked()
{
    OperateRightTable *o=new OperateRightTable;
    o->show();
    //connect(o, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    connect(o, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//建表
void MainWindow::on_createTable_pushButton_clicked()
{
    CreateTableW *c=new CreateTableW;
    c->show();
    // connect(c, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    connect(c, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

//删除表
void MainWindow::on_dropTable_pushButton_clicked()
{
    DropTable *d=new DropTable;
    d->show();
    //connect(d, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    connect(d, SIGNAL(sendData(QString)), this, SLOT(isFinish(QString)));
}

void MainWindow::isFinish(QString data){
    if(!data.contains(".")&&!data.isEmpty()){
        QMessageBox tempBox(QMessageBox::Information,"消息","<font size='12' color='white'>"+data,QMessageBox::Ok);

        tempBox.setStyleSheet("QMessageBox{background: rgb(50, 50, 50);}");
        tempBox.exec();

        QFile resultFile("D:\\temp\\DBMS_BJTU_2022-main\\project1-dbms\\result.txt");
        if(!resultFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }

        resultFile.remove();
    }
}

//更新工具栏
void MainWindow::updateToolBar(){
    //工具栏（只可上方停靠，不可移动）
    toolbar = new QToolBar(this);
    toolbar->setIconSize(QSize(100,100));
    toolbar->setAllowedAreas(Qt::TopToolBarArea);
    toolbar->setFixedHeight(80);
    toolbar->setMovable(false);

    //新建表
    //QIcon CreateDBIcon=QIcon("../untitled/Icon/createDB_icon.jpg");
    btn1= new QToolButton(toolbar);
    btn1->setIconSize(QSize(20,20));//为什么没用呢
    //btn1->setIcon(CreateDBIcon);
    btn1->setFixedSize(70,70);
    btn1->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn1->setText(QString::fromLocal8Bit("新建表"));
    toolbar->addWidget(btn1);
    toolbar->addSeparator();
    //connect(btn1, SIGNAL(clicked(bool)), this, SLOT(createDB()));

    //删除表
    //QIcon enquiryIcon=QIcon("../untitled/Icon/enquiry_icon.jpg");
    btn2= new QToolButton(toolbar);
    btn2->setIconSize(QSize(20,20));
    //btn2->setIcon(enquiryIcon);
    btn2->setFixedSize(70,70);
    btn2->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn2->setText(QString::fromLocal8Bit("删除表"));
    toolbar->addWidget(btn2);
    toolbar->addSeparator();
    //connect(btn2, SIGNAL(clicked(bool)), this, SLOT(createEnquiry()));

    //修改表
    //QIcon enquiryIcon=QIcon("../untitled/Icon/enquiry_icon.jpg");
    btn9= new QToolButton(toolbar);
    btn9->setIconSize(QSize(20,20));
    //btn2->setIcon(enquiryIcon);
    btn9->setFixedSize(70,70);
    btn9->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn9->setText(QString::fromLocal8Bit("修改表"));
    toolbar->addWidget(btn9);
    toolbar->addSeparator();
    //connect(btn2, SIGNAL(clicked(bool)), this, SLOT(createEnquiry()));

    //新建用户
    //QIcon createUserIcon=QIcon("../untitled/Icon/createUser_icon.jpg");
    btn3= new QToolButton(toolbar);
    btn3->setIconSize(QSize(20,20));
    //btn3->setIcon(createUserIcon);
    btn3->setFixedSize(70,70);
    btn3->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn3->setText(QString::fromLocal8Bit("新建用户" ));
    toolbar->addWidget(btn3);
    toolbar->addSeparator();
    //connect(btn3, SIGNAL(clicked(bool)), this, SLOT(createUser()));

    //权限管理
    //QIcon loginIcon=QIcon("../untitled/Icon/login_icon.jpg");
    btn4= new QToolButton(toolbar);
    btn4->setIconSize(QSize(20,20));
    //btn4->setIcon(loginIcon);
    btn4->setFixedSize(70,70);
    btn4->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn4->setText(QString::fromLocal8Bit("权限管理" ));
    toolbar->addWidget(btn4);
    toolbar->addSeparator();
    //connect(btn4, SIGNAL(clicked(bool)), this, SLOT(login()));

    //删除记录
    //QIcon runIcon=QIcon("../untitled/Icon/run_icon.jpg");
    btn5= new QToolButton(toolbar);
    btn5->setIconSize(QSize(20,20));
    //btn5->setIcon(runIcon);
    btn5->setFixedSize(70,70);
    btn5->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn5->setText(QString::fromLocal8Bit("删除记录" ));
    toolbar->addWidget(btn5);
    toolbar->addSeparator();
    //connect(btn5, SIGNAL(clicked(bool)), this, SLOT(run()));

    //查询记录
    //QIcon runIcon=QIcon("../untitled/Icon/run_icon.jpg");
    btn6= new QToolButton(toolbar);
    btn6->setIconSize(QSize(20,20));
    //btn5->setIcon(runIcon);
    btn6->setFixedSize(70,70);
    btn6->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn6->setText(QString::fromLocal8Bit("查询记录" ));
    toolbar->addWidget(btn6);
    toolbar->addSeparator();
    //connect(btn5, SIGNAL(clicked(bool)), this, SLOT(run()));

    //更新记录
    //QIcon runIcon=QIcon("../untitled/Icon/run_icon.jpg");
    btn7= new QToolButton(toolbar);
    btn7->setIconSize(QSize(20,20));
    //btn5->setIcon(runIcon);
    btn7->setFixedSize(70,70);
    btn7->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn7->setText(QString::fromLocal8Bit("更新记录" ));
    toolbar->addWidget(btn7);
    toolbar->addSeparator();
    //connect(btn5, SIGNAL(clicked(bool)), this, SLOT(run()));

    //插入记录
    //QIcon runIcon=QIcon("../untitled/Icon/run_icon.jpg");
    btn8= new QToolButton(toolbar);
    btn8->setIconSize(QSize(20,20));
    //btn5->setIcon(runIcon);
    btn8->setFixedSize(70,70);
    btn8->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    btn8->setText(QString::fromLocal8Bit("插入记录" ));
    toolbar->addWidget(btn8);
    toolbar->addSeparator();
    //connect(btn5, SIGNAL(clicked(bool)), this, SLOT(run()));

    this->addToolBar(toolbar);
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

        resultFile.remove();
    }
    else{
        //查询失败
        reShowTable(data);
    }
}

////更新左侧连接信息(未完成)
//void MainWindow::updateItemInfo(){
//    delete Dock1_,treeView_;
//    Dock1_ = new QDockWidget(this);
//    Dock1_->setAllowedAreas(Qt::LeftDockWidgetArea);

//    //导入模型
//    treeView_= new QTreeView();
//    QStandardItemModel *model = new QStandardItemModel(treeView_);//创建模型
//    treeView_->setModel(model);
//    if (!dirinfo_->exists()) {
//        delete dirinfo_, dirinfo_ = nullptr;
//        return;
//    }

//    QStringList dirList = dirinfo_->entryList(QDir::Dirs);
//    dirList.removeOne(".");
//    dirList.removeOne("..");
//    for(int i=0;i<dirList.size();++i)
//    {
//        qDebug()<<dirList[i];
//        QStandardItem *item = new QStandardItem(dirList[i]);
//        QString temp=dirList[i];
//        QDir* dirinfo2 = new QDir("data/"+temp);
//        if (!dirinfo2->exists()) {
//            delete dirinfo2, dirinfo2 = nullptr;
//            return;
//        }

//        //dirinfo->setNameFilters(QStringList("*.png"));过滤器
//        QStringList fileList = dirinfo2->entryList(QDir::Files);
//        fileList.removeOne(".");
//        fileList.removeOne("..");

//        for(int j=0;j<fileList.size();++j){
//            qDebug()<<fileList[j];
//            item->appendRow(new QStandardItem(fileList[j]));
//        }
//        model->appendRow(item);
//    }

//    Dock1_->setWidget(treeView_);
//    addDockWidget(Qt::LeftDockWidgetArea,Dock1_);
//}

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
