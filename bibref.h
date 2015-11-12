#ifndef BIBREF_H
#define BIBREF_H

#include <QDialog>
#include "bibarticle.h"

namespace Ui {
class Bibref;
}

class Bibref : public QDialog
{
    Q_OBJECT

public:
    explicit Bibref(QWidget *parent = 0);
    ~Bibref();

    void showRef(BibArticle article);

private:
    Ui::Bibref *ui;
};

#endif // BIBREF_H
