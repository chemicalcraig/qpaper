#include "newproject.h"
#include "ui_newproject.h"

NewProject::NewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewProject)
{
    ui->setupUi(this);

    //Connections
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(okClicked( )));
}

NewProject::~NewProject()
{
    delete ui;
}

/*******************************************
 *Functions
 *******************************************/
void NewProject::okClicked() {
    this->name = ui->lineEdit_projectname->text();
    this->description = ui->plainTextEdit_projectdescription->toPlainText();
}
