#include "world.h"
#include "cell.h"
#include <QtDebug>

World::World()
{
    quint32 i,j;

    //QHash<qint32, QColor> ColorHash
    //ColorHash.insert(0, Qt::white);
    //ColorHash.insert(1, Qt::black);
    //ColorHash.insert(2, Qt::red);
    //ColorHash.insert(3, Qt::blue);

    eventsText = new QPlainTextEdit();;

    quint32 tile_map[columns][rows] = {
        1,0,1,0,1,0,5,2,3,6
    };


    for (i = 0; i < columns; ++i) {
        for (j = 0;j < rows; ++j) {
            //cells[i][j] = new Cell();
            //qDebug() << "i = " << i << "; j = " << j;
            //qDebug() << "Tile is " << tile_map[i][j];
            cells[i][j] = new Cell(i,j);
            cells[i][j]->setRect(i * TILESIDE, j * TILESIDE, TILESIDE, TILESIDE);
            cells[i][j]->setType(tile_map[i][j]);
            //cells[i][j]->setBrush(QBrush(ColorHash[tile_map[i][j]]));
        }
    }
}

Cell *World::getCell(qint32 x, qint32 y)
{
    return cells[x][y];
}

void World::setCell(Cell * cell)
{
    //cell->setType();

    qint32 x, y;
    x = cell->getPoint().x();
    y = cell->getPoint().y();

    this->cells[x][y]->setType(cell->getType());
    //this->cells[x][y]->setBrush(QBrush(Qt::red));
    //cell->getType();



    this->cells[x][y]->setType(cell->getType());
}
