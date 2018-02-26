#include "intarrayvar.h"
//#include <Q>

IntArrayVar::IntArrayVar(QString name)
    : Var(name)
{
    Test();
}

void IntArrayVar::Test()
{
    for(int i = 4; i >= 0; i--){
        array.append(qrand() % 10);
    }
}

QString IntArrayVar::valueAsText()
{
    QString res = "[";
    foreach (int it, array) {
        res += QString::number(it) + ", ";
    }
    res += ']';
    return res;
}

Data IntArrayVar::getData()
{
    Data res;
    res.array = array;
    return res;
}

void IntArrayVar::setData(Data data)
{
    array = data.array;
}
