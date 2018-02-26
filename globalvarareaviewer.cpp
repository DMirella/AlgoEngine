#include "globalvarareaviewer.h"
#include "additionqt.h"

#include <QBoxLayout>
#include "globalvararea.h"
#include "vars/integervar.h"
#include "addvardialog.h"
#include "delvardialog.h"
#include "showvarsdialog.h"

#define BUTTON_WIDTH  73
#define BUTTON_HEIGHT 23
#define WIDGET_WIDTH  400
#define WIDGET_HEIGHT 70

GlobalVarAreaViewer::GlobalVarAreaViewer(QWidget *parent)
    : QGroupBox(parent)
{
    delVarButton   = new QPushButton(this);
    addVarButton   = new QPushButton(this);
    showVarsButton = new QPushButton(this);
    addVarDialog   = new AddVarDialog(this);
    delVarDialog   = new DelVarDialog(this);
    showVarsDialog = new ShowVarsDialog(this);
    varTitles      = new QLabel(this);

    //Interface set
    QVBoxLayout *buttonLay = new QVBoxLayout;
    regButton(addVarButton, "Add var", buttonLay);
    regButton(delVarButton, "Del var", buttonLay);
    regButton(showVarsButton, "Show vars", buttonLay);
    //setFixedSize(WIDGET_WIDTH, WIDGET_HEIGHT);

    QHBoxLayout *mainLay   = new QHBoxLayout(this);
    mainLay->addWidget(varTitles);
    mainLay->addLayout(buttonLay);
    setLayout(mainLay);

    setBackgroundColor(this, QColor(255, 255, 255));

    //connect signals/slots
    connect(addVarButton, SIGNAL(clicked(bool)), this, SLOT(onAddVarClicked()));
    connect(delVarButton, SIGNAL(clicked(bool)), this, SLOT(onDelVarClicked()));
    connect(showVarsButton, SIGNAL(clicked(bool)), this, SLOT(onShowVarsClicked()));
    connect(addVarDialog, SIGNAL(successAddVar(Var*)), this, SLOT(onSuccessAddVar(Var*)));
    connect(delVarDialog, SIGNAL(successDelVar(QString)), this, SLOT(onSuccessDelVar(QString)));
}

void GlobalVarAreaViewer::updateVarText()
{
    varTitles->clear();
    varTitles->setText(GlobalVarArea::toText());
}

void GlobalVarAreaViewer::regButton(QPushButton *btn, QString text, QBoxLayout *btnLay)
{
    btn->setText(text);
    btn->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);
    btnLay->addWidget(btn);
}

void GlobalVarAreaViewer::onAddVarClicked()
{
    addVarDialog->show();
}

void GlobalVarAreaViewer::onSuccessAddVar(Var *var)
{
    GlobalVarArea::addVar(var);
    updateVarText();
}

void GlobalVarAreaViewer::onDelVarClicked()
{
    delVarDialog->show();
}

void GlobalVarAreaViewer::onSuccessDelVar(QString idDelVar)
{
    GlobalVarArea::deleteById(idDelVar);
    updateVarText();
}

void GlobalVarAreaViewer::onShowVarsClicked()
{
    showVarsDialog->show();
}
