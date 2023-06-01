#include "function.h"

Function::Function(){
    QDir *dir =new QDir(QDir::currentPath());
    dir->cdUp();
    rootAddress_=dir->path().replace(QString("/"),QString("\\"))+"\\data";
}

QStringList Function::WriteContent(QStringList tableList)
{
    //创建并打开表文件
    QString s=tableList[0];
    QFile tmpFile(rootAddress_+"\\"+DBName_+"\\"+s+".txt");
    if(!tmpFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    //逐行读取，检查行是否为空
    QTextStream in(&tmpFile);
    QString str;
    in>>str;
    in>>str;
    in>>str;

    qDebug()<<tableList.size();

    QStringList content;

    //读记录
    if(tableList.size()==1)
    {//不为空
        while(!in.atEnd()){
            in >> str;
            if(str=="")break;
            qDebug() << str;
            content.append(str);
        }
        tmpFile.close();
        return content;
    }

    QStringList content2;
    QStringList tableList_1;
    for(int i=1;i<tableList.size();i++)
        tableList_1.append(tableList[i]);

    content=WriteContent(tableList_1);
    while(!in.atEnd())
    {
        in>>str;
        if(str=="")break;
        foreach(s,content)
        {
            QString newStr=str+"%"+s;
            content2.append(newStr);
        }
    }
    tmpFile.close();
    return content2;
}

bool Function::simplyConditionJudge(QString condition,QString data,QMap<QString,int>projection,QMap<QString,QString>dataTypeProjection)
{
    qDebug()<<"nowtheSimple";

    QStringList dataList=data.split("%",QString::SkipEmptyParts);
    //foreach(QString s,dataList)qDebug("%s",qPrintable(s));
    QChar compareOp;
    foreach(QChar c,condition)
    {
        if(c=='='||c=='>'||c=='<')
        {
            compareOp=c;
            break;
        }
    }
    QStringList conditionList=condition.split(QRegExp("[!<>=]"),QString::SkipEmptyParts);
    foreach(QString s,conditionList)qDebug("%s",qPrintable(s));

    //只有int，char两种数据类型
    int compareInt1,compareInt2,dataType=-1;//dataType 0为int,1为char
    QString compareString1,compareString2;
    bool res;

    qDebug("%s",qPrintable(dataTypeProjection[conditionList[0]]));
    qDebug()<<projection[conditionList[0]];
    qDebug()<<projection[conditionList[1]];

    if(dataTypeProjection[conditionList[0]].compare("int")==0)
    {
        compareInt1=dataList[projection[conditionList[0]]].toInt();
        dataType=0;
    }else{
        compareString1=dataList[projection[conditionList[0]]];
        dataType=1;
    }

    if(dataType==1){
        compareString1=conditionList[1];
        compareString2=dataList[0];
    }else{
        compareInt1=conditionList[1].toInt();
        compareInt2=dataList[0].toInt();
    }

    //如果是char类型
    if(dataType==1)
    {
        if(compareOp=='=')
            res=(compareString1.compare(compareString2)==0);
        else if(compareOp=='>')
            res=(compareString1.compare(compareString2)>0);
        else
            res=(compareString1.compare(compareString2)<0);
    }

    //如果是int类型
    if(dataType==0)
    {
        if(compareOp=='=')
            res=(compareInt1==compareInt2);
        else if(compareOp=='>')
            res=(compareInt1>compareInt2);
        else
            res=(compareInt1<compareInt2);
    }

    qDebug()<<res;

    if(condition[0]=='!')return ~res;
    return res;
}

//where条件判断

bool Function::JudgeCondition(QString condition,QString data,QMap<QString,int>projection,QMap<QString,QString>dataTypeProjection)
{
    //" "分词
    QStringList conditionList=condition.split(" ",QString::SkipEmptyParts);

    //为空
    if(condition=="")return true;

    QStack<QString>opr;
    QStack<bool>opn;
    QStringList simplyConditions;
    QString tmpCondition="";


    foreach(QString condition,conditionList)
    {
        qDebug("%s",qPrintable(condition));
        if(condition.compare("and")!=0&&condition.compare("or")!=0)
        {
            if(condition.compare("not")==0)
                tmpCondition+="!";
            else
            {
                tmpCondition+=condition;
                simplyConditions.append(tmpCondition);
                tmpCondition="";
            }
        }
        else simplyConditions.append(condition);
    }

    //简化条件语句
    foreach(QString condition,simplyConditions)
    {
        qDebug("%s",qPrintable(condition));
        if(condition.compare("and")==0||condition.compare("or")==0)
            opr.push(condition);
        else
        {
            if(opr.isEmpty())
                opn.push(simplyConditionJudge(condition,data,projection,dataTypeProjection));
            else
            {
                bool n1=opn.pop();
                QString o1=opr.pop();
                if(o1.compare("and")==0)
                    opn.push(n1&simplyConditionJudge(condition,data,projection,dataTypeProjection));
                else
                    opn.push(n1|simplyConditionJudge(condition,data,projection,dataTypeProjection));
            }
        }
    }
    return opn.pop();
}

int Function::Cmp(QString s1,QString s2,QString key,QMap<QString,int>projection,QMap<QString,QString>dataTypeProjection)
{
    qDebug()<<"here cmp";

    QStringList List_1=s1.split("%",QString::SkipEmptyParts);
    QStringList List_2=s2.split("%",QString::SkipEmptyParts);

    int rowNum=projection[key];

    qDebug()<<rowNum;

    QString c1=List_1[rowNum];
    QString c2=List_2[rowNum];

    qDebug("%s",qPrintable(c1+"vs"+c2));

    if(dataTypeProjection[key].compare("int")==0)
    {
        int ci1=c1.toInt();
        int ci2=c2.toInt();
        qDebug()<<ci1<<" "<<ci2;
        if(ci1==ci2)return 0;
        else if(ci1>ci2)return 1;
        else return -1;
    }
    if(c1==c2)return 0;
    else if(c1>c2)return 1;
    else return -1;
}

//select功能实现
QString Function::select(QString attribute,QString table,QString condition,QString order)
{
    bool isSingalTable=false;//判断是否为单表查询
    //创建一个中间缓存文件
    QFile file(rootAddress_+"\\temp.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    //存储表名.字段名的集合
    QSet<QString> attributeSet;
    //存储要查询的表名的列表
    QStringList tableList=table.split(',',QString::SkipEmptyParts);
    //存储要查询的属性的列表
    QStringList attributeList=attribute.split(',',QString::SkipEmptyParts);

    //要查询的表名只有1个-单表查询
    if(tableList.size()==1){
        isSingalTable=true;
        if(attributeList[0].toStdString()!="*"){
            foreach(QString s,attributeList){
                //将要查询的表名.字段名全部加入属性集合
                attributeSet.insert(tableList[0]+"."+s);
                //qDebug("%s",qPrintable(s));
            }
        }
    }

    QMap<QString,int> projection;//投影
    QMap<QString,QString> dataTypeProjection;//数据类型投影

    //根据选中表建立中间文件表头
    qDebug()<<"table";
    qDebug("%s",qPrintable(table));

    QString newForm="";//新的头文件表头
    int columnNum=0;

    //读取要查询的表文件，拼接成只有记录的
    foreach(QString s,tableList){
        qDebug("%s",qPrintable(rootAddress_+"\\"+DBName_+"\\"+s+".txt"));

        //打开要查询的表文件
        QFile tmpFile(rootAddress_+"\\"+DBName_+"\\"+s+".txt");
        if(!tmpFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }

        QTextStream in(&tmpFile);
        QString tmpString;

        //tmpString存取要查询的表的字段信息
        //"1|0|sno|char8%0|0|sname|char10%0|0|sex|char1%0|1|classno|char8%0|0|totalCredit|int"
        in>>tmpString;

        qDebug("%s",qPrintable(tmpString));

        //tmpList存取"%"分出的每个字段信息
        //"1|0|sno|char8"
        QStringList tmpList=tmpString.split('%',QString::SkipEmptyParts);

        foreach(QString tmps,tmpList){
            qDebug("%s",qPrintable(tmps));

            //attributeTmp存储"|"分出字段的每个信息
            //[0]=PK,[1]=FK,[2]=NAME,[3]=TYPE
            QStringList attributeTmp=tmps.split('|',QString::SkipEmptyParts);

            if(attributeList[0].toStdString()=="*" && isSingalTable){
                attributeSet.insert(tableList[0]+"."+attributeTmp[2]);
            }

            //columnNum记录字段的个数
            //映射[表名.字段名]=字段位置号
            projection[s+"."+attributeTmp[2]]=columnNum++;
            //类型映射[表名.字段名]=字段类型
            dataTypeProjection[s+"."+attributeTmp[2]]=attributeTmp[3];

            //一个char()类型的字段
            QString newString=s+"."+attributeTmp[2]+"|"+attributeTmp[3]+"%";
            //newForm="s.sno|char8%s.sname|char10%s.sex|char1%s.classno|char8%s.totalCredit|int%"
            newForm+=newString;
        }
        //关闭要查询的表文件
        tmpFile.close();
    }

    //将记录写入临时文件temp.txt
    QTextStream out(&file);
    out<<newForm+"\n";

    //调试用的
    QMap<QString,int>::iterator iter=projection.begin();
    while(iter!=projection.end()){
        qDebug()<<iter.key()<<":"<<iter.value();
        iter++;
    }

    //tableList_1存储表内每条记录
    //"08300010%s1%m%Rj801%0"
    QStringList tableList_1;
    foreach(QString s,tableList)
        tableList_1.append(s);

    qDebug()<<"abab";

    tableList_1=WriteContent(tableList);
    foreach(QString s,tableList_1)
        out<<s+"\n";
    file.close();

    //写结果文件
    QFile ResultFile(rootAddress_+"\\result.txt");
    if(!ResultFile.open(QIODevice::Append|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QFile tempFile(rootAddress_+"\\"+"temp.txt");
    if(!tempFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QFile temp2File(rootAddress_+"\\"+"temp2.txt");
    if(!temp2File.open(QIODevice::Append|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QTextStream resultOut(&ResultFile);
    QTextStream in(&tempFile);
    QTextStream tempOut(&temp2File);

    QString Header="";

    //是单表查询
    if(isSingalTable==true){
        //attributeSet存储 表名.字段名
        foreach(QString s,attributeSet)
            Header+=s+"%";
        //Header存储 "s.sno%s.sname%"
        tempOut<<Header<<"\n";
    }else{
        //是多表查询
        //attributeList存储 字段名
        foreach(QString s,attributeList)
            Header+=s+"%";
        //Header存储
        tempOut<<Header<<"\n";
    }

    //data临时存储一条记录
    //"08300010%s1%m%Rj801%0"
    QString data;
    in>>data;
    qDebug("%s",qPrintable(data));

    // QStringList conditionList=condition.split(" ",QString::SkipEmptyParts);
    int cnt=0;
    //判断where条件
    while(!in.atEnd())
    {
        in>>data;
        qDebug("%s",qPrintable(data));
        if(data=="")break;
        if(JudgeCondition(condition,data,projection,dataTypeProjection))
            tempOut<<data<<"\n";

        cnt+=1;

        qDebug()<<"shit";
        qDebug()<<cnt;
    }

    temp2File.close();
    tempFile.close();

    QFile tempToResult(rootAddress_+"\\"+"temp2.txt");
    if(!tempToResult.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QTextStream toBuffer(&tempToResult);
    toBuffer>>data;
    resultOut<<data<<"\n";

    //写入记录的数据
    if(order=="")
    {
        while(!toBuffer.atEnd())
        {
            toBuffer>>data;
            qDebug("%s",qPrintable(data));
            if(data=="")break;
            QStringList dataList=data.split("%",QString::SkipEmptyParts);
            QString rowData;
            //选取选出的行
            if(isSingalTable==true){
                foreach(QString s,attributeSet)
                    rowData+=dataList[projection[s]]+"%";
            }else{
                foreach(QString s,attributeList)
                    rowData+=dataList[projection[s]]+"%";
            }
            resultOut<<rowData<<"\n";
        }
    }
    else
    {
        QStringList orderList=order.split(",",QString::SkipEmptyParts);
        QStringList oneOforder=orderList[0].split(" ",QString::SkipEmptyParts);
        QString key=oneOforder[0];
        QStringList resultInOrder;
        QString direct=oneOforder[1];

        qDebug()<<"order!";

        while(!toBuffer.atEnd())
        {
            bool haveInserted=false;
            int place=0;
            toBuffer>>data;
            if(data=="")break;
            qDebug("%s",qPrintable(data));
            if(resultInOrder.isEmpty())resultInOrder.append(data);
            else
            {
                foreach(QString s,resultInOrder)
                {
                    if(direct[0].toLower()=='dec')
                    {
                        int CmpNum=Cmp(data,s,key,projection,dataTypeProjection);
                        qDebug()<<"the cmpNum";
                        qDebug()<<CmpNum;
                        if(CmpNum>0)
                        {
                            qDebug()<<place;
                            qDebug("%s",qPrintable("inserted"+data));
                            resultInOrder.insert(place,data);
                            haveInserted=true;
                            break;
                        }
                        place+=1;
                    }
                    else if(direct[0].toLower()=='asc'){

                        if(Cmp(data,s,key,projection,dataTypeProjection)<0)
                        {
                            resultInOrder.insert(place,data);
                            haveInserted=true;
                            break;
                        }
                        place+=1;
                    }
                }
                if(!haveInserted)resultInOrder.append(data);
            }

        }

        foreach(QString s,resultInOrder)
        {
            QStringList dataList=s.split("%",QString::SkipEmptyParts);
            QString rowData;
            if(rowData == "") break;
            foreach(QString s1,attributeList)
                rowData+=dataList[projection[s1]]+"%";
            resultOut<<rowData<<"\n";
        }
    }
    tempToResult.close();
    tempToResult.remove();
    tempFile.remove();
    ResultFile.close();

    return rootAddress_+"\\result.txt";

}

QString Function::rewriteFile(QString file_addr,QString target_tableName){
    QFile resultFile(file_addr);
    if(!resultFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QFile targetFile(rootAddress_+"\\"+DBName_+"\\"+target_tableName+".txt");
    if(!targetFile.open(QIODevice::WriteOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QTextStream result_in(&resultFile);
    QTextStream result_out(&targetFile);

    QString data;

    while(!result_in.atEnd()){
        result_in >> data;
        if(data=="")break;
        qDebug("%s",qPrintable(data));
        result_out << data << "\n";
    }

    resultFile.close();
    targetFile.close();

    return rootAddress_ + "\\" +DBName_+"\\"+ target_tableName + ".txt";
}

QString Function::delete_function(QString table,QString condition)
{

    //创建一个中间缓存文件
    QFile file(rootAddress_+"\\temp.txt");
    if(!file.open(QIODevice::Append|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QMap<QString,int>projection;//投影
    QMap<QString,QString> dataTypeProjection;//数据类型投影

    //根据选中表建立中间文件表头
    qDebug()<<"table";
    qDebug("%s",qPrintable(table));
    QStringList tableList=table.split(',',QString::SkipEmptyParts);
    QString newForm="";//新的头文件表头
    int columnNum=0;

    foreach(QString s,tableList)
    {
        qDebug("%s",qPrintable(rootAddress_+"\\"+DBName_+"\\"+s+".txt"));
        QFile tmpFile(rootAddress_+"\\"+DBName_+"\\"+s+".txt");
        if(!tmpFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }
        //读取from中的文件tempFile记录信息
        QTextStream in(&tmpFile);
        QString tmpString;
        in>>tmpString;
        qDebug("%s",qPrintable(tmpString));
        //1|0|sno|char8%0|0|sname|char10%0|0|sex|char1%0|1|classno|char8%0|0|totalCredit|int
        //分割每个属性信息
        //projrction存属性下标，dataTypeProjection存属性类型——key,value
        QStringList tmpList=tmpString.split('%',QString::SkipEmptyParts);
        foreach(QString tmps,tmpList)
        {
            qDebug("%s",qPrintable(tmps));
            QStringList attributeTmp=tmps.split('|',QString::SkipEmptyParts);
            projection[s+"."+attributeTmp[2]]=columnNum++;
            dataTypeProjection[s+"."+attributeTmp[2]]=attributeTmp[3];
            QString newString=s+"."+attributeTmp[2]+"|"+attributeTmp[3]+"%";
            newForm+=newString;
        }
        tmpFile.close();
    }
    //输出信息至file文件
    QTextStream out(&file);
    out<<newForm+"\n";
    QMap<QString,int>::iterator iter=projection.begin();
    while(iter!=projection.end())
    {
        qDebug()<<iter.key()<<":"<<iter.value();
        iter++;
    }

    //把所有数据写进file文件
    QStringList tableList_1;
    foreach(QString s,tableList)
        tableList_1.append(s);//不确定是值传递还是引用传递
    qDebug()<<"abab";
    tableList_1=WriteContent(tableList);
    foreach(QString s,tableList_1)
        out<<s+"\n";
    file.close();
    //写结果文件

    QFile ResultFile(rootAddress_+"\\result.txt");
    if(!ResultFile.open(QIODevice::Append|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QFile tempFile(rootAddress_+"\\"+"temp.txt");
    if(!tempFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QFile temp2File(rootAddress_+"\\"+"temp2.txt");
    if(!temp2File.open(QIODevice::Append|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QFile targetFile(rootAddress_+"\\"+DBName_+"\\"+table+".txt");
    if(!targetFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QTextStream resultOut(&ResultFile);
    QTextStream in(&tempFile);
    QTextStream tempOut(&temp2File);
    QTextStream character_in(&targetFile);

    QString Header="";

    QString data;
    in>>data;
    qDebug("%s",qPrintable(data));

    int cnt=0;
    while(!in.atEnd())
    {
        in>>data;
        qDebug("%s",qPrintable(data));
        if(data=="")break;
        if(JudgeCondition(condition,data,projection,dataTypeProjection))
            tempOut<<data<<"\n";

        cnt+=1;
        qDebug()<<"shit";
        qDebug()<<cnt;
    }

    //tempFile.remove();

    temp2File.close();
    tempFile.close();


    QFile tempToResult(rootAddress_+"\\"+"temp2.txt");
    if(!tempToResult.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QTextStream toBuffer(&tempToResult);
    QStringList delete_row;

    toBuffer>>data;
    delete_row.append(data);
    //        resultOut<<data<<"\n";

    while(!toBuffer.atEnd())
    {
        toBuffer>>data;
        qDebug("%s",qPrintable(data));
        delete_row.append(data);
        //resultOut<<data<<"\n";
        if(data=="")break;
        QStringList dataList=data.split("%",QString::SkipEmptyParts);
    }

    if(delete_row.size() == 0||delete_row[0]==""){
        qDebug() << "没有匹配数据";
        return "DeleteWrong";
    }else{
        foreach(QString s , delete_row){
            qDebug("%s",qPrintable(s));
        }
    }

    while(!character_in.atEnd()){
        character_in >> data;
        if(data == "") break;
        if(!delete_row.contains(data)){
            resultOut << data << "\n";
        }
    }


    targetFile.close();
    tempToResult.close();
    tempToResult.remove();
    tempFile.remove();
    ResultFile.close();

    rewriteFile(rootAddress_+"\\result.txt",table);

    return "DeleteOk";
}

//QString Function::delete_function(QString table,QString condition)
//{
//        QStringList field=condition.split("=",QString::SkipEmptyParts);
//        field.removeLast();

//        QString decision;
//        decision=foreignkey(field,table);
//        //decision = referenceConstraints(table);
//        if(decision == "yes"){
//            return  "FK记录不可删除";
//        }
//    //创建一个中间缓存文件
//    QFile file(rootAddress_+"\\temp.txt");
//    if(!file.open(QIODevice::Append|QIODevice::Text)){
//        qDebug()<<"文件打开失败";
//    }

//    QMap<QString,int>projection;//投影
//    QMap<QString,QString> dataTypeProjection;//数据类型投影

//    //根据选中表建立中间文件表头
//    qDebug()<<"table";
//    qDebug("%s",qPrintable(table));
//    QStringList tableList=table.split(',',QString::SkipEmptyParts);
//    QString newForm="";//新的头文件表头
//    int columnNum=0;

//    foreach(QString s,tableList)
//    {
//        qDebug("%s",qPrintable(rootAddress_+"\\"+DBName_+"\\"+s+".txt"));
//        QFile tmpFile(rootAddress_+"\\"+DBName_+"\\"+s+".txt");
//        if(!tmpFile.open(QIODevice::ReadOnly|QIODevice::Text)){
//            qDebug()<<"文件打开失败";
//        }
//        //读取from中的文件tempFile记录信息
//        QTextStream in(&tmpFile);
//        QString tmpString;
//        in>>tmpString;
//        qDebug("%s",qPrintable(tmpString));
//        //1|0|sno|char8%0|0|sname|char10%0|0|sex|char1%0|1|classno|char8%0|0|totalCredit|int
//        //分割每个属性信息
//        //projrction存属性下标，dataTypeProjection存属性类型——key,value
//        QStringList tmpList=tmpString.split('%',QString::SkipEmptyParts);
//        foreach(QString tmps,tmpList)
//        {
//            qDebug("%s",qPrintable(tmps));
//            QStringList attributeTmp=tmps.split('|',QString::SkipEmptyParts);
//            projection[s+"."+attributeTmp[2]]=columnNum++;
//            dataTypeProjection[s+"."+attributeTmp[2]]=attributeTmp[3];
//            QString newString=s+"."+attributeTmp[2]+"|"+attributeTmp[3]+"%";
//            newForm+=newString;
//        }
//        tmpFile.close();
//    }
//    //输出信息至file文件
//    QTextStream out(&file);
//    out<<newForm+"\n";
//    QMap<QString,int>::iterator iter=projection.begin();
//    while(iter!=projection.end()){
//        qDebug()<<iter.key()<<":"<<iter.value();
//        iter++;
//    }

//    //把所有数据写进file文件
//    QStringList tableList_1;
//    foreach(QString s,tableList)
//        tableList_1.append(s);//不确定是值传递还是引用传递
//    qDebug()<<"abab";
//    tableList_1=WriteContent(tableList);
//    foreach(QString s,tableList_1)
//        out<<s+"\n";
//    file.close();
//    //写结果文件

//    QFile ResultFile(rootAddress_+"\\result.txt");
//    if(!ResultFile.open(QIODevice::Append|QIODevice::Text)){
//        qDebug()<<"文件打开失败";
//    }

//    QFile tempFile(rootAddress_+"\\"+"temp.txt");
//    if(!tempFile.open(QIODevice::ReadOnly|QIODevice::Text)){
//        qDebug()<<"文件打开失败";
//    }

//    QFile temp2File(rootAddress_+"\\"+"temp2.txt");
//    if(!temp2File.open(QIODevice::Append|QIODevice::Text)){
//        qDebug()<<"文件打开失败";
//    }

//    QFile targetFile(rootAddress_+"\\"+DBName_+"\\"+table+".txt");
//    if(!targetFile.open(QIODevice::ReadOnly|QIODevice::Text)){
//        qDebug()<<"文件打开失败";
//    }

//    QTextStream resultOut(&ResultFile);
//    QTextStream in(&tempFile);
//    QTextStream tempOut(&temp2File);
//    QTextStream character_in(&targetFile);

//    QString Header="";

//    QString data;
//    in>>data;
//    qDebug("%s",qPrintable(data));

//    int cnt=0;
//    while(!in.atEnd())
//    {
//        in>>data;
//        qDebug("%s",qPrintable(data));
//        if(data=="")break;
//        if(JudgeCondition(condition,data,projection,dataTypeProjection))
//            tempOut<<data<<"\n";

//        cnt+=1;
//        qDebug()<<cnt;
//    }

//    //tempFile.remove();

//    temp2File.close();
//    tempFile.close();


//    QFile tempToResult(rootAddress_+"\\"+"temp2.txt");
//    if(!tempToResult.open(QIODevice::ReadOnly|QIODevice::Text)){
//        qDebug()<<"文件打开失败";
//    }

//    QTextStream toBuffer(&tempToResult);
//    QStringList delete_row;

//    toBuffer>>data;
//    delete_row.append(data);

//    while(!toBuffer.atEnd())
//    {
//        toBuffer>>data;
//        qDebug("%s",qPrintable(data));
//        delete_row.append(data);
//        if(data=="")break;
//        QStringList dataList=data.split("%",QString::SkipEmptyParts);
//    }

//    if(delete_row.size() == 0){
//        qDebug() << "没有匹配数据";
//        return "字段不存在";
//    }else{
//        foreach(QString s , delete_row){
//            qDebug("%s",qPrintable(s));
//        }
//    }

//    while(!character_in.atEnd()){
//        character_in >> data;
//        if(data == "") break;
//        if(!delete_row.contains(data)){
//            resultOut << data << "\n";
//        }
//    }


//    targetFile.close();
//    tempToResult.close();
//    tempToResult.remove();
//    tempFile.remove();
//    ResultFile.close();

//    rewriteFile(rootAddress_+"\\result.txt",table);

//    return "DeleteOk";
//}

QString Function::primarykey(QMap<QString,int> projection,QString table,QString file_addr){
    QFile targetFile(rootAddress_ + "\\"+DBName_+"\\" + table + ".txt");
    if(!targetFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QTextStream out(&targetFile);

    int index = 0;
    QString data;
    QStringList primaryKey;
    QStringList projection_index;
    QStringList temp;
    QStringList primary_content;
    QMap<QString,int> :: Iterator iter;

    out >> data;
    out >> data;

    if(!QString::compare(QString(data),QString("NF"))){
        targetFile.close();
        return "no";
    }
    else{
        primaryKey = data.split("%");
        for(int i = 0 ; i < primaryKey.size() ; i++){
            primaryKey[i] = table + "." + primaryKey[i];
        }
        foreach(QString s,primaryKey){
            qDebug() << "primaryKey";
            qDebug("%s",qPrintable(s));
        }

        foreach(QString s , primaryKey){
            iter = projection.find(s);
            projection_index.append(iter.key());
            qDebug() << iter.key()  << " " << iter.value();
        }

        QFile resultFile(file_addr);
        if(!resultFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }

        QTextStream out_result(&resultFile);
        QString temp_data;

        out_result >> data;
        out_result >> data;
        out_result >> data;

        qDebug("%s",qPrintable(data));

        while (!out_result.atEnd()) {
            temp_data = "";
            out_result >> data;
            temp = data.split("%");
            for(int i = 0 ; i < projection_index.size() ; i++){
                temp_data = temp_data + temp[projection_index[i].toInt()];
            }
            qDebug("%s",qPrintable(temp_data));
            primary_content.append(temp_data);
            index++;
        }

        for(int i = 0 ; i < primary_content.size() ; i++){
            for(int j = 0 ; j < primary_content.size() ; j++){
                if(primary_content[i] == primary_content[j] && i != j){
                    return "yes";
                }
            }
        }

        return "no";
    }
}

//判断是否为外键
QString Function::foreignkey(QStringList set_KeyValue,QString table){
    QFile targetFile(rootAddress_ + "\\" +DBName_+"\\"+ table + ".txt");
    if(!targetFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QTextStream out(&targetFile);

    QString data;
    QStringList temp_foreignkey;
    QStringList foreignkey;

    out >> data;
    out >> data;
    out >> data;

    if(!QString::compare(QString(data),QString("NF"),Qt::CaseSensitive)){
        targetFile.close();
        return "no";
    }

    temp_foreignkey = data.split("%");
    for(int i = 0 ; i < temp_foreignkey.size() ; i++){
        temp_foreignkey[i] = table + "." + temp_foreignkey[i];
    }

    foreach(QString s , temp_foreignkey){
        qDebug("%s",qPrintable(s));
        foreignkey.append(s.split("|"));
    }


    if(!foreignkey.contains(set_KeyValue[0])){
        qDebug("%s",qPrintable(data));
        qDebug("%s",qPrintable(set_KeyValue[0]));
        qDebug() << "1";
        targetFile.close();
        return "no";
    }
    else{
        for(int i = 0 ; i < foreignkey.size() ; i++){

            if(!QString::compare(QString(foreignkey[i]),QString(set_KeyValue[0]),Qt::CaseSensitive)){
                QString foreign_table;
                QString foreign_column;

                foreign_table = foreignkey[i+1];
                foreign_column = foreignkey[i+1] + "." + foreignkey[i+2];

                select("",foreign_table,foreign_column + "=" + set_KeyValue[1],"");
                QFile ResultFile(rootAddress_+"\\result.txt");
                if(!ResultFile.open(QIODevice::ReadOnly|QIODevice::Text)){
                    qDebug()<<"文件打开失败";
                }

                QTextStream out(&ResultFile);
                QString data;

                out >> data;
                if(data.isNull()){
                    qDebug() << "2";
                    qDebug("%s",qPrintable(data));
                    qDebug() << "外键值不存在";
                    targetFile.close();
                    ResultFile.remove();
                    return "yes";
                }
                else{
                    qDebug("%s",qPrintable(data));
                    targetFile.close();
                    ResultFile.remove();
                    return "no";
                }
            }
        }
    }
}

QString Function::update_function(QString table,QString set,QString condition)
{
    QStringList set_KeyValue;

    set = set.simplified();
    set_KeyValue = set.split("=");

    QString decision = "null";
    //判断是否为外键
    decision = foreignkey(set_KeyValue,table);
    if(decision == "no"){
        //创建一个中间缓存文件
        QFile file(rootAddress_+"\\temp.txt");
        if(!file.open(QIODevice::Append|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }

        QMap<QString,int>projection;//投影
        QMap<QString,QString> dataTypeProjection;//数据类型投影

        //根据选中表建立中间文件表头
        qDebug()<<"table";
        qDebug("%s",qPrintable(table));
        QStringList tableList=table.split(',',QString::SkipEmptyParts);
        QString newForm="";//新的头文件表头
        int columnNum=0;
        //QList<QFile> tableFileSet;
        foreach(QString s,tableList)
        {
            qDebug("%s",qPrintable(rootAddress_+"\\"+DBName_+"\\"+s+".txt"));
            QFile tmpFile(rootAddress_+"\\"+DBName_+"\\"+s+".txt");
            if(!tmpFile.open(QIODevice::ReadOnly|QIODevice::Text)){
                qDebug()<<"文件打开失败";
            }
            //读取from中的文件tempFile记录信息
            QTextStream in(&tmpFile);
            QString tmpString;
            in>>tmpString;
            qDebug("%s",qPrintable(tmpString));
            //1|0|sno|char8%0|0|sname|char10%0|0|sex|char1%0|1|classno|char8%0|0|totalCredit|int
            //分割每个属性信息
            //projrction存属性下标，dataTypeProjection存属性类型——key,value
            QStringList tmpList=tmpString.split('%',QString::SkipEmptyParts);
            foreach(QString tmps,tmpList)
            {
                qDebug("%s",qPrintable(tmps));
                QStringList attributeTmp=tmps.split('|',QString::SkipEmptyParts);
                //projection[s+"."+attributeTmp[2]]=columnNum++;
                projection[attributeTmp[2]]=columnNum++;
                //dataTypeProjection[s+"."+attributeTmp[2]]=attributeTmp[3];
                dataTypeProjection[attributeTmp[2]]=attributeTmp[3];
                QString newString=attributeTmp[2]+"|"+attributeTmp[3]+"%";
                //QString newString=s+"."+attributeTmp[2]+"|"+attributeTmp[3]+"%";
                newForm+=newString;
            }
            tmpFile.close();
        }
        //输出信息至file文件
        QTextStream out(&file);
        out<<newForm+"\n";
        QMap<QString,int>::iterator iter=projection.begin();
        while(iter!=projection.end())
        {
            qDebug()<<iter.key()<<":"<<iter.value();
            iter++;
        }

        //把所有数据写进file文件
        QStringList tableList_1;
        foreach(QString s,tableList)
            tableList_1.append(s);//不确定是值传递还是引用传递
        qDebug()<<"abab";
        tableList_1=WriteContent(tableList);
        foreach(QString s,tableList_1)
            out<<s+"\n";
        file.close();
        //写结果文件

        QFile ResultFile(rootAddress_+"\\result.txt");
        if(!ResultFile.open(QIODevice::Append|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }

        QFile tempFile(rootAddress_+"\\"+"temp.txt");
        if(!tempFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }

        QFile temp2File(rootAddress_+"\\"+"temp2.txt");
        if(!temp2File.open(QIODevice::Append|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }

        QFile targetFile(rootAddress_+"\\"+DBName_+"\\"+table+".txt");
        if(!targetFile.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }

        QTextStream resultOut(&ResultFile);
        QTextStream in(&tempFile);
        QTextStream tempOut(&temp2File);
        QTextStream character_in(&targetFile);

        QString Header="";

        QString data;
        in>>data;
        qDebug("%s",qPrintable(data));

        //QStringList conditionList=condition.split(" ",QString::SkipEmptyParts);
        int cnt=0;
        //判断符合where条件的记录
        while(!in.atEnd())
        {
            in>>data;
            qDebug("%s",qPrintable(data));
            if(data=="")break;
            if(JudgeCondition(condition,data,projection,dataTypeProjection))
                tempOut<<data<<"\n";

            cnt+=1;
            qDebug()<<"shit";
            qDebug()<<cnt;
        }

        //tempFile.remove();

        temp2File.close();
        tempFile.close();


        QFile tempToResult(rootAddress_+"\\"+"temp2.txt");
        if(!tempToResult.open(QIODevice::ReadOnly|QIODevice::Text)){
            qDebug()<<"文件打开失败";
        }

        QTextStream toBuffer(&tempToResult);
        QStringList update_row;
        QStringList update_content;
        QMap<QString,int>::iterator it=projection.begin();

        toBuffer>>data;
        update_row.append(data);
        //        resultOut<<data<<"\n";

        while(!toBuffer.atEnd())
        {
            toBuffer>>data;
            qDebug("%s",qPrintable(data));
            update_row.append(data);
            //                resultOut<<data<<"\n";
            if(data=="")break;
            QStringList dataList=data.split("%",QString::SkipEmptyParts);
        }
        qDebug()<<"不存在待更新列："<<update_row.size();
        if(update_row.size()==0||update_row[0]==""){
            //qDebug()<<"不存在待更新列："<<update_row.size();
            //qDebug() << "没有匹配数据";
            return "UpdateWrong";
        }else{
            foreach(QString s , update_row){
                qDebug() << "更新行";
                qDebug("%s",qPrintable(s));
            }
        }
        //更新数据
        while(!character_in.atEnd()){
            character_in >> data;
            if(data=="")break;
            if(update_row.contains(data)){
                QString new_data;
                //qDebug("%s",qPrintable(set_KeyValue[0]));
                update_content = data.split("%");
                it = projection.find(set_KeyValue[0]);
                update_content[it.value()] = set_KeyValue[1];
                foreach(QString s, update_content){
                    new_data = new_data + s + "%";
                }
                new_data = new_data.left(new_data.size() - 1);
                resultOut << new_data << "\n";
            }else{
                resultOut << data << "\n";
            }
        }

        targetFile.close();
        tempToResult.close();
        tempToResult.remove();
        tempFile.remove();
        ResultFile.close();


        decision = primarykey(projection,table,rootAddress_+"\\result.txt");
        qDebug("%s",qPrintable(decision));

        if(decision == "yes"){
            qDebug() << "主键应非空唯一";
            return "UpdateWrong";
        }
        else{
            rewriteFile(rootAddress_+"\\result.txt",table);
            return "UpdateOk";
        }

    }
    else {
        return "FK记录不可更改";
    }
}

QString Function::referenceConstraints(QString table)
{
    QFile relationFile(rootAddress_ + "\\relation.txt");
    if(!relationFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug()<<"文件打开失败";
    }

    QTextStream relation_in(&relationFile);
    QString data;
    QStringList temp_relation;
    QStringList relation;
    QStringList temp_relationTable;
    QStringList relationTable;

    while(!relation_in.atEnd()){
        relation_in >> data;

        if(data=="") break;

        temp_relation = data.split("-");

        relation.append(temp_relation[0]);
    }

    if(relation.size() == 0){
        return "no";
    }
    else{
        foreach(QString s, relation){
            temp_relationTable = s.split(".");

            relationTable.append(temp_relationTable[0]);

            qDebug() << temp_relationTable[0];
        }

        if(relationTable.contains(table)){
            return "yes";
        }
        else {
            return "no";
        }
    }
}

QString Function::insert(QString tableName,QString value)
{
    QStringList valueList=value.split(",",QString::SkipEmptyParts);

    QMap<QString,int>projection;
    QString tableForm;

    QFile readFile(rootAddress_+"\\"+DBName_+"\\"+tableName+".txt");
    if(!readFile.open(QIODevice::ReadOnly|QIODevice::Text))
        qDebug()<<"打开文件失败";

    QTextStream in(&readFile);
    in>>tableForm;

    qDebug("%s",qPrintable(tableForm));

    QStringList tableFormList=tableForm.split("%",QString::SkipEmptyParts);
    int cnt=0;

    foreach(QString s,tableFormList){
        QStringList attributeList=s.split("|",QString::SkipEmptyParts);

        projection[attributeList[2]]=cnt++;

        qDebug("%s",qPrintable(attributeList[2]));
        qDebug()<<cnt-1;
    }

    QString primaryKey;
    in>>primaryKey;

    qDebug("%s",qPrintable(primaryKey));

    QStringList primaryKeyList=primaryKey.split("%",QString::SkipEmptyParts);

    QString ForignKey;
    in>>ForignKey;

    qDebug("%s",qPrintable(ForignKey));

    QString data;
    QSet<QString>primaryKeySet;

    while(!in.atEnd()){
        qDebug()<<"the set";

        in>>data;

        if(data=="")break;

        qDebug("%s",qPrintable(data));

        QStringList dataList=data.split("%",QString::SkipEmptyParts);
        QString PK="";

        foreach(QString s,primaryKeyList)
            PK+=dataList[projection[s]]+"%";

        qDebug("%s",qPrintable(PK));

        primaryKeySet.insert(PK);
    }
    readFile.close();

    QString PK="";

    qDebug()<<"??";

    foreach(QString s,primaryKeyList)
        PK+=valueList[projection[s]]+"%";

    qDebug("%s",qPrintable(PK));

    if(primaryKeySet.contains(PK)) return "InsertWrong";

    QStringList ForignKeyList=ForignKey.split("%",QString::SkipEmptyParts);

    foreach(QString s,ForignKeyList){
        QSet<QString>FKSet;
        QStringList referenceData=s.split("|",QString::SkipEmptyParts);

        if(referenceData.size()==1){
            break;
        }

        QFile tmpFile(rootAddress_+"\\"+DBName_+"\\"+referenceData[1]+".txt");
        if(!tmpFile.open(QIODevice::ReadOnly|QIODevice::Text))
            qDebug()<<"打开文件失败";

        QTextStream tmpIn(&tmpFile);
        QString dataIntmp;
        tmpIn>>dataIntmp;

        QStringList tmpFormList=dataIntmp.split("%",QString::SkipEmptyParts);
        QMap<QString,int>tmpProjection;
        int tmpCnt=0;

        foreach(QString s1,tmpFormList){
            QStringList TmpAttributeList=s1.split("|",QString::SkipEmptyParts);

            tmpProjection[TmpAttributeList[2]]=tmpCnt++;

            qDebug("%s",qPrintable(TmpAttributeList[2]));
            qDebug()<<tmpCnt-1;
        }
        tmpIn>>dataIntmp;
        tmpIn>>dataIntmp;

        while(!tmpIn.atEnd()){
            tmpIn>>dataIntmp;

            if(dataIntmp=="")break;

            qDebug("%s",qPrintable(dataIntmp));

            QStringList dataIntmpList=dataIntmp.split("%",QString::SkipEmptyParts);

            FKSet.insert(dataIntmpList[tmpProjection[referenceData[2]]]);
        }
        tmpFile.close();

        qDebug()<<"isHere";
        qDebug("%s",qPrintable(valueList[projection[referenceData[0]]]));

        if(!FKSet.contains(valueList[projection[referenceData[0]]])) return "InsertWrong";
    }

    QFile writeFile(rootAddress_+"\\"+DBName_+"\\"+tableName+".txt");
    if(!writeFile.open(QIODevice::Append|QIODevice::Text))
        qDebug()<<"打开文件失败";

    QTextStream out(&writeFile);
    QString outString="";

    foreach(QString s,valueList)
        outString+=s+"%";

    out<<outString.left(outString.size()-1)+"\n";

    writeFile.close();

    return "InsertOk";
}

QString Function::AlterTable(QString operate,QString tableName,QString columnname,QString Datatype,QString newColumnName,QString newColumnType)
{
    QString tableForm;

    qDebug("%s",qPrintable(rootAddress_+"\\"+DBName_+"\\"+tableName+".txt"));

    QFile readFile(rootAddress_+"\\"+DBName_+"\\"+tableName+".txt");
    if(!readFile.open(QIODevice::ReadOnly|QIODevice::Text)){
        return "打开文件失败";
    }

    QTextStream in(&readFile);
    in>>tableForm;//字段信息行

    QString line2,line,line3;
    in>>line2;//PK信息行

    //tableFormList存每个字段的全部信息
    QStringList tableFormList=tableForm.split("%",QString::SkipEmptyParts);
    //attributeSet存每个字段的名字
    QSet<QString> attributeSet;
    foreach(QString s,tableFormList){
        QStringList tempList=s.split("|",QString::SkipEmptyParts);
        attributeSet.insert(tempList[2]);
    }

    in>>line3;//FK信息行

    if(operate.toUpper()=="ADD"){
        if(attributeSet.contains(columnname)==true){return "字段已存在";}
        else
        {
            tableForm+="%0|0|";
            tableForm+=columnname;
            tableForm+="|";
            tableForm+=Datatype;
            QFile writeFile(rootAddress_+"\\"+DBName_+"\\"+tableName+"1.txt");
            if(!writeFile.open(QIODevice::Append|QIODevice::Text))
                return"打开文件失败";
            QTextStream out(&writeFile);
            out << tableForm << endl;
            out << line2 << endl;
            out<<line3<<"\n";
            while(!in.atEnd())
            {
                in>>line;
                if(line=="")break;
                qDebug("%s",qPrintable(line));
                line+="%NULL";
                out << line<< endl;
            }
            writeFile.close();
            readFile.close();
            readFile.remove();
            writeFile.rename(rootAddress_+"\\"+DBName_+"\\"+tableName+".txt");
            return "ADDOK";
        }
    }
    else if(operate.toUpper()=="DROP"){
        QStringList primeKeyList=line2.split("%",QString::SkipEmptyParts);
        if(primeKeyList.contains(columnname)==true){return "PK不可删除";}
        if(attributeSet.contains(columnname)!=true){return "字段不存在";}

        QString FKReference=tableName+"."+columnname;
        QFile relationFile(rootAddress_+"\\relation.txt");
        if(!relationFile.open(QIODevice::ReadOnly|QIODevice::Text))
            return"打开文件失败";
        QTextStream relationIn(&relationFile);
        while(!relationIn.atEnd())
        {
            relationIn>>line;
            QStringList tempList=line.split("-");
            if(tempList[0]!="" && tempList[1]==FKReference)
            {
                relationFile.close();
                return "FK不可删除";
            }
        }
        relationFile.close();

        int updateNum=0,cnt=0;
        QString line1="";
        foreach(QString s,tableFormList)
        {
            QStringList tempList=s.split("|",QString::SkipEmptyParts);
            cnt+=1;
            if(tempList[2]==columnname){
                updateNum=cnt;continue;
            }else{
                line1+=s+"%";
            }
        }
        QFile writeFile(rootAddress_+"\\"+DBName_+"\\"+tableName+"1.txt");
        if(!writeFile.open(QIODevice::Append|QIODevice::Text))
            return"打开文件失败";
        QTextStream out(&writeFile);

        out<<line1.left(line1.size()-1)<<"\n";
        out << line2 << endl;
        out<<line3<<"\n";

        QStringList valueList;
        while(in.atEnd() == false)
        {
            in>>line;
            valueList=line.split("%",QString::SkipEmptyParts);
            valueList.removeAt(updateNum-1);
            if(valueList.size()==1){
                out << valueList[0]<< endl;
            }
            out << valueList.join("%")<< endl;
        }

        writeFile.close();
        readFile.close();
        readFile.remove();
        writeFile.rename(rootAddress_+"\\"+DBName_+"\\"+tableName+".txt");
        return "DROPOK";
    }
    else if(operate.toUpper()=="RENAME"){
        QStringList primeKeyList=line2.split("%",QString::SkipEmptyParts);
        if(primeKeyList.contains(columnname)==true){return "PK不可更新";}
        if(attributeSet.contains(columnname)!=true){return "字段不存在";}

        QString FKReference=tableName+"."+columnname;
        QFile relationFile(rootAddress_+"\\relation.txt");
        if(!relationFile.open(QIODevice::ReadOnly|QIODevice::Text))
            return"打开文件失败";
        QTextStream relationIn(&relationFile);
        while(!relationIn.atEnd())
        {
            relationIn>>line;
            QStringList tempList=line.split("-");
            if(tempList[0]!="" && tempList[1]==FKReference){
                relationFile.close();
                return "FK不可更新";
            }
        }
        relationFile.close();

        int updateNum=0,cnt=0;

        //找到要改的字段位置
        foreach(QString s,tableFormList){
            QStringList tempList=s.split("|",QString::SkipEmptyParts);
            cnt+=1;
            if(tempList[2]==columnname){
                updateNum=cnt;
                continue;
            }
        }

        //新建临时文件
        QFile writeFile(rootAddress_+"\\"+DBName_+"\\"+tableName+"1.txt");
        if(!writeFile.open(QIODevice::Append|QIODevice::Text))
            return"打开文件失败";
        QTextStream out(&writeFile);

        QStringList updValueList;
        QString updValue;

        int tnum = 0;
        foreach(QString s,tableFormList){
            if(tnum == updateNum-1) {
                updValueList=s.split("|",QString::SkipEmptyParts);
                break;
            }tnum++;
        }

        updValueList.replace(2,newColumnName);
        updValueList.replace(3,newColumnType);
        int num=0;
        foreach(QString s,updValueList){
            if(num!=updValueList.size()-1) {
                s.append("|");
            }
            updValue.append(s);
            num++;
        }
        tableFormList.replace(updateNum-1, updValue);

        int onum=0;
        QString outValue;
        foreach(QString s,tableFormList){
            if(onum!=tableFormList.size()-1) {
                s.append("%");
            }
            outValue.append(s);
            onum++;
        }
        out << outValue << endl;
        out << line2 << endl;
        out << line3 << endl;

        writeFile.close();
        readFile.close();
        readFile.remove();
        writeFile.rename(rootAddress_+"\\"+DBName_+"\\"+tableName+".txt");
        return "RENAMEOK";
    }
}


QString Function::CreateUsers(QString userName,QString password)
{
    QString k;
    QString filename = rootAddress_+"\\user.txt";  //以只读方式打开文件
    QFile file(filename);
    file.open(QIODevice::ReadOnly| QIODevice::Text);
    QString a=file.readAll();            //从文件中读取数据
    QStringList strlist = a.split("\n"); //将读取的数据通过转行符进行分割
    file.close();                        //关闭文件
    QFile file2(filename);               //以只写方式打开文件
    file2.open(QIODevice::WriteOnly| QIODevice::Text);
    QTextStream wstream(&file2);         //创建文件输入流
    if(a.isEmpty()){                     //文件里没有信息，就直接插入数据
        wstream<<userName<<'|'<<password;
    }
    else{                               //文件里有信息，将分割出来的信息再通过 | 进行分割
        for(int i=0;i<strlist.size();i++){

            QString b=strlist.at(i);
            QStringList strlist2 = b.split("|");
            if(strlist2.at(0) == userName){  //判断哪些与所传的userName变量相同，将相同的数据删除
                strlist.removeAt(i);

            }
        }

        file2.resize(0);   //将文件内容清空
        for(int m=0;m<strlist.size();m++){ //重新写入文件
            wstream<<strlist.at(m)<<endl;
        }

        wstream<<userName<<'|'<<password;//向文件添加传递到函数的变量所产生的用户信息


    }
    k="CreateOk";
    return k;
}

QString Function::OperateRights(QString operate,QString userName,QString tableName,QString right){

    QString opp;
    if(operate.toLower() == "grant"){   //如果是授权
        QFile file (rootAddress_+"\\right.txt");  //以读写方式打开文件
        file.open(QIODevice::ReadWrite| QIODevice::Text);
        QTextStream wstream(&file);   //创建数据输入流
        QByteArray array=file.readAll();
        QString k;               //判断授予的权限是否在五个权限之中
        qint8 l=0;                  //同上
        QStringList strlist = right.split(",");//以逗号分割信息
        for(int i = 0;i<strlist.size();i++){
            k=strlist.at(i);                    //提取分割的信息，循环判断以支持同时授权或回收多个权限。
            if(k!="select" && k!="alter" && k!="update" && k!="delete" && k!="insert" ){//如果不是规定五个权限之中的，报错
                l=1;
                opp="WronginRight";
            }
        }
        if(l == 0){                              //如果在五个权限之中，循环将信息写入文件，并返回信息
            for(int m=0;m<strlist.count();m++){

                wstream<<userName<<'%'<<tableName<<'%'<<strlist.at(m)<<'\n';
            }
            opp= "GrantOK";

        }
        file.close();

    }
    else if(operate.toLower() == "revoke"){ //如果是回收权限
        QFile file (rootAddress_+"\\right.txt");
        file.open(QIODevice::ReadOnly| QIODevice::Text); //以只读方式打开文件
        qint8 h = 0; //用来判断是否出错
        QString strall=file.readAll();
        QStringList strlist2=strall.split("\n");//通过转行符将文件信息分割
        QStringList strlist = right.split(",");//通过逗号将要回收信息的权限分割
        file.close();
        for(int m=0;m<strlist2.size();m++){ //循环查看文件中是否有对应用户，对应表，对应要回收的权限的信息
            for(int n=0;n<strlist.size();n++){
                if(strlist2.at(m) == userName+"%"+tableName+"%"+strlist.at(n)){
                    strlist2.removeAt(m); //有就将提取出的信息删除
                    h=1;
                }
            }


        }
        if(h==0){         //没有就报错
            opp="RevokeFail";
        }
        else{   //有就先显示回收权限成功
            opp="RevokeOK";
        }
        QFile file2(rootAddress_+"\\right.txt"); //以只写方式打开文件
        file2.open(QIODevice::WriteOnly| QIODevice::Text);
        QTextStream edit(&file2);
        file2.resize(0); //清空文件内容
        for(int i=0;i<strlist2.size();i++){ //重写信息到文件中
            edit<<strlist2.at(i)<<endl;
        }

        file2.close(); //关闭文件
    }
    else{
        //不是授权也不是回收权限就报错
        opp="Authorization erroes";

    }

    return opp;
}

QString Function::CreateTables(QString tableName,QString content){
    QString k;
    QStringList pKeyList;//存放主键
    QStringList fKeyList;//存放外键

    //创建表文件
    QString fileName = rootAddress_+"\\"+DBName_+"\\"+tableName+".txt";
    QFile file(fileName);

    QString fileName2 = rootAddress_+"\\relation.txt";
    QFile fileR(fileName2);

    //打开并读取relation表
    fileR.open(QIODevice::ReadWrite| QIODevice::Text);
    QByteArray array=fileR.readAll();

    if(file.exists()){//要创建的表存在就报错
        k="TableAlreadyExists";
    }
    else{
        //打开并读写创建的表文件
        bool openok=file.open(QIODevice::ReadWrite| QIODevice::Text);
        if(openok ){
            QTextStream wstream(&file);
            QTextStream wstream2(&fileR);
            qint8 p=0;  //对应是否为主键的数字
            qint8 u=0;   //对应是否为外键的数字
            int w=0;
            int f=0;
            QString h="PK";
            QString z="FK";
            QStringList strlist = content.split(",\n");//以逗号加转行符作为分割
            QStringList strlistfkr;

            for(int m =0;m<strlist.size();m++){
                //判断这一行是否包含不区分大小写的pk，是的话p为1，否则为0
                if(strlist.at(m).contains(h,Qt::CaseInsensitive)){
                    p=1;
                }else p=0;

                //判断这一行是否包含不区分大小写的fk，是的话u为1，否则为0
                if(strlist.at(m).contains(z,Qt::CaseInsensitive)){
                    u=1;
                }else u=0;

                QString ac = strlist.at(m);
                //以空格为区分进一步分割信息
                QStringList strlist1 = ac.split(" ");

                if(!p && !u){
                    //0|0 如果不是PK也不是FK
                    wstream<<p<<'|'<<u; //将信息填入进去

                    for(int n =0;n<strlist1.size();n++){
                        if(n==strlist1.size()-1 && m==strlist.size()-1){ //如果此块儿信息不是一行得最后一块儿信息
                            wstream<<'|'<<strlist1.at(n);
                        }else if(n==strlist1.size()-1){
                            wstream<<'|'<<strlist1.at(n)<<'%';
                        }else{//如果此块儿信息是一行得最后一块儿信息
                            wstream<<'|'<<strlist1.at(n);
                        }
                    }
                }
                else if(p&&!u){
                    //如果这一行的第一块儿信息是PK，不是FK
                    w=1;
                    pKeyList.append(strlist1.at(0));
                    strlist1.last().clear();//清除PK信息

                    wstream<<p<<'|'<<u; //将信息填入进去

                    for(int n =0;n<strlist1.size()-1;n++){
                        if(n==strlist1.size()-2&&m==strlist.size()-1){ //如果此块儿信息不是一行得最后一块儿信息
                            wstream<<'|'<<strlist1.at(n);
                        }else if(n==strlist1.size()-2){
                            wstream<<'|'<<strlist1.at(n)<<'%';
                        }else{//如果此块儿信息是一行得最后一块儿信息
                            wstream<<'|'<<strlist1.at(n);
                        }
                    }
                }

                else if(u&&!p){
                    //如果这一行的第一块儿信息是FK，不是PK
                    f=1;
                    fKeyList.append(strlist1.at(0));
                    wstream<<p<<'|'<<u; //将信息填入进去

                    QString fk = strlist1.last();
                    QStringList strlistfk = fk.split("=");

                    QString fkr = strlistfk.last();

                    strlist1.last().clear();//清除FK信息

                    strlistfkr = fkr.split(".");

                    for(int n =0;n<strlist1.size()-1;n++){
                        if(n==strlist1.size()-2&&m==strlist.size()-1){ //如果此块儿信息不是一行得最后一块儿信息
                            wstream<<'|'<<strlist1.at(n);
                        }else if(n==strlist1.size()-2){
                            wstream<<'|'<<strlist1.at(n)<<'%';
                        }else{//如果此块儿信息是一行得最后一块儿信息
                            wstream<<'|'<<strlist1.at(n);
                        }
                    }

                    //写入到relation文件中
                    wstream2<<strlistfkr[0] <<'.';
                    wstream2<<strlistfkr[1]<<'-';
                    wstream2<<tableName<<'.';
                    wstream2<<strlist1[0]<<'\n';

                }
                else if(p&&u){
                    //如果这一行的第一块儿信息是PK又是FK
                    w=1;
                    pKeyList.append(strlist1.at(0));
                    f=1;
                    fKeyList.append(strlist1.at(0));

                    wstream<<p<<'|'<<u; //将信息填入进去

                    QString fk = strlist1.last();
                    QStringList strlistfk = fk.split("=");

                    QString fkr = strlistfk.last();

                    strlist1.last().clear();//清除FK信息
                    strlist1[strlist1.size()-2].clear();//清除PK信息

                    strlistfkr = fkr.split(".");

                    for(int n =0;n<strlist1.size()-1;n++){
                        if(n==strlist1.size()-2&&m==strlist.size()-1){ //如果此块儿信息不是一行得最后一块儿信息
                            wstream<<'|'<<strlist1.at(n);
                        }else if(n==strlist1.size()-2){
                            wstream<<'|'<<strlist1.at(n)<<'%';
                        }else{//如果此块儿信息是一行得最后一块儿信息
                            wstream<<'|'<<strlist1.at(n);
                        }
                    }

                    //写入到relation文件中
                    wstream2<<strlistfkr[0] <<'.';
                    wstream2<<strlistfkr[1]<<'-';
                    wstream2<<tableName<<'.';
                    wstream2<<strlist1[0]<<'\n';
                }
            }

            //没有主键和外键，第二行添NP，第三行添NF
            if(w==0 && f==0){
                wstream<<'\n';
                QString sdd= "NP";
                wstream<<sdd<<'\n';
                sdd= "NF";
                wstream<<sdd<<'\n';
            }
            //有外键没有主键
            else if(w==0 && f==1){
                wstream<<'\n';
                QString sdd= "NP";
                wstream<<sdd<<'\n';
                for(int i=0;i<fKeyList.size();++i){
                    if(i==fKeyList.size()-1){
                        wstream<<fKeyList[i]<<"|"<<strlistfkr[0]<<"|"<<strlistfkr[1]<<'\n';
                    }else{
                        wstream<<fKeyList[i]<<"%";
                    }
                }
            }
            //有主键没有外键
            else if(w==1 && f==0){
                wstream<<'\n';
                for(int i=0;i<pKeyList.size();++i){
                    if(i==pKeyList.size()-1){
                        wstream<<pKeyList[i]<<'\n';
                    }else{
                        wstream<<pKeyList[i]<<"%";
                    }
                }
                QString sdd= "NF";
                wstream<<sdd<<'\n';
            }
            else if(w==1 && f==1){
                wstream<<'\n';
                for(int i=0;i<pKeyList.size();++i){
                    if(i==pKeyList.size()-1){
                        wstream<<pKeyList[i]<<'\n';
                    }else{
                        wstream<<pKeyList[i]<<"%";
                    }
                }

                for(int i=0;i<fKeyList.size();++i){
                    if(i==fKeyList.size()-1){
                        wstream<<fKeyList[i]<<"|"<<strlistfkr[0]<<"|"<<strlistfkr[1]<<'\n';
                    }else{
                        wstream<<fKeyList[i]<<"%";
                    }
                }
            }

            k="CreateOK";
        }
    }
    file.close();
    return k;
}

QString Function::DropTables(QString tableName){
    QString krr;
    int h=0;

    //","分词分出表名
    QStringList strlist3 = tableName.split(",");

    for(int k=0;k<strlist3.size();k++){
        //循环尝试打开创建好的表
        QString fileName = rootAddress_+"\\"+DBName_+"\\"+strlist3.at(k)+".txt";
        QFile file(fileName);
        if(!file.exists()){
            //打不开就报错
            h=3;
            qDebug()<<"DropTableWrong";
            break;
        }
        else{//能打开，就再打开relation表
            QString fileName2 = rootAddress_+"\\relation.txt";
            QFile file2(fileName2);
            file2.open(QIODevice::ReadWrite| QIODevice::Text);

            //接收relation.txt中的所有信息
            QString a=file2.readAll();
            QByteArray array=file2.readAll();

            //以转行符分割relation.txt的每行信息
            QStringList strlist = a.split("\n");
            file2.close();

            for(int i=0;i<strlist.size();i++){
                //取出relation.txt中一行
                QString b= strlist.at(i);

                //"-"分割有依赖的两个字段
                QStringList strlist2 = b.split("-");

                //接收表1.字段
                QString eeer= strlist2.at(0);
                //"."分割表名和字段名
                QStringList strlist7 = eeer.split(".");

                //如果要删除的表是表1，不允许删除
                if(strlist7.at(0).compare(strlist3.at(k),Qt::CaseSensitive)==0){
                    h=2;
                    file.close();
                    krr="DropTableFail";
                    return krr;
                }
            }
            for(int i=0;i<strlist.size();i++){
                //取出其中一行
                QString b= strlist.at(i);

                //"-"分割有依赖的两个字段
                QStringList strlist2 = b.split("-");

                //接收有依赖的表1.字段
                QString eeer= strlist2.at(0);
                //"."分割表名和字段名
                QStringList strlist7 = eeer.split(".");

                //接收有依赖的表2.字段
                QString c= strlist2.at(strlist2.size()-1);
                //"."分割表名和字段名
                QStringList strlist4 = c.split(".");

                //要删除的表不是表1，但是表2，就可以删除
                if(strlist7.at(0).compare(strlist3.at(k),Qt::CaseSensitive)!=0 && strlist4.at(0).compare(strlist3.at(k),Qt::CaseSensitive)==0){
                    QFile::remove(fileName);//删除表
                    strlist.removeAt(i);//删除依赖
                    h=1;
                }else if(strlist7.at(0).compare(strlist3.at(k),Qt::CaseSensitive)!=0 && strlist4.at(0).compare(strlist3.at(k),Qt::CaseSensitive)!=0){
                    //要删除的表不是表1，也不是表2，就可以删除
                    QFile::remove(fileName);//删除表
                    h=1;
                }
            }

            //打开relation.txt
            QFile file3(fileName2);
            file3.open(QIODevice::ReadWrite| QIODevice::Text);

            QTextStream edit(&file3);
            //取出relation.txt原来的信息
            QByteArray array2=file3.readAll();
            file3.resize(0);
            //将修改后的内容重新写入文件
            for(int i=0;i<strlist.size();i++){
                edit<<strlist.at(i)<<endl;
            }

            file3.close();
            if(h==2) { //没有就返回删除失败
                break;
            }
        }
        file.close();
    }

    if(h==1){
        krr="DropTableOK";
    }else if(h==2) {
        //没有就返回删除失败
        krr="DropTableFail";
    }else if(h==3){
        krr="TableNotExist";
    }

    return krr;
}

//新建数据库
QString Function::CreateDB(QString DBName){
    //判断该文件夹存不存在

    QString temp=rootAddress_+"\\"+DBName;
    QFileInfo fileInfo(temp);
    if(fileInfo.exists())
    {
        return "数据库已存在";
    }


    QDir dir(temp);
    if(!dir.exists()){
        dir.mkdir(temp);
        DBName_=DBName;
        return "CreateDBOK";
    }else{
        return "CreateDBWrong";
    }
}

//删除数据库
QString Function::DropDB(QString DBName){

    QString temp=rootAddress_+"\\"+DBName;
    QFile file(temp);
    if(!file.exists()){
        return "数据库不存在";
    }
    bool isFinish=dropFloder(temp);
    if(isFinish==true){
        DBName_="Ruanko";
        return "DropDBOK";
    }else{
        return "DRopDbWrong";
    }
}

//删除文件夹
bool Function::dropFloder(const QString strFilePath){
    if (strFilePath.isEmpty()){
        return false;
    }
    QDir dir(strFilePath);
    if(!dir.exists())
    {
        return true;
    }
    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot); //设置过滤
    QFileInfoList fileList = dir.entryInfoList(); // 获取所有的文件信息
    foreach (QFileInfo file, fileList)
    { //遍历文件信息
        if (file.isFile())
        { // 是文件，删除
            file.dir().remove(file.fileName());
        }else
        { // 递归调用函数，删除子文件夹
            dropFloder(file.absoluteFilePath());
        }
    }
    return dir.rmpath(dir.absolutePath()); // 这时候文件夹已经空了，再删除文件夹本身
}

void Function::matchSqlType(QString text){
    //smatch result;
    QString text_no_n=text;
    text_no_n.replace(QString("\n"),QString(" "));//将换行符替换成空格
    string temp=text_no_n.toLower().toStdString();//全小写
    /*
     * ^ 表示字符串的开始，匹配输入字符串开始的位置,^表示字符串必须以后面的规则开头
     * \ 表示将下一字符标记为特殊字符、转义字符
     * $ 表示字符串的结尾，匹配输入字符串结尾的位置
     * \s 表示任意空白符(tab也包含在内)
     * \s* 表示若干个空格（可以是0个）
     * \s+ 表示一个或多个空格
     * \w 表示任意字母、数字、下划线
     */

    if(regex_search (temp, regex("^create\\s+database"))){
        //新建数据库
        //Create database <DBname>;
        QStringList tempList=text.split(" ",QString::SkipEmptyParts);
        QStringList name=tempList[2].split(";",QString::SkipEmptyParts);

        sendData(CreateDB(name[0]));

        //qDebug()<<" create database ok";
    }else if(regex_search (temp, regex("^drop\\s+database"))){
        //删除数据库
        //Drop database <DBname>;
        QStringList tempList=text.split(" ",QString::SkipEmptyParts);
        QStringList name=tempList[2].split(";",QString::SkipEmptyParts);

        sendData( DropDB(name[0]));

        //qDebug()<<" drop database ok";
    }else if(regex_search (temp, regex("^create\\s+table"))){
        //新建表
        /*
         * Create table <tablename>(
         * <fieldName>  <type>  [PK],
         * <fieldName>  <type>  [FK=<tablename>.<field>],
         * <fieldName>  <type>
         * );
         */
        QStringList tempList=text.split("(\n",QString::SkipEmptyParts);
        QStringList line1=tempList[0].split(" ",QString::SkipEmptyParts);
        QStringList line2=tempList[1].split("\n);",QString::SkipEmptyParts);
        sendData(CreateTables(line1[2],line2[0]));

        //qDebug()<<" create table ok";
    }else if(regex_search (temp, regex("^drop\\s+table"))){
        //删除表
        //Drop table <tablename>;
        QStringList tempList=text.split(" ",QString::SkipEmptyParts);
        QStringList name=tempList[2].split(";",QString::SkipEmptyParts);

        sendData(DropTables(name[0]));

        //qDebug()<<" drop table ok";
    }else if(regex_search (temp,regex("^alter\\s+table"))){
        //修改表
        QStringList tempList=text.split("\n",QString::SkipEmptyParts);
        QStringList name=tempList[0].split(" ",QString::SkipEmptyParts);

        if(regex_search (temp, regex("^alter\\s+table\\s+(\\w+)\\s+add"))){
            //添加字段
            /*
             * Alter table <tablename>
             * Add <fieldname> <fieldtype>;
             */
            QStringList tempInfo=tempList[1].split(";",QString::SkipEmptyParts);
            QStringList alterInfo=tempInfo[0].split(" ",QString::SkipEmptyParts);
            QString qstr=QString::fromStdString("");

            sendData(AlterTable(alterInfo[0],name[2],alterInfo[1],alterInfo[2],qstr,qstr));
            //sendData(fun_->AlterTable(operate,table,column,dataType,newcolum,newtype));

           //qDebug()<<" alter table add ok";
        }else if(regex_search (temp, regex("^alter\\s+table\\s+(\\w+)\\s+drop"))){
            //删除字段
            /*
             * Alter table <tablename>
             * Drop <fieldname> <fieldtype>;
             */
            QStringList tempInfo=tempList[1].split(";",QString::SkipEmptyParts);
            QStringList alterInfo=tempInfo[0].split(" ",QString::SkipEmptyParts);
            QString qstr=QString::fromStdString("");

            sendData(AlterTable(alterInfo[0],name[2],alterInfo[1],alterInfo[2],qstr,qstr));

            //qDebug()<<" alter table drop ok";
        }else if(regex_search (temp, regex("^alter\\s+table\\s+(\\w+)\\s+rename"))){
            //重命名字段
            /*
             * Alter table <tablename>
             * Rename <fieldname> <fieldtype>
             * to <newfieldname> <newfieldtype>;
             */
            QStringList oldInfo=tempList[1].split(" ",QString::SkipEmptyParts);
            QStringList alterInfo=tempList[2].split(";",QString::SkipEmptyParts);
            QStringList newInfo=alterInfo[0].split(" ",QString::SkipEmptyParts);
            QString command=QString::fromStdString("rename");

            sendData(AlterTable(oldInfo[0],name[2],oldInfo[1],oldInfo[2],newInfo[1],newInfo[2]));

           // qDebug()<<" alter table rename ok";
        }
    }else if(regex_search (temp, regex("^insert\\s+into\\s+"))){
        //插入记录
        /*
         * Insert into <tablename>
         * Values (<value1>,<value2>,...);
         */
        QStringList tempList=text.split("\n",QString::SkipEmptyParts);
        QStringList name=tempList[0].split(" ",QString::SkipEmptyParts);
        QStringList tempText=tempList[1].split("(",QString::SkipEmptyParts);
        QStringList text1=tempText[1].split(");",QString::SkipEmptyParts);

        sendData(insert(name[2],text1[0]));

        //qDebug()<<" insert ok";
    }else if(regex_search (temp, regex("^delete\\s+"))){
        //删除记录
        /*
         * Delete <tablename>
         * Where <condition>;
         */
        QStringList tempList=text.split("\n",QString::SkipEmptyParts);
        QStringList name=tempList[0].split(" ",QString::SkipEmptyParts);
        QStringList tempInfo=tempList[1].split(";",QString::SkipEmptyParts);
        QStringList dropInfo=tempInfo[0].split(" ",QString::SkipEmptyParts);

        sendData(delete_function(name[1],dropInfo[1]));

        //qDebug()<<" delete ok";
    }else if(regex_search (temp, regex("^update\\s+"))){
        //更新记录
        /*
         * Update <tablename>
         * Set <updateinfo>
         * Where <condition>;
         */
        QStringList tempList=text.split("\n",QString::SkipEmptyParts);
        QStringList name=tempList[0].split(" ",QString::SkipEmptyParts);
        QStringList setInfo=tempList[1].split(" ",QString::SkipEmptyParts);
        QStringList tempInfo=tempList[2].split(";",QString::SkipEmptyParts);
        QStringList updInfo=tempInfo[0].split(" ",QString::SkipEmptyParts);

        sendData(update_function(name[1],setInfo[1],updInfo[1]));

        //qDebug()<<" update ok";
    }else if(regex_search (temp, regex("^select\\s+"))){
        //查询表
        QStringList tempList=text.split("\n",QString::SkipEmptyParts);
        QStringList name=tempList[0].split(" ",QString::SkipEmptyParts);
        QString qstr=QString::fromStdString("");

        if(regex_search (temp, regex("^select\\s+(.+)\\s+from\\s+(\\w+)\\s+where\\s+(\\w+)\\s+order"))){
            /*
             * Select <fieldname>
             * From <tablename>
             * Where <condition>
             * Order by <order>;
             */
            QStringList fromInfo=tempList[1].split(" ",QString::SkipEmptyParts);
            QStringList whereInfo=tempList[2].split(" ",QString::SkipEmptyParts);
            QStringList tempInfo=tempList[3].split(";",QString::SkipEmptyParts);
            QStringList orderInfo=tempInfo[0].split(" ",QString::SkipEmptyParts);

            sendTable((select(name[1],fromInfo[1],whereInfo[1],orderInfo[1])));

            //qDebug()<<" select ok";
        }else if(regex_search (temp, regex("^select\\s+(.+)\\s+from\\s+(\\w+)\\s+where"))){
            /*
             * Select <fieldname>
             * From <tablename>
             * Where <condition>;
             */
            QStringList fromInfo=tempList[1].split(" ",QString::SkipEmptyParts);
            QStringList tempInfo=tempList[2].split(";",QString::SkipEmptyParts);
            QStringList whereInfo=tempInfo[0].split(" ",QString::SkipEmptyParts);

            sendTable(select(name[1],fromInfo[1],whereInfo[1],qstr));
        }else if(regex_search (temp, regex("^select\\s+(.+)\\s+from"))){
            /*
             * Select <fieldname>
             * From <tablename>;
             */
            QStringList tempInfo=tempList[1].split(";",QString::SkipEmptyParts);
            QStringList fromInfo=tempInfo[0].split(" ",QString::SkipEmptyParts);
            sendTable(select(name[1],fromInfo[1],qstr,qstr));
        }
    }else if(regex_search (temp, regex("^grant\\s+"))){
        //授权
        /*
         * grant <priority>
         * on <tablename>
         * from <username>;
         */
        QStringList tempList=text.split("\n",QString::SkipEmptyParts);
        QStringList name=tempList[0].split(" ",QString::SkipEmptyParts);
        QStringList onInfo=tempList[1].split(" ",QString::SkipEmptyParts);
        QStringList tempInfo=tempList[2].split(";",QString::SkipEmptyParts);
        QStringList toInfo=tempInfo[0].split(" ",QString::SkipEmptyParts);
        QString command=QString::fromStdString("grant");

        sendData(OperateRights(command,name[1],onInfo[1],toInfo[1]));

        //qDebug()<<" grant ok";
    }else if(regex_search (temp, regex("^revoke\\s+"))){
        //回收
        /*
         * revoke <priority>
         * on <tablename>
         * from <username>;
         */
        QStringList tempList=text.split("\n",QString::SkipEmptyParts);
        QStringList name=tempList[0].split(" ",QString::SkipEmptyParts);
        QStringList onInfo=tempList[1].split(" ",QString::SkipEmptyParts);
        QStringList tempInfo=tempList[2].split(";",QString::SkipEmptyParts);
        QStringList toInfo=tempInfo[0].split(" ",QString::SkipEmptyParts);
        QString command=QString::fromStdString("revoke");

        sendData(OperateRights(command,name[1],onInfo[1],toInfo[1]));

        //qDebug()<<" revoke ok";
    }
}
