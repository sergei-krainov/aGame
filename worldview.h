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
#include <QPixmap>
#include <QColorDialog>
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
    bool running;

signals:
    void pauseSignal();
    void startSignal();

public:
    WorldView(World *world);

    static QHash<qint32, QColor> ColorHashFill();

public slots:
    void update();
    //void copen();
    void close();
    void pause();
    void start();
};

#endif // WORLDVIEW_H
