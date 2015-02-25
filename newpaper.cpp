#include "newpaper.h"
#include "ui_newpaper.h"

NewPaper::NewPaper(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewPaper)
{
    ui->setupUi(this);

    connect(ui->buttonBox,SIGNAL(accepted()), this, SLOT(okClicked()));
    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(showJournals()));
    connect(ui->lineEdit_authors, SIGNAL(textChanged(QString)), this, SLOT(entryChanged(QString)));
    connect(ui->lineEdit_year,SIGNAL(textChanged(QString)), this, SLOT(entryChanged(QString)));
    connect(ui->lineEdit_pages ,SIGNAL(textChanged(QString)), this, SLOT(entryChanged(QString)));
    connect(ui->pushButton_addPdf, SIGNAL(clicked()), this, SLOT(addPdf()));
}

NewPaper::~NewPaper()
{
    delete ui;
}

/*******************************************
 *Functions
 *******************************************/

/* Edit paper */
void NewPaper::setFields(QString key,QString title, QString auth, QString journal, QString volume, QString pages, QString issue, QString year, QString notes, QString pdfpath) {
    ui->lineEdit_title->setText(title);
    ui->lineEdit_authors->setText(auth);
    ui->lineEdit_journal->setText(journal);
    ui->lineEdit_volume->setText(volume);
    ui->lineEdit_pages->setText(pages);
    ui->lineEdit_issue->setText(issue);
    ui->lineEdit_year->setText(year);
    ui->lineEdit_keywords->setText(notes);
    ui->lineEdit_key->setText(key);
    this->pdf = pdfpath;
}

/* Attach a pdf to the paper entry */
void NewPaper::addPdf() {
    QString pdf_file = QFileDialog::getOpenFileName(this, tr("Open File"),
                                QDir::currentPath(),
                                                    tr("PDF Files (*.pdf *.PDF)"));
    if (!pdf_file.isEmpty()) {
        this->pdf = pdf_file;
    }
}

/* show journals */
void NewPaper::showJournals() {

    Journals *j = new Journals(this);
    int res = j->exec();

    ui->lineEdit_journal->setText(j->selectedJournal);
}

/* Text changed */
void NewPaper::entryChanged(QString str) {
    QString auth, year, pg;
    /* Get entries */
    auth = ui->lineEdit_authors->text();
    year = ui->lineEdit_year->text();
    pg = ui->lineEdit_pages->text();

    /* get formatted key */
    this->key = generateKey(auth,year,pg);

    /* update label */
    ui->lineEdit_key->setText(this->key);
}

/* Generate BibKey */
QString NewPaper::generateKey(QString auth, QString year, QString pg) {
    QString ret;
    QStringList list = auth.split(";");
    QStringList list2 = list.last().split(" ");
    auth = list2.last();
    pg = pg.split("-").first();
    year = year.remove(0,2);
    ret = auth+year+":"+pg;
    return ret;
}

void NewPaper::okClicked() {
    this->title = ui->lineEdit_title->text();
    this->authors = ui->lineEdit_authors->text();
    this->volume = ui->lineEdit_volume->text();
    this->issue = ui->lineEdit_issue->text();
    this->year = ui->lineEdit_year->text();
    this->notes = ui->lineEdit_keywords->text();
    this->pages = ui->lineEdit_pages->text();
    this->journal = ui->lineEdit_journal->text();
    this->publisher = ui->lineEdit_publisher->text();
    this->key = ui->lineEdit_key->text();

    allFields<<this->key<<this->title<<this->authors<<this->journal
               <<this->volume<<this->pages<<this->issue<<this->year<<this->notes
                 <<this->pdf ;
}
