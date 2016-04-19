/********************************************************************************
** Form generated from reading UI file 'unitinvocframe.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNITINVOCFRAME_H
#define UI_UNITINVOCFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_UnitInvocFrame
{
public:
    QVBoxLayout *unitInvocFrame_layout;
    QLabel *unitInvocFrame_label;
    QLineEdit *unitInvocFrame_name;
    QFrame *line;

    void setupUi(QFrame *UnitInvocFrame)
    {
        if (UnitInvocFrame->objectName().isEmpty())
            UnitInvocFrame->setObjectName(QStringLiteral("UnitInvocFrame"));
        UnitInvocFrame->resize(300, 90);
        UnitInvocFrame->setMinimumSize(QSize(300, 90));
        UnitInvocFrame->setMaximumSize(QSize(300, 90));
        UnitInvocFrame->setAutoFillBackground(true);
        UnitInvocFrame->setFrameShape(QFrame::Box);
        UnitInvocFrame->setFrameShadow(QFrame::Plain);
        unitInvocFrame_layout = new QVBoxLayout(UnitInvocFrame);
        unitInvocFrame_layout->setObjectName(QStringLiteral("unitInvocFrame_layout"));
        unitInvocFrame_label = new QLabel(UnitInvocFrame);
        unitInvocFrame_label->setObjectName(QStringLiteral("unitInvocFrame_label"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(unitInvocFrame_label->sizePolicy().hasHeightForWidth());
        unitInvocFrame_label->setSizePolicy(sizePolicy);
        unitInvocFrame_label->setAlignment(Qt::AlignCenter);

        unitInvocFrame_layout->addWidget(unitInvocFrame_label);

        unitInvocFrame_name = new QLineEdit(UnitInvocFrame);
        unitInvocFrame_name->setObjectName(QStringLiteral("unitInvocFrame_name"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(unitInvocFrame_name->sizePolicy().hasHeightForWidth());
        unitInvocFrame_name->setSizePolicy(sizePolicy1);
        unitInvocFrame_name->setMinimumSize(QSize(278, 0));
        unitInvocFrame_name->setMaximumSize(QSize(278, 16777215));
        unitInvocFrame_name->setAlignment(Qt::AlignCenter);
        unitInvocFrame_name->setReadOnly(true);

        unitInvocFrame_layout->addWidget(unitInvocFrame_name);

        line = new QFrame(UnitInvocFrame);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShadow(QFrame::Plain);
        line->setFrameShape(QFrame::HLine);

        unitInvocFrame_layout->addWidget(line);


        retranslateUi(UnitInvocFrame);

        QMetaObject::connectSlotsByName(UnitInvocFrame);
    } // setupUi

    void retranslateUi(QFrame *UnitInvocFrame)
    {
        UnitInvocFrame->setWindowTitle(QApplication::translate("UnitInvocFrame", "Frame", 0));
        unitInvocFrame_label->setText(QApplication::translate("UnitInvocFrame", "Sorcerer", 0));
    } // retranslateUi

};

namespace Ui {
    class UnitInvocFrame: public Ui_UnitInvocFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNITINVOCFRAME_H
