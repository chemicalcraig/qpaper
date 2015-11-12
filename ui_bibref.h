/********************************************************************************
** Form generated from reading UI file 'bibref.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BIBREF_H
#define UI_BIBREF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Bibref
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_id;
    QPlainTextEdit *plainTextEdit_bib;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Bibref)
    {
        if (Bibref->objectName().isEmpty())
            Bibref->setObjectName(QString::fromUtf8("Bibref"));
        Bibref->resize(400, 300);
        verticalLayout = new QVBoxLayout(Bibref);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_id = new QLabel(Bibref);
        label_id->setObjectName(QString::fromUtf8("label_id"));

        verticalLayout->addWidget(label_id);

        plainTextEdit_bib = new QPlainTextEdit(Bibref);
        plainTextEdit_bib->setObjectName(QString::fromUtf8("plainTextEdit_bib"));

        verticalLayout->addWidget(plainTextEdit_bib);

        buttonBox = new QDialogButtonBox(Bibref);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(Bibref);
        QObject::connect(buttonBox, SIGNAL(accepted()), Bibref, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Bibref, SLOT(reject()));

        QMetaObject::connectSlotsByName(Bibref);
    } // setupUi

    void retranslateUi(QDialog *Bibref)
    {
        Bibref->setWindowTitle(QApplication::translate("Bibref", "Dialog", 0, QApplication::UnicodeUTF8));
        label_id->setText(QApplication::translate("Bibref", "ID:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Bibref: public Ui_Bibref {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BIBREF_H
