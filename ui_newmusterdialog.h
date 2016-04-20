/********************************************************************************
** Form generated from reading UI file 'newmusterdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWMUSTERDIALOG_H
#define UI_NEWMUSTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_NewMusterDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *kinLabel;
    QLabel *reaLabel;
    QComboBox *selectKindred;
    QComboBox *selectRealm;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *NewMusterDialog)
    {
        if (NewMusterDialog->objectName().isEmpty())
            NewMusterDialog->setObjectName(QStringLiteral("NewMusterDialog"));
        NewMusterDialog->resize(317, 128);
        gridLayout = new QGridLayout(NewMusterDialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        kinLabel = new QLabel(NewMusterDialog);
        kinLabel->setObjectName(QStringLiteral("kinLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(kinLabel->sizePolicy().hasHeightForWidth());
        kinLabel->setSizePolicy(sizePolicy);

        gridLayout->addWidget(kinLabel, 0, 0, 1, 1);

        reaLabel = new QLabel(NewMusterDialog);
        reaLabel->setObjectName(QStringLiteral("reaLabel"));

        gridLayout->addWidget(reaLabel, 1, 0, 1, 1);

        selectKindred = new QComboBox(NewMusterDialog);
        selectKindred->setObjectName(QStringLiteral("selectKindred"));

        gridLayout->addWidget(selectKindred, 0, 1, 1, 1);

        selectRealm = new QComboBox(NewMusterDialog);
        selectRealm->setObjectName(QStringLiteral("selectRealm"));

        gridLayout->addWidget(selectRealm, 1, 1, 1, 1);

        buttonBox = new QDialogButtonBox(NewMusterDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(NewMusterDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), NewMusterDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), NewMusterDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(NewMusterDialog);
    } // setupUi

    void retranslateUi(QDialog *NewMusterDialog)
    {
        NewMusterDialog->setWindowTitle(QApplication::translate("NewMusterDialog", "Dialog", 0));
        kinLabel->setText(QApplication::translate("NewMusterDialog", "Select Kindred:", 0));
        reaLabel->setText(QApplication::translate("NewMusterDialog", "Select Realm:", 0));
    } // retranslateUi

};

namespace Ui {
    class NewMusterDialog: public Ui_NewMusterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWMUSTERDIALOG_H
