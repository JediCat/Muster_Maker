#ifndef COMMWIDGET_H
#define COMMWIDGET_H

#include <QWidget>

namespace Ui {
class CommWidget;
}

class CommWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CommWidget(QWidget *parent = 0);
    CommWidget(bool gen, QString numComm = "", QWidget *parent = 0);
    ~CommWidget();
    void changeNames(QString prefix);

private:
    Ui::CommWidget *ui;
    int units;

private slots:
    void addUnit();
    void removeUnit();
    void requestRefreshHost();
    void handleCommanderChange();
    void requestRefreshInvoc(QString prefix, bool remove, int unitIndex);

signals:
    void refresh();
    void invocChange(QString prefix, bool remove, int unitIndex);
};

#endif // COMMWIDGET_H
