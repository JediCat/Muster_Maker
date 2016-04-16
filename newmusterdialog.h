#ifndef NEWMUSTERDIALOG_H
#define NEWMUSTERDIALOG_H

#include <QDialog>

namespace Ui {
class NewMusterDialog;
}

class NewMusterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMusterDialog(QWidget *parent = 0);
    ~NewMusterDialog();

private:
    Ui::NewMusterDialog *ui;
};

#endif // NEWMUSTERDIALOG_H
