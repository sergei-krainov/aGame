#ifndef BOT_H
#define BOT_H

#include "cell.h"
#include "world.h"

class Bot : public Cell
{
private:
    World * _world;
public:
    //Bot();
    //using Cell::Cell;
    Bot(quint32 x, quint32 y, World *world);

    quint32 StepRight();

};

#endif // BOT_H
