#ifndef PAPERDATA_H
#define PAPERDATA_H

#include "mainwindow.h"

class PaperData
{
public:
    PaperData();

    QString title,authors,journal,volume;
    QString pages,issue,publisher,year,notes;
    QString key;
};

#endif // PAPERDATA_H
