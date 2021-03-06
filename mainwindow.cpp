#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    nprojects = 0;
    parentprojects = 1;
    whichView ="papers";

    //Connections
    //New projects
    connect(ui->actionMain, SIGNAL(triggered()), this, SLOT(newProject()));
    connect(ui->actionSub, SIGNAL(triggered()),this,SLOT(newSubProject()));
    connect(ui->pushButton_newproject, SIGNAL(clicked()),this, SLOT(newProject()));

    //Change current project
    connect(ui->treeView_projects, SIGNAL(clicked(QModelIndex)), this, SLOT(projectClicked(QModelIndex)));
    connect(ui->treeView_projects, SIGNAL(activated(QModelIndex)), this, SLOT(projectClicked(QModelIndex)));

    //Delete project
    connect(ui->actionDelete_Project, SIGNAL(triggered()), this, SLOT(deleteProject()));
    connect(ui->actionDelete_Project_2, SIGNAL(triggered()), this, SLOT(deleteProject()));

    //New paper
    connect(ui->actionAdd_Paper, SIGNAL(triggered()), this, SLOT(addNewPaper()));
    connect(ui->actionNew_Paper, SIGNAL(triggered()), this, SLOT(addNewPaper()));
    connect(ui->pushButton_newpaper, SIGNAL(clicked()), this, SLOT(addNewPaper()));

    //New Book/Chapter
    connect(ui->pushButton_book, SIGNAL (clicked()), this, SLOT(addNewBook()));

    //Click on paper
    connect(ui->tableView_papers, SIGNAL(clicked(QModelIndex)), this, SLOT(paperClicked(QModelIndex)));

    //Remove paper from project
    connect(ui->actionRemove_Paper_From_Project, SIGNAL(triggered()), this, SLOT(removePaperfromProject()));
    connect(ui->actionFrom_Project, SIGNAL(triggered()), this, SLOT(removePaperfromProject()));

    //Add paper to project from combobox
    connect(ui->comboBox_allpapers, SIGNAL(activated(int)), this, SLOT(addPaperstoProject(int)));
    connect(ui->comboBox_projects, SIGNAL(activated(QString)) , this, SLOT(addPapertoProjectfromBox(QString)));

    //Delete paper from entire database
    connect(ui->actionRemove_Paper_From_Database, SIGNAL(triggered()), this, SLOT(deletePaper()));
    connect(ui->actionAll_Instances, SIGNAL(triggered()), this, SLOT(deletePaper()));

    //Edit paper
    connect(ui->actionEdit_Paper,SIGNAL(triggered()),this,SLOT(editPaper()));
    connect(ui->actionEdit_Paper_2,SIGNAL(triggered()),this,SLOT(editPaper()));
    connect(ui->pushButton_editpaper, SIGNAL(clicked()), this, SLOT(editPaper()));

    //View paper externally
    connect(ui->actionView_Paper , SIGNAL(triggered()), this, SLOT(openPaper()));
    connect(ui->pushButton_viewpdf, SIGNAL(clicked()), this, SLOT(openPaper()));

    //View single paper bib entry
    connect(ui->actionBibTeX_entry, SIGNAL(triggered()), this, SLOT(viewBib()));
    connect(ui->pushButton_bibentry, SIGNAL(clicked()), this, SLOT(viewBib()));

    //print project bibtex
    connect(ui->actionCurrent_project, SIGNAL(triggered()), this, SLOT(printProjectBibtex()));
    connect(ui->pushButton_exportprojectbib, SIGNAL(clicked()), this, SLOT(printProjectBibtex()));

    //connect double click on paper to edit
    connect(ui->tableView_papers,SIGNAL(doubleClicked(QModelIndex)), this, SLOT(editPaper(QModelIndex)));

    //Show Journal abbreviations
    connect(ui->actionJournals,SIGNAL(triggered()),this,SLOT(showJournalAbbv()));

    //Switch paper/book view
    connect(ui->pushButton_switch,SIGNAL(clicked()),this,SLOT(switchView()));

    //Exit
    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(close()));

    //Set up databases
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbdir = QDir::homePath()+"/.qpaper/papers.db";
    db.setDatabaseName(dbdir);
    db.open();

    //Set up tables
    QSqlQuery query;
    QString strquery="CREATE TABLE allpapers (id integer primary key, nproject integer, projectid varchar(1000)";
    strquery +=", bibkey varchar(20), title varchar(500), nauth integer, author varchar(1000), journal varchar(100)";
    strquery +=",volume varchar(10), pages varchar(20), issue varchar(20)";
    strquery += ",publisher varchar(100), year varchar(4), notes varchar(5000), pdfpath varchar(5000))";
    query.exec("CREATE TABLE projects (id integer primary key, title varchar(100), description varchar(5000), isparent integer default 1, parentid integer, nchild integer)");
    query.exec(strquery);

    //All books
    strquery="CREATE TABLE allbooks (id integer primary key, nproject integer, projectid varchar(1000)";
        strquery +=", bibkey varchar(20), btitle varchar(1000), chtitle varchar(1000), nauth integer, author varchar(1000)";
        strquery +=", editor varchar(100)";
        strquery +=",volume varchar(10),  issue varchar(20), edition varchar(20), series varchar(20), pages varchar(20)";
        strquery += ", year varchar(4),publisher varchar(100),address varchar(100), notes varchar(5000), pdfpath varchar(5000))";
    query.exec(strquery);

    //Set up Project and paper views
    QSqlTableModel *papermodel, *projectmodel, *bookmodel;
    QStandardItemModel *projmodel;
    projmodel = new QStandardItemModel ;
    papermodel = new QSqlTableModel;
    bookmodel = new QSqlTableModel;
    //papermodel->setEditStrategy(QSqlTableModel::OnManualSubmit );
    projectmodel = new QSqlTableModel;
    //papermodel->setTable("allpapers");
    projectmodel->setTable("projects");
    papermodel->select();
    projectmodel->select();
    ui->treeView_projects->setHeaderHidden(true);
    ui->tableView_papers->setModel(papermodel);
    ui->tableView_papers->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView_papers->setSelectionBehavior(QAbstractItemView::SelectRows);
    initializeProjectData();
    initializePaperList();
    ui->treeView_projects->setModel(&mainprojectmodel);
    ui->tableView_papers->setSortingEnabled(true);
    //ui->tableView_papers->horizontalHeader()->setResizeMode(QHeaderView::Interactive);
    ui->tableView_papers->horizontalHeader()->setResizeMode(QHeaderView::Stretch);
    ui->tableView_papers->horizontalHeader()->resizeSections(QHeaderView::Stretch);
