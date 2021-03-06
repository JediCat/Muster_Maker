#include "unitframe.h"
#include "ui_unitframe.h"
#include <vector>
#include "ubiquity.h"
#include "dbmanager.h"
#include <QString>
#include "unit.h"
#include "constants.h"

UnitFrame::UnitFrame(QWidget *parent, bool comm) :
    QFrame(parent),
    ui(new Ui::UnitFrame)
{
    ui->setupUi(this);

    ui->unit_size->findChildren<QLineEdit*>().at(0)->setReadOnly(true);
    ui->unit_select->addItem("");
    if(!comm)
    {
        for(int i = 0; i < hostUnits.size(); i++)
        {
            ui->unit_select->addItem(hostUnits[i]->name);
        }
    }
    else
    {
        std::vector<Unit*> commUnits;
        for(int i = 0; i < hostUnits.size(); i++)
        {
            if(hostUnits[i]->minSize == hostUnits[i]->maxSize && hostUnits[i]->maxSize == 1 && hostUnits[i]->auth > 50)
            {
                commUnits.insert(commUnits.end(), hostUnits[i]);
            }
        }
        for(unsigned int i = 0; i < commUnits.size(); i++)
        {
            ui->unit_select->addItem(commUnits[i]->name);
        }

    }

    costPerUnit = 0;
    commandCosts[0] = 0;
    commandCosts[1] = 0;
    commandCosts[2] = 0;
    prevUnit = 99;

    connect(ui->unit_size, SIGNAL(valueChanged(int)), this, SLOT(onSpinBoxValueChanged()), Qt::QueuedConnection);
    connect(ui->unit_select, SIGNAL(currentIndexChanged(QString)), this, SLOT(onUnitSelectChanged()));
    connect(ui->unit_minU, SIGNAL(stateChanged(int)), this, SLOT(callRefresh()));
    connect(ui->unit_champ, SIGNAL(stateChanged(int)), this, SLOT(callRefresh()));
    connect(ui->unit_banner, SIGNAL(stateChanged(int)), this, SLOT(callRefresh()));
    connect(ui->unit_horn, SIGNAL(stateChanged(int)), this, SLOT(callRefresh()));
}

UnitFrame::~UnitFrame()
{
    delete ui;
}

void UnitFrame::changeNames(const QString prefix,const QString number)
{
    if(number == "")
    {
        ui->unit_Lname->setText("Commander");
    }
    else if(number == "-1")
    {
        ui->unit_Lname->setText("General");
    }
    else
    {
        ui->unit_Lname->setText("Unit " + number);
    }

    this->setObjectName(prefix);
    ui->unit_auth->setObjectName(prefix + "auth");
    ui->unit_banner->setObjectName(prefix + "banner");
    ui->unit_champ->setObjectName(prefix + "champ");
    ui->unit_cost->setObjectName(prefix + "cost");
    ui->unit_horn->setObjectName(prefix + "horn");
    ui->unit_Lauth->setObjectName(prefix + "Lauth");
    ui->unit_layout->setObjectName(prefix + "layout");
    ui->unit_Lban->setObjectName(prefix + "Lban");
    ui->unit_Lchamp->setObjectName(prefix + "Lchamp");
    ui->unit_Lcost->setObjectName(prefix + "Lcost");
    ui->unit_Lhorn->setObjectName(prefix + "Lhorn");
    ui->unit_LminU->setObjectName(prefix + "Lminu");
    ui->unit_Lmsize->setObjectName(prefix + "Lmsize");
    ui->unit_Lname->setObjectName(prefix + "Lname");
    ui->unit_Lsize->setObjectName(prefix + "Lsize");
    ui->unit_Lubi->setObjectName(prefix + "Lubi");
    ui->unit_minU->setObjectName(prefix + "minU");
    ui->unit_msize->setObjectName(prefix + "msize");
    ui->unit_select->setObjectName(prefix + "select");
    ui->unit_size->setObjectName(prefix + "size");
    ui->unit_ubi->setObjectName(prefix + "ubi");

}

void UnitFrame::enableCheckBoxes()
{
    ui->unit_banner->setEnabled(true);
    ui->unit_champ->setEnabled(true);
    ui->unit_horn->setEnabled(true);
}

void UnitFrame::onSpinBoxValueChanged() // slot
{
   QObject::sender()->findChild<QLineEdit*>()->deselect();
   emit refresh();
}

