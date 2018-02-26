#include "blockmanager.h"

BlockManager::BlockManager(BlockViewer *_blockViewer, QWidget *parent)
    : QObject(parent), blockViewer(_blockViewer)
{
}

void BlockManager::addBlock(BlockCreator *creator)
{
    if(creator == NULL){
        qDebug() << "addBlock(BlockManager): creator == NULL";
        return;
    }
    Block *block = creator->create(blockViewer);
    sequence.append(block);
    blockViewer->addBlock(block);

    connect(block, SIGNAL(closeMeManager(Block*)), this, SLOT(onBlockClose(Block*)));
}

void BlockManager::executeBlockList()
{
    QMutableListIterator<Block*> it(sequence);
    while(it.hasNext()){
        it.next();
        it.value()->doAlgorithm();
    }
}

void BlockManager::onBlockClose(Block *block)
{
    QMutableListIterator<Block*> it(sequence);
    while(it.hasNext()){
        it.next();
        if(it.value() == block){
            it.remove();
            break;
        }
    }
    block->close();
    delete block;
}
