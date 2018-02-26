#ifndef INTARRAYVAR_H
#define INTARRAYVAR_H

#include "var.h"
#include <QList>

class IntArrayVar : public Var
{
public:
    IntArrayVar(QString name);

    //Test function
    void Test();

    static const QString SVarTitle(){
        return "Int array";
    }
    // Var interface
    QString varTitle() const{
        return SVarTitle();
    }
    QString valueAsText();
    ClassVar getClassVar(){
        return ClassVar::Array;
    }
    Data getData();
    void setData(Data data);
protected:
    QList<int> array;
};



class IntArrayVarCreator : public VarCreator{

    // VarCreator interface
public:
    Var *create(QString name){
        return new IntArrayVar(name);
    }
};

#endif // INTARRAYVAR_H
