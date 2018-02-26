#ifndef ADDVARDIALOG_H
#define ADDVARDIALOG_H

#include <QDialog>
#include "Vars/var.h"

namespace Ui {
class AddVarDialog;
}

class AddVarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddVarDialog(QWidget *parent = 0);
    ~AddVarDialog();

private:
    Ui::AddVarDialog *ui;
signals:
    void successAddVar(Var *var);
private slots:
    void on_buttonBox_accepted();

    // QWidget interface
protected:
    void showEvent(QShowEvent *event);
};

#endif // ADDVARDIALOG_H
