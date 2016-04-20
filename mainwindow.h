#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Unit;
class QString;
class Ubiquity;
class QComboBox;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void updateUbiMins(Ubiquity newUbi);
    void updateUbiTotals(Ubiquity newUbi);
    void increaseUbi(Ubiquity* toMod, int mnsty, int cmmn, int uncmmn, int rare, int mythic, bool unique);
    void setInvocList();
    void addInvocToCombo(QComboBox* iList);
    QString numToString(int num);

private slots:
    void addCommand();
    void removeCommand();
    void onBattleSizeChange();
    void updateHost();
    void refreshInvocations(QString prefix, bool remove, int unitIndex);
    void newHost();
};

#endif // MAINWINDOW_H
