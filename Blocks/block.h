#ifndef BLOCK_H
#define BLOCK_H

#include <QGroupBox>
#include <QPushButton>
#include <QLabel>
#include <QDebug>
#include <QDialog>

#include "../Algorithms/algorithm.h"

class Block : public QGroupBox
{
    Q_OBJECT
public:
    Block(QWidget *parent);
    void setAlgorithm(Algorithm *_algo);
    ~Block();
    void doAlgorithm();

protected slots:
    void onSettingsButtonClicked();
    void onBlockClose();
protected:
    void setTitle(QString title);
    void setSettingsDialog(QDialog *_settingsDialog);

    QDialog *settingsDialog;

private:
    QLabel *titleLabel;
    QPushButton *settingsButton, *closeButton;
    Algorithm *algo;
signals:
    void closeMeManager(Block *me);
};

class BlockCreator{
public:
    virtual Block* create(QWidget *parent) = 0;
};

#endif // BLOCK_H
