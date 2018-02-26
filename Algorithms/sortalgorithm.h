#ifndef SORTALGORITHM_H
#define SORTALGORITHM_H

#include "algorithm.h"
#include "../Vars/intarrayvar.h"

class SortAlgorithmInput : public AlgorithmInput{
public:
    Var *array;
};

class SortAlgorithmOutput : public AlgorithmOutput{
public:
    Var *array;
};

enum SortMode{Increase, Decrease};
struct SortAlgorithmSettings{
    SortMode mode;
    SortAlgorithmInput input;
    SortAlgorithmOutput output;
};

class SortAlgorithm : public Algorithm
{
public:
    SortAlgorithm();

    void setSettings(SortAlgorithmSettings settings);

    // Algorithm interface
    void mainAlgorithm();
    static const QString name() { return "Sorting"; }
    const QString getName(){
        return name();
    }
private:
    SortAlgorithmSettings settings;
};

#endif // SORTALGORITHM_H
