/********************************************************************************
** Form generated from reading UI file 'unitframe.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITFRAME_H
#define UI_UNITFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_UnitFrame
{
public:
    QGridLayout *unit_layout;
    QLabel *unit_Lubi;
    QLabel *unit_LminU;
    QLabel *unit_Lauth;
    QLabel *unit_Lname;
    QLabel *unit_Lhorn;
    QLabel *unit_Lban;
    QLabel *unit_Lmsize;
    QLabel *unit_Lsize;
    QLabel *unit_Lchamp;
    QComboBox *unit_select;
    QLineEdit *unit_auth;
    QSpinBox *unit_size;
    QLineEdit *unit_msize;
    QCheckBox *unit_banner;
    QCheckBox *unit_champ;
    QCheckBox *unit_horn;
    QLineEdit *unit_ubi;
    QCheckBox *unit_minU;
    QLineEdit *unit_cost;
    QLabel *unit_Lcost;

    void setupUi(QFrame *UnitFrame)
    {
        if (UnitFrame->objectName().isEmpty())
            UnitFrame->setObjectName(QStringLiteral("UnitFrame"));
        UnitFrame->resize(1040, 61);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UnitFrame->sizePolicy().hasHeightForWidth());
        UnitFrame->setSizePolicy(sizePolicy);
        UnitFrame->setMinimumSize(QSize(1040, 61));
        UnitFrame->setMaximumSize(QSize(1040, 61));
        UnitFrame->setFrameShape(QFrame::Box);
        UnitFrame->setFrameShadow(QFrame::Raised);
        unit_layout = new QGridLayout(UnitFrame);
        unit_layout->setObjectName(QStringLiteral("unit_layout"));
        unit_layout->setHorizontalSpacing(25);
        unit_layout->setContentsMargins(0, -1, 9, -1);
        unit_Lubi = new QLabel(UnitFrame);
        unit_Lubi->setObjectName(QStringLiteral("unit_Lubi"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(unit_Lubi->sizePolicy().hasHeightForWidth());
        unit_Lubi->setSizePolicy(sizePolicy1);
        unit_Lubi->setMinimumSize(QSize(60, 0));
        unit_Lubi->setMaximumSize(QSize(93, 16777215));
        unit_Lubi->setAlignment(Qt::AlignCenter);

        unit_layout->addWidget(unit_Lubi, 0, 7, 1, 1);

        unit_LminU = new QLabel(UnitFrame);
        unit_LminU->setObjectName(QStringLiteral("unit_LminU"));

        unit_layout->addWidget(unit_LminU, 0, 8, 1, 1);

        unit_Lauth = new QLabel(UnitFrame);
        unit_Lauth->setObjectName(QStringLiteral("unit_Lauth"));
        sizePolicy.setHeightForWidth(unit_Lauth->sizePolicy().hasHeightForWidth());
        unit_Lauth->setSizePolicy(sizePolicy);

        unit_layout->addWidget(unit_Lauth, 0, 1, 1, 1);

        unit_Lname = new QLabel(UnitFrame);
        unit_Lname->setObjectName(QStringLiteral("unit_Lname"));
        sizePolicy.setHeightForWidth(unit_Lname->sizePolicy().hasHeightForWidth());
        unit_Lname->setSizePolicy(sizePolicy);
        unit_Lname->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        unit_layout->addWidget(unit_Lname, 0, 0, 1, 1);

        unit_Lhorn = new QLabel(UnitFrame);
        unit_Lhorn->setObjectName(QStringLiteral("unit_Lhorn"));
        sizePolicy1.setHeightForWidth(unit_Lhorn->sizePolicy().hasHeightForWidth());
        unit_Lhorn->setSizePolicy(sizePolicy1);

        unit_layout->addWidget(unit_Lhorn, 0, 6, 1, 1);

        unit_Lban = new QLabel(UnitFrame);
        unit_Lban->setObjectName(QStringLiteral("unit_Lban"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(unit_Lban->sizePolicy().hasHeightForWidth());
        unit_Lban->setSizePolicy(sizePolicy2);
        unit_Lban->setWordWrap(false);

        unit_layout->addWidget(unit_Lban, 0, 5, 1, 1);

        unit_Lmsize = new QLabel(UnitFrame);
        unit_Lmsize->setObjectName(QStringLiteral("unit_Lmsize"));
        sizePolicy1.setHeightForWidth(unit_Lmsize->sizePolicy().hasHeightForWidth());
        unit_Lmsize->setSizePolicy(sizePolicy1);

        unit_layout->addWidget(unit_Lmsize, 0, 3, 1, 1);

        unit_Lsize = new QLabel(UnitFrame);
        unit_Lsize->setObjectName(QStringLiteral("unit_Lsize"));
        sizePolicy.setHeightForWidth(unit_Lsize->sizePolicy().hasHeightForWidth());
        unit_Lsize->setSizePolicy(sizePolicy);

        unit_layout->addWidget(unit_Lsize, 0, 2, 1, 1);

        unit_Lchamp = new QLabel(UnitFrame);
        unit_Lchamp->setObjectName(QStringLiteral("unit_Lchamp"));
        sizePolicy1.setHeightForWidth(unit_Lchamp->sizePolicy().hasHeightForWidth());
        unit_Lchamp->setSizePolicy(sizePolicy1);

        unit_layout->addWidget(unit_Lchamp, 0, 4, 1, 1);

        unit_select = new QComboBox(UnitFrame);
        unit_select->setObjectName(QStringLiteral("unit_select"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(unit_select->sizePolicy().hasHeightForWidth());
        unit_select->setSizePolicy(sizePolicy3);
        unit_select->setMinimumSize(QSize(200, 20));
        unit_select->setMaximumSize(QSize(200, 20));

        unit_layout->addWidget(unit_select, 1, 0, 1, 1);

        unit_auth = new QLineEdit(UnitFrame);
        unit_auth->setObjectName(QStringLiteral("unit_auth"));
        sizePolicy.setHeightForWidth(unit_auth->sizePolicy().hasHeightForWidth());
        unit_auth->setSizePolicy(sizePolicy);
        unit_auth->setMinimumSize(QSize(0, 0));
        unit_auth->setMaximumSize(QSize(50, 16777215));
        unit_auth->setAlignment(Qt::AlignCenter);
        unit_auth->setReadOnly(true);

        unit_layout->addWidget(unit_auth, 1, 1, 1, 1);

        unit_size = new QSpinBox(UnitFrame);
        unit_size->setObjectName(QStringLiteral("unit_size"));
        sizePolicy.setHeightForWidth(unit_size->sizePolicy().hasHeightForWidth());
        unit_size->setSizePolicy(sizePolicy);
        unit_size->setMinimumSize(QSize(37, 20));
        unit_size->setReadOnly(false);
        unit_size->setButtonSymbols(QAbstractSpinBox::UpDownArrows);

        unit_layout->addWidget(unit_size, 1, 2, 1, 1);

        unit_msize = new QLineEdit(UnitFrame);
        unit_msize->setObjectName(QStringLiteral("unit_msize"));
        sizePolicy.setHeightForWidth(unit_msize->sizePolicy().hasHeightForWidth());
        unit_msize->setSizePolicy(sizePolicy);
        unit_msize->setMinimumSize(QSize(0, 0));
        unit_msize->setMaximumSize(QSize(64, 16777215));
        unit_msize->setAlignment(Qt::AlignCenter);

        unit_layout->addWidget(unit_msize, 1, 3, 1, 1);

        unit_banner = new QCheckBox(UnitFrame);
        unit_banner->setObjectName(QStringLiteral("unit_banner"));
        unit_banner->setEnabled(false);
        sizePolicy.setHeightForWidth(unit_banner->sizePolicy().hasHeightForWidth());
        unit_banner->setSizePolicy(sizePolicy);
        unit_banner->setLayoutDirection(Qt::LeftToRight);
        unit_banner->setTristate(false);

        unit_layout->addWidget(unit_banner, 1, 5, 1, 1);

        unit_champ = new QCheckBox(UnitFrame);
        unit_champ->setObjectName(QStringLiteral("unit_champ"));
        unit_champ->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(unit_champ->sizePolicy().hasHeightForWidth());
        unit_champ->setSizePolicy(sizePolicy4);
        unit_champ->setMinimumSize(QSize(0, 0));
        unit_champ->setLayoutDirection(Qt::LeftToRight);
        unit_champ->setTristate(false);

        unit_layout->addWidget(unit_champ, 1, 4, 1, 1);

        unit_horn = new QCheckBox(UnitFrame);
        unit_horn->setObjectName(QStringLiteral("unit_horn"));
        unit_horn->setEnabled(false);
        sizePolicy.setHeightForWidth(unit_horn->sizePolicy().hasHeightForWidth());
        unit_horn->setSizePolicy(sizePolicy);
        unit_horn->setLayoutDirection(Qt::LeftToRight);
        unit_horn->setTristate(false);

        unit_layout->addWidget(unit_horn, 1, 6, 1, 1);

        unit_ubi = new QLineEdit(UnitFrame);
        unit_ubi->setObjectName(QStringLiteral("unit_ubi"));
        sizePolicy.setHeightForWidth(unit_ubi->sizePolicy().hasHeightForWidth());
        unit_ubi->setSizePolicy(sizePolicy);
        unit_ubi->setMaximumSize(QSize(93, 16777215));
        unit_ubi->setAlignment(Qt::AlignCenter);

        unit_layout->addWidget(unit_ubi, 1, 7, 1, 1);

        unit_minU = new QCheckBox(UnitFrame);
        unit_minU->setObjectName(QStringLiteral("unit_minU"));
        sizePolicy.setHeightForWidth(unit_minU->sizePolicy().hasHeightForWidth());
        unit_minU->setSizePolicy(sizePolicy);
        unit_minU->setLayoutDirection(Qt::LeftToRight);
        unit_minU->setTristate(false);

        unit_layout->addWidget(unit_minU, 1, 8, 1, 1);

        unit_cost = new QLineEdit(UnitFrame);
        unit_cost->setObjectName(QStringLiteral("unit_cost"));
        sizePolicy.setHeightForWidth(unit_cost->sizePolicy().hasHeightForWidth());
        unit_cost->setSizePolicy(sizePolicy);
        unit_cost->setMaximumSize(QSize(50, 16777215));
        unit_cost->setAlignment(Qt::AlignCenter);

        unit_layout->addWidget(unit_cost, 1, 10, 1, 1);

        unit_Lcost = new QLabel(UnitFrame);
        unit_Lcost->setObjectName(QStringLiteral("unit_Lcost"));
        sizePolicy1.setHeightForWidth(unit_Lcost->sizePolicy().hasHeightForWidth());
        unit_Lcost->setSizePolicy(sizePolicy1);

        unit_layout->addWidget(unit_Lcost, 0, 10, 1, 1);


        retranslateUi(UnitFrame);

        QMetaObject::connectSlotsByName(UnitFrame);
    } // setupUi

    void retranslateUi(QFrame *UnitFrame)
    {
        UnitFrame->setWindowTitle(QApplication::translate("UnitFrame", "Frame", 0));
        unit_Lubi->setText(QApplication::translate("UnitFrame", "Ubiquity", 0));
        unit_LminU->setText(QApplication::translate("UnitFrame", "Min. Ubiquity?", 0));
        unit_Lauth->setText(QApplication::translate("UnitFrame", "Authority", 0));
        unit_Lname->setText(QApplication::translate("UnitFrame", "General", 0));
        unit_Lhorn->setText(QApplication::translate("UnitFrame", "Horn Blower", 0));
        unit_Lban->setText(QApplication::translate("UnitFrame", "Banner Bearer", 0));
        unit_Lmsize->setText(QApplication::translate("UnitFrame", "Max Unit Size", 0));
        unit_Lsize->setText(QApplication::translate("UnitFrame", "Unit Size", 0));
        unit_Lchamp->setText(QApplication::translate("UnitFrame", "Champion", 0));
        unit_banner->setText(QString());
        unit_champ->setText(QString());
        unit_horn->setText(QString());
        unit_ubi->setText(QString());
        unit_minU->setText(QString());
        unit_Lcost->setText(QApplication::translate("UnitFrame", "Unit Gold Cost", 0));
    } // retranslateUi

};

namespace Ui {
    class UnitFrame: public Ui_UnitFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITFRAME_H
