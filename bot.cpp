#include "bot.h"
#include "cell.h"
#include "world.h"

//Bot::Bot()
//{

//}

Bot::Bot(quint32 x, quint32 y, World *world)
{
    this->setPoint(QPoint(x,y));
    _world = world;
}

quint32 Bot::StepRight()
{
    quint32 x, y;
    //QPoint * p = this->getPoint();

    x = this->getPoint().x();
    y = this->getPoint().y();

    Cell * target = _world->getCell(x+1, y);
    if (target->getType() == FREE) {
        Bot * old = this;
        old->setType(FREE);
        _world->setCell(old);

        this->setPoint(QPoint(x+1,y));
        this->setType(BOT);

        _world->setCell(this);

    }
}
