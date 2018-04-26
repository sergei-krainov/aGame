#include "world.h"
#include "cell.h"
#include <QtDebug>

World::World()
{
    quint32 i,j;



    quint32 tile_map[columns][rows] = {
        1,0,1,0,1,0
    };


    for (i = 0; i < columns; ++i) {
        for (j = 0;j < rows; ++j) {
            //cells[i][j] = new Cell();
            //qDebug() << "i = " << i << "; j = " << j;
            //qDebug() << "Tile is " << tile_map[i][j];
            cells[i][j] = new Cell(i,j);
            cells[i][j]->setRect(i * TILESIDE, j * TILESIDE, TILESIDE, TILESIDE);
            cells[i][j]->setType(tile_map[i][j]);
        }
    }
}

Cell *World::getCell(quint32 x, quint32 y)
{
    return cells[x][y];
}

void World::setCell(Cell * cell)
{
    //cell->setType();

    quint32 x, y;
    x = cell->getPoint().x();
    y = cell->getPoint().y();

    this->cells[x][y]->setType(cell->getType());
    //this->cells[x][y]->setBrush(QBrush(Qt::red));
    //cell->getType();



    this->cells[x][y]->setType(cell->getType());
}
