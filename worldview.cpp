#include "worldview.h"
#include <QtDebug>

WorldView::WorldView(World * world)
{
    _world = world;

    qint32 i, j, tileside, columns, rows, menuHeight;

    scene = new QGraphicsScene;
    mainLayout = new QVBoxLayout;
    menuBar = new QMenuBar;
    menuBar->setGeometry(0,0,WIDTH + EVENTSWIDTH,20);
    menu = menuBar->addMenu("Test");
    menu2 = menuBar->addMenu("Test2");
    menu3 = menuBar->addMenu("Test3");
    //menu->setGeometry(0,0,100,100);
    QAction * act = menu->addAction("Test100");

    scene->addWidget(menuBar);

    qDebug() << "Size is " << menuBar->size().height();
    menuHeight = menuBar->size().height();



    tileside = _world->getTileside();
    columns  = _world->getColumns();
    rows     = _world->getRows();

    QPlainTextEdit * eventsText = _world->eventsText;

    for (i = 0; i < columns; ++i) {
        for (j = 0; j < rows; ++j) {
            Cell * tmp = _world->getCell(i,j);

            tmp->setRect(i * TILESIDE, j * TILESIDE + menuHeight, TILESIDE, TILESIDE);
            tmp->setBrush(QBrush(ColorHash[tmp->getType()]));

            scene->addItem(tmp);
        }

    }

    QFont hnFont("Helvetica [Cronyx]", 12);
    eventsText->setFont(hnFont);

    eventsText->document()->setPlainText("Hello");
    eventsText->setGeometry(i * tileside, menuHeight, EVENTSWIDTH, rows * tileside);
    //eventsText->setMinimumSize(50, 50);

    eventsText->appendPlainText("Text");




    scene->addWidget(_world->eventsText);


    //scene->addText(eventsText);



    //mainLayout = new QVBoxLayout;
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

    //mainLayout->addWidget(menuBar);
    mainLayout->addWidget(view);

    view->show();
    //menuBar->show();
    //view->setFixedSize(800, 600);
}

void WorldView::update()
{
    // _world->getCell(i,j)->setBrush(QBrush(ColorHash1[_world->getCell(i,j)->getType()]));
    //Cell * tmpCell = _world->changedCells->pop();

    while(! _world->changedCells->isEmpty()) {
        Cell * tmpCell = _world->changedCells->pop();
        tmpCell->setBrush(QBrush(ColorHash[tmpCell->getType()]));
    }

    view->update();
}

QHash<qint32, QColor> WorldView::ColorHashFill()
{
    QHash<qint32, QColor> tmp;

    tmp.insert(0, Qt::white);
    tmp.insert(1, Qt::black);
    tmp.insert(2, Qt::green);
    tmp.insert(3, Qt::red);
    tmp.insert(4, Qt::blue);

    return tmp;
}

QHash<qint32, QColor> WorldView::ColorHash = WorldView::ColorHashFill();
