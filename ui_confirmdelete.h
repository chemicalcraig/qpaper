/********************************************************************************
** Form generated from reading UI file 'confirmdelete.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMDELETE_H
#define UI_CONFIRMDELETE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ConfirmDelete
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;
    QLabel *label_title;

    void setupUi(QDialog *ConfirmDelete)
    {
        if (ConfirmDelete->objectName().isEmpty())
            ConfirmDelete->setObjectName(QString::fromUtf8("ConfirmDelete"));
        ConfirmDelete->resize(318, 153);
        gridLayout = new QGridLayout(ConfirmDelete);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(ConfirmDelete);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ConfirmDelete);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);

        label_title = new QLabel(ConfirmDelete);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QFont font;
        font.setPointSize(14);
        label_title->setFont(font);

        gridLayout->addWidget(label_title, 1, 0, 1, 1);


        retranslateUi(ConfirmDelete);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfirmDelete, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfirmDelete, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConfirmDelete);
    } // setupUi

    void retranslateUi(QDialog *ConfirmDelete)
    {
        ConfirmDelete->setWindowTitle(QApplication::translate("ConfirmDelete", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfirmDelete", "Are you sure you want to delete:", 0, QApplication::UnicodeUTF8));
        label_title->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ConfirmDelete: public Ui_ConfirmDelete {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMDELETE_H
