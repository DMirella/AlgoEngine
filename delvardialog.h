#ifndef DELVARDIALOG_H
#define DELVARDIALOG_H

#include <QDialog>
#include "Vars/var.h"

namespace Ui {
class DelVarDialog;
}

class DelVarDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DelVarDialog(QWidget *parent = 0);
    ~DelVarDialog();

private:
    Ui::DelVarDialog *ui;
    QList<QString> varIdsList;

    // QWidget interface
protected:
    void showEvent(QShowEvent *event);
signals:
    void successDelVar(QString idDelVar);
private slots:
    void on_buttonBox_accepted();
};

#endif // DELVARDIALOG_H
