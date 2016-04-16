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

            //If a unit has been selected, update the host
            if(unitName->currentText() != "")
            {
                //Pointer to the size of the unit
                QSpinBox* sizePoint = currUnitFrame->findChild<QSpinBox*>(prefix + "size");
                //Pointer to the actual unit, not the just the Frame
                Unit* currUnit = findUnit(unitName->currentText());

                //Cost of the unit = cost per unit * size of unit
                int currCost = sizePoint->value() * currUnit->costPer;
                //Update the displayed cost for the current Unit Frame
                currUnitFrame->findChild<QLineEdit*>(prefix + "cost")->setText(QString::number(currCost));
                //Add the current cost to the total cost of the host
                cost += currCost;

                //If the current unit is to be counter toward the minimum Ubiquity
                // update the host's ubiquity counts.
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

    if(firstCommName == "General")
    {
        auth -= authToSub;
        firstComm->findChild<QLineEdit*>(firstComm->objectName() + "auth")->setText(QString::number(auth));
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
