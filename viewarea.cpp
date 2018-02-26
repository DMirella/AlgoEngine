#include "viewarea.h"

ViewArea::ViewArea(QWidget *parent)
    : QGroupBox(parent)
{
    BlockViewer *blockViewer = new BlockViewer(this);

    vLayout->addWidget(blockViewer);
    blockManager = new BlockManager(blockViewer, this);
}
