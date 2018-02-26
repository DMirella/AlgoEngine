#include "availableblocklist.h"

AvailableBlockList::AvailableBlockList(QListWidget *_listBlocksWidget, BlockManager *_blockManager)
    : listBlocksWidget(_listBlocksWidget), blockManager(_blockManager)
{
    connect(listBlocksWidget, SIGNAL(doubleClicked(QModelIndex)),
            this, SLOT(onBlockChoose(QModelIndex)));
}

void AvailableBlockList::addBlockToList(QString title, BlockCreator *blockCreator)
{
    QListWidgetItem *itm = new QListWidgetItem;
    itm->setText(title);
    blockCreatorList.append(blockCreator);

    listBlocksWidget->addItem(itm);
}

void AvailableBlockList::onBlockChoose(QModelIndex)
{
    int index = listBlocksWidget->currentRow();
    if(index != -1){
        blockManager->addBlock(blockCreatorList.at(index));
    }
}
