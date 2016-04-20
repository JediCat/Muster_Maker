#ifndef NEWMUSTERDIALOG_H
#define NEWMUSTERDIALOG_H

#include <QDialog>
#include <QVector>

class QString;

namespace Ui {
class NewMusterDialog;
}

class NewMusterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewMusterDialog(QWidget *parent = 0);
    ~NewMusterDialog();

    int getRealmID();

private:
    Ui::NewMusterDialog *ui;
    void populateRealms();
    void initKindredSelect();

    int prevKindredIndex;
    int kindredIndex;
    int realmID;
    bool dbOpen;

protected:
    void accept() Q_DECL_OVERRIDE;

private slots:
    void onKindredSelectChange();
    void onRealmSelectChange();

};

extern QVector<QString> realmList;

#endif // NEWMUSTERDIALOG_H
