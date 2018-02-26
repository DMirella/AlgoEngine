#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "blockviewer.h"
#include "availableblocklist.h"
#include "blockmanager.h"
#include "globalvarareaviewer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionRun_triggered();

private:
    void registerVars();

    Ui::MainWindow *ui;

    BlockViewer *blockViewerWidget;
    AvailableBlockList *availableBlockList;
    BlockManager *blockManager;
    GlobalVarAreaViewer *globalVarViewer;
};

#endif // MAINWINDOW_H
