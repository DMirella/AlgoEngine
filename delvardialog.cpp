#include "delvardialog.h"
#include "ui_delvardialog.h"
#include "delvardialog.h"
#include "globalvararea.h"

#include <QListWidgetItem>
#include <QDebug>

DelVarDialog::DelVarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DelVarDialog)
{
    ui->setupUi(this);
}

DelVarDialog::~DelVarDialog()
{
    delete ui;
}

void DelVarDialog::showEvent(QShowEvent *event)
{
    ui->varListView->clear();
    varIdsList = GlobalVarArea::getIds();
    foreach (QString it, varIdsList) {
        QListWidgetItem *itm = new QListWidgetItem;
        itm->setText(it);
        ui->varListView->addItem(itm);
    }
}

void DelVarDialog::on_buttonBox_accepted()
{
    int index = ui->varListView->currentRow();
    if(index >= 0){
        emit successDelVar(varIdsList.at(index));
    }
}
