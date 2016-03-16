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
        QTextStream ts(&res);
        while (!ts.atEnd()) {
            QString line = ts.readLine();
            list += line;
            qDebug()<<i<<" "<<list.at(i);
            i++;
        }
        lines = i;
    }
    res.close();
    if (res.open(QIODevice::WriteOnly|QIODevice::Text)) {
        QTextStream ts(&res);
        str = "@string{"+ui->lineEdit->text()+"={"+ui->lineEdit_2->text()+"}}";
        for (int j=0; j<lines-1; j++){
            ts<<list.at(j)<<"\n";
        }
        ts<<str<<"\n";
        ts<<"end"<<"\n";
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
