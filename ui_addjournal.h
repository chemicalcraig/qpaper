/********************************************************************************
** Form generated from reading UI file 'addjournal.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDJOURNAL_H
#define UI_ADDJOURNAL_H

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

QT_BEGIN_NAMESPACE

class Ui_AddJournal
{
public:
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_title;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddJournal)
    {
        if (AddJournal->objectName().isEmpty())
            AddJournal->setObjectName(QString::fromUtf8("AddJournal"));
        AddJournal->resize(320, 144);
        gridLayout = new QGridLayout(AddJournal);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(AddJournal);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(AddJournal);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        label = new QLabel(AddJournal);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        lineEdit = new QLineEdit(AddJournal);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(AddJournal);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_title = new QLineEdit(AddJournal);
        lineEdit_title->setObjectName(QString::fromUtf8("lineEdit_title"));

        gridLayout->addWidget(lineEdit_title, 2, 1, 1, 1);

        buttonBox = new QDialogButtonBox(AddJournal);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 3, 0, 1, 2);


        retranslateUi(AddJournal);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddJournal, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddJournal, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddJournal);
    } // setupUi

    void retranslateUi(QDialog *AddJournal)
    {
        AddJournal->setWindowTitle(QApplication::translate("AddJournal", "Dialog", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddJournal", "Abbreviation:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddJournal", "Accronym:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddJournal", "Full Title:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddJournal: public Ui_AddJournal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDJOURNAL_H
