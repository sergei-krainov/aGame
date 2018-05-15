#include "worldview.h"
#include <QtDebug>

WorldView::WorldView(World * world)
{
    _world = world;

    qint32 i, j, tileside, columns, rows, menuHeight, menuWidth;

    scene = new QGraphicsScene;
    mainLayout = new QVBoxLayout;
    menuBar = new QMenuBar;
    menuBar->setGeometry(0,0,WIDTH + EVENTSWIDTH,20);

    menu = menuBar->addMenu("Test");
    menu2 = menuBar->addMenu("Test2");
    menu3 = menuBar->addMenu("Test3");
    //menu->setGeometry(0,0,100,100);
    QAction * act1 = menu->addAction("Test100");

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, _world, _world->openMapFile);

    menu->addAction(openAct);

    //scene->addWidget(menuBar);
    QGraphicsProxyWidget * proxyWidget = scene->addWidget(menuBar);
    proxyWidget->setZValue(100);

    //scene->addWidget(menuBar);

    qDebug() << "Size is " << menuBar->size().height();
    menuHeight = menuBar->size().height();
    menuWidth = menuBar->size().width();


    tileside = _world->getTileside();
    columns  = _world->getColumns();
    rows     = _world->getRows();

    QPlainTextEdit * eventsText = _world->eventsText;

    //qDebug() << "Test1" << columns;

    for (j = 0; j < rows; ++j) {
        for (i = 0; i < columns; ++i) {
            qDebug() << "View i:j" << i << j;
            Cell * tmp = _world->getCell(i,j);
            if (tmp == NULL)
                qDebug() << "Here we go";

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
    //scene->addWidget(menuBar);
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

/* void WorldView::copen()
{
    qDebug() << "Open";

    QString fileName = QFileDialog::getOpenFileName(0, tr("Open the file"),".");
    QFile file(fileName);
    //currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(0, "Warning", tr("Cannot open file: ") + file.errorString());
        return;
    }
    //setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    qDebug() << text;
    //ui->textEdit->setText(text);
    file.close();
} */

QHash<qint32, QColor> WorldView::ColorHashFill()
{
    QHash<qint32, QColor> tmp;

    tmp.insert(FREE, Qt::white);
    tmp.insert(WALL, Qt::black);
    tmp.insert(BOT, Qt::green);
    tmp.insert(YUMMY, Qt::red);
    tmp.insert(UNKNOWN, Qt::blue);

    return tmp;
}

QHash<qint32, QColor> WorldView::ColorHash = WorldView::ColorHashFill();
