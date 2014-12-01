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

    QString str;

    //format entry for bib file
    QFile res("Journal_strings.txt");
        if (res.open(QIODevice::Append|QIODevice::Text)) {
        str = "@string{"+ui->lineEdit->text()+"={"+ui->lineEdit_2->text()+"}}";
        QTextStream ts(&res);
        ts<<str<<"\n";
    }

    //format entry for human readable txt file
    QFile res2("Journals_readable.txt");
    if (res2.open(QIODevice::Append|QIODevice::Text)) {
        str = ui->lineEdit->text()+" = "+ui->lineEdit_2->text();
        QTextStream out(&res2);
        out<<str<<"\n";
    }


    //res2.write(str.toAscii());
}
