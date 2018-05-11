#ifndef CELL_H
#define CELL_H

#include <QApplication>
#include <QGraphicsRectItem>
#include <QPoint>
#include <QBrush>

enum CELLTYPE {FREE, WALL, BOT, YUMMY, UNKNOWN};

class Cell : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    //QPoint point;
    //virtual ~Cell() {}

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
    qint32 getX() {return point.x();}
    qint32 getY() {return point.y();}
    void setPoint(QPoint);
    quint32 getType() {return type;}
    //qint32 getType();
    void setType(quint32);
};

#endif // CELL_H
