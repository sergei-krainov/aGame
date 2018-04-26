#include "cell.h"

void Cell::setPoint(QPoint p)
{
    point = p;
}

void Cell::setType(quint32 st)
{
    type = (CELLTYPE)st;
}


/* QHash<qint32, QString> initCellTypeHash() {
    QHash<qint32, QString> tmp;
    tmp.insert(0, "FREE");
    tmp.insert(1, "WALL");
    tmp.insert(2, "BOT");
    tmp.insert(3, "UNKNOWN");

    return tmp;
}

QHash<qint32, QString> CellTypeHash = initCellTypeHash(); */

