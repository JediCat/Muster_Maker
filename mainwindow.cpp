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
#include <QLineEdit>
#include "ubiquity.h"



QVector<int> unitsPerTab;

DbManager db;
std::vector<Unit*> hostUnits;
int commCount = 49;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QString pwd(QCoreApplication::applicationDirPath());
    pwd.replace("/","\\");
    db = DbManager(pwd + ERAINN);

    //Qt Setup
    ui->setupUi(this);

    //Populate Unit List
    db.selectUnits(hostUnits, ERAINN_COUNT);

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
    Ubiquity* minUbi = new Ubiquity();
    Ubiquity* totalUbi = new Ubiquity();

    QList<CommWidget*> commList = this->findChildren<CommWidget*>();

    int commNum = commList.size();

    QList<UnitFrame*>* unitList = new QList<UnitFrame*>[commNum];

    for(int i = 0; i < commNum; i++)
    {
        unitList[i] = commList[i]->findChildren<UnitFrame*>();
    }

    //Variables for dynamic updating of authority if the First Command's commander is the General
    UnitFrame* general;
    UnitFrame* firstComm;
    QString firstCommName;
    int auth;
    int authToSub = 0;

    //Host Update Main Loop
    for(int i = 0; i < commNum; i++)
    {
        //Number of Units to Loop through
        int unitNum = unitList[i].size();

        //Unit Loop
        for(int j = 0; j < unitNum; j++)
        {

            UnitFrame* currUnitFrame = unitList[i][j]; //Current Unit
            QString prefix = currUnitFrame->objectName(); //Prefix of current unit
            QComboBox* unitName = currUnitFrame->findChild<QComboBox*>(prefix + "select"); //Name of the current unit

            /*
             * Checks if the current unit is the General; used for First Command = General
             * If general, save pointer, set auth to General's authority
             * If first command's commander, save the current unit pointer, and the name of the commander
             * If not General, check if we're in the first command, and not the commander
             * If true, subtract the current units authority from the commander/general's authority
            */
            if(prefix == "gen_")
            {
                general = currUnitFrame;
                auth = general->findChild<QLineEdit*>("gen_auth")->text().toInt();
            }
            else if(prefix == "comm_1_comm_")
            {
                firstComm = currUnitFrame;
                firstCommName = unitName->currentText();
            }
            else
            {
                if(commList[i]->objectName() == "comm_1" && j > 0)
                {
                    QLineEdit* debug = currUnitFrame->findChild<QLineEdit*>(prefix + "auth");
                    authToSub += debug->text().toInt();
                }
            }

            //For dynamic ubiquity
            if(j > 0 && unitName->currentText() != "")
            {
                Unit* unitType = findUnit(unitName->currentText());
                currUnitFrame->findChild<QLineEdit*>(prefix + "ubi")->setText(currUnitFrame->constructUbi(unitType->ubi));
            }

            //If a unit has been selected, update the host
            if(unitName->currentText() != "")
            {
                //Pointer to the size of the unit
                QSpinBox* sizePoint = currUnitFrame->findChild<QSpinBox*>(prefix + "size");
                //Pointer to the actual unit, not the just the Frame
                Unit* currUnit = findUnit(unitName->currentText());

                //Cost of the unit = cost per unit * size of unit
                int currCost = sizePoint->value() * currUnit->costPer;

                //If the current unit is to be counter toward the minimum Ubiquity
                // update the host's minimum ubiquity counts.
                if(currUnitFrame->findChild<QCheckBox*>(prefix + "minU")->isChecked())
                {
                    increaseUbi(minUbi,
                                currUnit->ubi->mnsty,
                                currUnit->ubi->cmmn,
                                currUnit->ubi->uncmmn,
                                currUnit->ubi->rare,
                                currUnit->ubi->mythic,
                                currUnit->ubi->unique);
                }
                else
                {
                    currCost += (currUnitFrame->findChild<QCheckBox*>(prefix + "champ")->isChecked()) ? currUnitFrame->commandCosts[0] : 0;
                    currCost += (currUnitFrame->findChild<QCheckBox*>(prefix + "banner")->isChecked()) ? currUnitFrame->commandCosts[1] : 0;
                    currCost += (currUnitFrame->findChild<QCheckBox*>(prefix + "horn")->isChecked()) ? currUnitFrame->commandCosts[2] : 0;
                }

                //Increase Ubiquity for host's Current Ubiquity counts
                increaseUbi(totalUbi,
                            currUnit->ubi->mnsty,
                            currUnit->ubi->cmmn,
                            currUnit->ubi->uncmmn,
                            currUnit->ubi->rare,
                            currUnit->ubi->mythic,
                            currUnit->ubi->unique);
                //Update the displayed cost for the current Unit Frame
                currUnitFrame->findChild<QLineEdit*>(prefix + "cost")->setText(QString::number(currCost));
                //Add the current cost to the total cost of the host
                cost += currCost;
            }
        }
    }

    if(firstCommName == "General")
    {
        auth -= authToSub;
        firstComm->findChild<QLineEdit*>(firstComm->objectName() + "auth")->setText(QString::number(auth));
    }

    ui->read_goldCurr->setText(QString::number(cost));
    updateUbiMins(*minUbi);
    updateUbiTotals(*totalUbi);

}

void MainWindow::updateUbiTotals(Ubiquity newUbi)
{
    ui->read_mnstyTotal->setText(QString::number(newUbi.mnsty));
    ui->read_cmmnTotal->setText(QString::number(newUbi.cmmn));
    ui->read_uncmmnTotal->setText(QString::number(newUbi.uncmmn));
    ui->read_rareTotal->setText(QString::number(newUbi.rare));
    ui->read_mythicTotal->setText(QString::number(newUbi.mythic));
    ui->read_uniqueTotal->setText(QString::number(newUbi.unique));
}

void MainWindow::updateUbiMins(Ubiquity newUbi)
{
    ui->read_mnstyCurr->setText(QString::number(newUbi.mnsty));
    ui->read_cmmnCurr->setText(QString::number(newUbi.cmmn));
    ui->read_uncmmnCurr->setText(QString::number(newUbi.uncmmn));
    ui->read_rareCurr->setText(QString::number(newUbi.rare));
    ui->read_mythicCurr->setText(QString::number(newUbi.mythic));
    ui->read_uniqueCurr->setText(QString::number(newUbi.unique));
}

void MainWindow::increaseUbi(Ubiquity* toMod, int mnsty, int cmmn, int uncmmn, int rare, int mythic, bool unique)
{
    toMod->mnsty += mnsty;
    toMod->cmmn += cmmn;
    toMod->uncmmn += uncmmn;
    toMod->rare += rare;
    toMod->mythic += mythic;
    toMod->unique += (unique) ? 1 : 0;
}
