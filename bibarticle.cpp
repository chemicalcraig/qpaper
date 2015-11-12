#include "bibarticle.h"

BibArticle::BibArticle()
{
}

/* Constructor with entries */
BibArticle::BibArticle(QString k,QString t,QString a,QString j,QString v,QString p,QString i,QString y,QString n, QString pa) {
    this->key=k;
    this->title=t;
    this->authors=a;
    this->journal=j;
    this->volume=v;
    this->page=p;
    this->issue=i;
    this->year=y;
    this->note=n;
    this->path=pa;
}

void BibArticle::setEntries(QString k,QString t,QString a,QString j,QString v,QString p,QString i,QString y,QString n, QString pa) {
    this->key=k;
    this->title=t;
    this->authors=a;
    this->journal=j;
    this->volume=v;
    this->page=p;
    this->issue=i;
    this->year=y;
    this->note=n;
    this->path=pa;
}

/* Format BibTeX entry as QByteArray */
void BibArticle::formatEntry() {
    this->bibEntry+="\n";
    this->bibEntry+="@article{"+this->getkey()+",\n";
    this->bibEntry+="  Author = {"+this->getauth()+"},\n";
    this->bibEntry+="  Journal = {"+this->getjournal()+"},\n";
    this->bibEntry+="  Number = {"+this->getissue()+"},\n";
    this->bibEntry+="  Pages = {"+this->getpage()+"},\n";
    this->bibEntry+="  Title = {"+this->gettitle()+"},\n";
    this->bibEntry+="  Volume = {"+this->getvolume()+"},\n";
    this->bibEntry+="  Year = {"+this->getyear()+"}}\n";
}

/* Get individual entries */
QString BibArticle::getauth() {
    QString s(this->authors );
    return s;
}

QString BibArticle::gettitle(){
    QString s(this->title);
    return s;
}

QString BibArticle::getpage(){
    QString s(this->page);
    return s;
}

QString BibArticle::getyear(){
    QString s(this->year);
    return s;
}

QString BibArticle::getvolume(){
    QString s(this->volume);
    return s;
}

QString BibArticle::getnumber(){
    QString s(this->number);
    return s;
}

QString BibArticle::getjournal(){
    QString s(this->journal);
    return s;

}

QString BibArticle::getmonth(){
    QString s(this->month);
    return s;
}

QString BibArticle::getnote(){
    QString s(this->note);
    return s;
}

QString BibArticle::getkey(){
    QString s=this->key;
    return s;
}

QString BibArticle::getissue(){
    QString s(this->issue);
    return s;
}

