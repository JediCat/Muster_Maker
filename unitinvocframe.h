#ifndef UNITINVOCFRAME_H
#define UNITINVOCFRAME_H

#include <QFrame>

namespace Ui {
class UnitInvocFrame;
}

class UnitInvocFrame : public QFrame
{
    Q_OBJECT

public:
    explicit UnitInvocFrame(QWidget *parent = 0);
    ~UnitInvocFrame();
    void changeNames(QString prefix);

private:
    Ui::UnitInvocFrame *ui;

};

#endif // UNITINVOCFRAME_H
