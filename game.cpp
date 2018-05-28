#include "game.h"

#include <QtDebug>

Game::Game()
{
    _world = new World;
    _view = new WorldView(_world);

    timer = new QTimer();
    timer->setInterval(TIMEOUT);

    connect(timer, SIGNAL(timeout()),
            _view, SLOT(update()));

    connect(_view, SIGNAL(pauseSignal()),
            timer, SLOT(stop()));

    connect(_view, SIGNAL(startSignal()),
            timer, SLOT(start()));
}

void Game::start()
{
    //timer = new QTimer;

    Bot * bot1 = new Bot(4,2,_world);

    //QVector<qint32> * sur1;

    //bot1->getSurroundings();

    connect(timer, SIGNAL(timeout()),
            bot1, SLOT(MakeDecision()));



    //timer->start(TIMEOUT);

    //bot1->setType(BOT);
    //bot1->getPoint();

    //bot1->StepLeft();

    //bot1->StepRight();

    qDebug() << "Bot at " << bot1->getPoint();
    //qDebug() << "Bot type of " << bot1->getType();

    //bot1->StepRight();

    //qDebug() << "Bot at " << bot1->getPoint();
    //qDebug() << "Bot type of " << bot1->getType();

    //bot1->StepLeft();
    //bot1->StepDown();

    _view->update();
}
