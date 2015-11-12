#-------------------------------------------------
#
# Project created by QtCreator 2014-08-02T15:05:34
#
#-------------------------------------------------

QT       += core gui \
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QPaper
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newproject.cpp \
    projectdata.cpp \
    newpaper.cpp \
    paperdata.cpp \
    journals.cpp \
    addjournal.cpp \
    bibref.cpp \
    bibarticle.cpp

HEADERS  += mainwindow.h \
    newproject.h \
    projectdata.h \
    newpaper.h \
    paperdata.h \
    journals.h \
    addjournal.h \
    bibref.h \
    bibarticle.h

FORMS    += mainwindow.ui \
    newproject.ui \
    newpaper.ui \
    journals.ui \
    addjournal.ui \
    bibref.ui

OTHER_FILES += \
    todo.txt \
    Journal_strings.txt

RESOURCES += \
    qpaperres.qrc
