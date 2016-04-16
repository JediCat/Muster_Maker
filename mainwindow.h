#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class Unit;
class QString;

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
    void updateUbi(int mn, int cm, int unc, int ra, int my, int uq);

private slots:
    void addCommand();
    void removeCommand();
    void onBattleSizeChange();
    void updateHost();
};

#endif // MAINWINDOW_H
