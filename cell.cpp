#include "cell.h"

QHash<qint32, QColor> Cell::ColorHashFill()
{
    QHash<qint32, QColor> tmp;

    tmp.insert(0, Qt::white);
    tmp.insert(1, Qt::black);
    tmp.insert(2, Qt::red);
    tmp.insert(3, Qt::blue);

    return tmp;
}

QHash<qint32, QColor> Cell::ColorHash = Cell::ColorHashFill();

Cell::Cell(quint32 x, quint32 y, CELLTYPE t)
{
    point = QPoint(x,y);
    type = (CELLTYPE)t;

    //ColorHash.insert(0, Qt::white);
        //ColorHash.insert(1, Qt::black);
        //ColorHash.insert(2, Qt::red);
        //ColorHash.insert(3, Qt::blue);
}

void Cell::setPoint(QPoint p)
{
    point = p;
}

void Cell::setType(quint32 st)
{
    type = (CELLTYPE)st;
    //this->setBrush(QBrush(Qt::black));
    this->setBrush(QBrush(Cell::ColorHash[type]));
}
