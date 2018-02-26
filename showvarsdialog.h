#ifndef SHOWVARSDIALOG_H
#define SHOWVARSDIALOG_H

#include <QDialog>

namespace Ui {
class ShowVarsDialog;
}

class ShowVarsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowVarsDialog(QWidget *parent = 0);
    ~ShowVarsDialog();

private:
    Ui::ShowVarsDialog *ui;

    // QWidget interface
protected:
    void showEvent(QShowEvent *event);
};

#endif // SHOWVARSDIALOG_H
