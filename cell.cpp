#include "cell.h"

Cell::Cell(qint32 x = 0, qint32 y = 0, qint32 t = 0)
{
    //point(QPoint(x,y)),stype(World::CellTypeHash1[t])
    point = QPoint(x,y);
    ntype = t;
    stype = World::CellTypeHash1[t];
}

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

