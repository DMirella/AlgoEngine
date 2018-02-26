#ifndef BLOCKVIEWER_H
#define BLOCKVIEWER_H

#include <QGroupBox>
#include <QLayout>
#include <QList>

#include "Blocks/block.h"

class BlockViewer : public QGroupBox
{
    Q_OBJECT
public:
    BlockViewer(QWidget *parent);
    void addBlock(Block *block);
private:
    QVBoxLayout *vLayout;
};

#endif // BLOCKVIEWER_H
