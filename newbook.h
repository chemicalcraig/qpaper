#ifndef NEWBOOK_H
#define NEWBOOK_H

#include <QDialog>
#include <QFileDialog>

namespace Ui {
class NewBook;
}

class NewBook : public QDialog
{
    Q_OBJECT

public:
    explicit NewBook(QWidget *parent = 0);
    ~NewBook();

    QStringList allFields;
    QString btitle,authors,volume,editors,edition;
    QString pages,issue,publisher,year,notes,chtitle,series;
    QString key,address;
    QString generateKey(QString auth, QString year, QString pg);
    QString pdf;
    Ui::NewBook *ui;
    void setFields(QString key, QString btitle, QString chtitle, QString auth, QString editors,
                   QString volume, QString issue, QString edition, QString series, QString pages,  QString year,
                   QString publisher, QString address, QString notes, QString pdfpath);

private:

public slots:
    void okClicked();
    void entryChanged(QString str);
    void addPdf();
};

#endif // NEWBOOK_H
