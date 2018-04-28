#include "worldview.h"
#include <QtDebug>

WorldView::WorldView(World * world)
{
    _world = world;

    qint32 i, j, tileside, columns, rows;

    scene = new QGraphicsScene;
    mainLayout = new QVBoxLayout;
    tileside = _world->getTileside();
    columns  = _world->getColumns();
    rows     = _world->getRows();

    QPlainTextEdit * eventsText = _world->eventsText;

    for (i = 0; i < columns; ++i) {
            for (j = 0; j < rows; ++j) {
                //Cell * tmp = _world->getCell(i,j);

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
                scene->addItem(_world->getCell(i,j));
            }

    }


    //eventsText = scene->addText("Hello");
    //eventsText
    //eventsText->setPos(i * world->getTileside(), 0);

    //eventsText = new QPlainTextEdit();
    //eventsText->anchorAt(QPoint(i * world->getTileside(),0));
    /* QFont f1 = eventsText->font();
    QFontMetrics fm(f1);
    f1.setPointSize(18);
    eventsText->setFont(f1); */

    //eventsText->setFont("Helvetica Neue");

    QFont hnFont("Helvetica [Cronyx]", 12);
    eventsText->setFont(hnFont);

    eventsText->document()->setPlainText("Hello");
    eventsText->setGeometry(i * tileside, 0, EVENTSWIDTH, rows * tileside);
    //eventsText->setMinimumSize(50, 50);

    eventsText->appendPlainText("Text");




    scene->addWidget(_world->eventsText);


    //scene->addText(eventsText);



    //mainLayout = new QVBoxLayout;
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

    mainLayout->addWidget(view);
    view->show();
    //view->setFixedSize(800, 600);
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
