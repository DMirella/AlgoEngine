#ifndef DFSSETTINGSDIALOG_H
#define DFSSETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
class DFSSettingsDialog;
}

class DFSSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DFSSettingsDialog(QWidget *parent = 0);
    ~DFSSettingsDialog();

private:
    Ui::DFSSettingsDialog *ui;
};

#endif // DFSSETTINGSDIALOG_H
