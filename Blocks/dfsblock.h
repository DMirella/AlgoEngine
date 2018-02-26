#ifndef DFSBLOCK_H
#define DFSBLOCK_H

#include "block.h"
#include "Algorithms/dfsalgorithm.h"
#include <QWidget>

class DFSBlock : public Block
{
public:
    DFSBlock(QWidget *parent);
};

class DFSBlockCreator : public BlockCreator{
public:
    Block* create(QWidget *parent){
        DFSBlock *dfsBlock = new DFSBlock(parent);
        //dfsBlock->setAlgorithm(new DFSAlgorithm());
        return dfsBlock;
    }
};

#endif // DFSBLOCK_H
