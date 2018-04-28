#include "cell.h"

#include <QtDebug>

QHash<qint32, QColor> Cell::ColorHashFill()
{
    QHash<qint32, QColor> tmp;

    tmp.insert(0, Qt::white);
    tmp.insert(1, Qt::black);
    tmp.insert(2, Qt::green);
    tmp.insert(3, Qt::red);
    tmp.insert(4, Qt::blue);

    return tmp;
}

QHash<qint32, QColor> Cell::ColorHash = Cell::ColorHashFill();

Cell::Cell(quint32 x, quint32 y, CELLTYPE t)
{
    point = QPoint(x,y);
    type = (CELLTYPE)t;
}

void Cell::setPoint(QPoint p)
{
    point = p;
}

void Cell::setType(quint32 st)
{
    type = (CELLTYPE)st;
    //this->setBrush(QBrush(Qt::black));
    //qDebug() << "Color is " << Cell::ColorHash[type];
    if (Cell::ColorHash[type].isValid()) {
        this->setBrush(QBrush(Cell::ColorHash[type]));
    }
    else {
        qDebug() << "Color is invalid";
        this->setBrush(QBrush(Cell::ColorHash[4]));
    }
}
