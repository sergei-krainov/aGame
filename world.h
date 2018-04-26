#ifndef WORLD_H
#define WORLD_H

#include "cell.h"
#include <QtGlobal>
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QObject>

#define WIDTH 800
#define HEIGHT 600
#define TILESIDE 25
#define NUMCELLS 100

class World : public QObject
{
    Q_OBJECT

private:
    static const qint32 columns = WIDTH/TILESIDE;
    static const qint32 rows    = HEIGHT/TILESIDE;
    //quint32 map[WIDTH/TILESIDE][HEIGHT/TILESIDE];
    Cell *cells[columns][rows];
    //QHash<qint32, QString> CellTypeHash1;
    //QHash<QString, QColor> CellColor;

    //QGraphicsRectItem * cells[columns][rows];

    //QGraphicsScene * scene;
    //QVBoxLayout * mainLayout;
    //QGraphicsView * view;
    //enum tile_type {EMPTY, WALL, BOT, UNKNOWN};
public:
    World();
    static QHash<qint32, QString> initCellTypeHash();
    QHash<qint32, QString> CellTypeHash;
    static QHash<qint32, QString> CellTypeHash1;
    qint32 getColumns() const {return columns;}
    qint32 getRows() const {return rows;}
    Cell *getCell(qint32, qint32);
    void setCell(Cell*);
    QString getCellType(qint32 x);
};


#endif // WORLD_H
