#include "dfsblock.h"

#include "dfssettingsdialog.h"
#include "../Algorithms/dfsalgorithm.h"

DFSBlock::DFSBlock(QWidget *parent)
    : Block(parent)
{
    setSettingsDialog(new DFSSettingsDialog(this));
}
