#include "blockviewer.h"
#include "additionqt.h"

#include <QSpacerItem>

BlockViewer::BlockViewer(QWidget *parent)
    : QGroupBox(parent)
{
    vLayout = new QVBoxLayout(this);
    vLayout->addStretch();

    setBackgroundColor(this, QColor(255, 255, 255));
}

void BlockViewer::addBlock(Block *block)
{
    vLayout->insertWidget(vLayout->count() - 1, block, 0, Qt::AlignLeft);
}
