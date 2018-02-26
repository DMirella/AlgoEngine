#include "var.h"

Var::Var(QString name)
{
    this->name = name;
}

QString Var::getName() const
{
    return name;
}
