#ifndef CELL_H
#define CELL_H

#include <QApplication>
#include <QGraphicsRectItem>
#include <QPoint>
#include <QBrush>

enum CELLTYPE {FREE, WALL, BOT, YUMMY, UNKNOWN};

class Cell: public QGraphicsRectItem
{
private:
    //QPoint point;

protected:
    QPoint point;
    enum CELLTYPE type;
    //static QHash<qint32, QColor> ColorHash;

public:
    //Cell(quint32 x = 0, quint32 y = 0, CELLTYPE t = FREE) :
    //    point(QPoint(x,y)),type(t)
    //{}
    //static QHash<qint32, QColor> ColorHashFill();

    Cell(quint32 x = 0, quint32 y = 0, CELLTYPE t = FREE);

    QPoint getPoint() {return point;}
    void setPoint(QPoint);
    quint32 getType() {return type;}
    void setType(quint32);
};

#endif // CELL_H
