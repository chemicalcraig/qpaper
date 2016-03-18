#include "newbook.h"
#include "ui_newbook.h"

NewBook::NewBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewBook)
{
    ui->setupUi(this);

    connect(ui->buttonBox,SIGNAL(accepted()), this, SLOT(okClicked()));
    connect(ui->lineEdit_auth, SIGNAL(textChanged(QString)), this, SLOT(entryChanged(QString)));
    connect(ui->lineEdit_year,SIGNAL(textChanged(QString)), this, SLOT(entryChanged(QString)));
    connect(ui->lineEdit_pages ,SIGNAL(textChanged(QString)), this, SLOT(entryChanged(QString)));
    connect(ui->pushButton_addPdf, SIGNAL(clicked()), this, SLOT(addPdf()));
}

NewBook::~NewBook()
{
    delete ui;
}
/*******************************************
 *Functions
 *******************************************/

/* Edit paper */
void NewBook::setFields(QString key, QString btitle, QString chtitle, QString auth, QString editors,
                         QString volume, QString issue, QString edition, QString series, QString pages,  QString year,
                         QString publisher, QString address, QString notes, QString pdfpath){
    ui->lineEdit_btitle->setText(btitle);
    ui->lineEdit_chtitle->setText(chtitle);
    ui->lineEdit_auth->setText(auth);
    ui->lineEdit_editors->setText(editors);
    ui->lineEdit_volume->setText(volume);
    ui->lineEdit_pages->setText(pages);
    ui->lineEdit_issue->setText(issue);
    ui->lineEdit_year->setText(year);
    ui->lineEdit_edition->setText(edition);
    ui->lineEdit_series->setText(series);
    ui->lineEdit_publisher->setText(publisher);
    ui->lineEdit_address->setText(address);
    ui->plainTextEdit_notes->document()->setPlainText(notes);
    ui->lineEdit_key->setText(key);
    this->pdf = pdfpath;
}

/* Attach a pdf to the paper entry */
void NewBook::addPdf() {
    QString pdf_file = QFileDialog::getOpenFileName(this, tr("Open File"),
                                QDir::currentPath(),
                                                    tr("PDF Files (*.pdf *.PDF)"));
    if (!pdf_file.isEmpty()) {
        this->pdf = pdf_file;
    }
}

/* Text changed */
void NewBook::entryChanged(QString str) {
    QString auth, year, pg;
    /* Get entries */
    auth = ui->lineEdit_auth->text();
    year = ui->lineEdit_year->text();
    pg = ui->lineEdit_pages->text();

    /* get formatted key */
    this->key = generateKey(auth,year,pg);

    /* update label */
    ui->lineEdit_key->setText(this->key);
}

/* Generate BibKey */
QString NewBook::generateKey(QString auth, QString year, QString pg) {
    QString ret;
    QStringList list = auth.split(";");
    QStringList list2 = list.last().split(" ");
    auth = list2.last();
    pg = pg.split("-").first();
    year = year.remove(0,2);
    ret = auth+year+":"+pg;
    return ret;
}

void NewBook::okClicked() {
    this->btitle = ui->lineEdit_btitle->text();
    this->authors = ui->lineEdit_auth->text();
    this->volume = ui->lineEdit_volume->text();
    this->issue = ui->lineEdit_issue->text();
    this->edition = ui->lineEdit_edition->text();
    this->editors = ui->lineEdit_editors->text();
    this->year = ui->lineEdit_year->text();
    this->notes = ui->plainTextEdit_notes->document()->toPlainText();
    this->pages = ui->lineEdit_pages->text();
    this->publisher = ui->lineEdit_publisher->text();
    this->address = ui->lineEdit_address->text();
    this->chtitle = ui->lineEdit_chtitle->text();
    this->series = ui->lineEdit_series->text();
    this->key = ui->lineEdit_key->text();

    allFields<< this->key << this->btitle << this->chtitle << this->authors
             << this->editors << this->volume << this->issue << this->edition
             << this->series << this->pages << this->year << this->publisher
             << this->address << this->notes << this->pdf;
}
