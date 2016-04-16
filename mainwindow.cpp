#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unitframe.h"
#include "commwidget.h"
#include <QPushButton>
#include <QObject>
#include <QWidget>
#include <QVector>
#include <QCheckBox>
#include <QSpinBox>
#include "unit.h"
#include "dbmanager.h"
#include "battlesize.h"
#include <QComboBox>



QVector<int> unitsPerTab;
DbManager db = DbManager("D:\\SQLite\\erainn.db");
std::vector<Unit*> hostUnits;
int commCount = 49;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Qt Setup
    ui->setupUi(this);

    //Populate Unit List
    db.selectUnits(hostUnits, ERAINN);

    //Connections
    connect(ui->actionAdd_Command, SIGNAL(triggered(bool)), this, SLOT(addCommand()));
    connect(ui->actionRemove_Command, SIGNAL(triggered(bool)), this, SLOT(removeCommand()));
    connect(ui->batSizeSlct, SIGNAL(currentIndexChanged(QString)), this, SLOT(onBattleSizeChange()));


    //Initialize First Commands
    CommWidget* hostComm = new CommWidget(true);
    ui->tabWidget->insertTab(commCount-49, hostComm, "Host Command");
    CommWidget* commOne = new CommWidget(false, QString(QChar(commCount)));
    ui->tabWidget->insertTab(commCount-48, commOne, "Command " + QString(QChar(commCount)));
    commCount++;

    //Connect Initial Commands
    connect(hostComm, SIGNAL(refresh()), this, SLOT(updateHost()), Qt::QueuedConnection);
    connect(commOne, SIGNAL(refresh()), this, SLOT(updateHost()), Qt::QueuedConnection);

    //Populate Battle Sizes
    ui->batSizeSlct->addItem("");
    ui->batSizeSlct->addItem(BATTLESIZE[0].name);
    ui->batSizeSlct->addItem(BATTLESIZE[1].name);
    ui->batSizeSlct->addItem(BATTLESIZE[2].name);
    ui->batSizeSlct->addItem(BATTLESIZE[3].name);
    ui->batSizeSlct->addItem(BATTLESIZE[4].name);


    //Set view to first tab
    ui->tabWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addCommand()
{
    CommWidget* comm = new CommWidget(false, QString(QChar(commCount)));
    ui->tabWidget->insertTab(commCount-48, comm, "Command " + QString(QChar(commCount)));
    commCount++;

}

void MainWindow::removeCommand()
{
    if(commCount < 51)
    {
        return;
    }

    QWidget* widget;
    QString name = "comm_" + QString(QChar(commCount));

    widget = ui->tabWidget->findChild<QWidget*>(name);
    if(ui->tabWidget->currentIndex() == commCount-49)
    {
        ui->tabWidget->setCurrentIndex(commCount-50);
    }
    ui->tabWidget->removeTab(commCount-49);
    delete widget;
    commCount -= 1;

}

void MainWindow::onBattleSizeChange()
{
    int i = ui->batSizeSlct->currentIndex()-1;
    if(i != -1)
    {
        ui->read_goldMin->setText(QString::number(BATTLESIZE[i].goldMin));
        ui->read_goldMax->setText(QString::number(BATTLESIZE[i].goldMax));

        ui->read_mnstyMin->setText(QString::number(BATTLESIZE[i].mnstyMin));
        ui->read_mnstyMax->setText(QString::number(BATTLESIZE[i].mnstyMax));

        ui->read_cmmnMin->setText(QString::number(BATTLESIZE[i].cmmnMin));
        ui->read_cmmnMax->setText(QString::number(BATTLESIZE[i].cmmnMax));

        ui->read_uncmmnMin->setText(QString::number(BATTLESIZE[i].uncmmnMin));
        ui->read_uncmmnMax->setText(QString::number(BATTLESIZE[i].uncmmnMax));

        ui->read_rareMin->setText(QString::number(BATTLESIZE[i].rareMin));
        ui->read_rareMax->setText(QString::number(BATTLESIZE[i].rareMax));

        ui->read_mythicMin->setText(QString::number(BATTLESIZE[i].mythicMin));
        ui->read_mythicMax->setText(QString::number(BATTLESIZE[i].mythicMax));

        ui->read_uniqueMin->setText(QString::number(BATTLESIZE[i].uniqueMin));
        ui->read_uniqueMax->setText(QString::number(BATTLESIZE[i].uniqueMax));
    }
    else
    {
        ui->read_goldMin->setText("");
        ui->read_goldMax->setText("");

        ui->read_mnstyMin->setText("");
        ui->read_mnstyMax->setText("");

        ui->read_cmmnMin->setText("");
        ui->read_cmmnMax->setText("");

        ui->read_uncmmnMin->setText("");
        ui->read_uncmmnMax->setText("");

        ui->read_rareMin->setText("");
        ui->read_rareMax->setText("");

        ui->read_mythicMin->setText("");
        ui->read_mythicMax->setText("");

        ui->read_uniqueMin->setText("");
        ui->read_uniqueMax->setText("");
    }
}

