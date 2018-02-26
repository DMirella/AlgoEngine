#ifndef INTEGERVAR_H
#define INTEGERVAR_H

#include "var.h"

class IntegerVar : public Var
{
public:
    IntegerVar(QString _name);

    static const QString SVarTitle(){
        return "Integer";
    }
    // Var interface
    QString varTitle() const{
        return SVarTitle();
    }
    QString valueAsText(){
        return "None";
    }
    ClassVar getClassVar(){
        return ClassVar::Value;
    }
    Data getData(){}
    void setData(Data data){}
};



class IntegerVarCreator : public VarCreator{

    // VarCreator interface
public:
    Var *create(QString name){
        return new IntegerVar(name);
    }
};

#endif // INTEGERVAR_H
