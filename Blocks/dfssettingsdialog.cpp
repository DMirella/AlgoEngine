#include "dfssettingsdialog.h"
#include "ui_dfssettingsdialog.h"

DFSSettingsDialog::DFSSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DFSSettingsDialog)
{
    ui->setupUi(this);
}

DFSSettingsDialog::~DFSSettingsDialog()
{
    delete ui;
}
