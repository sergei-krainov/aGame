#include "game.h"

#include <QtDebug>

Game::Game()
{
    _world = new World;
    _view = new WorldView(_world);
}

void Game::start()
{
    timer = new QTimer;

    Bot * bot1 = new Bot(0,0,_world);

    //QVector<qint32> * sur1;

    //bot1->getSurroundings();


    connect(timer, SIGNAL(timeout()),
            bot1, SLOT(MakeDecision()));

    connect(timer, SIGNAL(timeout()),
            _view, SLOT(update()));

    timer->start(TIMEOUT);

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
