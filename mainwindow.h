#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qt/QtSql>
#include <Qt/qstandarditemmodel.h>
#include <QDebug>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include "newproject.h"
#include "newpaper.h"
#include "projectdata.h"
#include "paperdata.h"
#include "journals.h"
using namespace std;

class Projectdata;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QSqlDatabase db; // Paper database
    bool    projectSet; //Is there a current project?
    bool    paperSet; //Is there a current paper?
    int     currentprojectId;  //Sets current project
    bool    isprojectchild;
    int     parentprojects;
    QString currentprojectname,currentpapername,currentpaperkey;
    QStringList projectNames,allpapernames,allpaperkeys;
    QStandardItemModel mainprojectmodel;

    //Main Project data wrapper
    Projectdata *mainProjects;
    int nprojects;
    //add a new project to mainProjects
    void addProject(Projectdata proj);
    QStringList parseAuthors(QString str);
    //get all projects a paper belongs to
    QString getProjectsfromPaper(QString papertitle);
    QStringList getProjectsfromBibkey(QString bibkey);

    QString getLastAuthor(QString str); //get last author on paper
    QString formatAuthorList(QString str); //format author list
    QString formatBibKey(QString auth, QString year, QString pg); //format bibtex key
    QString getJournal(QString j, QFile *res); //get journal abbreviation from accronym

    void paperAccepted(NewPaper *newpaper);


    
private:
    Ui::MainWindow *ui;
    void initializeProjectData(); //gets a list of all project names
    void initializePaperList(); //gets a stringlist of all paper titles
    void setProjectAll(); //sets current project to "All" and changes view and variables accordingly



public slots:
    void headerClicked(QModelIndex ind);
    void newProject();  //Add a new project
    void newSubProject();  //Add a new sub project
    void newPaper();    //Add a new paper
    void projectClicked(QModelIndex ind); //Click on project name, sets to current project
    void projectClicked(QString str); //overloaded version of above
    void deleteProject(); //delete project
    void addNewPaper();
    void projectEntryChanged(); //change project name
    void paperClicked(QModelIndex ind); //clicked on paper
    void paperClicked(QModelIndex ind,bool mult); //clicked on paper

    void removePaperfromProject(); //Remove paper
    void deletePaper(); //Delete paper from db
    void addPaperstoProject(int nproj);
    //void addPapertoProject(int n); //Add paper to project from combobox_allpapers
    void addPapertoProject(int n,QString str); //Add paper to project from combobox_allpapers
    void addPapertoProjectfromBox(QString str); //Add paper to project from combobox_projects
    void paperDataChanged(QModelIndex ind1, QModelIndex ind2); //paper entry changed in table view
    void printProjectBibtex();  //print project bibtex
    void showJournalAbbv(); //show journal abbreviations
    void openPaper(); //open paper w/ external program
    void editPaper();

};

#endif // MAINWINDOW_H
