#ifndef WORLDVIEW_H
#define WORLDVIEW_H


#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include <QMenuBar>
#include "world.h"

#define EVENTSWIDTH 200

class WorldView : public QObject
{
    Q_OBJECT

private:
    QGraphicsScene * scene;
    QVBoxLayout * mainLayout;
    QGraphicsView * view;
    QMenuBar * menuBar;
    QMenu * menu;
    QMenu * menu2;
    QMenu * menu3;
    //QPlainTextEdit * eventsText;
    World * _world;
    static QHash<qint32, QColor> ColorHash;

public:
    WorldView(World *world);

    static QHash<qint32, QColor> ColorHashFill();

public slots:
    void update();
};

#endif // WORLDVIEW_H
