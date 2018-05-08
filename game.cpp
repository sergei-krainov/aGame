#include "game.h"

#include <QtDebug>

Game::Game()
{
    _world = new World;
    _view = new WorldView(_world);
}

void Game::start()
{
    Bot * bot1 = new Bot(0,0,_world);
    //bot1->setType(BOT);
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

    _view->update();
}
