#include "addjournal.h"
#include "ui_addjournal.h"

AddJournal::AddJournal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddJournal)
{
    ui->setupUi(this);

    /* Connections */
    connect(ui->buttonBox, SIGNAL(accepted()) , this , SLOT(okClicked()));
}

AddJournal::~AddJournal()
{
    delete ui;
}

/****************************
 *Functions
 ****************************/

void AddJournal::okClicked() {
    QStringList list;

    QString str,str2;
    int lines;

    //format entry for bib file
    QFile res("Journal_strings.txt");
    if (res.open(QIODevice::ReadOnly|QIODevice::Text)) {
        int i=0;
        //Get number of lines in file and store all entries for sorting
        QTextStream ts(&res);
        while (!ts.atEnd()) {
            QString line = ts.readLine();
            if (line != "end") {
                list += line;
            }
            i++;
        }
        //format and add name of new journal to list
        str = "@string{"+ui->lineEdit->text()+"={"+ui->lineEdit_2->text()+"}}";
        list += str;
        //sort list
        list.sort();
        //add end
        list += "end";
        lines = i;
    }
    res.close();
    if (res.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QTextStream ts(&res);
        for (int j=0; j<list.length(); j++){
            ts<<list.at(j)<<"\n";
        }
    }
    res.close();


    //format entry for human readable txt file
    list.clear();
    QFile res2("Journals_readable.txt");
    if (res2.open(QIODevice::ReadOnly|QIODevice::Text)) {
        int i=0;
        //Get number of lines in file and store all entries for sorting
        QTextStream ts(&res2);
        while (!ts.atEnd()) {
            QString line = ts.readLine();
            list += line;
            i++;
        }
        //Add new formatted entry to list
        if (ui->lineEdit_title->text().isEmpty())
            str = ui->lineEdit->text()+" = "+ui->lineEdit_2->text();
        else
            str = ui->lineEdit->text()+" = "+ui->lineEdit_2->text()+", "+ui->lineEdit_title->text();
        list += str;
        //sort list
        list.sort();
    }
    res2.close();

    if (res2.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QTextStream out(&res2);
        for (int j=0; j<list.length(); j++)
        out<<list.at(j)<<"\n";
    }
    res2.close();
}
