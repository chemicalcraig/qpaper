#include "confirmdelete.h"
#include "ui_confirmdelete.h"

ConfirmDelete::ConfirmDelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmDelete)
{
    ui->setupUi(this);
//    QString str = ui->label->text();
//    str += "/n"+this->deleteObj+"?";
//    ui->label->setText(str);
}

ConfirmDelete::~ConfirmDelete()
{
    delete ui;
}

void ConfirmDelete::setDeleteObj(QString s) {
    this->deleteObj = s;
    ui->label_title->setText(this->deleteObj+" ?");
}
