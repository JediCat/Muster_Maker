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
    void enableCheckBoxes();

private:
    Ui::UnitFrame *ui;
    QString constructUbi(const Ubiquity *ubi);
    void setFieldEnabled(bool enable);
    void blankFields();

private slots:
    void onSpinBoxValueChanged();
    void onUnitSelectChanged();
    void onMinUbiCheck();\

signals:
    void refresh();

};

#endif // UNITFRAME_H
