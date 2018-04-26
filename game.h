#ifndef GAME_H
#define GAME_H

#include "worldview.h"
#include "bot.h"

#define WIDTH 800
#define HEIGHT 600
#define TILESIDE 25
#define NUMCELLS 100

class Game
{
private:
    //static const quint32 columns = WIDTH/TILESIDE;
    //static const quint32 rows    = HEIGHT/TILESIDE;
    //quint32 map[WIDTH/TILESIDE][HEIGHT/TILESIDE];
    //Cell *cells[columns][rows];
    //QMap<int, QString> Cellmap;
    //static QHash<qint32, QString> CellTypeHash;
    //QHash<QString, QColor> CellColor;
public:
    Game();
    //Cell *cells[columns][rows];
};

#endif // GAME_H
