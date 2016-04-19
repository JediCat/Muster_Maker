/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionTest;
    QAction *actionTest2;
    QAction *actionAdd_Tab;
    QAction *actionRemove_Tab;
    QAction *actionAdd_Command;
    QAction *actionRemove_Command;
    QAction *actionNew_Host;
    QAction *actionSave_Host;
    QAction *actionLoad_Host;
    QAction *actionQuit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *hostDetails_widget;
    QGridLayout *hostDetails_layout;
    QLineEdit *read_goldMin;
    QLabel *la_mainstay;
    QLineEdit *read_mnstyMin;
    QLabel *la_battleSize;
    QLabel *la_common;
    QLineEdit *read_cmmnCurr;
    QLineEdit *read_mnstyCurr;
    QLineEdit *read_cmmnMin;
    QLineEdit *read_uniqueCurr;
    QLabel *la_uncommon;
    QLineEdit *read_uncmmnCurr;
    QLineEdit *read_mythicCurr;
    QLabel *la_rare;
    QLineEdit *read_uncmmnMin;
    QLabel *la_mythic;
    QLineEdit *read_rareCurr;
    QLineEdit *read_rareMin;
    QLabel *la_unique;
    QLineEdit *read_mythicMin;
    QLineEdit *read_uniqueMin;
    QComboBox *batSizeSlct;
    QLabel *la_gold;
    QLineEdit *read_goldCurr;
    QLineEdit *read_goldMax;
    QLineEdit *read_rareMax;
    QLineEdit *read_rareTotal;
    QLineEdit *read_uncmmnTotal;
    QLineEdit *read_cmmnTotal;
    QLineEdit *read_mythicTotal;
    QLineEdit *read_cmmnMax;
    QLineEdit *read_mnstyMax;
    QLineEdit *read_mnstyTotal;
    QLineEdit *read_uncmmnMax;
    QLineEdit *read_mythicMax;
    QLineEdit *read_uniqueMax;
    QLineEdit *read_uniqueTotal;
    QTabWidget *tabWidget;
    QWidget *hostOptions;
    QWidget *hostInvoc;
    QScrollArea *invoc_scroll;
    QWidget *invoc_scrollArea;
    QVBoxLayout *invocUnitList;
    QWidget *invocListWidget;
    QFormLayout *invocListLayout;
    QLabel *label_2;
    QFrame *line;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuCommands;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1092, 525);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1092, 525));
        MainWindow->setMaximumSize(QSize(1092, 1600000));
        actionTest = new QAction(MainWindow);
        actionTest->setObjectName(QStringLiteral("actionTest"));
        actionTest2 = new QAction(MainWindow);
        actionTest2->setObjectName(QStringLiteral("actionTest2"));
        actionAdd_Tab = new QAction(MainWindow);
        actionAdd_Tab->setObjectName(QStringLiteral("actionAdd_Tab"));
        actionRemove_Tab = new QAction(MainWindow);
        actionRemove_Tab->setObjectName(QStringLiteral("actionRemove_Tab"));
        actionAdd_Command = new QAction(MainWindow);
        actionAdd_Command->setObjectName(QStringLiteral("actionAdd_Command"));
        actionRemove_Command = new QAction(MainWindow);
        actionRemove_Command->setObjectName(QStringLiteral("actionRemove_Command"));
        actionNew_Host = new QAction(MainWindow);
        actionNew_Host->setObjectName(QStringLiteral("actionNew_Host"));
        actionSave_Host = new QAction(MainWindow);
        actionSave_Host->setObjectName(QStringLiteral("actionSave_Host"));
        actionLoad_Host = new QAction(MainWindow);
        actionLoad_Host->setObjectName(QStringLiteral("actionLoad_Host"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        hostDetails_widget = new QWidget(centralWidget);
        hostDetails_widget->setObjectName(QStringLiteral("hostDetails_widget"));
        hostDetails_layout = new QGridLayout(hostDetails_widget);
        hostDetails_layout->setSpacing(6);
        hostDetails_layout->setContentsMargins(11, 11, 11, 11);
        hostDetails_layout->setObjectName(QStringLiteral("hostDetails_layout"));
        read_goldMin = new QLineEdit(hostDetails_widget);
        read_goldMin->setObjectName(QStringLiteral("read_goldMin"));
        sizePolicy.setHeightForWidth(read_goldMin->sizePolicy().hasHeightForWidth());
        read_goldMin->setSizePolicy(sizePolicy);
        read_goldMin->setMaximumSize(QSize(50, 16777215));
        read_goldMin->setAlignment(Qt::AlignCenter);
        read_goldMin->setReadOnly(true);

        hostDetails_layout->addWidget(read_goldMin, 1, 3, 1, 1);

        la_mainstay = new QLabel(hostDetails_widget);
        la_mainstay->setObjectName(QStringLiteral("la_mainstay"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(la_mainstay->sizePolicy().hasHeightForWidth());
        la_mainstay->setSizePolicy(sizePolicy1);
        la_mainstay->setMaximumSize(QSize(50, 16777215));

        hostDetails_layout->addWidget(la_mainstay, 0, 5, 2, 1);

        read_mnstyMin = new QLineEdit(hostDetails_widget);
        read_mnstyMin->setObjectName(QStringLiteral("read_mnstyMin"));
        sizePolicy.setHeightForWidth(read_mnstyMin->sizePolicy().hasHeightForWidth());
        read_mnstyMin->setSizePolicy(sizePolicy);
        read_mnstyMin->setMaximumSize(QSize(25, 16777215));
        read_mnstyMin->setAlignment(Qt::AlignCenter);
        read_mnstyMin->setReadOnly(true);

        hostDetails_layout->addWidget(read_mnstyMin, 1, 6, 1, 1);

        la_battleSize = new QLabel(hostDetails_widget);
        la_battleSize->setObjectName(QStringLiteral("la_battleSize"));
        QFont font;
        font.setPointSize(10);
        la_battleSize->setFont(font);
        la_battleSize->setAlignment(Qt::AlignCenter);

        hostDetails_layout->addWidget(la_battleSize, 0, 0, 1, 1);

        la_common = new QLabel(hostDetails_widget);
        la_common->setObjectName(QStringLiteral("la_common"));
        sizePolicy1.setHeightForWidth(la_common->sizePolicy().hasHeightForWidth());
        la_common->setSizePolicy(sizePolicy1);

        hostDetails_layout->addWidget(la_common, 0, 9, 2, 1);

        read_cmmnCurr = new QLineEdit(hostDetails_widget);
        read_cmmnCurr->setObjectName(QStringLiteral("read_cmmnCurr"));
        sizePolicy.setHeightForWidth(read_cmmnCurr->sizePolicy().hasHeightForWidth());
        read_cmmnCurr->setSizePolicy(sizePolicy);
        read_cmmnCurr->setMaximumSize(QSize(25, 16777215));
        read_cmmnCurr->setAlignment(Qt::AlignCenter);
        read_cmmnCurr->setReadOnly(true);

        hostDetails_layout->addWidget(read_cmmnCurr, 0, 10, 1, 1);

        read_mnstyCurr = new QLineEdit(hostDetails_widget);
        read_mnstyCurr->setObjectName(QStringLiteral("read_mnstyCurr"));
        sizePolicy.setHeightForWidth(read_mnstyCurr->sizePolicy().hasHeightForWidth());
        read_mnstyCurr->setSizePolicy(sizePolicy);
        read_mnstyCurr->setMaximumSize(QSize(25, 16777215));
        read_mnstyCurr->setAlignment(Qt::AlignCenter);
        read_mnstyCurr->setReadOnly(true);

        hostDetails_layout->addWidget(read_mnstyCurr, 0, 6, 1, 1);

        read_cmmnMin = new QLineEdit(hostDetails_widget);
        read_cmmnMin->setObjectName(QStringLiteral("read_cmmnMin"));
        sizePolicy.setHeightForWidth(read_cmmnMin->sizePolicy().hasHeightForWidth());
        read_cmmnMin->setSizePolicy(sizePolicy);
        read_cmmnMin->setMaximumSize(QSize(25, 16777215));
        read_cmmnMin->setAlignment(Qt::AlignCenter);
        read_cmmnMin->setReadOnly(true);

        hostDetails_layout->addWidget(read_cmmnMin, 1, 10, 1, 1);

        read_uniqueCurr = new QLineEdit(hostDetails_widget);
        read_uniqueCurr->setObjectName(QStringLiteral("read_uniqueCurr"));
        sizePolicy.setHeightForWidth(read_uniqueCurr->sizePolicy().hasHeightForWidth());
        read_uniqueCurr->setSizePolicy(sizePolicy);
        read_uniqueCurr->setMaximumSize(QSize(25, 16777215));
        read_uniqueCurr->setAlignment(Qt::AlignCenter);
        read_uniqueCurr->setReadOnly(true);

        hostDetails_layout->addWidget(read_uniqueCurr, 0, 26, 1, 1);

        la_uncommon = new QLabel(hostDetails_widget);
        la_uncommon->setObjectName(QStringLiteral("la_uncommon"));
        sizePolicy1.setHeightForWidth(la_uncommon->sizePolicy().hasHeightForWidth());
        la_uncommon->setSizePolicy(sizePolicy1);

        hostDetails_layout->addWidget(la_uncommon, 0, 13, 2, 1);

        read_uncmmnCurr = new QLineEdit(hostDetails_widget);
        read_uncmmnCurr->setObjectName(QStringLiteral("read_uncmmnCurr"));
        sizePolicy.setHeightForWidth(read_uncmmnCurr->sizePolicy().hasHeightForWidth());
        read_uncmmnCurr->setSizePolicy(sizePolicy);
        read_uncmmnCurr->setMaximumSize(QSize(25, 16777215));
        read_uncmmnCurr->setAlignment(Qt::AlignCenter);
        read_uncmmnCurr->setReadOnly(true);

        hostDetails_layout->addWidget(read_uncmmnCurr, 0, 14, 1, 1);

        read_mythicCurr = new QLineEdit(hostDetails_widget);
        read_mythicCurr->setObjectName(QStringLiteral("read_mythicCurr"));
        sizePolicy.setHeightForWidth(read_mythicCurr->sizePolicy().hasHeightForWidth());
        read_mythicCurr->setSizePolicy(sizePolicy);
        read_mythicCurr->setMaximumSize(QSize(25, 16777215));
        read_mythicCurr->setAlignment(Qt::AlignCenter);
        read_mythicCurr->setReadOnly(true);

        hostDetails_layout->addWidget(read_mythicCurr, 0, 22, 1, 1);

        la_rare = new QLabel(hostDetails_widget);
        la_rare->setObjectName(QStringLiteral("la_rare"));
        sizePolicy1.setHeightForWidth(la_rare->sizePolicy().hasHeightForWidth());
        la_rare->setSizePolicy(sizePolicy1);

        hostDetails_layout->addWidget(la_rare, 0, 17, 2, 1);

        read_uncmmnMin = new QLineEdit(hostDetails_widget);
        read_uncmmnMin->setObjectName(QStringLiteral("read_uncmmnMin"));
        sizePolicy.setHeightForWidth(read_uncmmnMin->sizePolicy().hasHeightForWidth());
        read_uncmmnMin->setSizePolicy(sizePolicy);
        read_uncmmnMin->setMaximumSize(QSize(25, 16777215));
        read_uncmmnMin->setAlignment(Qt::AlignCenter);
        read_uncmmnMin->setReadOnly(true);

        hostDetails_layout->addWidget(read_uncmmnMin, 1, 14, 1, 1);

        la_mythic = new QLabel(hostDetails_widget);
        la_mythic->setObjectName(QStringLiteral("la_mythic"));
        sizePolicy1.setHeightForWidth(la_mythic->sizePolicy().hasHeightForWidth());
        la_mythic->setSizePolicy(sizePolicy1);

        hostDetails_layout->addWidget(la_mythic, 0, 21, 2, 1);

        read_rareCurr = new QLineEdit(hostDetails_widget);
        read_rareCurr->setObjectName(QStringLiteral("read_rareCurr"));
        sizePolicy.setHeightForWidth(read_rareCurr->sizePolicy().hasHeightForWidth());
        read_rareCurr->setSizePolicy(sizePolicy);
        read_rareCurr->setMaximumSize(QSize(25, 16777215));
        read_rareCurr->setAlignment(Qt::AlignCenter);
        read_rareCurr->setReadOnly(true);

        hostDetails_layout->addWidget(read_rareCurr, 0, 18, 1, 1);

        read_rareMin = new QLineEdit(hostDetails_widget);
        read_rareMin->setObjectName(QStringLiteral("read_rareMin"));
        sizePolicy.setHeightForWidth(read_rareMin->sizePolicy().hasHeightForWidth());
        read_rareMin->setSizePolicy(sizePolicy);
        read_rareMin->setMaximumSize(QSize(25, 16777215));
        read_rareMin->setAlignment(Qt::AlignCenter);
        read_rareMin->setReadOnly(true);

        hostDetails_layout->addWidget(read_rareMin, 1, 18, 1, 1);

        la_unique = new QLabel(hostDetails_widget);
        la_unique->setObjectName(QStringLiteral("la_unique"));
        sizePolicy1.setHeightForWidth(la_unique->sizePolicy().hasHeightForWidth());
        la_unique->setSizePolicy(sizePolicy1);

        hostDetails_layout->addWidget(la_unique, 0, 25, 2, 1);

        read_mythicMin = new QLineEdit(hostDetails_widget);
        read_mythicMin->setObjectName(QStringLiteral("read_mythicMin"));
        sizePolicy.setHeightForWidth(read_mythicMin->sizePolicy().hasHeightForWidth());
        read_mythicMin->setSizePolicy(sizePolicy);
        read_mythicMin->setMaximumSize(QSize(25, 16777215));
        read_mythicMin->setAlignment(Qt::AlignCenter);
        read_mythicMin->setReadOnly(true);

        hostDetails_layout->addWidget(read_mythicMin, 1, 22, 1, 1);

        read_uniqueMin = new QLineEdit(hostDetails_widget);
        read_uniqueMin->setObjectName(QStringLiteral("read_uniqueMin"));
        sizePolicy.setHeightForWidth(read_uniqueMin->sizePolicy().hasHeightForWidth());
        read_uniqueMin->setSizePolicy(sizePolicy);
        read_uniqueMin->setMaximumSize(QSize(25, 16777215));
        read_uniqueMin->setAlignment(Qt::AlignCenter);
        read_uniqueMin->setReadOnly(true);

        hostDetails_layout->addWidget(read_uniqueMin, 1, 26, 1, 1);

        batSizeSlct = new QComboBox(hostDetails_widget);
        batSizeSlct->setObjectName(QStringLiteral("batSizeSlct"));
        sizePolicy.setHeightForWidth(batSizeSlct->sizePolicy().hasHeightForWidth());
        batSizeSlct->setSizePolicy(sizePolicy);
        batSizeSlct->setMinimumSize(QSize(150, 0));

        hostDetails_layout->addWidget(batSizeSlct, 1, 0, 1, 1);

        la_gold = new QLabel(hostDetails_widget);
        la_gold->setObjectName(QStringLiteral("la_gold"));
        sizePolicy1.setHeightForWidth(la_gold->sizePolicy().hasHeightForWidth());
        la_gold->setSizePolicy(sizePolicy1);
        la_gold->setFont(font);
        la_gold->setAlignment(Qt::AlignCenter);

        hostDetails_layout->addWidget(la_gold, 0, 1, 2, 1);

        read_goldCurr = new QLineEdit(hostDetails_widget);
        read_goldCurr->setObjectName(QStringLiteral("read_goldCurr"));
        sizePolicy.setHeightForWidth(read_goldCurr->sizePolicy().hasHeightForWidth());
        read_goldCurr->setSizePolicy(sizePolicy);
        read_goldCurr->setMaximumSize(QSize(50, 16777215));
        read_goldCurr->setAlignment(Qt::AlignCenter);
        read_goldCurr->setReadOnly(true);

        hostDetails_layout->addWidget(read_goldCurr, 0, 3, 1, 1);

        read_goldMax = new QLineEdit(hostDetails_widget);
        read_goldMax->setObjectName(QStringLiteral("read_goldMax"));
        sizePolicy.setHeightForWidth(read_goldMax->sizePolicy().hasHeightForWidth());
        read_goldMax->setSizePolicy(sizePolicy);
        read_goldMax->setMaximumSize(QSize(50, 16777215));
        read_goldMax->setAlignment(Qt::AlignCenter);
        read_goldMax->setReadOnly(true);

        hostDetails_layout->addWidget(read_goldMax, 0, 4, 2, 1);

        read_rareMax = new QLineEdit(hostDetails_widget);
        read_rareMax->setObjectName(QStringLiteral("read_rareMax"));
        sizePolicy.setHeightForWidth(read_rareMax->sizePolicy().hasHeightForWidth());
        read_rareMax->setSizePolicy(sizePolicy);
        read_rareMax->setMaximumSize(QSize(25, 16777215));
        read_rareMax->setAlignment(Qt::AlignCenter);
        read_rareMax->setReadOnly(true);

        hostDetails_layout->addWidget(read_rareMax, 1, 19, 1, 1);

        read_rareTotal = new QLineEdit(hostDetails_widget);
        read_rareTotal->setObjectName(QStringLiteral("read_rareTotal"));
        sizePolicy.setHeightForWidth(read_rareTotal->sizePolicy().hasHeightForWidth());
        read_rareTotal->setSizePolicy(sizePolicy);
        read_rareTotal->setMaximumSize(QSize(25, 16777215));
        read_rareTotal->setAlignment(Qt::AlignCenter);
        read_rareTotal->setReadOnly(true);

        hostDetails_layout->addWidget(read_rareTotal, 0, 19, 1, 1);

        read_uncmmnTotal = new QLineEdit(hostDetails_widget);
        read_uncmmnTotal->setObjectName(QStringLiteral("read_uncmmnTotal"));
        sizePolicy.setHeightForWidth(read_uncmmnTotal->sizePolicy().hasHeightForWidth());
        read_uncmmnTotal->setSizePolicy(sizePolicy);
        read_uncmmnTotal->setMaximumSize(QSize(25, 16777215));
        read_uncmmnTotal->setAlignment(Qt::AlignCenter);
        read_uncmmnTotal->setReadOnly(true);

        hostDetails_layout->addWidget(read_uncmmnTotal, 0, 15, 1, 1);

        read_cmmnTotal = new QLineEdit(hostDetails_widget);
        read_cmmnTotal->setObjectName(QStringLiteral("read_cmmnTotal"));
        sizePolicy.setHeightForWidth(read_cmmnTotal->sizePolicy().hasHeightForWidth());
        read_cmmnTotal->setSizePolicy(sizePolicy);
        read_cmmnTotal->setMaximumSize(QSize(25, 16777215));
        read_cmmnTotal->setAlignment(Qt::AlignCenter);
        read_cmmnTotal->setReadOnly(true);

        hostDetails_layout->addWidget(read_cmmnTotal, 0, 11, 1, 1);

        read_mythicTotal = new QLineEdit(hostDetails_widget);
        read_mythicTotal->setObjectName(QStringLiteral("read_mythicTotal"));
        sizePolicy.setHeightForWidth(read_mythicTotal->sizePolicy().hasHeightForWidth());
        read_mythicTotal->setSizePolicy(sizePolicy);
        read_mythicTotal->setMaximumSize(QSize(25, 16777215));
        read_mythicTotal->setAlignment(Qt::AlignCenter);
        read_mythicTotal->setReadOnly(true);

        hostDetails_layout->addWidget(read_mythicTotal, 0, 23, 1, 1);

        read_cmmnMax = new QLineEdit(hostDetails_widget);
        read_cmmnMax->setObjectName(QStringLiteral("read_cmmnMax"));
        sizePolicy.setHeightForWidth(read_cmmnMax->sizePolicy().hasHeightForWidth());
        read_cmmnMax->setSizePolicy(sizePolicy);
        read_cmmnMax->setMaximumSize(QSize(25, 16777215));
        read_cmmnMax->setAlignment(Qt::AlignCenter);
        read_cmmnMax->setReadOnly(true);

        hostDetails_layout->addWidget(read_cmmnMax, 1, 11, 1, 1);

        read_mnstyMax = new QLineEdit(hostDetails_widget);
        read_mnstyMax->setObjectName(QStringLiteral("read_mnstyMax"));
        sizePolicy.setHeightForWidth(read_mnstyMax->sizePolicy().hasHeightForWidth());
        read_mnstyMax->setSizePolicy(sizePolicy);
        read_mnstyMax->setMaximumSize(QSize(25, 16777215));
        read_mnstyMax->setAlignment(Qt::AlignCenter);
        read_mnstyMax->setReadOnly(true);

        hostDetails_layout->addWidget(read_mnstyMax, 1, 7, 1, 1);

        read_mnstyTotal = new QLineEdit(hostDetails_widget);
        read_mnstyTotal->setObjectName(QStringLiteral("read_mnstyTotal"));
        sizePolicy.setHeightForWidth(read_mnstyTotal->sizePolicy().hasHeightForWidth());
        read_mnstyTotal->setSizePolicy(sizePolicy);
        read_mnstyTotal->setMaximumSize(QSize(25, 16777215));
        read_mnstyTotal->setAlignment(Qt::AlignCenter);
        read_mnstyTotal->setReadOnly(true);

        hostDetails_layout->addWidget(read_mnstyTotal, 0, 7, 1, 1);

        read_uncmmnMax = new QLineEdit(hostDetails_widget);
        read_uncmmnMax->setObjectName(QStringLiteral("read_uncmmnMax"));
        sizePolicy.setHeightForWidth(read_uncmmnMax->sizePolicy().hasHeightForWidth());
        read_uncmmnMax->setSizePolicy(sizePolicy);
        read_uncmmnMax->setMaximumSize(QSize(25, 16777215));
        read_uncmmnMax->setAlignment(Qt::AlignCenter);
        read_uncmmnMax->setReadOnly(true);

        hostDetails_layout->addWidget(read_uncmmnMax, 1, 15, 1, 1);

        read_mythicMax = new QLineEdit(hostDetails_widget);
        read_mythicMax->setObjectName(QStringLiteral("read_mythicMax"));
        sizePolicy.setHeightForWidth(read_mythicMax->sizePolicy().hasHeightForWidth());
        read_mythicMax->setSizePolicy(sizePolicy);
        read_mythicMax->setMaximumSize(QSize(25, 16777215));
        read_mythicMax->setAlignment(Qt::AlignCenter);
        read_mythicMax->setReadOnly(true);

        hostDetails_layout->addWidget(read_mythicMax, 1, 23, 1, 1);

        read_uniqueMax = new QLineEdit(hostDetails_widget);
        read_uniqueMax->setObjectName(QStringLiteral("read_uniqueMax"));
        sizePolicy.setHeightForWidth(read_uniqueMax->sizePolicy().hasHeightForWidth());
        read_uniqueMax->setSizePolicy(sizePolicy);
        read_uniqueMax->setMaximumSize(QSize(25, 16777215));
        read_uniqueMax->setAlignment(Qt::AlignCenter);
        read_uniqueMax->setReadOnly(true);

        hostDetails_layout->addWidget(read_uniqueMax, 1, 27, 1, 1);

        read_uniqueTotal = new QLineEdit(hostDetails_widget);
        read_uniqueTotal->setObjectName(QStringLiteral("read_uniqueTotal"));
        sizePolicy.setHeightForWidth(read_uniqueTotal->sizePolicy().hasHeightForWidth());
        read_uniqueTotal->setSizePolicy(sizePolicy);
        read_uniqueTotal->setMaximumSize(QSize(25, 16777215));
        read_uniqueTotal->setAlignment(Qt::AlignCenter);
        read_uniqueTotal->setReadOnly(true);

        hostDetails_layout->addWidget(read_uniqueTotal, 0, 27, 1, 1);

        la_battleSize->raise();
        batSizeSlct->raise();
        read_goldMin->raise();
        la_mainstay->raise();
        read_mnstyCurr->raise();
        read_mnstyMin->raise();
        la_common->raise();
        read_cmmnCurr->raise();
        read_cmmnMin->raise();
        la_uncommon->raise();
        read_uncmmnCurr->raise();
        read_uncmmnMin->raise();
        la_rare->raise();
        read_rareCurr->raise();
        read_rareMin->raise();
        la_mythic->raise();
        read_mythicCurr->raise();
        read_mythicMin->raise();
        la_unique->raise();
        read_uniqueCurr->raise();
        read_uniqueMin->raise();
        la_gold->raise();
        read_goldCurr->raise();
        read_goldMax->raise();
        read_mnstyMax->raise();
        read_mnstyTotal->raise();
        read_cmmnMax->raise();
        read_cmmnTotal->raise();
        read_uncmmnMax->raise();
        read_uncmmnTotal->raise();
        read_rareMax->raise();
        read_rareTotal->raise();
        read_mythicMax->raise();
        read_mythicTotal->raise();
        read_uniqueMax->raise();
        read_uniqueTotal->raise();

        gridLayout->addWidget(hostDetails_widget, 1, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(0, 400));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setDocumentMode(false);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);
        hostOptions = new QWidget();
        hostOptions->setObjectName(QStringLiteral("hostOptions"));
        tabWidget->addTab(hostOptions, QString());
        hostInvoc = new QWidget();
        hostInvoc->setObjectName(QStringLiteral("hostInvoc"));
        hostInvoc->setAutoFillBackground(true);
        invoc_scroll = new QScrollArea(hostInvoc);
        invoc_scroll->setObjectName(QStringLiteral("invoc_scroll"));
        invoc_scroll->setGeometry(QRect(365, 0, 330, 374));
        invoc_scroll->setMinimumSize(QSize(330, 374));
        invoc_scroll->setMaximumSize(QSize(16777215, 16777215));
        invoc_scroll->setWidgetResizable(true);
        invoc_scroll->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        invoc_scrollArea = new QWidget();
        invoc_scrollArea->setObjectName(QStringLiteral("invoc_scrollArea"));
        invoc_scrollArea->setGeometry(QRect(0, 0, 328, 372));
        invocUnitList = new QVBoxLayout(invoc_scrollArea);
        invocUnitList->setSpacing(6);
        invocUnitList->setContentsMargins(11, 11, 11, 11);
        invocUnitList->setObjectName(QStringLiteral("invocUnitList"));
        invocUnitList->setContentsMargins(5, 5, 5, -1);
        invoc_scroll->setWidget(invoc_scrollArea);
        invocListWidget = new QWidget(hostInvoc);
        invocListWidget->setObjectName(QStringLiteral("invocListWidget"));
        invocListWidget->setGeometry(QRect(700, 0, 151, 371));
        invocListWidget->setMaximumSize(QSize(151, 371));
        invocListLayout = new QFormLayout(invocListWidget);
        invocListLayout->setSpacing(6);
        invocListLayout->setContentsMargins(11, 11, 11, 11);
        invocListLayout->setObjectName(QStringLiteral("invocListLayout"));
        label_2 = new QLabel(invocListWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        invocListLayout->setWidget(0, QFormLayout::SpanningRole, label_2);

        line = new QFrame(invocListWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setMinimumSize(QSize(30, 2));
        line->setFrameShadow(QFrame::Plain);
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);

        invocListLayout->setWidget(1, QFormLayout::SpanningRole, line);

        tabWidget->addTab(hostInvoc, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1092, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuCommands = new QMenu(menuBar);
        menuCommands->setObjectName(QStringLiteral("menuCommands"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuCommands->menuAction());
        menuFile->addAction(actionNew_Host);
        menuFile->addAction(actionSave_Host);
        menuFile->addAction(actionLoad_Host);
        menuFile->addAction(actionQuit);
        menuCommands->addSeparator();
        menuCommands->addAction(actionAdd_Command);
        menuCommands->addAction(actionRemove_Command);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Muster Maker", 0));
        actionTest->setText(QApplication::translate("MainWindow", "Add Button", 0));
        actionTest2->setText(QApplication::translate("MainWindow", "Remove Button", 0));
        actionAdd_Tab->setText(QApplication::translate("MainWindow", "Add Tab", 0));
        actionRemove_Tab->setText(QApplication::translate("MainWindow", "Remove Tab", 0));
        actionAdd_Command->setText(QApplication::translate("MainWindow", "Add Command", 0));
        actionRemove_Command->setText(QApplication::translate("MainWindow", "Remove Command", 0));
        actionNew_Host->setText(QApplication::translate("MainWindow", "New Host", 0));
        actionSave_Host->setText(QApplication::translate("MainWindow", "Save Host", 0));
        actionLoad_Host->setText(QApplication::translate("MainWindow", "Load Host", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        la_mainstay->setText(QApplication::translate("MainWindow", "Mainstay", 0));
        la_battleSize->setText(QApplication::translate("MainWindow", "Battle Size", 0));
        la_common->setText(QApplication::translate("MainWindow", "Common", 0));
        read_cmmnCurr->setText(QApplication::translate("MainWindow", "0", 0));
        read_mnstyCurr->setText(QApplication::translate("MainWindow", "0", 0));
        read_uniqueCurr->setText(QApplication::translate("MainWindow", "0", 0));
        la_uncommon->setText(QApplication::translate("MainWindow", "Unccomon", 0));
        read_uncmmnCurr->setText(QApplication::translate("MainWindow", "0", 0));
        read_mythicCurr->setText(QApplication::translate("MainWindow", "0", 0));
        la_rare->setText(QApplication::translate("MainWindow", "Rare", 0));
        la_mythic->setText(QApplication::translate("MainWindow", "Mythic", 0));
        read_rareCurr->setText(QApplication::translate("MainWindow", "0", 0));
        la_unique->setText(QApplication::translate("MainWindow", "Unique", 0));
        la_gold->setText(QApplication::translate("MainWindow", "Gold", 0));
        read_goldCurr->setText(QApplication::translate("MainWindow", "0", 0));
        read_rareTotal->setText(QApplication::translate("MainWindow", "0", 0));
        read_uncmmnTotal->setText(QApplication::translate("MainWindow", "0", 0));
        read_cmmnTotal->setText(QApplication::translate("MainWindow", "0", 0));
        read_mythicTotal->setText(QApplication::translate("MainWindow", "0", 0));
        read_mnstyTotal->setText(QApplication::translate("MainWindow", "0", 0));
        read_uniqueTotal->setText(QApplication::translate("MainWindow", "0", 0));
        tabWidget->setTabText(tabWidget->indexOf(hostOptions), QApplication::translate("MainWindow", "Unit Options", 0));
        label_2->setText(QApplication::translate("MainWindow", "Invocations", 0));
        tabWidget->setTabText(tabWidget->indexOf(hostInvoc), QApplication::translate("MainWindow", "Invocations", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuCommands->setTitle(QApplication::translate("MainWindow", "Commands", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
