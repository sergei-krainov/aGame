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

    quint32 DoStep(qint32, qint32);
    quint32 StepRight();
    quint32 StepLeft();
    quint32 StepUp();
    quint32 StepDown();
};

#endif // BOT_H
