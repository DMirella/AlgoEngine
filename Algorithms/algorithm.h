#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <QString>

class AlgorithmInput;
class AlgorithmOutput;
class AlgorithmSettings;

class Algorithm
{
public:
    Algorithm();
    virtual void mainAlgorithm() = 0;
    virtual const QString getName() = 0;
protected:
    //AlgorithmSettings *settings;
};


class AlgorithmInput
{
public:
    AlgorithmInput(){}
    //virtual bool isInputValid() const = 0;
};


class AlgorithmOutput
{
public:
    AlgorithmOutput(){}
};



class AlgorithmSettings{
public:
    AlgorithmSettings();
};

#endif // ALGORITHM_H
