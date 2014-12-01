#ifndef NEWPAPER_H
#define NEWPAPER_H

#include "journals.h"

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class NewPaper;
}

class NewPaper : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewPaper(QWidget *parent = 0);
    ~NewPaper();

    QStringList allFields;
    QString title,authors,journal,volume;
    QString pages,issue,publisher,year,notes;
    QString key;
    QString generateKey(QString auth, QString year, QString pg);
    QString pdf;
    Ui::NewPaper *ui;
    void setFields(QString title, QString auth, QString journal, QString volume, QString pages, QString issue, QString year, QString notes, QString pdfpath);

private:


public slots:
    void okClicked();
    void showJournals();
    void entryChanged(QString str);
    void addPdf();
};

#endif // NEWPAPER_H
