#ifndef CELL_H
#define CELL_H

#include <QGraphicsRectItem>
#include <QHash>

enum CELLTYPE {FREE, WALL, BOT, UNKNOWN};

//static QHash<qint32, QString> CellTypeHash;
//QHash<QString, QColor> CellColor;


class Cell: public QGraphicsRectItem
{
private:

protected:
    QPoint point;
    enum CELLTYPE type;

public:
    Cell(qint32 x = 0, qint32 y = 0, CELLTYPE t = FREE) :
        point(QPoint(x,y)),type(t)
    {}

    QPoint getPoint() {return point;}
    void setPoint(QPoint);
    quint32 getType() {return type;}
    void setType(quint32);
};

#endif // CELL_H
