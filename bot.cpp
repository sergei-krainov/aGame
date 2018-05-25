#include "bot.h"
#include <QtDebug>

//Bot::Bot()
//{

//}

bool Bot::withinCircle(qint32 x, qint32 y)
{
    return (sqrt(pow(x,2) + pow(y,2)) <= VISIBILITY);
}

Bot::Bot(quint32 x, quint32 y, World *world)
{
    this->setPoint(QPoint(x,y));
    this->setType(BOT);
    _world = world;

    _world->setCell(this);

    //area = pow(VISIBILITY*2,2);

    qDebug() << "Area is " << AREA;

    surroundings.reserve(AREA);

    for (qint32 x = -VISIBILITY;x <= VISIBILITY;++x) {
        for (qint32 y = -VISIBILITY;y <= VISIBILITY;++y) {
            if (withinCircle(x,y))
                surroundings.append(QVector<qint32>{x,y});
        }
    }

    //surroundings = new QVector< QVector<qint32> >(12);
    //surroundings->append(QVector<qint32>{0,-2});
}

/* QVector<QVector<qint32> > Bot::initSurroundings()
{
    QVector< QVector<qint32> > tmp;// = new QVector< QVector<qint32> >(12);;
    tmp.reserve(AREA);

    for (qint32 x = -VISIBILITY;x <= VISIBILITY;++x) {
        for (qint32 y = -VISIBILITY;y <= VISIBILITY;++y) {
            tmp.append(QVector<qint32>{x,y});
        }
    }

    //tmp.append(QVector<qint32>{1,-2});

    return tmp;
}

QVector<QVector<qint32> > Bot::surroundings = Bot::initSurroundings(); */

quint32 Bot::DoStep(qint32 xbias, qint32 ybias)
{
    qint32 x, y, nx, ny;
    Cell * target;


    //x = this->getPoint().x();
    //y = this->getPoint().y();

    x = this->getX();
    y = this->getY();

    nx = x + xbias;
    ny = y + ybias;

    //qDebug() << "Here?" << nx << ny;

    if (nx < 0 || nx >= _world->getColumns())
        return 1;

    if (ny < 0 || ny >= _world->getRows())
        return 1;

    target = _world->getCell(nx, ny);

    if (target->getType() == FREE) {
        Bot * old = this;
        old->setType(FREE);
        _world->setCell(old);

        this->setPoint(QPoint(nx,ny));
        this->setType(BOT);

        _world->setCell(this);

        //_world->eventsText->appendPlainText("Just did the step!The QPlainTextEdit class provides a widget that is used to edit and display plain text\n");
    }
    else {
        return 1;
    }

    return 0;
}

QVector<qint32> *Bot::getSurroundings()
{
    qint32 x, y, nx, ny;
    Cell * tmpCell;
    QVector<qint32> * vec = new QVector<qint32>;
    vec->reserve(AREA);


    x = this->getX();
    y = this->getY();

    for (QVector< QVector<qint32> >::const_iterator sit = surroundings.begin(); sit != surroundings.end(); ++sit) {

        nx = x + (*sit)[0];
        ny = y + (*sit)[1];

        tmpCell = _world->getCell(nx, ny);

        if (tmpCell == NULL || withinCircle(nx,ny) == 0)
            vec->append(-1);
        else
            vec->append(tmpCell->getType());

    }

    return vec;
}

quint32 Bot::StepRight()
{
    //qDebug() << "Here?";
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

quint32 Bot::MakeDecision()
{
    QVector<qint32> * vec = getSurroundings();

    qDebug() << "MakeDecision" << this->getX() << this->getY();

    if (this->StepRight() != 0) {
        if (this->StepDown() != 0) {
            if (this->StepLeft() != 0) {
                this->StepUp();
            }
        }
    }

    //_world->eventsText->appendPlainText("Just did the step!The QPlainTextEdit class provides a widget that is used to edit and display plain text\n");
    _world->_eventsText->append("Just did the step!The QPlainTextEdit class provides a widget that is used to edit and display plain text\n");


    return 0;
}
