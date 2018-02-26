#include "globalvararea.h"

#include <QDebug>

QMap<QString, Var*> GlobalVarArea::varTable;
QList<QPair<QString, VarCreator*> > GlobalVarArea::availableVars;
QList<QString> GlobalVarArea::availableVarTitles;

GlobalVarArea::GlobalVarArea()
{
}

GlobalVarArea::~GlobalVarArea()
{
    foreach(Var *it, varTable.values()) {
        delete it;
    }
}

int GlobalVarArea::addVar(Var *var)
{
    QString id = var->getName();
    if(varTable.contains(id)) {
        qDebug() << "addVar: varTable contains \"" + id + "\"";
        return -1;
    }
    varTable[id] = var;
    return 0;
}

QString GlobalVarArea::toText()
{
    QString res;
    foreach(Var *it, varTable.values()){
        res += it->varTitle() + ": " + it->getName() + "; ";
    }
    return res;
}

void GlobalVarArea::varRegister(QString title, VarCreator *creator)
{
    availableVars.append({title, creator});
    availableVarTitles.append(title);
}

QList<QString> GlobalVarArea::getVarTitles()
{
    return availableVarTitles;
}

Var *GlobalVarArea::createVarAt(int index, QString name)
{
    return availableVars.at(index).second->create(name);
}

void GlobalVarArea::createAndAddVarAt(int index, QString name)
{
    addVar(createVarAt(index, name));
}

QList<QString> GlobalVarArea::getIds()
{
    QList<QString> res;
    foreach(QString it, varTable.keys()){
        res.append(it);
    }
    return res;
}

void GlobalVarArea::deleteById(QString id)
{
    delete varTable[id];
    varTable.remove(id);
}

Var* GlobalVarArea::getVarById(QString id)
{
    return varTable[id];
}

QList<VarTextDescription> GlobalVarArea::getVarTextDescriptions()
{
    QList<VarTextDescription> res;
    foreach(QString it, varTable.keys()){
        VarTextDescription cur;
        cur.type  = varTable[it]->varTitle();
        cur.id    = varTable[it]->getName();
        cur.value = varTable[it]->valueAsText();
        res.append(cur);
    }
    return res;
}

QList<QString> GlobalVarArea::getIdVarsByClass(ClassVar classVar)
{
    QList<QString> res;
    foreach (Var *var, varTable.values()) {
        if(var->getClassVar() == classVar){
            res.append(var->getName());
        }
    }
    return res;
}
