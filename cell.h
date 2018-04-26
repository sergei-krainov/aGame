#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QHash>
#include "world.h"

//enum CELLTYPE {FREE, WALL, BOT, UNKNOWN};

//static QHash<qint32, QString> CellTypeHash;
//QHash<QString, QColor> CellColor;


class Cell: public QGraphicsRectItem
{
private:

protected:
    QPoint point;
    //enum CELLTYPE type;
    quint32 ntype;
    QString stype;

public:
    //Cell(qint32 x = 0, qint32 y = 0, qint32 t = 0) :
    //    point(QPoint(x,y)),stype(World::CellTypeHash1[t])
    //{}
    Cell(qint32 x = 0, qint32 y = 0, qint32 t = 0);

    QPoint getPoint() {return point;}
    void setPoint(QPoint);
    quint32 getType() {return ntype;}
    void setType(quint32);
};

#endif // CELL_H
