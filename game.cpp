#include "game.h"

#include <QtDebug>

Game::Game()
{
    World * world = new World();
    WorldView * view = new WorldView(world);

    Bot * bot1 = new Bot(0,0,world);
    bot1->setType(BOT);
    //bot1->getPoint();

    //bot1->StepLeft();

    bot1->StepRight();

    qDebug() << "Bot at " << bot1->getPoint();
    qDebug() << "Bot type of " << bot1->getType();

    bot1->StepRight();

    qDebug() << "Bot at " << bot1->getPoint();
    qDebug() << "Bot type of " << bot1->getType();

    bot1->StepLeft();
    bot1->StepDown();

    view->update();
}
