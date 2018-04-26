#ifndef WORLD_H
#define WORLD_H

#include "cell.h"
#include <QtGlobal>
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHash>

#define WIDTH 800
#define HEIGHT 600
#define TILESIDE 25
#define NUMCELLS 100

class World
{
private:
    static const qint32 columns = WIDTH/TILESIDE;
    static const qint32 rows    = HEIGHT/TILESIDE;
    //quint32 map[WIDTH/TILESIDE][HEIGHT/TILESIDE];
    Cell *cells[columns][rows];

    //QHash<qint32, QColor> ColorHash;

    //QGraphicsRectItem * cells[columns][rows];

    //QGraphicsScene * scene;
    //QVBoxLayout * mainLayout;
    //QGraphicsView * view;
    //enum tile_type {EMPTY, WALL, BOT, UNKNOWN};
public:
    World();
    qint32 getColumns() {return columns;}
    qint32 getRows() {return rows;}
    Cell *getCell(qint32, qint32);
    void setCell(Cell*);
};

#endif // WORLD_H
