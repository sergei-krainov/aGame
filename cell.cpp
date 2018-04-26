#include "cell.h"

void Cell::setPoint(QPoint p)
{
    point = p;
}

void Cell::setType(quint32 st)
{
    type = (CELLTYPE)st;
}
