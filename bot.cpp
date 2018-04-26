#include "bot.h"
#include <QtDebug>

//Bot::Bot()
//{

//}

Bot::Bot(quint32 x, quint32 y, World *world)
{
    this->setPoint(QPoint(x,y));
    _world = world;
}

quint32 Bot::DoStep(qint32 xbias, qint32 ybias)
{
    qint32 x, y, nx, ny;
    //QPoint * p = this->getPoint();
    Cell * target;


    x = this->getPoint().x();
    y = this->getPoint().y();

    nx = x + xbias;
    ny = y + ybias;

    qDebug() << "Here?";

    if (nx < 0 || nx > _world->getColumns())
        return 1;

    if (ny < 0 || ny > _world->getRows())
        return 1;

    target = _world->getCell(nx, ny);

    if (target->getType() == FREE) {
        Bot * old = this;
        old->setType(FREE);
        _world->setCell(old);

        this->setPoint(QPoint(nx,ny));
        this->setType(BOT);

        _world->setCell(this);
    }
    else {
        return 1;
    }

    return 0;
}

quint32 Bot::StepRight()
{
    return (this->DoStep(1,0));
}

quint32 Bot::StepLeft()
{
    return (this->DoStep(-1,0));
}

quint32 Bot::StepUp()
{
    return (this->DoStep(0, -1));
}

quint32 Bot::StepDown()
{
    return (this->DoStep(0, 1));
}
