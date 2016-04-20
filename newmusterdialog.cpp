#include "newmusterdialog.h"
#include "ui_newmusterdialog.h"
#include "dbmanager.h"
#include <QCloseEvent>
#include "constants.h"

NewMusterDialog::NewMusterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMusterDialog)
{
    ui->setupUi(this);

    connect(ui->selectKindred, SIGNAL(currentIndexChanged(int)), this, SLOT(onKindredSelectChange()));
    connect(ui->selectRealm, SIGNAL(currentIndexChanged(int)), this, SLOT(onRealmSelectChange()));

    prevKindredIndex = 99;
    dbOpen = false;

    initKindredSelect();
}

NewMusterDialog::~NewMusterDialog()
{
    delete ui;
}

void NewMusterDialog::initKindredSelect()
{
    ui->selectKindred->addItem("");
    for(int i = 0; i < NUM_KINDRED; i++)
    {
        ui->selectKindred->addItem(KINDRED_NAME[i]);
    }
}

int NewMusterDialog::getRealmID()
{
    return realmID;
}

void NewMusterDialog::onKindredSelectChange()
{
    kindredIndex = ui->selectKindred->currentIndex() - 1;

    populateRealms();
}

void NewMusterDialog::populateRealms()
{
    if(kindredIndex != -1 && kindredIndex == 5)
    {
        int j = ui->selectRealm->count() - 1;
        for(int i = j; i > -1; i--)
        {
            ui->selectRealm->removeItem(i);
            if(i != j)
            {
                realmList.remove(i);
            }
        }

        if(!dbOpen)
        {
            //Establish Database
            QString pwd(QCoreApplication::applicationDirPath());
            pwd.replace("/","\\");
            db = DbManager(pwd + KINDRED_DB[kindredIndex]);
            dbOpen = true;
            prevKindredIndex = kindredIndex;
        }
        else
        {
            if(prevKindredIndex != kindredIndex)
            {
                db.close();
                QString pwd(QCoreApplication::applicationDirPath());
                pwd.replace("/","\\");
                db = DbManager(pwd + KINDRED_DB[kindredIndex]);
            }
        }

        db.fetchRealms();

        ui->selectRealm->addItem("");
        for(int i = 0; i < realmList.size(); i++)
        {
            ui->selectRealm->addItem(realmList[i]);
        }

        prevKindredIndex = kindredIndex;
    }
}

void NewMusterDialog::onRealmSelectChange()
{
    realmID = ui->selectRealm->currentIndex();
}

void NewMusterDialog::accept()
{
    int rInd = ui->selectRealm->currentIndex();
    int kInd = ui->selectKindred->currentIndex();
    QFont newFont = ui->kinLabel->font();

    if(kInd == 0 || kInd == -1)
    {
        newFont.setBold(true);
        ui->kinLabel->setFont(newFont);
        ui->kinLabel->setStyleSheet("QLabel {color : red}");
        if(rInd == 0 || rInd == -1)
        {
            newFont = ui->reaLabel->font();
            newFont.setBold(true);
            ui->reaLabel->setFont(newFont);
            ui->reaLabel->setStyleSheet("QLabel {color : red}");
        }
    }
    else
    {
        newFont.setBold(false);
        ui->kinLabel->setFont(newFont);
        ui->kinLabel->setStyleSheet("");
        if(rInd == 0 || rInd == -1)
        {
            newFont = ui->reaLabel->font();
            newFont.setBold(true);
            ui->reaLabel->setFont(newFont);
            ui->reaLabel->setStyleSheet("QLabel {color : red}");
        }
        else
        {
            QDialog::accept();
        }

    }
}
