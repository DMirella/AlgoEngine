#include "sortsettingsdialog.h"
#include "ui_sortsettingsdialog.h"

#include <QDebug>
#include "../globalvararea.h"

SortSettingsDialog::SortSettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortSettingsDialog)
{
    ui->setupUi(this);
}

SortSettingsDialog::~SortSettingsDialog()
{
    delete ui;
}

void SortSettingsDialog::initComboBox(QComboBox *cmb)
{
    cmb->clear();
    QList<QString> ids = GlobalVarArea::getIdVarsByClass(ClassVar::Array);
    foreach (QString it, ids) {
        cmb->addItem(it);
    }
}

void SortSettingsDialog::showEvent(QShowEvent *event)
{
    initComboBox(ui->inArrayComboBox);
    initComboBox(ui->outArrayComboBox);
}

void SortSettingsDialog::on_buttonBox_accepted()
{
    int inIndex = ui->inArrayComboBox->currentIndex();
    int outIndex = ui->outArrayComboBox->currentIndex();
    if(inIndex == -1){
        qDebug() << "SortSettingsDialog: input == -1";
        return;
    }
    if(outIndex == -1){
        qDebug() << "SortSettingsDialog: output == -1";
        return;
    }

    QString inIdVar = ui->inArrayComboBox->currentText();
    QString outIdVar = ui->outArrayComboBox->currentText();
    SortAlgorithmSettings settings;
    if(ui->incRadioButton->isChecked())settings.mode = SortMode::Increase;
    else settings.mode = SortMode::Decrease;
    settings.input.array = GlobalVarArea::getVarById(inIdVar);
    settings.output.array = GlobalVarArea::getVarById(outIdVar);

    emit successSet(settings);
}
