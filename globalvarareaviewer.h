#ifndef GLOBALVARAREAVIEWER_H
#define GLOBALVARAREAVIEWER_H

#include <QGroupBox>
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include "Vars/var.h"

class GlobalVarAreaViewer : public QGroupBox
{
    Q_OBJECT
public:
    GlobalVarAreaViewer(QWidget *parent);
    void updateVarText();
private:
    void regButton(QPushButton *btn, QString text, QBoxLayout *btnLay);

    QLabel *varTitles;
    QPushButton *addVarButton, *delVarButton, *showVarsButton;
    QDialog *addVarDialog;
    QDialog *delVarDialog;
    QDialog *showVarsDialog;
private slots:
    void onAddVarClicked();
    void onSuccessAddVar(Var *var);
    void onDelVarClicked();
    void onSuccessDelVar(QString idDelVar);
    void onShowVarsClicked();
};

#endif // GLOBALVARAREAVIEWER_H
