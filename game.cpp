#include "game.h"

#include <QtDebug>

Game::Game()
{
    World * world = new World();
    WorldView * view = new WorldView(world);

    /* Cellmap.insert(0,"FREE");
    Cellmap.insert(1,"WALL");
    Cellmap.insert(2,"BOT");
    Cellmap.insert(3,"UNKNOWN"); */

    Bot * bot1 = new Bot(0,0,world);
    bot1->setType(BOT);
    //bot1->getPoint();
    qDebug() << "Type is..." << World::CellTypeHash1[1];
    qDebug() << "Type is.." << world->getCellType(0);

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
