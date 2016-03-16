#ifndef CONFIRMDELETE_H
#define CONFIRMDELETE_H

#include <QDialog>

namespace Ui {
class ConfirmDelete;
}

class ConfirmDelete : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDelete(QWidget *parent = 0);
    QString deleteObj;
    void setDeleteObj(QString s);
    ~ConfirmDelete();

private:
    Ui::ConfirmDelete *ui;
};

#endif // CONFIRMDELETE_H
