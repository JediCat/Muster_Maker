/********************************************************************************
** Form generated from reading UI file 'commwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMWIDGET_H
#define UI_COMMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommWidget
{
public:
    QScrollArea *comm_scroll;
    QWidget *comm_scrollArea;
    QVBoxLayout *comm_layout;
    QPushButton *comm_addUnit;
    QPushButton *comm_remUnit;

    void setupUi(QWidget *CommWidget)
    {
        if (CommWidget->objectName().isEmpty())
            CommWidget->setObjectName(QStringLiteral("CommWidget"));
        CommWidget->resize(1068, 374);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CommWidget->sizePolicy().hasHeightForWidth());
        CommWidget->setSizePolicy(sizePolicy);
        CommWidget->setMinimumSize(QSize(1068, 374));
        CommWidget->setMaximumSize(QSize(1068, 374));
        comm_scroll = new QScrollArea(CommWidget);
        comm_scroll->setObjectName(QStringLiteral("comm_scroll"));
        comm_scroll->setGeometry(QRect(0, 40, 1061, 331));
        comm_scroll->setMinimumSize(QSize(1061, 331));
        comm_scroll->setMaximumSize(QSize(1061, 331));
        comm_scroll->setWidgetResizable(true);
        comm_scroll->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        comm_scrollArea = new QWidget();
        comm_scrollArea->setObjectName(QStringLiteral("comm_scrollArea"));
        comm_scrollArea->setGeometry(QRect(0, 0, 1059, 329));
        comm_layout = new QVBoxLayout(comm_scrollArea);
        comm_layout->setObjectName(QStringLiteral("comm_layout"));
        comm_layout->setContentsMargins(0, 0, 0, 0);
        comm_scroll->setWidget(comm_scrollArea);
        comm_addUnit = new QPushButton(CommWidget);
        comm_addUnit->setObjectName(QStringLiteral("comm_addUnit"));
        comm_addUnit->setGeometry(QRect(870, 10, 91, 23));
        comm_remUnit = new QPushButton(CommWidget);
        comm_remUnit->setObjectName(QStringLiteral("comm_remUnit"));
        comm_remUnit->setGeometry(QRect(970, 10, 91, 23));

        retranslateUi(CommWidget);

        QMetaObject::connectSlotsByName(CommWidget);
    } // setupUi

    void retranslateUi(QWidget *CommWidget)
    {
        CommWidget->setWindowTitle(QApplication::translate("CommWidget", "Form", 0));
        comm_addUnit->setText(QApplication::translate("CommWidget", "Add Unit", 0));
        comm_remUnit->setText(QApplication::translate("CommWidget", "Remove Unit", 0));
    } // retranslateUi

};

namespace Ui {
    class CommWidget: public Ui_CommWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMWIDGET_H
