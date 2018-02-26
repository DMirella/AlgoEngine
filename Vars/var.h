#ifndef VAR_H
#define VAR_H

#include <QString>
#include <QList>

enum ClassVar{Value, Array};
struct Data{
    QList<int> array;
};

class Var
{
public:
    Var(QString name);
    virtual QString varTitle() const = 0;
    virtual QString valueAsText() = 0;
    QString getName() const;
    virtual ClassVar getClassVar() = 0;
    virtual Data getData() = 0;
    virtual void setData(Data data) = 0;
protected:
    QString name;
};

class VarCreator{
public:
    virtual Var* create(QString name) = 0;
};

#endif // VAR_H
