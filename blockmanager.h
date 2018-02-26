#ifndef BLOCKMANAGER_H
#define BLOCKMANAGER_H

#include <QList>

#include "Blocks/block.h"
#include "blockviewer.h"

class BlockManager : public QObject
{
    Q_OBJECT
public:
    BlockManager(BlockViewer *_blockViewer, QWidget *parent);
    void addBlock(BlockCreator *creator);

    void executeBlockList();
private:
    QList<Block*> sequence;
    BlockViewer *blockViewer;
private slots:
    void onBlockClose(Block *block);
};

#endif // BLOCKSEQUENCE_H
