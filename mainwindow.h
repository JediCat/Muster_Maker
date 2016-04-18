#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Unit;
class QString;
class Ubiquity;

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
    void increaseUbi(Ubiquity* toMod, int mnsty, int cmmn, int uncmmn, int rare, int mythic, int unique);

private slots:
    void addCommand();
    void removeCommand();
    void onBattleSizeChange();
    void updateHost();
};

#endif // MAINWINDOW_H
