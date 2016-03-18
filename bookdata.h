#ifndef BOOKDATA_H
#define BOOKDATA_H

#include "mainwindow.h"

class BookData
{
public:
    BookData();

    QString btitle,authors,volume,editors,edition;
    QString pages,issue,publisher,year,notes,chtitle,series;
    QString key,address;
};

#endif // BOOKDATA_H
