#ifndef CELL_H
#define CELL_H

#include <QApplication>
#include <QGraphicsRectItem>
#include <QPoint>

enum CELLTYPE {FREE, WALL, BOT, UNKNOWN};

class Cell: public QGraphicsRectItem
{
private:
    //QPoint point;

protected:
    QPoint point;
    //enum CELLTYPE {FREE, WALL, BOT, UNKNOWN} type;
    enum CELLTYPE type;

public:
    Cell(quint32 x = 0, quint32 y = 0, CELLTYPE t = FREE) :
        point(QPoint(x,y)),type(t)
    {}

    QPoint getPoint() {return point;}
    void setPoint(QPoint);
    quint32 getType() {return type;}
    void setType(quint32);
};

#endif // CELL_H
