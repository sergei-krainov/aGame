#include "world.h"
#include <QtDebug>

World::World()
{
    qint32 i,j;

    //QHash<qint32, QString> CellTypeHash;

    //QHash<qint32, QString> CellTypeHash;
    //World::CellTypeHash1.insert(0, "FREE");
    //World::CellTypeHash1.insert(1, "TEST");

    //QHash<qint32, QString>CellTypeHash = initCellTypeHash();
    CellTypeHash.insert(0, "FREE");
    CellTypeHash.insert(1, "WALL");
    CellTypeHash.insert(2, "BOT");
    CellTypeHash.insert(3, "UNKNOWN");

    qDebug() << "Type is" << CellTypeHash[1];

    qDebug() << "Type TEST is" << World::CellTypeHash1[0];

    qint32 tile_map[columns][rows] = {
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

//QHash<qint32, QString> World::CellTypeHash1;

QHash<qint32, QString> World::initCellTypeHash() {
    QHash<qint32, QString> tmp;
    tmp.insert(0, "FREE");
    tmp.insert(1, "WALL");
    tmp.insert(2, "BOT");
    tmp.insert(3, "UNKNOWN");

    return tmp;
}

QHash<qint32, QString> World::CellTypeHash1 = World::initCellTypeHash();

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

QString World::getCellType(qint32 x)
{
    qDebug() << "Type3 is" << CellTypeHash[x];

    return CellTypeHash[x];
}