void MainWindow::updateHost()
{
    int cost = 0;
    int mnsty = 0;
    int cmmn = 0;
    int uncmmn = 0;
    int rare = 0;
    int mythic = 0;
    int unique = 0;

    QList<CommWidget*> commList = this->findChildren<CommWidget*>();

    int commNum = commList.size();

    QList<UnitFrame*>* unitList = new QList<UnitFrame*>[commNum];

    for(int i = 0; i < commNum; i++)
    {
        unitList[i] = commList[i]->findChildren<UnitFrame*>();
    }

    for(int i = 0; i < commNum; i++)
    {
        int unitNum = unitList[i].size();
        for(int j = 0; j < unitNum; j++)
        {
            UnitFrame* currUnitFrame = unitList[i][j];
            QString prefix = currUnitFrame->objectName();
            QComboBox* unitName = currUnitFrame->findChild<QComboBox*>(prefix + "select");
            if(unitName->currentText() != "")
            {
                QSpinBox* sizePoint = currUnitFrame->findChild<QSpinBox*>(prefix + "size");

                Unit* currUnit = findUnit(unitName->currentText());


                int currCost = sizePoint->value() * currUnit->costPer;
                currUnitFrame->findChild<QLineEdit*>(prefix + "cost")->setText(QString::number(currCost));
                cost += currCost;

                if(currUnitFrame->findChild<QCheckBox*>(prefix + "minU")->isChecked())
                {
                    mnsty += currUnit->ubi->mnsty;
                    cmmn += currUnit->ubi->cmmn;
                    uncmmn += currUnit->ubi->uncmmn;
                    rare += currUnit->ubi->rare;
                    mythic += currUnit->ubi->mythic;
                    unique += (currUnit->ubi->unique) ? 1:0;
                }
            }

        }
    }


    QComboBox* debug1 = unitList[1][0]->findChild<QComboBox*>("comm_1_comm_select");

    if(debug1->currentText() == "General")
    {
        //unitList[1][0]->findChild<QLineEdit*>("comm_1_comm_auth")->setText(unitList[0][0]->findChild<QLineEdit*>("gen_auth")->text());
    }

    ui->read_goldCurr->setText(QString::number(cost));
    updateUbi(mnsty, cmmn, uncmmn, rare, mythic, unique);

}

Unit* MainWindow::findUnit(QString name)
{
    Unit* target;
    for(int i = 0; i < ERAINN; i ++)
    {
        if(hostUnits[i]->name == name)
        {
            target = hostUnits[i];
        }
    }

    return target;
}

void MainWindow::updateUbi(int mn, int cm, int unc, int ra, int my, int uq)
{
    ui->read_mnstyCurr->setText(QString::number(mn));
    ui->read_cmmnCurr->setText(QString::number(cm));
    ui->read_uncmmnCurr->setText(QString::number(unc));
    ui->read_rareCurr->setText(QString::number(ra));
    ui->read_mythicCurr->setText(QString::number(my));
    ui->read_uniqueCurr->setText(QString::number(uq));
}
