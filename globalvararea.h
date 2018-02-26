#ifndef GLOBALVARAREA_H
#define GLOBALVARAREA_H

#include <QMap>
#include <QString>
#include <QGroupBox>

#include "Vars/var.h"

struct VarTextDescription{
    QString type;
    QString id;
    QString value;
};

class GlobalVarArea
{
public:
    GlobalVarArea();
    ~GlobalVarArea();
    static int addVar(Var *var);
    static QString toText();
    static void varRegister(QString title, VarCreator *creator);
    static QList<QString> getVarTitles();
    static Var* createVarAt(int index, QString name);
    static void createAndAddVarAt(int index, QString name);
    static QList<QString> getIds();
    static void deleteById(QString id);
    static Var* getVarById(QString id);
    static QList<VarTextDescription> getVarTextDescriptions();
    static QList<QString> getIdVarsByClass(ClassVar classVar);

private:
    static void deleteVarTable();

    static QMap<QString, Var*> varTable; //id = var
    static QList<QPair<QString, VarCreator*> > availableVars;
    static QList<QString> availableVarTitles;
};

#endif // GLOBALVARAREA_H
