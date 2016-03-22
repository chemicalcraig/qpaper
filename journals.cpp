#include "journals.h"
#include "QDebug"
#include "QFile"
#include "ui_journals.h"
#include <QDir>

Journals::Journals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Journals)
{
    ui->setupUi(this);

    /* Display Journals */
    showJournals();

    /* Connections */
    connect(ui->pushButton_add, SIGNAL(clicked()), this, SLOT(addJournal()));
    connect(ui->pushButton_select, SIGNAL(clicked()), this, SLOT(selectJournal()));
}

Journals::~Journals()
{
    delete ui;
}

/*******************************
 *Functions
 ******************************/

/* Select Journal */
void Journals::selectJournal() {
    QString str;
        if (ui->listWidget_journallist->selectedItems().length()>0) {
        str = ui->listWidget_journallist->selectedItems().at(0)->text();
        this->selectedJournal = str.split("=").at(0);
        this->close();
    }
}

/* Show journals in window */
void Journals::showJournals () {
    /* Clear list */
    ui->listWidget_journallist->clear();

    /* Display journals */
    QFile res(QDir::homePath()+"/.qpaper/Journals_readable.txt");
    res.open(QIODevice::ReadOnly|QIODevice::Text);
    QTextDocument *doc = new QTextDocument ;
    doc->setPlainText(res.readAll());

    /* Get nlines */
    QStringList list = doc->toPlainText().split(QRegExp("[\r\n]"),QString::SkipEmptyParts);
    int nlines = list.length();

    /* Insert document into listview */
    for (int i=0; i<nlines; i++) {
        ui->listWidget_journallist->insertItem(i,list.at(i) );
    }

    //ui->textEdit->setDocument(doc);
}

/* Add a new journal to list */
void Journals::addJournal() {
    AddJournal *aj = new AddJournal(this);
    int res = aj->exec();

    if (res == QDialog::Accepted) {
        showJournals();
    }
}