//    ui->tableView_papers->horizontalHeader()->setHidden(false);
//    ui->tableView_papers->hideColumn(0);
//    ui->tableView_papers->hideColumn(1);
//    ui->tableView_papers->hideColumn(2);
//    ui->tableView_papers->hideColumn(4);
//    ui->tableView_papers->hideColumn(10);

    //combo box
    ui->comboBox_allpapers->insertItem(0,"<-- Select a Paper to Add to a Project -->");
    ui->comboBox_allpapers->setHidden(true);
    ui->comboBox_projects->setHidden(true);

    //Set some parameters
    projectSet  = false;
    paperSet = false;

    //Show all papers
    setProjectAll();

    //connect paper model
    //connect(papermodel,SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(paperDataChanged(QModelIndex,QModelIndex)));



}

MainWindow::~MainWindow()
{
    delete ui;
}

/********************************************************
 *Functions
 ********************************************************/
/* Set to book view */
void MainWindow::switchView() {
    if (whichView == "papers") {
        projectClickedBooks(currentprojectname);
    } else if (whichView == "books") {
        projectClicked(currentprojectname);
    }
}

/* View single bib entry */
void MainWindow::viewBib() {
    if (!paperSet) return;

    QSqlQuery query;
    Bibref *bib = new Bibref(this);

    QFile res(QDir::homePath()+"/.qpaper/Journal_strings.txt");
    res.open(QIODevice::ReadOnly|QIODevice::Text);

    query.exec("SELECT * from "+currentprojectname+"papers where bibkey like '"+currentpaperkey+"'" );

    BibArticle *article;
    while (query.next()) {
        if (currentprojectname!="all") {
            QString s = getJournal(query.value(3).toString(),&res);
            QString a = formatAuthorList(query.value(2).toString());
            article = new BibArticle(query.value(0).toString(),
                                 query.value(1).toString(),
                                 a,
                                 s,
                                 query.value(4).toString(),
                                 query.value(5).toString(),
                                 query.value(6).toString(),
                                 query.value(7).toString(),
                                 query.value(8).toString(),
                                 query.value(9).toString());
        } else {
            QString s = getJournal(query.value(7).toString(),&res);
            QString a = formatAuthorList(query.value(6).toString());
            article = new BibArticle(query.value(3).toString(),
                                 query.value(4).toString(),
                                 a,
                                 s,
                                 query.value(8).toString(),
                                 query.value(9).toString(),
                                 query.value(10).toString(),
                                 query.value(12).toString(),
                                 query.value(13).toString(),
                                 query.value(14).toString());
        }
        res.close();
        article->formatEntry();
    }
    bib->showRef(article);
    int result = bib->exec();
}

