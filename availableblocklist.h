#ifndef AVAILABLEBLOCKLIST_H
#define AVAILABLEBLOCKLIST_H

#include <QListWidget>

#include "Blocks/block.h"
#include "blockmanager.h"

class AvailableBlockList : public QObject
{
    Q_OBJECT
public:
    AvailableBlockList(QListWidget *_listBlocksWidget, BlockManager *_blockManager);
    void addBlockToList(QString title, BlockCreator *blocksCreator);
private slots:
    void onBlockChoose(QModelIndex);
private:
    QListWidget *listBlocksWidget;
    QList<BlockCreator*> blockCreatorList;
    BlockManager *blockManager;
};

#endif // AVAILABLEBLOCKLIST_H
