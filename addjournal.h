#ifndef ADDJOURNAL_H
#define ADDJOURNAL_H

#include "QFile"
#include <QDialog>
#include <QTextStream>
#include <QTextDocument>
#include <QDebug>

namespace Ui {
class AddJournal;
}

class AddJournal : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddJournal(QWidget *parent = 0);
    ~AddJournal();
    
private:
    Ui::AddJournal *ui;

public slots:
    void okClicked();
};

#endif // ADDJOURNAL_H
