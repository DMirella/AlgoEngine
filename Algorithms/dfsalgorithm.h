#ifndef DFSALGORITHM_H
#define DFSALGORITHM_H

#include "algorithm.h"

class DFSAlgorithm : public Algorithm
{
public:
    DFSAlgorithm();
    static const QString name() { return "DFS"; }
    const QString getName(){ return name();}
    void mainAlgorithm();
};

#endif // DFSALGORITHM_H
