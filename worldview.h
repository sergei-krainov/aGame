#ifndef WORLDVIEW_H
#define WORLDVIEW_H


#include <QGraphicsScene>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QPlainTextEdit>
#include <QGraphicsProxyWidget>
#include <QMenuBar>
#include <QPushButton>
#include <QGroupBox>
#include <QHBoxLayout>
#include "world.h"

#define EVENTSWIDTH 200
#define BUTTONSH 50

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
    QGroupBox * buttons;
    QHBoxLayout * buttonsLayout;
    QPushButton * startB;
    QPushButton * pauseB;
    QPushButton * stopB;
    //QPlainTextEdit * eventsText;
    World * _world;
    static QHash<qint32, QColor> ColorHash;

    QAction * openAct;
    QAction * closeAct;

    void createActions();
    void createMenus();

public:
    WorldView(World *world);

    static QHash<qint32, QColor> ColorHashFill();

public slots:
    void update();
    //void copen();
    void close();
};

#endif // WORLDVIEW_H
