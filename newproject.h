#ifndef NEWPROJECT_H
#define NEWPROJECT_H

#include <QDialog>

namespace Ui {
class NewProject;
}

class NewProject : public QDialog
{
    Q_OBJECT
    
public:
    explicit NewProject(QWidget *parent = 0);
    ~NewProject();

    QString name,description;
    
private:
    Ui::NewProject *ui;

public slots:
    void okClicked();
};

#endif // NEWPROJECT_H
