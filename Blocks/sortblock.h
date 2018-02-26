#ifndef SORTBLOCK_H
#define SORTBLOCK_H

#include "block.h"
#include "../Algorithms/sortalgorithm.h"

class SortBlock : public Block
{
    Q_OBJECT
public:
    SortBlock(QWidget *parent);
private slots:
    void onSuccessSet(SortAlgorithmSettings settings);
private:
    SortAlgorithm *sortAlgo;
};


class SortBlockCreator : public BlockCreator{
public:
    Block* create(QWidget *parent){
        SortBlock *sortBlock = new SortBlock(parent);
        return sortBlock;
    }
};


#endif // SORTBLOCK_H