void MainWindow::headerClicked(QModelIndex ind) {
}

/* Edit paper entry */
void MainWindow::editPaper(QModelIndex ind) {
    editPaper();
}

void MainWindow::editPaper() {
    QSqlQuery query;


    if (whichView == "papers") {
    NewPaper *np = new NewPaper(this);
    //Get the record from the current project and create a corresponding paper display window
    query.exec("Select title, author, journal, volume, pages, issue, year, notes, pdfpath from '"+currentprojectname+"papers' where bibkey = '"+currentpaperkey+"'");
    query.first();
    if (query.value(0).toString().isEmpty() &&
            query.value(1).toString().isEmpty() &&
            query.value(2).toString().isEmpty() &&
            query.value(3).toString().isEmpty() &&
            query.value(4).toString().isEmpty() &&
            query.value(5).toString().isEmpty() &&
            query.value(6).toString().isEmpty() &&
            query.value(7).toString().isEmpty() &&
            query.value(8).toString().isEmpty()) {
        //No entry, do nothing
        return;
    }
    query.exec("Select title, author, journal, volume, pages, issue, year, notes, pdfpath from '"+currentprojectname+"papers' where bibkey = '"+currentpaperkey+"'");
    while (query.next()) {
        np->setFields(currentpaperkey,query.value(0).toString(),query.value(1).toString(),
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

        QSqlQuery query2;
        query2.exec("Update '"+currentprojectname+"papers' set title='"+np->title+"' where bibkey = '"+currentpaperkey+"'");
        query2.exec("Update '"+currentprojectname+"papers' set author='"+np->authors+"' where bibkey = '"+currentpaperkey+"'");
        query2.exec("Update '"+currentprojectname+"papers' set journal='"+np->journal+"' where bibkey = '"+currentpaperkey+"'");
        query2.exec("Update '"+currentprojectname+"papers' set volume='"+np->volume+"' where bibkey = '"+currentpaperkey+"'");
        query2.exec("Update '"+currentprojectname+"papers' set pages='"+np->pages+"' where bibkey = '"+currentpaperkey+"'");
        query2.exec("Update '"+currentprojectname+"papers' set issue='"+np->issue+"' where bibkey = '"+currentpaperkey+"'");
        query2.exec("Update '"+currentprojectname+"papers' set year='"+np->year+"' where bibkey = '"+currentpaperkey+"'");
        query2.exec("Update '"+currentprojectname+"papers' set notes='"+np->notes+"' where bibkey = '"+currentpaperkey+"'");
        query2.exec("Update '"+currentprojectname+"papers' set pdfpath='"+np->pdf+"' where bibkey = '"+currentpaperkey+"'");
        query2.exec("Update '"+currentprojectname+"papers' set bibkey='"+np->key+"' where bibkey = '"+currentpaperkey+"'");

        for (int i=0; i<np->allFields.length(); i++) {
            rec.setValue(i,QVariant(np->allFields.at(i)));
        }

        if (currentprojectname == "all") {
            //get a list of all the projects the changed paper is a part of
            QSqlQuery query3;
            QStringList strlist;
            //int id = query3.value(0).toInt();
            strlist = getProjectsfromBibkey(np->key);
            query3.exec("select title from projects where id="+strlist.at(0));
            query3.first();
            currentprojectname=query3.value(0).toString();
            bool ok;

            for (int i=0; i<strlist.length(); i++) {
                //currentprojectname=projectNames.at(strlist.at(i).toInt(&ok,10)-1);
                qDebug()<<currentprojectname;
                query2.exec("Update '"+currentprojectname+"papers' set title='"+np->title+"' where bibkey = '"+currentpaperkey+"'");
                query2.exec("Update '"+currentprojectname+"papers' set author='"+np->authors+"' where bibkey = '"+currentpaperkey+"'");
                query2.exec("Update '"+currentprojectname+"papers' set journal='"+np->journal+"' where bibkey = '"+currentpaperkey+"'");
                query2.exec("Update '"+currentprojectname+"papers' set volume='"+np->volume+"' where bibkey = '"+currentpaperkey+"'");
                query2.exec("Update '"+currentprojectname+"papers' set pages='"+np->pages+"' where bibkey = '"+currentpaperkey+"'");
                query2.exec("Update '"+currentprojectname+"papers' set issue='"+np->issue+"' where bibkey = '"+currentpaperkey+"'");
                query2.exec("Update '"+currentprojectname+"papers' set year='"+np->year+"' where bibkey = '"+currentpaperkey+"'");
                query2.exec("Update '"+currentprojectname+"papers' set notes='"+np->notes+"' where bibkey = '"+currentpaperkey+"'");
                query2.exec("Update '"+currentprojectname+"papers' set pdfpath='"+np->pdf+"' where bibkey = '"+currentpaperkey+"'");
                query2.exec("Update '"+currentprojectname+"papers' set bibkey='"+np->key+"' where bibkey = '"+currentpaperkey+"'");
            }
            qDebug()<<237;
            currentprojectname="all";
            setProjectAll();
        } else {
            //update the allpapers db
            query2.exec("Update 'allpapers' set title='"+np->title+"' where bibkey = '"+currentpaperkey+"'");
            query2.exec("Update 'allpapers' set author='"+np->authors+"' where bibkey = '"+currentpaperkey+"'");
            query2.exec("Update 'allpapers' set journal='"+np->journal+"' where bibkey = '"+currentpaperkey+"'");
            query2.exec("Update 'allpapers' set volume='"+np->volume+"' where bibkey = '"+currentpaperkey+"'");
            query2.exec("Update 'allpapers' set pages='"+np->pages+"' where bibkey = '"+currentpaperkey+"'");
            query2.exec("Update 'allpapers' set issue='"+np->issue+"' where bibkey = '"+currentpaperkey+"'");
            query2.exec("Update 'allpapers' set year='"+np->year+"' where bibkey = '"+currentpaperkey+"'");
            query2.exec("Update 'allpapers' set notes='"+np->notes+"' where bibkey = '"+currentpaperkey+"'");
            query2.exec("Update 'allpapers' set pdfpath='"+np->pdf+"' where bibkey = '"+currentpaperkey+"'");
            query2.exec("Update 'allpapers' set bibkey='"+np->key+"' where bibkey = '"+currentpaperkey+"'");
            //edit paper list

            //now display
            projectClicked(currentprojectname);
        }
    }
    }//end papers
//    if (whichView == "books") {
//        NewBook *np = new NewBook(this);
//        //Get the record from the current project and create a corresponding paper display window
//        query.exec("Select btitle, chtitle, author, editor, volume,issue,edition,series, pages, year,publisher,address, notes, pdfpath from '"+currentprojectname+"books' where bibkey = '"+currentpaperkey+"'");
//        query.first();
//        if (query.value(0).toString().isEmpty() &&
//                query.value(1).toString().isEmpty() &&
//                query.value(2).toString().isEmpty() &&
//                query.value(3).toString().isEmpty() &&
//                query.value(4).toString().isEmpty() &&
//                query.value(5).toString().isEmpty() &&
//                query.value(6).toString().isEmpty() &&
//                query.value(7).toString().isEmpty() &&
//                query.value(8).toString().isEmpty() &&
//                query.value(9).toString().isEmpty() &&
//                query.value(10).toString().isEmpty() &&
//                query.value(11).toString().isEmpty() &&
//                query.value(12).toString().isEmpty() &&
//                query.value(13).toString().isEmpty()) {
//            //No entry, do nothing
//            return;
//        }
//        query.exec("Select Select btitle, chtitle, author, editor, volume,issue,edition,series, pages, year,publisher,address, notes, pdfpath from '"+currentprojectname+"books' where bibkey = '"+currentpaperkey+"'");
//        while (query.next()) {
//            np->setFields(currentpaperkey,query.value(0).toString(),query.value(1).toString(),
//                          query.value(2).toString(),query.value(3).toString(),
//                          query.value(4).toString(),query.value(5).toString(),
//                          query.value(6).toString(),query.value(7).toString(),
//                          query.value(8).toString());
//        }

//        int res = np->exec();
//    }
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
}

QString MainWindow::getJournal(QString j, QFile *res) {
    QString str;
    ifstream infile;
    infile.open(res->fileName().toLatin1());
    string s,s1;
    char tempc[1000];
    int count = 0;
    while (!infile.eof()) {
        infile.getline(tempc,1000);
        s1 = tempc;
        //No match, return original string
        if (!s1.compare(0,2,"end",0,2)) {

          return j;
        }
        s = strtok(tempc,"{=");
        s = strtok(NULL,"{=");
        str=s.c_str();
        if (j.endsWith(' '))
            j.chop(1);
        str.remove('"');

        if (j==str) {
            s = strtok(NULL,"{=}");
            str = s.c_str();
            return str;
        }
        count++;
    }

    return j;
}

/* print project bibtex */
void MainWindow::printProjectBibtex() {
    ofstream outfile;
    QString bibfilestring = QFileDialog::getSaveFileName (this,
                                                          tr("Export Bib file"), "",
                                                          tr("Bib Files (*.bib)"));//currentprojectname;
    if (!bibfilestring.endsWith(".bib"))
        bibfilestring+=".bib";
    outfile.open(bibfilestring.toUtf8().constData() );
    /* Write Journal Strings */
    /* Write paper entries */
    /* first the journal strings */
    QFile res(QDir::homePath()+"/.qpaper/Journal_strings.txt");
    res.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray ar;
    QFile res2(bibfilestring);
    res2.remove();
    res2.open(QIODevice::WriteOnly|QIODevice::Text);
    /* Now the papers */
    QSqlQuery query;
    query.exec("SELECT * from '"+currentprojectname+"papers'" );
    int count=0;
    while(query.next()) {
        count++;
    }
    BibArticle *article = new BibArticle[count];
    query.exec("SELECT * from '"+currentprojectname+"papers'" );
    int i=0;
    while (query.next()) {
        QString s = getJournal(query.value(3).toString(),&res);
        QString a = formatAuthorList(query.value(2).toString());
        article[i].setEntries(query.value(0).toString(),
                                 query.value(1).toString(),
                                 a,
                                 s,
                                 query.value(4).toString(),
                                 query.value(5).toString(),
                                 query.value(6).toString(),
                                 query.value(7).toString(),
                                 query.value(8).toString(),
                                 query.value(9).toString());
        article[i].formatEntry();
        ar+=article[i].bibEntry;

        i++;
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
        if (list2.last()=="Jr.") {
            ret += "{";
            ret += list2.at(list2.length()-2);
            ret += " ";
            ret += list2.at(list2.length()-1);
            ret+="}, ";
            for (int j=0; j<list2.length()-2; j++) {
                ret += list2.at(j)+" ";
            }
        } else {
        ret += list2.last()+", ";
        for (int j=0; j<list2.length()-1; j++) {
            ret += list2.at(j)+" ";
        }
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
QString MainWindow::getProjectsfromPaper(QString bibkey) {
    QSqlQuery query;
    query.exec("SELECT projectid FROM allpapers where bibkey=\""+bibkey+"\"");
    QString str,str2;
    query.first();
    str+=query.value(0).toString();

    //Get rid of duplicates
    QStringList list = str.split(";");
    list.removeDuplicates();

    //str2.push_front(";");
    for (int i=0; i<list.length(); i++) {
        str2+=list.at(i);
        str2+=";";
    }

    return str2;
}

QStringList MainWindow::getProjectsfromBibkey(QString bibkey) {
    QSqlQuery query;
    query.exec("SELECT projectid FROM allpapers where bibkey='"+bibkey+"'");
    QString str;
    query.first();
    str=query.value(0).toString();

    //Get rid of duplicates
    QStringList list = str.split(";");
    list.removeDuplicates();
    list.removeAt(0);
    list.removeAll(QString::number(0));

    return list;
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

/* Add papers to project from All list combo box*/
void MainWindow::addPaperstoProject(int nproj) {
    QItemSelectionModel *select = ui->tableView_papers->selectionModel();
    QString str = ui->comboBox_allpapers->itemText(nproj);
    if (!select->hasSelection())
        return;
    QModelIndexList list = select->selectedRows();
    for (int i=0; i<list.count(); i++) {
        paperClicked(list.at(i),true);
        addPapertoProject(nproj,str);
    }
    projectClicked(str);
}

/* Add paper to project from All list combo box*/

void MainWindow::addPapertoProject(int n,QString proj) {
    if (n==0)
        return;

    QSqlQuery query;
    QString strlist;
    query.exec("SELECT id FROM projects WHERE title='"+proj+"'");
    query.first();
    int id = query.value(0).toInt();

    strlist = getProjectsfromPaper(currentpaperkey);
    if (strlist.contains(QString::number(id))) {
        QString st = QString::number(id)+";";
        strlist.remove(st);
    }
    strlist += QString::number(id)+";";

    query.exec("Update allpapers SET projectid='"+strlist+"' where title='"+currentpapername+"'");

    query.exec("DROP TABLE '"+proj+"papers'");
    query.exec("CREATE TABLE '"+proj+"papers' AS SELECT bibkey, title, author, journal, volume, pages, issue, year, notes, pdfpath from allpapers WHERE projectid like '%;"+QString::number(id)+";%'");

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

    QString str = getProjectsfromPaper(currentpaperkey);
    str.remove(";"+QString::number(currentprojectId));
    if (str == ";") {
        query.exec("UPDATE allpapers SET projectid=';0;' WHERE title ='"+currentpapername+"'");
    }   else    {
        query.exec("UPDATE allpapers SET projectid='"+str+"' WHERE title =\""+currentpapername+"\"");
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

/* Click on paper, overridden for multiple selections */
void MainWindow::paperClicked(QModelIndex in, bool mult) {
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

/* Add a new book to the current project */
void MainWindow::addNewBook() {

    //if (!projectSet ) return;

    NewBook *newbook = new NewBook(this);

    int res = newbook->exec();

    newbook->setFocusPolicy(Qt::StrongFocus);
    newbook->setModal(Qt::WindowModal);

    if (res == QDialog::Accepted)
        bookAccepted(newbook);

}

/* Paper accepted, insert or update record */
void MainWindow::bookAccepted(NewBook *newbook) {
        BookData dat;
        dat.key = newbook->key;
        dat.btitle = newbook->btitle;
        dat.chtitle = newbook->chtitle;
        dat.authors = newbook->authors;
        dat.editors = newbook->editors;
        dat.volume = newbook->volume;
        dat.issue = newbook->issue;
        dat.series = newbook->series;
        dat.edition = newbook->edition;
        dat.year = newbook->year;
        dat.notes = newbook->notes;
        dat.publisher = newbook->publisher;
        dat.address = newbook->address;
        dat.pages = newbook->pages;
        QStringList authlist = parseAuthors(dat.authors);

        QSqlQuery query,query2;
        query2.exec("SELECT id from allbooks where bibkey='"+dat.key+"'");
        query2.first();
        QString cid = query2.value(0).toString();
        QString qstrquery = "INSERT OR REPLACE INTO allbooks (id, bibkey, btitle,chtitle, author,editor, volume,issue, edition,series,pages, year,publisher,address,notes,projectid,pdfpath) VALUES (:id, :bibkey, :btitle,:chtitle, :author,:editor, :volume,:issue,:edition,:series, :pages, :year,:publisher,:address, :notes,:projectid,:pdfpath)";
        query.prepare(qstrquery);
        query.bindValue(0,cid);
        query.bindValue(1,dat.key);
        query.bindValue(2,dat.btitle);
        query.bindValue(3,dat.chtitle);
        query.bindValue(4,dat.authors);
        query.bindValue(5,dat.editors);
        query.bindValue(6,dat.volume);
        query.bindValue(7,dat.issue);
        query.bindValue(8,dat.edition);
        query.bindValue(9,dat.series);
        query.bindValue(10,dat.pages);
        query.bindValue(11,dat.year);
        query.bindValue(12,dat.publisher);
        query.bindValue(13,dat.address);
        query.bindValue(14,dat.notes);
        QString str = ";"+QString::number(currentprojectId)+";";
        QString str2 = ";0;";
        QString str3 = ";0;"+QString::number(currentprojectId)+";";
        if (currentprojectname != "all") {
            query.bindValue(15,str3 );
        } else {
            query.bindValue(15,str2);
        }
        query.bindValue(16,newbook->pdf);

        query.exec();

        if (currentprojectname != "all") {
            query.exec("DROP TABLE '"+currentprojectname+"books'");
            query.exec("CREATE TABLE '"+currentprojectname+"books' AS SELECT bibkey, btitle, chtitle, author, editor, volume, issue, edition, series, pages, year, publisher, address, notes, pdfpath from allbooks WHERE projectid like '%;"+QString::number(currentprojectId)+";%'");
        }

        //add paper to names list
        allbooknames<<dat.chtitle;
        allbookkeys<<dat.key;

        //Update paper view
        if (currentprojectname == "all") {
            setProjectAll();
            setProjectAll();
        } else {
            projectClicked(currentprojectname);
        }
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
        QString str3 = ";0;"+QString::number(currentprojectId)+";";
        if (currentprojectname != "all") {
            query.bindValue(11,str3 );
        } else {
            query.bindValue(11,str2);
        }
        query.bindValue(12,newpaper->pdf);

        query.exec();

        if (currentprojectname != "all") {
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

    ConfirmDelete *cd = new ConfirmDelete(this);
    cd->setDeleteObj(currentprojectname);
    int res = cd->exec();
    if (res == QDialog::Accepted) {


    QSqlQuery query;
    query.exec("SELECT isparent from projects WHERE id="+QString::number(currentprojectId ));
    while (query.next()) {
        if (query.value(0).toBool())
            parentprojects --;
    }
    query.exec("DELETE FROM projects WHERE id="+QString::number(currentprojectId ));
    query.exec("DELETE FROM projects WHERE parentid="+QString::number(currentprojectId ));
    //nprojects --;
    delete[] mainProjects;
    dynamic_cast<QStandardItemModel*>(ui->treeView_projects->model())->clear();
    initializeProjectData();
    projectSet = false;
    ui->label_papers->setText("Papers for: ");
    query.exec("DROP TABLE '"+currentprojectname+"papers'");

    //remove parentid from papers table
    QString str = getProjectsfromPaper(currentpaperkey);
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
    else {
        return;
    }
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
    nprojects = 1;
    int i=0;

    //Get number of total projects (main + sub)
    while(query.next()) {
        i++;

        nrecords = i+1;
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
    parentprojects=1;
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

    whichView = "papers";

    QString str = ind.data().toString();

    //If "All" clicked
    if (str == "all") {
        setProjectAll();
    } else {
       // ui->actionAdd_Paper->setEnabled(false);

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
        ui->actionSub->setEnabled(true);
        ui->actionDelete_Project->setEnabled(true);

        ui->tableView_papers->showColumn(0);
        ui->tableView_papers->showColumn(1);
        ui->tableView_papers->showColumn(2);
        ui->tableView_papers->showColumn(3);
        ui->tableView_papers->showColumn(5);
        ui->tableView_papers->showColumn(7);
        ui->tableView_papers->showColumn(8);
//        ui->tableView_papers->reset();


        //Table does not exist
        if (!db.tables().contains(str+"papers")) {
            for (int i=0; i<dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->rowCount(); i++)
                 ui->tableView_papers->setRowHidden(i,true );
            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->clear();
            ui->tableView_papers->reset();
            for (int i=0; i<15; i++)
                ui->tableView_papers->hideColumn(i);

        } else {
        //Table exists
            for (int i=0; i<dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->rowCount(); i++)
                 ui->tableView_papers->setRowHidden(i,true );
            //dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->clear();
            //ui->tableView_papers->reset();

            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setTable(str+"papers");
            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->select();


            for (int i=0; i<dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->rowCount(); i++)
                 ui->tableView_papers->setRowHidden(i,false );
            for (int i=0; i<15; i++)
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
    qDebug()<<str;
    whichView = "papers";


    //ui->actionAdd_Paper->setEnabled(false);
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
        ui->actionSub->setEnabled(true);
        ui->actionDelete_Project->setEnabled(true);

        ui->tableView_papers->showColumn(0);
        ui->tableView_papers->showColumn(1);
        ui->tableView_papers->showColumn(2);
        ui->tableView_papers->showColumn(3);
        ui->tableView_papers->showColumn(5);
        ui->tableView_papers->showColumn(7);
        ui->tableView_papers->showColumn(8);
//        ui->tableView_papers->reset();


        QString str2 = str+"papers";
        if (!db.tables().contains(str2)) {
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
            ui->tableView_papers->reset();


            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setTable(str2);
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

/* Show Books */
void MainWindow::projectClickedBooks(QString str) {
    whichView = "books";

    //ui->actionAdd_Paper->setEnabled(false);
        projectSet = true;

        //Get project name and set to current project
        currentprojectname = str;

        //Query 'projects' table to get current project id and set to current
        QSqlQuery query;
        query.exec("SELECT id FROM projects WHERE title='"+str+"'");
        query.first();
        currentprojectId = query.value(0).toInt();

        //update labels
        ui->label_papers->setText("Books for: "+str);

        //update description
        query.exec("SELECT description FROM projects WHERE title='"+str+"'");
        query.first();

        ui->textEdit_projdescription->setText(query.value(0).toString());

        //Update book view

        paperSet = false;
        ui->textEdit_paperNotes->clear();
        ui->comboBox_projects->setHidden(false);
        ui->comboBox_allpapers->setHidden(true);
        ui->comboBox_allpapers->setEnabled(false);
        ui->comboBox_projects->clear();
        ui->comboBox_projects->insertItem(0,"<-- Select Book to Add to Project '"+currentprojectname+"' -->");
        ui->comboBox_projects->addItems(allbookkeys);
        ui->actionSub->setEnabled(true);
        ui->actionDelete_Project->setEnabled(true);

        ui->tableView_papers->showColumn(0);
        ui->tableView_papers->showColumn(1);
        ui->tableView_papers->showColumn(2);
        ui->tableView_papers->showColumn(3);
        ui->tableView_papers->showColumn(5);
        ui->tableView_papers->showColumn(7);
        ui->tableView_papers->showColumn(8);
//        ui->tableView_papers->reset();


        QString str2 = str+"books";
        if (!db.tables().contains(str2)) {
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
            ui->tableView_papers->reset();


            dynamic_cast<QSqlTableModel*>(ui->tableView_papers->model())->setTable(str2);
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
    ui->actionSub->setEnabled(false);
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
