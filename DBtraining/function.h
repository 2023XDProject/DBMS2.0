#ifndef FUNCTION_H
#define FUNCTION_H
#include"QString"
#include "qwidget.h"
#include <QCoreApplication>
#include<QDebug>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QString>
#include <QSet>
#include<QList>
#include<QMap>
#include<QStack>
#include<QDir>
#include <QDataStream>


class Function: public QObject
{
    Q_OBJECT
private:
    //QString rootAddress = "D:\\temp\\DBMS_BJTU_2022-main\\project1-dbms";
    QString rootAddress_;
    QString DBName_="Ruanko";

public:
    Function();

    QStringList WriteContent(QStringList tableList);

    bool simplyConditionJudge(QString condition,QString data,QMap<QString,int>projection,QMap<QString,QString>dataTypeProjection);

    bool JudgeCondition(QString conditionList,QString data,QMap<QString,int>projection,QMap<QString,QString>dataTypeProjection);

    int Cmp(QString s1,QString s2,QString key,QMap<QString,int>projection,QMap<QString,QString>dataTypeProjection);

    QString select(QString attribute,QString table,QString condition,QString order);

    QString rewriteFile(QString file_addr,QString target_tableName);

    QString delete_function(QString table,QString condition);

    QString update_function(QString table,QString set,QString condition);

    //QString primarykey(QStringList set_KeyValue,QString table);
    QString primarykey(QMap<QString,int> projection,QString table,QString file_addr);

    QString foreignkey(QStringList set_KeyValue,QString table);

    QString referenceConstraints(QString table);

    QString insert(QString tableName,QString value);

    QString AlterTable(QString operate,QString tableName,QString columnname,QString Datatype);

    QString CreateUsers(QString userName,QString password);

    QString OperateRights(QString operate,QString userName,QString tableName,QString right);

    QString CreateTables(QString tableName,QString content);

    QString DropTables(QString tableName);

    QString CreateDB(QString DBName);

    QString DropDB(QString DBName);

    //删除文件夹
    bool dropFloder(const QString strFilePath);
};

#endif // FUNCTION_H
