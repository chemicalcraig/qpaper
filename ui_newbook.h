/********************************************************************************
** Form generated from reading UI file 'newbook.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWBOOK_H
#define UI_NEWBOOK_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewBook
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEdit_btitle;
    QLabel *label_3;
    QLineEdit *lineEdit_chtitle;
    QLabel *label_2;
    QLineEdit *lineEdit_auth;
    QLabel *label_8;
    QLineEdit *lineEdit_editors;
    QLabel *label_4;
    QLineEdit *lineEdit_volume;
    QLabel *label_5;
    QLineEdit *lineEdit_issue;
    QLabel *label_13;
    QLineEdit *lineEdit_edition;
    QLabel *label_14;
    QLineEdit *lineEdit_series;
    QLabel *label_6;
    QLineEdit *lineEdit_pages;
    QLabel *label_7;
    QLineEdit *lineEdit_year;
    QLabel *label_11;
    QLineEdit *lineEdit_publisher;
    QLabel *label_12;
    QLineEdit *lineEdit_address;
    QLabel *label_9;
    QPlainTextEdit *plainTextEdit_notes;
    QLabel *label_10;
    QLineEdit *lineEdit_key;
    QPushButton *pushButton_addPdf;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewBook)
    {
        if (NewBook->objectName().isEmpty())
            NewBook->setObjectName(QString::fromUtf8("NewBook"));
        NewBook->resize(652, 680);
        gridLayout = new QGridLayout(NewBook);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(NewBook);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit_btitle = new QLineEdit(NewBook);
        lineEdit_btitle->setObjectName(QString::fromUtf8("lineEdit_btitle"));

        gridLayout->addWidget(lineEdit_btitle, 0, 1, 1, 1);

        label_3 = new QLabel(NewBook);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_chtitle = new QLineEdit(NewBook);
        lineEdit_chtitle->setObjectName(QString::fromUtf8("lineEdit_chtitle"));

        gridLayout->addWidget(lineEdit_chtitle, 1, 1, 1, 1);

        label_2 = new QLabel(NewBook);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        lineEdit_auth = new QLineEdit(NewBook);
        lineEdit_auth->setObjectName(QString::fromUtf8("lineEdit_auth"));

        gridLayout->addWidget(lineEdit_auth, 2, 1, 1, 1);

        label_8 = new QLabel(NewBook);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        lineEdit_editors = new QLineEdit(NewBook);
        lineEdit_editors->setObjectName(QString::fromUtf8("lineEdit_editors"));

        gridLayout->addWidget(lineEdit_editors, 3, 1, 1, 1);

        label_4 = new QLabel(NewBook);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        lineEdit_volume = new QLineEdit(NewBook);
        lineEdit_volume->setObjectName(QString::fromUtf8("lineEdit_volume"));

        gridLayout->addWidget(lineEdit_volume, 4, 1, 1, 1);

        label_5 = new QLabel(NewBook);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 5, 0, 1, 1);

        lineEdit_issue = new QLineEdit(NewBook);
        lineEdit_issue->setObjectName(QString::fromUtf8("lineEdit_issue"));

        gridLayout->addWidget(lineEdit_issue, 5, 1, 1, 1);

        label_13 = new QLabel(NewBook);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 6, 0, 1, 1);

        lineEdit_edition = new QLineEdit(NewBook);
        lineEdit_edition->setObjectName(QString::fromUtf8("lineEdit_edition"));

        gridLayout->addWidget(lineEdit_edition, 6, 1, 1, 1);

        label_14 = new QLabel(NewBook);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 7, 0, 1, 1);

        lineEdit_series = new QLineEdit(NewBook);
        lineEdit_series->setObjectName(QString::fromUtf8("lineEdit_series"));

        gridLayout->addWidget(lineEdit_series, 7, 1, 1, 1);

        label_6 = new QLabel(NewBook);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        lineEdit_pages = new QLineEdit(NewBook);
        lineEdit_pages->setObjectName(QString::fromUtf8("lineEdit_pages"));

        gridLayout->addWidget(lineEdit_pages, 8, 1, 1, 1);

        label_7 = new QLabel(NewBook);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        lineEdit_year = new QLineEdit(NewBook);
        lineEdit_year->setObjectName(QString::fromUtf8("lineEdit_year"));

        gridLayout->addWidget(lineEdit_year, 9, 1, 1, 1);

        label_11 = new QLabel(NewBook);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 10, 0, 1, 1);

        lineEdit_publisher = new QLineEdit(NewBook);
        lineEdit_publisher->setObjectName(QString::fromUtf8("lineEdit_publisher"));

        gridLayout->addWidget(lineEdit_publisher, 10, 1, 1, 1);

        label_12 = new QLabel(NewBook);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 11, 0, 1, 1);

        lineEdit_address = new QLineEdit(NewBook);
        lineEdit_address->setObjectName(QString::fromUtf8("lineEdit_address"));

        gridLayout->addWidget(lineEdit_address, 11, 1, 1, 1);

        label_9 = new QLabel(NewBook);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 12, 0, 1, 1);

        plainTextEdit_notes = new QPlainTextEdit(NewBook);
        plainTextEdit_notes->setObjectName(QString::fromUtf8("plainTextEdit_notes"));

        gridLayout->addWidget(plainTextEdit_notes, 12, 1, 1, 1);

        label_10 = new QLabel(NewBook);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 13, 0, 1, 1);

        lineEdit_key = new QLineEdit(NewBook);
        lineEdit_key->setObjectName(QString::fromUtf8("lineEdit_key"));

        gridLayout->addWidget(lineEdit_key, 13, 1, 1, 1);

        pushButton_addPdf = new QPushButton(NewBook);
        pushButton_addPdf->setObjectName(QString::fromUtf8("pushButton_addPdf"));

        gridLayout->addWidget(pushButton_addPdf, 14, 1, 1, 1);

        buttonBox = new QDialogButtonBox(NewBook);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 15, 0, 1, 2);


        retranslateUi(NewBook);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewBook, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewBook, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewBook);
    } // setupUi

    void retranslateUi(QDialog *NewBook)
    {
        NewBook->setWindowTitle(QApplication::translate("NewBook", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewBook", "Book Title:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewBook", "Chapter Title:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewBook", "Authors (separated by ';'):", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NewBook", "Editors (separated by ';'):", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewBook", "Volume:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NewBook", "Issue:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("NewBook", "Edition:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("NewBook", "Series:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NewBook", "Pages:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NewBook", "Year:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NewBook", "Publisher:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("NewBook", "Address:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("NewBook", "Notes:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NewBook", "BibTex Key:", 0, QApplication::UnicodeUTF8));
        pushButton_addPdf->setText(QApplication::translate("NewBook", "Add PDF", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewBook: public Ui_NewBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWBOOK_H
