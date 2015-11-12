#include "bibref.h"
#include "ui_bibref.h"

Bibref::Bibref(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Bibref)
{
    ui->setupUi(this);
}

Bibref::~Bibref()
{
    delete ui;
}

void Bibref::showRef(BibArticle article) {
    QString s;
    s.append(article.bibEntry);
    ui->plainTextEdit_bib->insertPlainText(s);
    ui->label_id->setText("Key: "+article.getkey());
}
void Bibref::showRef(BibArticle *article) {
    QString s;
    s.append(article->bibEntry);
    ui->plainTextEdit_bib->insertPlainText(s);
    ui->label_id->setText("Key: "+article->getkey());
}
