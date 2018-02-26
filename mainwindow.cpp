#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QListWidget>

#include "Blocks/dfsblock.h"
#include "Blocks/sortblock.h"
#include "globalvararea.h"

#include "Algorithms/dfsalgorithm.h"
#include "Algorithms/sortalgorithm.h"

#include "vars/integervar.h"
#include "vars/intarrayvar.h"

void DebugFirstStage(AvailableBlockList *av);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    globalVarViewer = new GlobalVarAreaViewer(this);
    blockViewerWidget = new BlockViewer(this);
    blockManager = new BlockManager(blockViewerWidget, this);

    QGroupBox *mainWi = new QGroupBox(this);
    QVBoxLayout *mainLay = new QVBoxLayout(mainWi);
    mainLay->addWidget(globalVarViewer);
    mainLay->addWidget(blockViewerWidget);
    mainWi->setLayout(mainLay);
    setCentralWidget(mainWi);

    QListWidget *listBlocks = new QListWidget(this);
    ui->dockWidget->setWidget(listBlocks);
    availableBlockList = new AvailableBlockList(listBlocks, blockManager);

    registerVars();
    DebugFirstStage(availableBlockList);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete availableBlockList;
}

//Отладка первого этапа разработки
void DebugFirstStage(AvailableBlockList *av){
   // av->addBlockToList(DFSAlgorithm::name(), new DFSBlockCreator);
    av->addBlockToList(SortAlgorithm::name(), new SortBlockCreator);
}

void MainWindow::on_actionRun_triggered()
{
    blockManager->executeBlockList();
}

void MainWindow::registerVars()
{
    GlobalVarArea::varRegister(IntegerVar::SVarTitle(), new IntegerVarCreator);
    GlobalVarArea::varRegister(IntArrayVar::SVarTitle(), new IntArrayVarCreator);
}
