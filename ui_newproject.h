/********************************************************************************
** Form generated from reading UI file 'newproject.ui'
**
** Created: Sat Sep 27 12:39:30 2014
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECT_H
#define UI_NEWPROJECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewProject
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *lineEdit_projectname;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_projectdescription;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewProject)
    {
        if (NewProject->objectName().isEmpty())
            NewProject->setObjectName(QString::fromUtf8("NewProject"));
        NewProject->resize(640, 480);
        verticalLayout = new QVBoxLayout(NewProject);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(NewProject);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        lineEdit_projectname = new QLineEdit(NewProject);
        lineEdit_projectname->setObjectName(QString::fromUtf8("lineEdit_projectname"));

        verticalLayout->addWidget(lineEdit_projectname);

        label_2 = new QLabel(NewProject);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        plainTextEdit_projectdescription = new QPlainTextEdit(NewProject);
        plainTextEdit_projectdescription->setObjectName(QString::fromUtf8("plainTextEdit_projectdescription"));

        verticalLayout->addWidget(plainTextEdit_projectdescription);

        buttonBox = new QDialogButtonBox(NewProject);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(NewProject);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewProject, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewProject, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewProject);
    } // setupUi

    void retranslateUi(QDialog *NewProject)
    {
        NewProject->setWindowTitle(QApplication::translate("NewProject", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewProject", "Project Name:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewProject", "Project Description:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewProject: public Ui_NewProject {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECT_H
