/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCurrent_project;
    QAction *actionAll_papers;
    QAction *actionAdd_Paper;
    QAction *actionDelete_Project;
    QAction *actionRemove_Paper_From_Project;
    QAction *actionRemove_Paper_From_Database;
    QAction *actionJournals;
    QAction *actionEdit_Paper;
    QAction *actionView_Paper;
    QAction *actionView;
    QAction *actionPaper;
    QAction *actionBibTeX_entry;
    QAction *actionMain;
    QAction *actionSub;
    QAction *actionDelete_Project_2;
    QAction *actionNew_Paper;
    QAction *actionFrom_Project;
    QAction *actionAll_Instances;
    QAction *actionEdit_Paper_2;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_newproject;
    QPushButton *pushButton_newpaper;
    QPushButton *pushButton_book;
    QPushButton *pushButton_editpaper;
    QPushButton *pushButton_viewpdf;
    QPushButton *pushButton_bibentry;
    QPushButton *pushButton_exportprojectbib;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_projects;
    QTreeView *treeView_projects;
    QSpacerItem *verticalSpacer;
    QLabel *label_description;
    QTextEdit *textEdit_projdescription;
    QGridLayout *gridLayout;
    QComboBox *comboBox_allpapers;
    QPushButton *pushButton_switch;
    QLabel *label;
    QTableView *tableView_papers;
    QTextEdit *textEdit_paperNotes;
    QComboBox *comboBox_projects;
    QLabel *label_papers;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew_Project;
    QMenu *menuExport_bibtex;
    QMenu *menuRemove_Paper;
    QMenu *menuBib_Tools;
    QMenu *menuView;
    QMenu *menuEdit;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1205, 666);
        actionCurrent_project = new QAction(MainWindow);
        actionCurrent_project->setObjectName(QString::fromUtf8("actionCurrent_project"));
        actionAll_papers = new QAction(MainWindow);
        actionAll_papers->setObjectName(QString::fromUtf8("actionAll_papers"));
        actionAdd_Paper = new QAction(MainWindow);
        actionAdd_Paper->setObjectName(QString::fromUtf8("actionAdd_Paper"));
        actionDelete_Project = new QAction(MainWindow);
        actionDelete_Project->setObjectName(QString::fromUtf8("actionDelete_Project"));
        actionRemove_Paper_From_Project = new QAction(MainWindow);
        actionRemove_Paper_From_Project->setObjectName(QString::fromUtf8("actionRemove_Paper_From_Project"));
        actionRemove_Paper_From_Database = new QAction(MainWindow);
        actionRemove_Paper_From_Database->setObjectName(QString::fromUtf8("actionRemove_Paper_From_Database"));
        actionJournals = new QAction(MainWindow);
        actionJournals->setObjectName(QString::fromUtf8("actionJournals"));
        actionEdit_Paper = new QAction(MainWindow);
        actionEdit_Paper->setObjectName(QString::fromUtf8("actionEdit_Paper"));
        actionView_Paper = new QAction(MainWindow);
        actionView_Paper->setObjectName(QString::fromUtf8("actionView_Paper"));
        actionView = new QAction(MainWindow);
        actionView->setObjectName(QString::fromUtf8("actionView"));
        actionPaper = new QAction(MainWindow);
        actionPaper->setObjectName(QString::fromUtf8("actionPaper"));
        actionBibTeX_entry = new QAction(MainWindow);
        actionBibTeX_entry->setObjectName(QString::fromUtf8("actionBibTeX_entry"));
        actionMain = new QAction(MainWindow);
        actionMain->setObjectName(QString::fromUtf8("actionMain"));
        actionSub = new QAction(MainWindow);
        actionSub->setObjectName(QString::fromUtf8("actionSub"));
        actionDelete_Project_2 = new QAction(MainWindow);
        actionDelete_Project_2->setObjectName(QString::fromUtf8("actionDelete_Project_2"));
        actionNew_Paper = new QAction(MainWindow);
        actionNew_Paper->setObjectName(QString::fromUtf8("actionNew_Paper"));
        actionFrom_Project = new QAction(MainWindow);
        actionFrom_Project->setObjectName(QString::fromUtf8("actionFrom_Project"));
        actionAll_Instances = new QAction(MainWindow);
        actionAll_Instances->setObjectName(QString::fromUtf8("actionAll_Instances"));
        actionEdit_Paper_2 = new QAction(MainWindow);
        actionEdit_Paper_2->setObjectName(QString::fromUtf8("actionEdit_Paper_2"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_newproject = new QPushButton(centralWidget);
        pushButton_newproject->setObjectName(QString::fromUtf8("pushButton_newproject"));

        horizontalLayout_2->addWidget(pushButton_newproject);

        pushButton_newpaper = new QPushButton(centralWidget);
        pushButton_newpaper->setObjectName(QString::fromUtf8("pushButton_newpaper"));

        horizontalLayout_2->addWidget(pushButton_newpaper);

        pushButton_book = new QPushButton(centralWidget);
        pushButton_book->setObjectName(QString::fromUtf8("pushButton_book"));

        horizontalLayout_2->addWidget(pushButton_book);

        pushButton_editpaper = new QPushButton(centralWidget);
        pushButton_editpaper->setObjectName(QString::fromUtf8("pushButton_editpaper"));

        horizontalLayout_2->addWidget(pushButton_editpaper);

        pushButton_viewpdf = new QPushButton(centralWidget);
        pushButton_viewpdf->setObjectName(QString::fromUtf8("pushButton_viewpdf"));

        horizontalLayout_2->addWidget(pushButton_viewpdf);

        pushButton_bibentry = new QPushButton(centralWidget);
        pushButton_bibentry->setObjectName(QString::fromUtf8("pushButton_bibentry"));

        horizontalLayout_2->addWidget(pushButton_bibentry);

        pushButton_exportprojectbib = new QPushButton(centralWidget);
        pushButton_exportprojectbib->setObjectName(QString::fromUtf8("pushButton_exportprojectbib"));

        horizontalLayout_2->addWidget(pushButton_exportprojectbib);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        verticalLayout->setContentsMargins(0, -1, 84, -1);
        label_projects = new QLabel(centralWidget);
        label_projects->setObjectName(QString::fromUtf8("label_projects"));

        verticalLayout->addWidget(label_projects);

        treeView_projects = new QTreeView(centralWidget);
        treeView_projects->setObjectName(QString::fromUtf8("treeView_projects"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeView_projects->sizePolicy().hasHeightForWidth());
        treeView_projects->setSizePolicy(sizePolicy1);
        treeView_projects->setMinimumSize(QSize(250, 100));

        verticalLayout->addWidget(treeView_projects);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        label_description = new QLabel(centralWidget);
        label_description->setObjectName(QString::fromUtf8("label_description"));

        verticalLayout->addWidget(label_description);

        textEdit_projdescription = new QTextEdit(centralWidget);
        textEdit_projdescription->setObjectName(QString::fromUtf8("textEdit_projdescription"));
        sizePolicy1.setHeightForWidth(textEdit_projdescription->sizePolicy().hasHeightForWidth());
        textEdit_projdescription->setSizePolicy(sizePolicy1);
        textEdit_projdescription->setMinimumSize(QSize(250, 50));
        textEdit_projdescription->setMaximumSize(QSize(16777215, 100));

        verticalLayout->addWidget(textEdit_projdescription);


        horizontalLayout->addLayout(verticalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox_allpapers = new QComboBox(centralWidget);
        comboBox_allpapers->setObjectName(QString::fromUtf8("comboBox_allpapers"));

        gridLayout->addWidget(comboBox_allpapers, 1, 0, 1, 1);

        pushButton_switch = new QPushButton(centralWidget);
        pushButton_switch->setObjectName(QString::fromUtf8("pushButton_switch"));

        gridLayout->addWidget(pushButton_switch, 5, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 6, 0, 1, 1);

        tableView_papers = new QTableView(centralWidget);
        tableView_papers->setObjectName(QString::fromUtf8("tableView_papers"));

        gridLayout->addWidget(tableView_papers, 4, 0, 1, 1);

        textEdit_paperNotes = new QTextEdit(centralWidget);
        textEdit_paperNotes->setObjectName(QString::fromUtf8("textEdit_paperNotes"));
        textEdit_paperNotes->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(textEdit_paperNotes, 7, 0, 1, 1);

        comboBox_projects = new QComboBox(centralWidget);
        comboBox_projects->setObjectName(QString::fromUtf8("comboBox_projects"));

        gridLayout->addWidget(comboBox_projects, 2, 0, 1, 1);

        label_papers = new QLabel(centralWidget);
        label_papers->setObjectName(QString::fromUtf8("label_papers"));

        gridLayout->addWidget(label_papers, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1205, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuNew_Project = new QMenu(menuFile);
        menuNew_Project->setObjectName(QString::fromUtf8("menuNew_Project"));
        menuExport_bibtex = new QMenu(menuFile);
        menuExport_bibtex->setObjectName(QString::fromUtf8("menuExport_bibtex"));
        menuRemove_Paper = new QMenu(menuFile);
        menuRemove_Paper->setObjectName(QString::fromUtf8("menuRemove_Paper"));
        menuBib_Tools = new QMenu(menuBar);
        menuBib_Tools->setObjectName(QString::fromUtf8("menuBib_Tools"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuBib_Tools->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addAction(menuNew_Project->menuAction());
        menuFile->addAction(actionDelete_Project_2);
        menuFile->addSeparator();
        menuFile->addAction(actionNew_Paper);
        menuFile->addAction(menuRemove_Paper->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(menuExport_bibtex->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuNew_Project->addAction(actionMain);
        menuNew_Project->addAction(actionSub);
        menuExport_bibtex->addAction(actionCurrent_project);
        menuExport_bibtex->addAction(actionAll_papers);
        menuRemove_Paper->addAction(actionFrom_Project);
        menuRemove_Paper->addAction(actionAll_Instances);
        menuBib_Tools->addAction(actionJournals);
        menuView->addAction(actionPaper);
        menuView->addAction(actionBibTeX_entry);
        menuEdit->addAction(actionEdit_Paper_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionCurrent_project->setText(QApplication::translate("MainWindow", "Current project", 0, QApplication::UnicodeUTF8));
        actionAll_papers->setText(QApplication::translate("MainWindow", "All papers", 0, QApplication::UnicodeUTF8));
        actionAdd_Paper->setText(QApplication::translate("MainWindow", "Add Paper", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionAdd_Paper->setToolTip(QApplication::translate("MainWindow", "Add a new paper to the current project", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionDelete_Project->setText(QApplication::translate("MainWindow", "Delete Project", 0, QApplication::UnicodeUTF8));
        actionRemove_Paper_From_Project->setText(QApplication::translate("MainWindow", "Remove Paper From Project", 0, QApplication::UnicodeUTF8));
        actionRemove_Paper_From_Database->setText(QApplication::translate("MainWindow", "Remove Paper From Database", 0, QApplication::UnicodeUTF8));
        actionJournals->setText(QApplication::translate("MainWindow", "Journals", 0, QApplication::UnicodeUTF8));
        actionEdit_Paper->setText(QApplication::translate("MainWindow", "Edit Paper", 0, QApplication::UnicodeUTF8));
        actionView_Paper->setText(QApplication::translate("MainWindow", "View Paper", 0, QApplication::UnicodeUTF8));
        actionView->setText(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        actionPaper->setText(QApplication::translate("MainWindow", "Paper", 0, QApplication::UnicodeUTF8));
        actionBibTeX_entry->setText(QApplication::translate("MainWindow", "BibTeX entry", 0, QApplication::UnicodeUTF8));
        actionMain->setText(QApplication::translate("MainWindow", "Main", 0, QApplication::UnicodeUTF8));
        actionSub->setText(QApplication::translate("MainWindow", "Sub", 0, QApplication::UnicodeUTF8));
        actionDelete_Project_2->setText(QApplication::translate("MainWindow", "Delete Project", 0, QApplication::UnicodeUTF8));
        actionNew_Paper->setText(QApplication::translate("MainWindow", "New Paper", 0, QApplication::UnicodeUTF8));
        actionFrom_Project->setText(QApplication::translate("MainWindow", "From Project", 0, QApplication::UnicodeUTF8));
        actionAll_Instances->setText(QApplication::translate("MainWindow", "All Instances", 0, QApplication::UnicodeUTF8));
        actionEdit_Paper_2->setText(QApplication::translate("MainWindow", "Paper", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        pushButton_newproject->setText(QApplication::translate("MainWindow", "Add New Project", 0, QApplication::UnicodeUTF8));
        pushButton_newpaper->setText(QApplication::translate("MainWindow", "Add New Paper", 0, QApplication::UnicodeUTF8));
        pushButton_book->setText(QApplication::translate("MainWindow", "Add New Book/Chapter", 0, QApplication::UnicodeUTF8));
        pushButton_editpaper->setText(QApplication::translate("MainWindow", "Edit Paper", 0, QApplication::UnicodeUTF8));
        pushButton_viewpdf->setText(QApplication::translate("MainWindow", "View PDF", 0, QApplication::UnicodeUTF8));
        pushButton_bibentry->setText(QApplication::translate("MainWindow", "View bib Entry", 0, QApplication::UnicodeUTF8));
        pushButton_exportprojectbib->setText(QApplication::translate("MainWindow", "Export Project .bib", 0, QApplication::UnicodeUTF8));
        label_projects->setText(QApplication::translate("MainWindow", "Projects:", 0, QApplication::UnicodeUTF8));
        label_description->setText(QApplication::translate("MainWindow", "Description:", 0, QApplication::UnicodeUTF8));
        pushButton_switch->setText(QApplication::translate("MainWindow", "View Books", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Notes:", 0, QApplication::UnicodeUTF8));
        label_papers->setText(QApplication::translate("MainWindow", "Papers:", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuNew_Project->setTitle(QApplication::translate("MainWindow", "New Project", 0, QApplication::UnicodeUTF8));
        menuExport_bibtex->setTitle(QApplication::translate("MainWindow", "Export bibtex", 0, QApplication::UnicodeUTF8));
        menuRemove_Paper->setTitle(QApplication::translate("MainWindow", "Remove Paper", 0, QApplication::UnicodeUTF8));
        menuBib_Tools->setTitle(QApplication::translate("MainWindow", "Bib Tools", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
