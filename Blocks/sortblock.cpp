#include "sortblock.h"
#include "../Algorithms/sortalgorithm.h"
#include "sortsettingsdialog.h"

SortBlock::SortBlock(QWidget *parent)
    :Block(parent)
{
    sortAlgo = new SortAlgorithm;
    SortSettingsDialog *sortSettingsDialog = new SortSettingsDialog(this);

    setAlgorithm(sortAlgo);
    setSettingsDialog(sortSettingsDialog);
    connect(sortSettingsDialog, SIGNAL(successSet(SortAlgorithmSettings)),
            this, SLOT(onSuccessSet(SortAlgorithmSettings)));
}

void SortBlock::onSuccessSet(SortAlgorithmSettings settings)
{
    sortAlgo->setSettings(settings);
}
