/********************************************************************************
** Form generated from reading UI file 'newpaper.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPAPER_H
#define UI_NEWPAPER_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QDialog>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewPaper
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_title;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_journal;
    QLineEdit *lineEdit_authors;
    QLabel *label_5;
    QLineEdit *lineEdit_pages;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QPushButton *pushButton;
    QLineEdit *lineEdit_volume;
    QLineEdit *lineEdit_issue;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_year;
    QLineEdit *lineEdit_publisher;
    QLabel *label_9;
    QLabel *label_8;
    QLineEdit *lineEdit_keywords;
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton_addPdf;
    QLineEdit *lineEdit_key;
    QLabel *label_10;

    void setupUi(QDialog *NewPaper)
    {
        if (NewPaper->objectName().isEmpty())
            NewPaper->setObjectName(QString::fromUtf8("NewPaper"));
        NewPaper->setWindowModality(Qt::WindowModal);
        NewPaper->resize(640, 480);
        NewPaper->setFocusPolicy(Qt::StrongFocus);
        NewPaper->setSizeGripEnabled(true);
        NewPaper->setModal(true);
        gridLayout = new QGridLayout(NewPaper);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_title = new QLineEdit(NewPaper);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));

        gridLayout->addWidget(lineEdit_title, 0, 1, 1, 1);

        label_2 = new QLabel(NewPaper);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(NewPaper);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        lineEdit_journal = new QLineEdit(NewPaper);
        lineEdit_journal->setObjectName(QString::fromUtf8("lineEdit_journal"));

        gridLayout->addWidget(lineEdit_journal, 2, 1, 1, 1);

        lineEdit_authors = new QLineEdit(NewPaper);
        lineEdit_authors->setObjectName(QString::fromUtf8("lineEdit_authors"));

        gridLayout->addWidget(lineEdit_authors, 1, 1, 1, 1);

        label_5 = new QLabel(NewPaper);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        lineEdit_pages = new QLineEdit(NewPaper);
        lineEdit_pages->setObjectName(QString::fromUtf8("lineEdit_pages"));

        gridLayout->addWidget(lineEdit_pages, 5, 1, 1, 1);

        label = new QLabel(NewPaper);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(NewPaper);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        pushButton = new QPushButton(NewPaper);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        lineEdit_volume = new QLineEdit(NewPaper);
        lineEdit_volume->setObjectName(QString::fromUtf8("lineEdit_volume"));

        gridLayout->addWidget(lineEdit_volume, 3, 1, 1, 1);

        lineEdit_issue = new QLineEdit(NewPaper);
        lineEdit_issue->setObjectName(QString::fromUtf8("lineEdit_issue"));

        gridLayout->addWidget(lineEdit_issue, 4, 1, 1, 1);

        label_6 = new QLabel(NewPaper);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 5, 0, 1, 1);

        label_7 = new QLabel(NewPaper);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 6, 0, 1, 1);

        lineEdit_year = new QLineEdit(NewPaper);
        lineEdit_year->setObjectName(QString::fromUtf8("lineEdit_year"));

        gridLayout->addWidget(lineEdit_year, 6, 1, 1, 1);

        lineEdit_publisher = new QLineEdit(NewPaper);
        lineEdit_publisher->setObjectName(QString::fromUtf8("lineEdit_publisher"));

        gridLayout->addWidget(lineEdit_publisher, 7, 1, 1, 1);

        label_9 = new QLabel(NewPaper);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 8, 0, 1, 1);

        label_8 = new QLabel(NewPaper);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 7, 0, 1, 1);

        lineEdit_keywords = new QLineEdit(NewPaper);
        lineEdit_keywords->setObjectName(QString::fromUtf8("lineEdit_keywords"));

        gridLayout->addWidget(lineEdit_keywords, 8, 1, 1, 1);

        buttonBox = new QDialogButtonBox(NewPaper);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 11, 0, 1, 2);

        pushButton_addPdf = new QPushButton(NewPaper);
        pushButton_addPdf->setObjectName(QString::fromUtf8("pushButton_addPdf"));

        gridLayout->addWidget(pushButton_addPdf, 9, 1, 1, 1);

        lineEdit_key = new QLineEdit(NewPaper);
        lineEdit_key->setObjectName(QString::fromUtf8("lineEdit_key"));

        gridLayout->addWidget(lineEdit_key, 10, 1, 1, 1);

        label_10 = new QLabel(NewPaper);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 10, 0, 1, 1);

        QWidget::setTabOrder(lineEdit_title, lineEdit_authors);
        QWidget::setTabOrder(lineEdit_authors, pushButton);
        QWidget::setTabOrder(pushButton, lineEdit_journal);
        QWidget::setTabOrder(lineEdit_journal, lineEdit_volume);
        QWidget::setTabOrder(lineEdit_volume, lineEdit_issue);
        QWidget::setTabOrder(lineEdit_issue, lineEdit_pages);
        QWidget::setTabOrder(lineEdit_pages, lineEdit_year);
        QWidget::setTabOrder(lineEdit_year, lineEdit_publisher);
        QWidget::setTabOrder(lineEdit_publisher, lineEdit_keywords);
        QWidget::setTabOrder(lineEdit_keywords, pushButton_addPdf);
        QWidget::setTabOrder(pushButton_addPdf, buttonBox);

        retranslateUi(NewPaper);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewPaper, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewPaper, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewPaper);
    } // setupUi

    void retranslateUi(QDialog *NewPaper)
    {
        NewPaper->setWindowTitle(QApplication::translate("NewPaper", "Add a New Paper", 0));
        label_2->setText(QApplication::translate("NewPaper", "Authors (separated by ';'):", 0));
        label_4->setText(QApplication::translate("NewPaper", "Volume:", 0));
        label_5->setText(QApplication::translate("NewPaper", "Issue:", 0));
        label->setText(QApplication::translate("NewPaper", "Title:", 0));
        label_3->setText(QApplication::translate("NewPaper", "Journal:", 0));
        pushButton->setText(QApplication::translate("NewPaper", "acronyms", 0));
        label_6->setText(QApplication::translate("NewPaper", "Pages:", 0));
        label_7->setText(QApplication::translate("NewPaper", "Year:", 0));
        label_9->setText(QApplication::translate("NewPaper", "Notes:", 0));
        label_8->setText(QApplication::translate("NewPaper", "Publisher:", 0));
        pushButton_addPdf->setText(QApplication::translate("NewPaper", "Add PDF", 0));
        label_10->setText(QApplication::translate("NewPaper", "BibTex Key:", 0));
    } // retranslateUi

};

namespace Ui {
    class NewPaper: public Ui_NewPaper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPAPER_H
