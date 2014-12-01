/********************************************************************************
** Form generated from reading UI file 'journals.ui'
**
** Created: Sat Sep 27 18:17:29 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_JOURNALS_H
#define UI_JOURNALS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Journals
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget_journallist;
    QPushButton *pushButton_add;
    QPushButton *pushButton_select;

    void setupUi(QDialog *Journals)
    {
        if (Journals->objectName().isEmpty())
            Journals->setObjectName(QString::fromUtf8("Journals"));
        Journals->resize(640, 480);
        verticalLayout_2 = new QVBoxLayout(Journals);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(Journals);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        scrollArea = new QScrollArea(Journals);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 620, 439));
        verticalLayout = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget_journallist = new QListWidget(scrollAreaWidgetContents);
        listWidget_journallist->setObjectName(QString::fromUtf8("listWidget_journallist"));

        verticalLayout->addWidget(listWidget_journallist);

        pushButton_add = new QPushButton(scrollAreaWidgetContents);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        verticalLayout->addWidget(pushButton_add);

        pushButton_select = new QPushButton(scrollAreaWidgetContents);
        pushButton_select->setObjectName(QString::fromUtf8("pushButton_select"));

        verticalLayout->addWidget(pushButton_select);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);


        retranslateUi(Journals);

        QMetaObject::connectSlotsByName(Journals);
    } // setupUi

    void retranslateUi(QDialog *Journals)
    {
        Journals->setWindowTitle(QApplication::translate("Journals", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Journals", "Journal Abbreviations", 0, QApplication::UnicodeUTF8));
        pushButton_add->setText(QApplication::translate("Journals", "Add New Journal", 0, QApplication::UnicodeUTF8));
        pushButton_select->setText(QApplication::translate("Journals", "Select Journal", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Journals: public Ui_Journals {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_JOURNALS_H
