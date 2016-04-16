#include "newmusterdialog.h"
#include "ui_newmusterdialog.h"

NewMusterDialog::NewMusterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewMusterDialog)
{
    ui->setupUi(this);
}

NewMusterDialog::~NewMusterDialog()
{
    delete ui;
}
