#ifndef VIEWAREA_H
#define VIEWAREA_H

#include <QGroupBox>

#include "blockmanager.h"
#include "availableblocklist.h"

class ViewArea : public QGroupBox
{
public:
    ViewArea(QWidget *parent);
private:
    BlockManager *blockManager;
    QVBoxLayout *vLayout;
};

#endif // VIEWAREA_H
