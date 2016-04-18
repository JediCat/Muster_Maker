#ifndef UNITFRAME_H
#define UNITFRAME_H

#include <QFrame>
#include "unit.h"

class QString;
class Ubiquity;


namespace Ui {
class UnitFrame;
}

class UnitFrame : public QFrame
{
    Q_OBJECT

public:
    explicit UnitFrame(QWidget *parent = 0, bool comm = false);
    ~UnitFrame();
    void changeNames(const QString prefix, const QString number = "");
    QString constructUbi(const Ubiquity *ubi);
    void enableCheckBoxes();
    int commandCosts[3];

private:
    Ui::UnitFrame *ui;
    void setFieldEnabled(bool enable);
    void blankFields();
    int costPerUnit;

private slots:
    void onSpinBoxValueChanged();
    void onUnitSelectChanged();
    void callRefresh();\

signals:
    void refresh();
    void commandChanged();

};

#endif // UNITFRAME_H
