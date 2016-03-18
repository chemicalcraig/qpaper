#include "newproject.h"
#include "ui_newproject.h"
#include "qbuttongroup.h"
#include <QAbstractButton>
#include <QPushButton>
#include <QDebug>

NewProject::NewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProject)
{
    ui->setupUi(this);

    //Connections
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(okClicked( )));

    //Project name changed
    connect(ui->lineEdit_projectname, SIGNAL(textChanged(QString)), this, SLOT(nameChanged(QString)));

    ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
}

NewProject::~NewProject()
{
    delete ui;
}

/*******************************************
 *Functions
 *******************************************/
/** Project name changed, check for spaces and other characters **/
void NewProject::nameChanged(QString str) {
    //check for forbidden characters, if detected disable ok button
    if (str.contains(" ")) {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);
    } else {
        ui->buttonBox->button(QDialogButtonBox::Ok)->setEnabled(true);
    }
}

void NewProject::okClicked() {
    if (ui->lineEdit_projectname->text().contains(" ")) {

    }
    this->name = ui->lineEdit_projectname->text();
    this->description = ui->plainTextEdit_projectdescription->toPlainText();
}
