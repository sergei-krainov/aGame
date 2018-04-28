#ifndef WORLDVIEW_H
#define WORLDVIEW_H


#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include "world.h"

#define EVENTSWIDTH 200

class WorldView
{
private:
    QGraphicsScene * scene;
    QVBoxLayout * mainLayout;
    QGraphicsView * view;
    //QPlainTextEdit * eventsText;
    World * _world;
public:
    WorldView(World *world);
    void update();
};

#endif // WORLDVIEW_H
