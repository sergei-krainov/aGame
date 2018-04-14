#ifndef WORLDVIEW_H
#define WORLDVIEW_H


#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QGraphicsView>
#include "world.h"

class WorldView
{
private:
    QGraphicsScene * scene;
    QVBoxLayout * mainLayout;
    QGraphicsView * view;
    World * _world;
public:
    WorldView(World * world);
    void update();
};

#endif // WORLDVIEW_H
