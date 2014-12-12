#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nprojects = 0;
    parentprojects = 1;

    //Connections
    //New projects
    connect(ui->actionNew_main_project, SIGNAL(triggered()), this, SLOT(newProject()));
    connect(ui->actionSub_project, SIGNAL(triggered()),this,SLOT(newSubProject()));
    connect(ui->actionNew_Main_Project, SIGNAL(triggered()), this, SLOT(newProject()));
    connect(ui->actionNew_Sub_Project, SIGNAL(triggered()),this,SLOT(newSubProject()));

    //Change current project
    connect(ui->treeView_projects, SIGNAL(clicked(QModelIndex)), this, SLOT(projectClicked(QModelIndex)));
    connect(ui->treeView_projects, SIGNAL(activated(QModelIndex)), this, SLOT(projectClicked(QModelIndex)));

    //Delete project
    connect(ui->actionDelete_Project, SIGNAL(triggered()), this, SLOT(deleteProject()));

    //New paper
    connect(ui->actionAdd_Paper, SIGNAL(triggered()), this, SLOT(addNewPaper()));

    //Click on paper
    connect(ui->tableView_papers, SIGNAL(clicked(QModelIndex)), this, SLOT(paperClicked(QModelIndex)));

    //Remove paper from project
    connect(ui->actionRemove_Paper_From_Project, SIGNAL(triggered()), this, SLOT(removePaperfromProject()));

    //Add paper to project from combobox
    connect(ui->comboBox_allpapers, SIGNAL(activated(int)), this, SLOT(addPapertoProject(int)));
    connect(ui->comboBox_projects, SIGNAL(activated(QString)) , this, SLOT(addPapertoProjectfromBox(QString)));

    //Delete paper from entire database
    connect(ui->actionRemove_Paper_From_Database, SIGNAL(triggered()), this, SLOT(deletePaper()));

    //Edit paper
    connect(ui->actionEdit_Paper,SIGNAL(triggered()),this,SLOT(editPaper()));

    //View paper externally
    connect(ui->actionView_Paper, SIGNAL(triggered()), this, SLOT(openPaper()));

    //Set up databases
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QDir::currentPath()+"/papers.db");
    db.open();


    //Set up tables
    QSqlQuery query;
    QString strquery="CREATE TABLE allpapers (id integer primary key, nproject integer, projectid varchar(1000)";
    strquery +=", bibkey varchar(20), title varchar(500), nauth integer, author varchar(1000), journal varchar(100)";
    strquery +=",volume varchar(10), pages varchar(20), issue varchar(20)";
    strquery += ",publisher varchar(100), year varchar(4), notes varchar(5000), pdfpath varchar(5000))";
    query.exec("CREATE TABLE projects (id integer primary key, title varchar(100), description varchar(5000), isparent integer default 1, parentid integer, nchild integer)");
    query.exec(strquery);

    //Set up Project and paper views
    QSqlTableModel *papermodel, *projectmodel;
    QStandardItemModel *projmodel;
    projmodel = new QStandardItemModel ;
    papermodel = new QSqlTableModel;
    papermodel->setEditStrategy(QSqlTableModel::OnManualSubmit );
    projectmodel = new QSqlTableModel;
    //papermodel->setTable("allpapers");
    projectmodel->setTable("projects");
    papermodel->select();
    projectmodel->select();
    ui->treeView_projects->setHeaderHidden(true);
    ui->tableView_papers->setModel(papermodel);
    initializeProjectData();
    initializePaperList();
    ui->treeView_projects->setModel(&mainprojectmodel);
