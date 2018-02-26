#include "additionqt.h"

void setBackgroundColor(QWidget *widget, QColor color)
{
    widget->setAutoFillBackground(true);
    QPalette p = widget->palette();
    p.setColor(widget->backgroundRole(), color);
    widget->setPalette(p);
}