void UnitFrame::onUnitSelectChanged()
{
    //For dynamic invocation management
    if(prevUnit != 99 && hostUnits[prevUnit]->invocSlots > 0)
    {
        emit invocChange(this->objectName(), true, prevUnit);
    }


    unsigned int i;
    Unit* locUnit;
    for(i = 0; i < hostUnits.size(); i++)
    {
        if(hostUnits[i]->name == ui->unit_select->currentText())
        {
            prevUnit = i;
            break;
        }
    }
    if(i < hostUnits.size() || ui->unit_select->currentIndex() == 0)
    {
        setFieldEnabled(true);
        if(i < hostUnits.size())
        {
            locUnit = hostUnits[i];
            ui->unit_auth->setText(QString::number(locUnit->auth));
            ui->unit_size->setMinimum(locUnit->minSize);
            ui->unit_size->setMaximum(locUnit->maxSize);
            ui->unit_msize->setText(QString::number(locUnit->maxSize));
            costPerUnit = locUnit->costPer;
            ui->unit_cost->setText(QString::number(costPerUnit*locUnit->minSize));
            ui->unit_ubi->setText(constructUbi(locUnit->ubi));


        }
        else
        {
            locUnit = NULL;
            blankFields();
        }
    }
    else
    {
        locUnit = NULL;
        setFieldEnabled(false);
    }

    emit refresh();

    QString frameName = this->objectName();

    int check = frameName.indexOf("gen");
    if(check == -1)
    {
        check = frameName.indexOf("_comm_");
    }

    ui->unit_champ->setChecked(false);
    ui->unit_banner->setChecked(false);
    ui->unit_horn->setChecked(false);

    int check2 = frameName.indexOf("host");
    if(locUnit != NULL)
    {
        if(check2 != -1 && locUnit->maxSize == 1)
        {
            db.fetchCommandOptions(ui->unit_champ, ui->unit_banner, ui->unit_horn, locUnit->unitID, true, commandCosts);
        }
        else
        {
            db.fetchCommandOptions(ui->unit_champ, ui->unit_banner, ui->unit_horn, locUnit->unitID, false, commandCosts);
        }

        if(locUnit->invocSlots > 0)
        {
            emit invocChange(frameName, false, i);
        }
    }

    if(check != -1)
    {
        emit commandChanged();
    }
}

void UnitFrame::setFieldEnabled(bool enable)
{
    blankFields();
    ui->unit_size->setEnabled(enable);
    ui->unit_msize->setEnabled(enable);
    ui->unit_cost->setEnabled(enable);
    ui->unit_ubi->setEnabled(enable);
    ui->unit_minU->setEnabled(enable);
}

void UnitFrame::blankFields()
{
    ui->unit_auth->setText("");
    ui->unit_size->setMinimum(0);
    ui->unit_size->setMaximum(99);
    ui->unit_size->setValue(0);
    ui->unit_msize->setText("");
    ui->unit_cost->setText("");
    ui->unit_ubi->setText("");
    ui->unit_cost->setText("");
}

void UnitFrame::callRefresh()
{
    emit refresh();
}

QString UnitFrame::constructUbi(const Ubiquity* ubi)
{
    QString ubiString = "";

    if(ubi->unique)
    {
        ubiString += "Uq";
    }

    if(ubi->mythic > 0)
    {
        if(ubiString == "")
        {
            ubiString += "My";
            if(ubi->mythic > 1)
            {
                ubiString += ("(" + QString::number(ubi->mythic) + ")");
            }
        }
        else
        {
            ubiString += " + My";
            if(ubi->mythic > 1)
            {
                ubiString += ("(" + QString::number(ubi->mythic) + ")");
            }
        }
    }

    if(ubi->rare > 0)
    {
        if(ubiString == "")
        {
            ubiString += "R";
            if(ubi->rare > 1)
            {
                ubiString += ("(" + QString::number(ubi->rare) + ")");
            }
        }
        else
        {
            ubiString += " + R";
            if(ubi->rare > 1)
            {
                ubiString += ("(" + QString::number(ubi->rare) + ")");
            }
        }
    }

    if(ubi->uncmmn > 0)
    {
        if(ubiString == "")
        {
            ubiString += "Un";
            if(ubi->uncmmn > 1)
            {
                ubiString += ("(" + QString::number(ubi->uncmmn) + ")");
            }
        }
        else
        {
            ubiString += " + Un";
            if(ubi->uncmmn > 1)
            {
                ubiString += ("(" + QString::number(ubi->uncmmn) + ")");
            }
        }
    }

    if(ubi->cmmn > 0)
    {
        if(ubiString == "")
        {
            ubiString += "C";
            if(ubi->cmmn > 1)
            {
                ubiString += ("(" + QString::number(ubi->cmmn) + ")");
            }
        }
        else
        {
            ubiString += " + C";
            if(ubi->cmmn > 1)
            {
                ubiString += ("(" + QString::number(ubi->cmmn) + ")");
            }
        }
    }

    if(ubi->mnsty > 0)
    {
        if(ubiString == "")
        {
            ubiString += "Ma";
            if(ubi->mnsty > 1)
            {
                ubiString += ("(" + QString::number(ubi->mnsty) + ")");
            }
        }
        else
        {
            ubiString += " + Ma";
            if(ubi->mnsty > 1)
            {
                ubiString += ("(" + QString::number(ubi->mnsty) + ")");
            }
        }
    }

    return ubiString;
}
