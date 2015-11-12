#ifndef BIBARTICLE_H
#define BIBARTICLE_H
#include <QString>
#include <QDebug>

class BibArticle
{
public:
    BibArticle();
    BibArticle(QString k, QString t, QString a, QString j, QString v, QString p, QString i, QString y, QString n, QString pa);
    void setEntries(QString k, QString t, QString a, QString j, QString v, QString p, QString i, QString y, QString n, QString pa);
    QString authors,title,page,year,volume,number,journal,month, note,key,issue,path;
    QByteArray bibEntry;
    void setauth(QString s){this->authors=s;};
    void settitle(QString s){this->title=s;};
    void setpage(QString s){this->page=s;};
    void setyear(QString s){this->year=s;};
    void setvolume(QString s){this->volume=s;};
    void setjournal(QString s){this->journal=s;};
    void setmonth(QString s){this->month=s;};
    void setnote(QString s){this->note=s;};
    void setkey(QString s){this->key=s;};
    void setissue(QString s){this->issue=s;};
    void setpath(QString s){this->path=s;};
    void formatEntry();

    QString getauth();
    QString gettitle();
    QString getpage();
    QString getyear();
    QString getvolume();
    QString getnumber();
    QString getjournal();
    QString getmonth();
    QString getnote();
    QString getkey();
    QString getissue();

};

#endif // BIBARTICLE_H
