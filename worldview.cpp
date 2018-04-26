#include "worldview.h"
#include <QtDebug>

WorldView::WorldView(World * world)
{
    _world = world;

    qint32 i, j;
    scene = new QGraphicsScene;

    for (i = 0; i < world->getColumns(); ++i) {
            for (j = 0; j < world->getRows(); ++j) {
                //Cell * tmp = world->getCell(i,j);

                /* //qDebug() << "i = " << i << "; j = " << j;
                //qDebug() << "Type is " << tmp->getType();

                switch(tmp->getType()) {
                case WALL:
                    tmp->setBrush(QBrush(Qt::black));
                    break;
                case FREE:
                    tmp->setBrush(QBrush(Qt::white));
                    break;
                case BOT:
                    tmp->setBrush(QBrush(Qt::red));
                    break;
                default:
                    tmp->setBrush(QBrush(Qt::blue));
                    break;
                } */

                //scene->addItem(tmp);
                scene->addItem(world->getCell(i,j));
            }
    }



    mainLayout = new QVBoxLayout;
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

    mainLayout->addWidget(view);
    view->show();
    view->setFixedSize(800, 600);
}

void WorldView::update()
{
    /* qint32 i, j;

    for (i = 0; i < _world->getColumns(); ++i) {
            for (j = 0; j < _world->getRows(); ++j) {
                Cell * tmp = _world->getCell(i,j);

                switch(tmp->getType()) {
                case WALL:
                    tmp->setBrush(QBrush(Qt::black));
                    break;
                case FREE:
                    tmp->setBrush(QBrush(Qt::white));
                    break;
                case BOT:
                    tmp->setBrush(QBrush(Qt::red));
                    break;
                default:
                    tmp->setBrush(QBrush(Qt::blue));
                    break;
                }
            }
    } */

    view->update();
}
