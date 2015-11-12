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
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
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
    QAction *actionNew_main_project;
    QAction *actionSub_project;
    QAction *actionNew_Main_Project;
    QAction *actionNew_Sub_Project;
    QAction *actionDelete_Project;
    QAction *actionRemove_Paper_From_Project;
    QAction *actionRemove_Paper_From_Database;
    QAction *actionJournals;
    QAction *actionEdit_Paper;
    QAction *actionView_Paper;
    QAction *actionView;
    QAction *actionPaper;
    QAction *actionBibTeX_entry;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_projects;
    QTreeView *treeView_projects;
    QSpacerItem *verticalSpacer;
    QLabel *label_description;
    QTextEdit *textEdit_projdescription;
    QGridLayout *gridLayout;
    QComboBox *comboBox_allpapers;
    QTableView *tableView_papers;
    QTextEdit *textEdit_paperNotes;
    QComboBox *comboBox_projects;
    QLabel *label_papers;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew_Project;
    QMenu *menuExport_bibtex;
    QMenu *menuBib_Tools;
    QMenu *menuView;
    QToolBar *mainToolBar;
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
        actionNew_main_project = new QAction(MainWindow);
        actionNew_main_project->setObjectName(QString::fromUtf8("actionNew_main_project"));
        actionSub_project = new QAction(MainWindow);
        actionSub_project->setObjectName(QString::fromUtf8("actionSub_project"));
        actionNew_Main_Project = new QAction(MainWindow);
        actionNew_Main_Project->setObjectName(QString::fromUtf8("actionNew_Main_Project"));
        actionNew_Sub_Project = new QAction(MainWindow);
        actionNew_Sub_Project->setObjectName(QString::fromUtf8("actionNew_Sub_Project"));
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
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
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

        tableView_papers = new QTableView(centralWidget);
        tableView_papers->setObjectName(QString::fromUtf8("tableView_papers"));

        gridLayout->addWidget(tableView_papers, 4, 0, 1, 1);

        textEdit_paperNotes = new QTextEdit(centralWidget);
        textEdit_paperNotes->setObjectName(QString::fromUtf8("textEdit_paperNotes"));
        textEdit_paperNotes->setMaximumSize(QSize(16777215, 100));

        gridLayout->addWidget(textEdit_paperNotes, 6, 0, 1, 1);

        comboBox_projects = new QComboBox(centralWidget);
        comboBox_projects->setObjectName(QString::fromUtf8("comboBox_projects"));

        gridLayout->addWidget(comboBox_projects, 2, 0, 1, 1);

        label_papers = new QLabel(centralWidget);
        label_papers->setObjectName(QString::fromUtf8("label_papers"));

        gridLayout->addWidget(label_papers, 0, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 5, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1205, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuNew_Project = new QMenu(menuFile);
        menuNew_Project->setObjectName(QString::fromUtf8("menuNew_Project"));
        menuExport_bibtex = new QMenu(menuFile);
        menuExport_bibtex->setObjectName(QString::fromUtf8("menuExport_bibtex"));
        menuBib_Tools = new QMenu(menuBar);
        menuBib_Tools->setObjectName(QString::fromUtf8("menuBib_Tools"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuBib_Tools->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuFile->addAction(menuNew_Project->menuAction());
        menuFile->addAction(menuExport_bibtex->menuAction());
        menuNew_Project->addAction(actionNew_main_project);
        menuNew_Project->addAction(actionSub_project);
        menuExport_bibtex->addAction(actionCurrent_project);
        menuExport_bibtex->addAction(actionAll_papers);
        menuBib_Tools->addAction(actionJournals);
        menuView->addAction(actionPaper);
        menuView->addAction(actionBibTeX_entry);
        mainToolBar->addAction(actionNew_Main_Project);
        mainToolBar->addAction(actionNew_Sub_Project);
        mainToolBar->addAction(actionDelete_Project);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd_Paper);
        mainToolBar->addAction(actionRemove_Paper_From_Project);
        mainToolBar->addAction(actionRemove_Paper_From_Database);
        mainToolBar->addAction(actionEdit_Paper);
        mainToolBar->addAction(actionView_Paper);

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
        actionNew_main_project->setText(QApplication::translate("MainWindow", "Main project", 0, QApplication::UnicodeUTF8));
        actionSub_project->setText(QApplication::translate("MainWindow", "Sub project", 0, QApplication::UnicodeUTF8));
        actionNew_Main_Project->setText(QApplication::translate("MainWindow", "New Main Project", 0, QApplication::UnicodeUTF8));
        actionNew_Sub_Project->setText(QApplication::translate("MainWindow", "New Sub Project", 0, QApplication::UnicodeUTF8));
        actionDelete_Project->setText(QApplication::translate("MainWindow", "Delete Project", 0, QApplication::UnicodeUTF8));
        actionRemove_Paper_From_Project->setText(QApplication::translate("MainWindow", "Remove Paper From Project", 0, QApplication::UnicodeUTF8));
        actionRemove_Paper_From_Database->setText(QApplication::translate("MainWindow", "Remove Paper From Database", 0, QApplication::UnicodeUTF8));
        actionJournals->setText(QApplication::translate("MainWindow", "Journals", 0, QApplication::UnicodeUTF8));
        actionEdit_Paper->setText(QApplication::translate("MainWindow", "Edit Paper", 0, QApplication::UnicodeUTF8));
        actionView_Paper->setText(QApplication::translate("MainWindow", "View Paper", 0, QApplication::UnicodeUTF8));
        actionView->setText(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        actionPaper->setText(QApplication::translate("MainWindow", "Paper", 0, QApplication::UnicodeUTF8));
        actionBibTeX_entry->setText(QApplication::translate("MainWindow", "BibTeX entry", 0, QApplication::UnicodeUTF8));
        label_projects->setText(QApplication::translate("MainWindow", "Projects:", 0, QApplication::UnicodeUTF8));
        label_description->setText(QApplication::translate("MainWindow", "Description:", 0, QApplication::UnicodeUTF8));
        label_papers->setText(QApplication::translate("MainWindow", "Papers:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Paper Notes:", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuNew_Project->setTitle(QApplication::translate("MainWindow", "New Project", 0, QApplication::UnicodeUTF8));
        menuExport_bibtex->setTitle(QApplication::translate("MainWindow", "Export bibtex", 0, QApplication::UnicodeUTF8));
        menuBib_Tools->setTitle(QApplication::translate("MainWindow", "Bib Tools", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
