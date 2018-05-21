#ifndef GAME_H
#define GAME_H

#include <QTimer>
#include "worldview.h"
#include "bot.h"

#define WIDTH 800
#define HEIGHT 600
#define TILESIDE 25
#define NUMCELLS 100
#define TIMEOUT 1000

class Game : public QObject
{

private:
    //static const quint32 columns = WIDTH/TILESIDE;
    //static const quint32 rows    = HEIGHT/TILESIDE;
    //quint32 map[WIDTH/TILESIDE][HEIGHT/TILESIDE];
    //Cell *cells[columns][rows];
    //QMap<int, QString> Cellmap;
    //static QHash<qint32, QString> CellTypeHash;
    //QHash<QString, QColor> CellColor;
    World * _world;
    WorldView * _view;
    QTimer * timer;
public:
    Game();
    void start();
    //Cell *cells[columns][rows];
public slots:
    void pause();
};

#endif // GAME_H
