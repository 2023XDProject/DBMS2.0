#-------------------------------------------------
#
# Project created by QtCreator 2022-05-12T15:28:49
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DBtraining
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    createdb.cpp \
    dropdb.cpp \
        main.cpp \
        mainwindow.cpp \
    select.cpp \
    deletetable.cpp \
    updatetable.cpp \
    function.cpp \
    inserttable.cpp \
    altertable.cpp \
    createusertable.cpp \
    operaterighttable.cpp \
    createtablew.cpp \
    droptable.cpp

HEADERS += \
    createdb.h \
    dropdb.h \
        mainwindow.h \
    select.h \
    deletetable.h \
    updatetable.h \
    function.h \
    inserttable.h \
    altertable.h \
    createusertable.h \
    operaterighttable.h \
    createtablew.h \
    droptable.h

FORMS += \
    createdb.ui \
    dropdb.ui \
        mainwindow.ui \
    select.ui \
    deletetable.ui \
    updatetable.ui \
    inserttable.ui \
    altertable.ui \
    createusertable.ui \
    operaterighttable.ui \
    createtablew.ui \
    droptable.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