//    ui->tableView_papers->horizontalHeader()->setHidden(true);
//    ui->tableView_papers->hideColumn(0);
//    ui->tableView_papers->hideColumn(1);
//    ui->tableView_papers->hideColumn(2);
//    ui->tableView_papers->hideColumn(4);
//    ui->tableView_papers->hideColumn(10);

    //combo box
    ui->comboBox_allpapers->insertItem(0,"<-- Select a Paper to Add to a Project -->");
    ui->comboBox_allpapers->setHidden(true);
    ui->comboBox_projects->setHidden(true);

    //print project bibtex
    connect(ui->actionCurrent_project, SIGNAL(triggered()), this, SLOT(printProjectBibtex()));


    //Set some parameters
    projectSet  = false;
    paperSet = false;

    //Show all papers
    //setProjectAll();

    //connect paper model
    connect(papermodel,SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(paperDataChanged(QModelIndex,QModelIndex)));

    //Show Journal abbreviations
    connect(ui->actionJournals,SIGNAL(triggered()),this,SLOT(showJournalAbbv()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/********************************************************
 *Functions
 ********************************************************/

/* Edit paper entry */
void MainWindow::editPaper() {
    QSqlQuery query;
    NewPaper *np = new NewPaper(this);

    query.exec("Select title, author, journal, volume, pages, issue, year, notes, pdfpath from '"+currentprojectname+"papers' where bibkey = '"+currentpaperkey+"'");
    while (query.next()) {
        np->setFields(query.value(0).toString(),query.value(1).toString(),
                      query.value(2).toString(),query.value(3).toString(),
                      query.value(4).toString(),query.value(5).toString(),
                      query.value(6).toString(),query.value(7).toString(),
                      query.value(8).toString());
    }

    int res = np->exec();

    if (res == QDialog::Accepted) {
        QModelIndex ind = ui->tableView_papers->currentIndex();
        int row = ind.row();
        QSqlRecord rec;
        rec = dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->record(row);
        for (int i=0; i<np->allFields.length(); i++) {
            rec.setValue(i,QVariant(np->allFields.at(i)));
        }
        dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setRecord(row,rec);
        dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->submitAll();
    }
}

/* Open paper externally */
void MainWindow::openPaper() {
    QProcess proc;
    QSqlQuery query;
    QString str;

    query.exec("SELECT pdfpath from '"+currentprojectname+"papers' where bibkey='"+currentpaperkey+"'" );
    query.first();
    str = query.value(0).toString();

    proc.start("xdg-open", QStringList()<<str);
    proc.waitForFinished(1000);
}

/* show journal abbreviations */
void MainWindow::showJournalAbbv() {
    Journals *j = new Journals(this);
    j->exec();
    qDebug()<<j->selectedJournal;
}

/* print project bibtex */
void MainWindow::printProjectBibtex() {
    QString title,authors,journal,volume,pages,issue,year,notes,lastauthor,bkey;
    ofstream outfile;
    QString bibfilestring = currentprojectname;
    bibfilestring+=".bib";
    outfile.open(bibfilestring.toUtf8().constData() );

    /* Write Journal Strings */

    /* Write paper entries */
    /* first the journal strings */
    QFile res("Journal_strings.txt");
    res.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray ar = res.readAll();
    QFile res2(bibfilestring);
    res2.remove();
    res2.open(QIODevice::WriteOnly|QIODevice::Text);
   // res2.write(ar);

    /* Now the papers */
    QSqlQuery query;
    query.exec("SELECT * from '"+currentprojectname+"papers'" );

    while (query.next()) {
        /* get last author's last name */
        lastauthor = getLastAuthor(query.value(1).toString());
        //*  title
        title = query.value(0).toString();
        //*  authors
        authors = formatAuthorList(query.value(1).toString());
        //*  journal
        journal = query.value(2).toString();
        //*  volume
        volume = query.value(3).toString();
        //*  pages
        pages = query.value(4).toString();
        //*  issue
        issue = query.value(5).toString();
        //*  year
        year = query.value(6).toString();
        //*  notes
        notes = query.value(7).toString();

        /* Format Bibtex key */
        bkey = formatBibKey(lastauthor,year,pages);

        /* Write things to the file */
        //ar.clear();
        ar+="\n";
        ar+="@article{"+bkey+",\n";
        ar+="  Author = {"+authors+"},\n";
        ar+="  Journal = {"+journal+"},\n";
        ar+="  Number = {"+issue+"},\n";
        ar+="  Pages = {"+pages+"},\n";
        ar+="  Title = {"+title+"},\n";
        ar+="  Volume = {"+volume+"},\n";
        ar+="  Year = {"+year+"}}\n";

    }
    res2.write(ar);
    res2.close();
    res.close();

}

/* Format bibtex key */
QString MainWindow::formatBibKey(QString auth, QString year, QString pg) {
    QString ret;
    ret = auth+year.remove(0,2)+":"+pg.split("-").first();
    return ret;
}

/* Format the author list */
QString MainWindow::formatAuthorList(QString str) {
    QString ret;
    QStringList list = str.split(";");
    //Get first and last names
    for (int i=0; i<list.length(); i++) {
        QStringList list2 = list.at(i).split(" ");
        ret += list2.last()+", ";
        for (int j=0; j<list2.length()-1; j++) {
            ret += list2.at(j)+" ";
        }
        if (i<list.length()-1)
            ret += "and ";
    }
    return ret;
}

/* Get the last author's name from the list of authors */
QString MainWindow::getLastAuthor(QString str) {
    QStringList list = str.split(";");
    QStringList list2 = list.last().split(" ");
    return list2.last();

}

/* Paper data changed */
void MainWindow::paperDataChanged(QModelIndex ind1, QModelIndex ind2) {
    QStringList list;
    list<<"title"<<"author"<<"journal"<<"volume"<<"pages"<<"issue"<<"year"<<"notes";
    if (currentprojectname != "all") {
        QSqlQuery query;
        if (ind1.column() != 0)
            query.exec("UPDATE allpapers SET "+(list.at(ind1.column()))+" ='"+ind1.data(0).toString()+"' WHERE title='"+currentpapername+"'");
        else {
            QSqlQuery query2;
            query2.exec("SELECT pages FROM allpapers WHERE pages='"+ind1.model()->index(ind1.row(),4).data(0).toString()+"'");
            query2.first();
            query.exec("UPDATE allpapers SET "+(list.at(ind1.column()))+" ='"+ind1.data(0).toString()+"' WHERE pages='"+query2.value(0).toString()+"'");
        }
    } else {
        QSqlQuery query;
        //query.exec()
    }
}

/* Get all projects a paper belongs to as a string */
QString MainWindow::getProjectsfromPaper(QString papertitle) {
    QSqlQuery query;
    query.exec("SELECT projectid FROM allpapers where title='"+papertitle+"'");
    QString str,str2;
    query.first();
    str+=query.value(0).toString();

    //Get rid of duplicates
    QStringList list = str.split(";");
    list = str.split(";");
    list = str.split(";");
    list.removeDuplicates();

    //str2.push_front(";");
    for (int i=0; i<list.length(); i++) {
        str2+=list.at(i);
        str2+=";";
    }

    return str2;
}

/* Add paper to current project from combo box */

void MainWindow::addPapertoProjectfromBox(QString str) {
    QSqlQuery query;
    QString strlist;
    query.exec("SELECT id FROM projects WHERE title='"+currentprojectname+"'");
    query.first();
    int id = query.value(0).toInt();
    strlist = getProjectsfromPaper(str);
    if (!strlist.contains(QString::number(id)+";"))
        strlist += QString::number(id)+";";

    query.exec("Update allpapers SET projectid='"+strlist+"' where bibkey='"+str+"'");

    query.exec("DROP TABLE '"+currentprojectname+"papers'");
    query.exec("CREATE TABLE '"+currentprojectname+"papers' AS SELECT bibkey, title, author, journal, volume, pages, issue, year, notes, pdfpath from allpapers WHERE projectid like '%;"+QString::number(id)+";%'");
    dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setTable(currentprojectname+"papers");
    dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->select();

    projectClicked(currentprojectname);
}

/* Add paper to project from All list combo box*/

void MainWindow::addPapertoProject(int n) {
    if (n==0)
        return;
    QString str = ui->comboBox_allpapers->itemText(n);
    currentprojectname = str;
    QSqlQuery query;
    QString strlist;
    query.exec("SELECT id FROM projects WHERE title='"+str+"'");
    query.first();
    int id = query.value(0).toInt();
    strlist = getProjectsfromPaper(currentpapername);
    strlist += QString::number(id)+";";

    query.exec("Update allpapers SET projectid='"+strlist+"' where title='"+currentpapername+"'");

    query.exec("DROP TABLE '"+str+"papers'");
    query.exec("CREATE TABLE '"+str+"papers' AS SELECT bibkey, title, author, journal, volume, pages, issue, year, notes, pdfpath from allpapers WHERE projectid like '%;"+QString::number(id)+";%'");
//    dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setTable(str+"papers");
//    dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->select();

    projectClicked(str);

}

/* Delete paper from db */
void MainWindow::deletePaper() {

    if (!paperSet) return;

    QSqlQuery query;
    query.exec("DELETE FROM allpapers WHERE title='"+currentpapername+"'");
    QStringList lst = db.tables();
    for (int i=0; i<lst.length(); i++) {
        query.exec("DELETE FROM "+lst.at(i)+" where bibkey='"+currentpaperkey+"'");
    }
    setProjectAll();
    QModelIndex ind = ui->treeView_projects->model()->index(0,0,QModelIndex());
    ui->treeView_projects->setCurrentIndex(ind);
}

/* Remove paper from project */
void MainWindow::removePaperfromProject() {

    QSqlQuery query;
    if (currentprojectname == "all" || !projectSet) return;

    QString str = getProjectsfromPaper(currentpapername);
    str.remove(";"+QString::number(currentprojectId));
    if (str == ";") {
        query.exec("UPDATE allpapers SET projectid=';0;' WHERE title ='"+currentpapername+"'");
    }   else    {
        query.exec("UPDATE allpapers SET projectid='"+str+"' WHERE title ='"+currentpapername+"'");
    }
    query.exec("DROP TABLE '"+currentprojectname+"papers'");
    query.exec("CREATE TABLE '"+currentprojectname+"papers' AS SELECT bibkey, title, author, journal, volume, pages, issue, year, notes, pdfpath from allpapers WHERE projectid like '%;"+QString::number(currentprojectId)+";%'");
    dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setTable(currentprojectname+"papers");
    dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->select();
}

/* Click on paper */
void MainWindow::paperClicked(QModelIndex in) {
    paperSet = true;
    QModelIndex ind2,keyind;
    QSqlQuery query;

    if (currentprojectname == "all") {
        ui->comboBox_allpapers->setEnabled(true);
        ui->comboBox_allpapers->setHidden(false);
        ind2 = in.model()->index(in.row(),4,QModelIndex());
        keyind = in.model()->index(in.row(),3,QModelIndex());
    } else {
        ind2 = in.model()->index(in.row(),1,QModelIndex());
        keyind = in.model()->index(in.row(),0,QModelIndex());

    }

    currentpapername = ind2.data().toString();
    currentpaperkey = keyind.data().toString();
    query.exec("SELECT notes from allpapers where bibkey='"+currentpaperkey+"'");
    query.first();
    ui->textEdit_paperNotes->setText(query.value(0).toString());


    //If in All Projects, populate combo box
    if (currentprojectname == "all") {
        ui->comboBox_allpapers->setItemText(0,"<-- Add "+currentpaperkey+" to a Project -->");
    } else {

    }
}

/* Change name of project */
void MainWindow::projectEntryChanged(){

}

/* Parse author list */
QStringList MainWindow::parseAuthors(QString str) {

    QStringList strlist = str.split(";");
    return strlist;
}

/* Add a new paper to the current project */
void MainWindow::addNewPaper() {

    //if (!projectSet ) return;

    NewPaper *newpaper = new NewPaper(this);

    int res = newpaper->exec();

    newpaper->setFocusPolicy(Qt::StrongFocus);
    newpaper->setModal(Qt::WindowModal);

    if (res == QDialog::Accepted)
        paperAccepted(newpaper);

}

/* Paper accepted, insert or update record */
void MainWindow::paperAccepted(NewPaper *newpaper) {
        PaperData dat;
        dat.key = newpaper->key;
        dat.title = newpaper->title;
        dat.authors = newpaper->authors;
        dat.volume = newpaper->volume;
        dat.issue = newpaper->issue;
        dat.year = newpaper->year;
        dat.notes = newpaper->notes;
        dat.pages = newpaper->pages;
        dat.journal = newpaper->journal;
        QStringList authlist = parseAuthors(dat.authors);

        QSqlQuery query,query2;
        query2.exec("SELECT id from allpapers where bibkey='"+dat.key+"'");
        query2.first();
        QString cid = query2.value(0).toString();
        QString qstrquery = "INSERT OR REPLACE INTO allpapers (id, bibkey, title, author, journal, volume, pages, year, issue, notes,publisher,projectid,pdfpath) VALUES (:id, :bibkey, :title, :author, :journal, :volume, :pages, :year, :issue, :notes,:publisher,:projectid,:pdfpath)";
        query.prepare(qstrquery);
        query.bindValue(0,cid);
        query.bindValue(1,dat.key);
        query.bindValue(2,dat.title);
        query.bindValue(3,dat.authors);
        query.bindValue(4,dat.journal);
        query.bindValue(5,dat.volume);
        query.bindValue(6,dat.pages);
        query.bindValue(7,dat.year);
        query.bindValue(8,dat.issue);
        query.bindValue(9,dat.notes);
        query.bindValue(10,dat.publisher);
        QString str = ";"+QString::number(currentprojectId)+";";
        QString str2 = ";0;";
        if (currentprojectname != "all") {
            query.bindValue(11,str );
        } else {
            query.bindValue(11,str2);
        }
        query.bindValue(12,newpaper->pdf);

        query.exec();

        if (currentprojectname != "all") {
            dynamic_cast<QStandardItemModel*>(ui->tableView_papers->model())->clear();

            ui->tableView_papers->reset();
            dynamic_cast<QStandardItemModel*>(ui->tableView_papers->model())->clear();

            query.exec("DROP TABLE '"+currentprojectname+"papers'");
            query.exec("CREATE TABLE '"+currentprojectname+"papers' AS SELECT bibkey, title, author, journal, volume, pages, issue, year, notes, pdfpath from allpapers WHERE projectid like '%;"+QString::number(currentprojectId)+";%'");
        }
        //add paper to names list
        allpapernames<<dat.title;
        allpaperkeys<<dat.key;

        //Update paper view
        if (currentprojectname == "all") {
            setProjectAll();
            setProjectAll();
        } else {
            projectClicked(currentprojectname);
        }
}

/* Delete a project */
void MainWindow::deleteProject() {

    if (!projectSet || currentprojectname == "all") return;

    QSqlQuery query;
    query.exec("SELECT isparent from projects WHERE id="+QString::number(currentprojectId ));
    while (query.next()) {
        if (query.value(0).toBool())
            parentprojects --;
    }
    query.exec("DELETE FROM projects WHERE id="+QString::number(currentprojectId ));
    query.exec("DELETE FROM projects WHERE parentid="+QString::number(currentprojectId ));
    nprojects --;
    delete[] mainProjects;
    dynamic_cast<QStandardItemModel*>(ui->treeView_projects->model())->clear();
    initializeProjectData();
    projectSet = false;
    ui->label_papers->setText("Papers for: ");
    query.exec("DROP TABLE '"+currentprojectname+"papers'");

    //remove parentid from papers table
    QString str = getProjectsfromPaper(currentpapername);
    str.remove(";"+QString::number(currentprojectId));
    query.exec("SELECT id, projectid from allpapers WHERE projectid like '%;"+QString::number(currentprojectId)+";%'");
    QSqlQuery query2;
    while (query.next()) {
        str = query.value(1).toString().remove(";"+QString::number(currentprojectId));
        query2.exec("UPDATE allpapers SET projectid='"+str+"' WHERE id ="+query.value(0).toString());
    }

    //Remove all occurrences of project name from list
    projectNames.removeAll(currentprojectname);

    //Default to All
    setProjectAll();
}


/* Add a new project to main array of projects */
void MainWindow::addProject(Projectdata proj) {

    nprojects ++;

    Projectdata *temp = new Projectdata[nprojects];
    int i;
    for (i=0; i<nprojects-1; i++) {
        temp[i] = mainProjects[i];

    }

    temp[nprojects-1]=proj;
    if (nprojects > 1) delete[] mainProjects;
    mainProjects = new Projectdata[nprojects];
    for (i=0; i<nprojects;i++) {
        mainProjects[i] = temp[i];
    }

    delete[] temp;
}

/* Initialize Project Class */

void MainWindow::initializeProjectData() {

    QSqlQuery query;

    //Get all project
    bool ok = query.exec("SELECT * from projects");
    int nrecords = 0;
    nprojects = 0;
    int i=0;

    //Get number of total projects (main + sub)
    while(query.next()) {
        i++;

        nrecords = i;
    }

    //if no records exist return
    if (nrecords < 1) {
        //Insert "All" item
        QStandardItem item;
        item.setText("all");
        mainprojectmodel.setItem(0,item.clone());
        return;
    }

    query.first();
    this->nprojects = nrecords;
    mainProjects = new Projectdata[nrecords];
    i=0;

    ok = query.exec("SELECT * from projects where isparent!='false'");
    while(query.next() ) {

        //Fill out the parents first
        if (i==0 || nrecords == 1) {

            query.first();
        }

        mainProjects[i].isParent = query.value(3).toBool();
        mainProjects[i].projectId = query.value(0).toInt();
        mainProjects[i].name = query.value(1).toString();
        mainProjects[i].item.setText(query.value(1).toString());
        mainProjects[i].description = query.value(2).toString();
        mainProjects[i].parentId = query.value(4).toInt();
        mainProjects[i].nchild = query.value(5).toInt();

       // mainprojectmodel.insertRow(i,mainProjects[i].item.clone());
        mainprojectmodel.setItem(i+1,mainProjects[i].item.clone());
        i++;
        parentprojects++;
    }

    //Now insert the children
    query.exec("SELECT * FROM projects WHERE isparent='false'");

    while (query.next()) {
        int parid = query.value(4).toInt();
        mainProjects[i].isParent = query.value(3).toBool();
        mainProjects[i].projectId = query.value(0).toInt();
        mainProjects[i].name = query.value(1).toString();
        mainProjects[i].item.setText(query.value(1).toString());
        mainProjects[i].description = query.value(2).toString();
        mainProjects[i].parentId = query.value(4).toInt();
        mainProjects[i].nchild = query.value(5).toInt();

        QSqlQuery query2;

        query2.exec("SELECT title FROM projects WHERE id="+QString::number(parid));

        while (query2.next()) {
            QList<QStandardItem *> list = mainprojectmodel.findItems(query2.value(0).toString());
            list[0]->appendRow(mainProjects[i].item.clone());
        }
        i++;
    }

    for (int j=0; j<i; j++) {
        projectNames<<mainProjects[j].name;
    }

    //Insert "All" item
    QStandardItem item;
    item.setText("all");
    mainprojectmodel.setItem(0,item.clone());
}

/* Initialize paper list */

void MainWindow::initializePaperList() {
    QSqlQuery query;
    query.exec("SELECT bibkey, title FROM allpapers");
    while (query.next()) {
        allpaperkeys<<query.value(0).toString();
        allpapernames<<query.value(1).toString();
    }
}

/* Add a paper to current project */

void MainWindow::newPaper() {
}


/* Create a new project */

void MainWindow::newProject() {

    NewProject *newproj = new NewProject(this);
    int res = newproj->exec();

    if (res == QDialog::Accepted) {
        Projectdata dat;
        QSqlQuery query;
        QString qstrquery = "INSERT INTO projects (title, description) VALUES (:title,:description)";
        query.prepare(qstrquery);
        query.bindValue(0,newproj->name);
        query.bindValue(1,newproj->description);
        query.exec();

        dat.isParent = 1;
        dat.isChild = 0;
        dat.name = newproj->name;
        dat.nchild = 0;
        dat.description = newproj->description;
        dat.npapers = 0;
        query.exec("SELECT id FROM projects where title ='"+newproj->name+"'");
        query.first();
        dat.projectId = query.value(0).toInt();
        dat.item.setText(newproj->name);
        addProject(dat);
        currentprojectId = dat.projectId;


        //Add new project to View Model
        mainProjects[nprojects-1].item.setText(newproj->name);

        //CTC see how this changes when adding child projects
        mainprojectmodel.setItem(parentprojects,mainProjects[nprojects-1].item.clone());

        query.exec("CREATE TABLE '"+dat.name+"papers' AS SELECT bibkey, title, author, journal, volume, pages, issue, year, notes, pdfpath from allpapers WHERE projectid="+QString::number(dat.projectId));

        //increment number of parent projects
        parentprojects++;

        //add project name to list
        projectNames<<newproj->name;
    }
}


/* Create a new sub project */

void MainWindow::newSubProject() {

    //If no current project, jump out
    if(!projectSet) return;

    //new dialog window
    NewProject *newproj = new NewProject(this);
    int res = newproj->exec();

    if (res == QDialog::Accepted) {
        //Create new database entry
        Projectdata dat;
        QSqlQuery query;
        QString qstrquery = "INSERT INTO projects (title, description,isparent,parentid) VALUES (:title,:description,:isparent,:parentid)";
        query.prepare(qstrquery);
        query.bindValue(0,newproj->name);
        query.bindValue(1,newproj->description);
        query.bindValue(2,false);
        query.bindValue(3,currentprojectId);
        query.exec();

        dat.isParent = 0;
        dat.isChild = 1;
        dat.name = newproj->name;
        dat.nchild = 0;
        dat.description = newproj->description;
        dat.npapers = 0;
        dat.parentId = currentprojectId;
        dat.item.setText(newproj->name);
        query.exec("SELECT id FROM projects where title ='"+newproj->name+"'");
        query.first();
        dat.projectId = query.value(0).toInt();
        dat.parentName = currentprojectname;
        addProject(dat);
        mainProjects[nprojects-1].item.setText(newproj->name);
        currentprojectId = dat.projectId;

        //Find parent item
        QList<QStandardItem *> list = mainprojectmodel.findItems(currentprojectname);
        list[0]->appendRow(mainProjects[nprojects-1].item.clone() );

        //update parent db record
        QSqlQuery query2;
        query2.exec("UPDATE projects SET isparent='true' WHERE id in ("+QString::number(currentprojectId)+")");
        query2.exec("UPDATE projects SET nchild = nchild + 1 WHERE id in ("+QString::number(currentprojectId)+")");

        query.exec("CREATE TABLE '"+dat.name+"papers' AS SELECT bibkey, title, author, journal, volume, pages, issue, year, notes, pdfpath from allpapers WHERE projectid="+QString::number(currentprojectId));

        //add project name to list
        projectNames<<newproj->name;
    }
}

/* Set current project */

void MainWindow::projectClicked(QModelIndex ind) {
    QString str = ind.data().toString();

    //If "All" clicked
    if (str == "all") {
        setProjectAll();
    } else {
        ui->actionAdd_Paper->setEnabled(false);

        projectSet = true;

        //Get project name and set to current project
        currentprojectname = str;

        //Query 'projects' table to get current project id and set to current
        QSqlQuery query;
        query.exec("SELECT id FROM projects WHERE title='"+str+"'");
        query.first();
        currentprojectId = query.value(0).toInt();

        //update labels
        ui->label_papers->setText("Papers for: "+str);

        //update description
        query.exec("SELECT description FROM projects WHERE title='"+str+"'");
        query.first();
        ui->textEdit_projdescription->setText(query.value(0).toString());

        //Update paper view

        paperSet = false;
        ui->textEdit_paperNotes->clear();
        ui->comboBox_projects->setHidden(false);
        ui->comboBox_allpapers->setHidden(true);
        ui->comboBox_allpapers->setEnabled(false);
        ui->comboBox_projects->clear();
        ui->comboBox_projects->insertItem(0,"<-- Select Paper to Add to Project '"+currentprojectname+"' -->");
        ui->comboBox_projects->addItems(allpaperkeys);
        ui->actionNew_Sub_Project->setEnabled(true);
        ui->actionDelete_Project->setEnabled(true);

        ui->tableView_papers->showColumn(0);
        ui->tableView_papers->showColumn(1);
        ui->tableView_papers->showColumn(2);
        ui->tableView_papers->showColumn(3);
        ui->tableView_papers->showColumn(5);
        ui->tableView_papers->showColumn(7);
        ui->tableView_papers->showColumn(8);
//        ui->tableView_papers->reset();


        if (!db.tables().contains(str+"papers")) {
            for (int i=0; i<dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->rowCount(); i++)
                 ui->tableView_papers->setRowHidden(i,true );
            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->clear();
            ui->tableView_papers->reset();
            for (int i=0; i<15; i++)
                ui->tableView_papers->hideColumn(i);

        } else {
            for (int i=0; i<dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->rowCount(); i++)
                 ui->tableView_papers->setRowHidden(i,true );
            //dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->clear();
            //ui->tableView_papers->reset();

            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setTable(str+"papers");
            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->select();

            for (int i=0; i<dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->rowCount(); i++)
                 ui->tableView_papers->setRowHidden(i,false );
            for (int i=0; i<14; i++)
                ui->tableView_papers->hideColumn(i);
            ui->tableView_papers->showColumn(0);
            ui->tableView_papers->showColumn(1);
            ui->tableView_papers->showColumn(2);
            ui->tableView_papers->showColumn(3);
            ui->tableView_papers->showColumn(5);
            ui->tableView_papers->showColumn(7);
            ui->tableView_papers->showColumn(8);

        }
    }
}
void MainWindow::projectClicked(QString str) {

    ui->actionAdd_Paper->setEnabled(false);
        projectSet = true;

        //Get project name and set to current project
        currentprojectname = str;

        //Query 'projects' table to get current project id and set to current
        QSqlQuery query;
        query.exec("SELECT id FROM projects WHERE title='"+str+"'");
        query.first();
        currentprojectId = query.value(0).toInt();

        //update labels
        ui->label_papers->setText("Papers for: "+str);

        //update description
        query.exec("SELECT description FROM projects WHERE title='"+str+"'");
        query.first();

        ui->textEdit_projdescription->setText(query.value(0).toString());

        //Update paper view

        paperSet = false;
        ui->textEdit_paperNotes->clear();
        ui->comboBox_projects->setHidden(false);
        ui->comboBox_allpapers->setHidden(true);
        ui->comboBox_allpapers->setEnabled(false);
        ui->comboBox_projects->clear();
        ui->comboBox_projects->insertItem(0,"<-- Select Paper to Add to Project '"+currentprojectname+"' -->");
        ui->comboBox_projects->addItems(allpaperkeys);
        ui->actionNew_Sub_Project->setEnabled(true);
        ui->actionDelete_Project->setEnabled(true);

        ui->tableView_papers->showColumn(0);
        ui->tableView_papers->showColumn(1);
        ui->tableView_papers->showColumn(2);
        ui->tableView_papers->showColumn(3);
        ui->tableView_papers->showColumn(5);
        ui->tableView_papers->showColumn(7);
        ui->tableView_papers->showColumn(8);
//        ui->tableView_papers->reset();


        if (!db.tables().contains(str+"papers")) {
            for (int i=0; i<dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->rowCount(); i++)
                 ui->tableView_papers->setRowHidden(i,true );
            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->clear();
            ui->tableView_papers->reset();
            for (int i=0; i<15; i++)
                ui->tableView_papers->hideColumn(i);

        } else {
            for (int i=0; i<dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->rowCount(); i++)
                 ui->tableView_papers->setRowHidden(i,true );
            //dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->clear();
            //ui->tableView_papers->reset();

            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setTable(str+"papers");
            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->select();

            for (int i=0; i<dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->rowCount(); i++)
                 ui->tableView_papers->setRowHidden(i,false );
            for (int i=0; i<14; i++)
                ui->tableView_papers->hideColumn(i);
            ui->tableView_papers->showColumn(0);
            ui->tableView_papers->showColumn(1);
            ui->tableView_papers->showColumn(2);
            ui->tableView_papers->showColumn(3);
            ui->tableView_papers->showColumn(5);
            ui->tableView_papers->showColumn(7);
            ui->tableView_papers->showColumn(8);

        }
}

void MainWindow::setProjectAll() {
    ui->actionAdd_Paper->setEnabled(true);

    projectSet = false;
    currentprojectname = "all";
    currentprojectId = 0;
    ui->label_papers->setText("All Papers");
    ui->actionDelete_Project->setEnabled(false);
    ui->actionNew_Sub_Project->setEnabled(false);
    ui->comboBox_allpapers->setHidden(false);
    ui->comboBox_projects->setHidden(true);


//    for (int i=0; i<14; i++)
//        ui->tableView_papers->showColumn(i);

//    ui->tableView_papers->hideColumn(0);
//    ui->tableView_papers->hideColumn(1);
//    ui->tableView_papers->hideColumn(2);
//    ui->tableView_papers->hideColumn(5);
//    ui->tableView_papers->hideColumn(11);


    dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->clear();
    dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setTable("allpapers");
    dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->select();
    for (int i=0; i<15; i++)
        ui->tableView_papers->showColumn(i);

    ui->tableView_papers->hideColumn(0);
    ui->tableView_papers->hideColumn(1);
    ui->tableView_papers->hideColumn(2);
    ui->tableView_papers->hideColumn(5);
    ui->tableView_papers->hideColumn(11);
    ui->tableView_papers->hideColumn(12);

    //Populate combo box with projects
    paperSet = false;
    ui->textEdit_paperNotes->clear();
    ui->comboBox_allpapers->clear();
    ui->comboBox_allpapers->insertItem(0,"<-- Select a Paper to Add to a Project -->");
    ui->comboBox_allpapers->addItems(projectNames);
    ui->comboBox_allpapers->setEnabled(false);

   // ui->tableView_papers->setEditTriggers(QAbstractItemView::NoEditTriggers);
}
