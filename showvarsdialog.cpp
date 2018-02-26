#include "showvarsdialog.h"
#include "ui_showvarsdialog.h"

#include "globalvararea.h"

ShowVarsDialog::ShowVarsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowVarsDialog)
{
    ui->setupUi(this);
}

ShowVarsDialog::~ShowVarsDialog()
{
    delete ui;
}

void ShowVarsDialog::showEvent(QShowEvent *event)
{
    ui->varsTableWidget->setRowCount(0);
    QList<VarTextDescription> varsDescription = GlobalVarArea::getVarTextDescriptions();
    int lastRow = 0;
    foreach(VarTextDescription it, varsDescription){
        ui->varsTableWidget->insertRow(lastRow);
        ui->varsTableWidget->setItem(lastRow, 0, new QTableWidgetItem(it.type));
        ui->varsTableWidget->setItem(lastRow, 1, new QTableWidgetItem(it.id));
        ui->varsTableWidget->setItem(lastRow, 2, new QTableWidgetItem(it.value));
    }
}
