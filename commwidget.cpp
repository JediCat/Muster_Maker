#include "commwidget.h"
#include "ui_commwidget.h"
#include "unitframe.h"
#include <QComboBox>
#include "dbmanager.h"

CommWidget::CommWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommWidget)
{
    ui->setupUi(this);
}

CommWidget::CommWidget(bool gen, QString numComm, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommWidget)
{
    ui->setupUi(this);

    ui->comm_layout->setAlignment(Qt::AlignTop);

    UnitFrame* newComm = new UnitFrame(0, true);
    QString prefix;

    if(gen)
    {
        prefix = "hostComm";
        this->setObjectName(prefix);
        this->changeNames(prefix + "_");
        newComm->changeNames("gen_", "-1");

    }
    else
    {
        prefix = "comm_" + numComm;
        this->setObjectName(prefix);
        this->changeNames(prefix + "_");
        newComm->changeNames(prefix + "_comm_");
        if(prefix == "comm_1")
        {
            newComm->findChild<QComboBox*>(prefix + "_comm_select")->addItem("General");
        }
    }

    units = 48;
    connect(ui->comm_addUnit, SIGNAL(clicked(bool)), this, SLOT(addUnit()));
    connect(ui->comm_remUnit, SIGNAL(clicked(bool)), this, SLOT(removeUnit()));
    connect(newComm, SIGNAL(refresh()), this, SLOT(requestRefreshHost()));
    connect(newComm, SIGNAL(commandChanged()), this, SLOT(handleCommanderChange()));
    connect(newComm, SIGNAL(invocChange(QString,bool,int)), this, SLOT(requestRefreshInvoc(QString,bool,int)));

    ui->comm_layout->addWidget(newComm);
}

CommWidget::~CommWidget()
{
    delete ui;
}

void CommWidget::changeNames(QString prefix)
{
    ui->comm_addUnit->setObjectName(prefix + "addUnit");
    ui->comm_remUnit->setObjectName(prefix + "remUnit");
    ui->comm_layout->setObjectName(prefix + "layout");
    ui->comm_scroll->setObjectName(prefix + "scroll");
    ui->comm_scrollArea->setObjectName(prefix + "scrollArea");
}

void CommWidget::addUnit()
{
    if(units-48 == 9)
    {
        return;
    }

    units++;

    QString number = QString(QChar(units));
    QString prefix = this->objectName() + "_unit" + number + "_";

    UnitFrame* newUnit = new UnitFrame();

    newUnit->changeNames(prefix, number);
    newUnit->enableCheckBoxes();

    ui->comm_layout->addWidget(newUnit);

    connect(newUnit, SIGNAL(refresh()), this, SLOT(requestRefreshHost()));
    connect(newUnit, SIGNAL(invocChange(QString,bool,int)), this, SLOT(requestRefreshInvoc(QString,bool,int)));

    newUnit->show();


}

void CommWidget::removeUnit()
{
    if(units-48 < 1)
    {
        return;
    }

    QString number = QString(QChar(units));
    QString prefix = this->objectName() + "_unit" + number + "_";

    QFrame* toDelete = this->findChild<QFrame*>(prefix);
    delete toDelete;
    units--;
}

void CommWidget::requestRefreshHost()
{
    emit refresh();
}

void CommWidget::handleCommanderChange()
{
    QString frameName = QObject::sender()->objectName();

    int check = frameName.indexOf("gen");
    if(check == -1)
    {
        check = frameName.indexOf("_comm_");
    }

    if(check != -1)
    {
        QComboBox* comm = this->findChild<QComboBox*>(frameName + "select");
        QString name = comm->currentText();
        if(name != "General")
        {
            for(unsigned int i = 0; i < hostUnits.size(); i++)
            {
                if(hostUnits[i]->ubiChanged)
                {
                    Ubiquity* toDel = hostUnits[i]->ubi;
                    hostUnits[i]->ubi = hostUnits[i]->oldUbi;
                    delete toDel;
                    hostUnits[i]->ubiChanged = false;
                }
            }
            if(name != "")
            {
                Unit* commander = findUnit(name);
                if(commander->comm)
                {
                    std::vector<ubiChange> ubiChanges = db.fetchUbiChange(commander->unitID);
                    for(unsigned int i = 0; i < ubiChanges.size(); i++)
                    {
                        Unit* target = findUnit(ubiChanges[i].targetName);
                        target->ubi = ubiChanges[i].newUbi;
                        target->ubiChanged = true;
                    }
                }
            }
        }
    }

    emit refresh();
}

void CommWidget::requestRefreshInvoc(QString prefix, bool remove, int unitIndex)
{
    emit invocChange(prefix, remove, unitIndex);
}
