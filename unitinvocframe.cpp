#include "unitinvocframe.h"
#include "ui_unitinvocframe.h"

UnitInvocFrame::UnitInvocFrame(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::UnitInvocFrame)
{
    ui->setupUi(this);
}

UnitInvocFrame::~UnitInvocFrame()
{
    delete ui;
}

void UnitInvocFrame::changeNames(QString prefix)
{
    this->setObjectName(prefix);
    ui->unitInvocFrame_label->setObjectName(prefix + "label");
    ui->unitInvocFrame_layout->setObjectName(prefix + "layout");
    ui->unitInvocFrame_name->setObjectName(prefix + "name");
}
