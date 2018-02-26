#ifndef SORTSETTINGSDIALOG_H
#define SORTSETTINGSDIALOG_H

#include <QDialog>
#include <QComboBox>
#include "../Algorithms/sortalgorithm.h"

namespace Ui {
class SortSettingsDialog;
}

class SortSettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortSettingsDialog(QWidget *parent = 0);
    ~SortSettingsDialog();

private:
    void initComboBox(QComboBox *cmb);

    Ui::SortSettingsDialog *ui;
signals:
    void successSet(SortAlgorithmSettings settings);

    // QWidget interface
protected:
    void showEvent(QShowEvent *event);
private slots:
    void on_buttonBox_accepted();
};

#endif // SORTSETTINGSDIALOG_H
