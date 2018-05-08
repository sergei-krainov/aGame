#include "cell.h"

#include <QtDebug>

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
    //if (Cell::ColorHash[type].isValid()) {
    //    this->setBrush(QBrush(Cell::ColorHash[type]));
    //}
    //else {
    //    qDebug() << "Color is invalid";
    //    this->setBrush(QBrush(Cell::ColorHash[4]));
    //}
}
