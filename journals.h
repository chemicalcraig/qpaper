#ifndef JOURNALS_H
#define JOURNALS_H

#include "addjournal.h"
#include <QDialog>

namespace Ui {
class Journals;
}

class Journals : public QDialog
{
    Q_OBJECT
    
public:
    explicit Journals(QWidget *parent = 0);
    void showJournals ();
    QString selectedJournal;

    ~Journals();
    
private:
    Ui::Journals *ui;

public slots:
    void addJournal();
    void selectJournal();
};

#endif // JOURNALS_H
