#include "addvardialog.h"
#include "ui_addvardialog.h"
#include "globalvararea.h"

#include <QDebug>

AddVarDialog::AddVarDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddVarDialog)
{
    ui->setupUi(this);

}

AddVarDialog::~AddVarDialog()
{
    delete ui;
}

void AddVarDialog::on_buttonBox_accepted()
{
    int index = ui->varComboBox->currentIndex();
    if(index != -1){
        emit successAddVar(GlobalVarArea::createVarAt(index, ui->nameEdit->text()));
    }
}

void AddVarDialog::showEvent(QShowEvent *event)
{
    //Load varTitles
    ui->varComboBox->clear();
    QList<QString> varTitles = GlobalVarArea::getVarTitles();
    foreach (QString it, varTitles) {
        ui->varComboBox->addItem(it);
    }
}
