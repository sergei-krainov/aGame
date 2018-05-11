#ifndef BOT_H
#define BOT_H

#include <QVector>
#include "cell.h"
#include "world.h"

#define VISIBILITY 2
#define AREA (VISIBILITY*2)^2

class Bot : public Cell
{
    Q_OBJECT

private:
    World * _world;

    /* QVector<qint32> surroundings{ 0,-2,
                                 -1,-1,
                                  0,-1,
                                  1,-1,
                                 -2,0,
                                 -1,0,
                                  1,0,
                                  2,0,
                                 -1,1,
                                  0,1,
                                  1,1,
                                  0,2,
                                }; */
    static QVector< QVector<qint32> > surroundings;
    bool withinCircle(qint32, qint32);



public:
    //Bot();
    //using Cell::Cell;
    Bot(quint32 x, quint32 y, World *world);
    static QVector<QVector<qint32> > initSurroundings();

    quint32 DoStep(qint32, qint32);
    QVector<qint32> * getSurroundings();

public slots:
    quint32 StepRight();
    quint32 StepLeft();
    quint32 StepUp();
    quint32 StepDown();
    quint32 MakeDecision();
};

#endif // BOT_H
