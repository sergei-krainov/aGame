#include "worldview.h"
#include <QtDebug>

void WorldView::createActions()
{
    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    //menu->addAction(openAct);
    connect(openAct, &QAction::triggered, _world, _world->openMapFile);


    closeAct = new QAction(tr("&Close..."), this);
    closeAct->setShortcuts(QKeySequence::Close);
    closeAct->setStatusTip(tr("Close an app"));
    //menu->addAction(closeAct);
    connect(closeAct, &QAction::triggered, this, this->close);

    connect(_world, World::newMap, this, this->update);
}

void WorldView::createMenus()
{
    menuBar = new QMenuBar;
    menuBar->setGeometry(0,0,WIDTH + EVENTSWIDTH,20);

    menu = menuBar->addMenu("File");
    menu->addAction(openAct);

    //menu = menuBar->addMenu("Close");
    menu->addAction(closeAct);

    menu2 = menuBar->addMenu("Test2");
    menu3 = menuBar->addMenu("Test3");
}

WorldView::WorldView(World * world)
{
    _world = world;

    qint32 i, j, tileside, columns, rows, menuHeight, menuWidth;

    scene = new QGraphicsScene;
    mainLayout = new QVBoxLayout;
    QGraphicsProxyWidget * proxyWidget = new QGraphicsProxyWidget;
    QPlainTextEdit * eventsText = new QPlainTextEdit;

    QFont hnFont("Helvetica [Cronyx]", 12);


    createActions();
    createMenus();


    proxyWidget = scene->addWidget(menuBar);
    proxyWidget->setZValue(100);

    menuHeight = menuBar->size().height();
    menuWidth = menuBar->size().width();


    tileside = _world->getTileside();
    columns  = _world->getColumns();
    rows     = _world->getRows();

    eventsText = _world->eventsText;

    for (j = 0; j < rows; ++j) {
        for (i = 0; i < columns; ++i) {
            Cell * tmp = _world->getCell(i,j);

            if (tmp != NULL) {
                tmp->setRect(i * TILESIDE, j * TILESIDE + menuHeight, TILESIDE, TILESIDE);
                tmp->setBrush(QBrush(ColorHash[tmp->getType()]));
                scene->addItem(tmp);
            }
            else {
                qDebug() << "EFAULT";
            }
        }

    }

    eventsText->setFont(hnFont);
    eventsText->setGeometry(i * tileside + 1, menuHeight, EVENTSWIDTH, rows * tileside);


    scene->addWidget(_world->eventsText);

    qint32 mainH, mainW, buttonW;

    mainH = rows * tileside + menuHeight;
    mainW = columns * tileside + EVENTSWIDTH;

    /* Divide by 4, because we have 3 buttons and
     * in any case form needs some space for fillers */
    buttonW = mainW / 4;

    buttons = new QGroupBox();
    buttons->setGeometry(0, mainH, mainW, BUTTONSH);
    buttonsLayout = new QHBoxLayout;

    /* QPixmap pixmap("image_path");
    QIcon ButtonIcon(pixmap);
    button->setIcon(ButtonIcon);
    button->setIconSize(pixmap.rect().size()); */

    //QPixmap pixmap("pics/start.jpg");
    //QIcon ButtonIcon(pixmap);
    //startB->setIcon(ButtonIcon);
    //startB->setIconSize(pixmap.rect().size());

    /* QColor col = QColorDialog::getColor(Qt::white, this);
    if(col.isValid()) {
    QString qss = QString("background-color: %1").arg(col.name());
    ui->pushButton->setStyleSheet(qss);*/

    startB = new QPushButton("Start");

    startB->setStyleSheet("background-color: green;font-size: 20px");

    //startB = new QPushButton()
    //startB = new QPushButton(QIcon(QPixmap("pics/start.jpg")), NULL);
    //startB->setIconSize(QSize(100,100));

    pauseB = new QPushButton("Pause");
    stopB = new QPushButton("Stop");



    startB->setMinimumSize(buttonW, BUTTONSH);
    pauseB->setMinimumSize(buttonW, BUTTONSH);
    stopB->setMinimumSize(buttonW, BUTTONSH);

    buttonsLayout->addWidget(startB);
    buttonsLayout->addWidget(pauseB);
    buttonsLayout->addWidget(stopB);
    //buttonsLayout->addStretch(1);
    buttons->setLayout(buttonsLayout);

    scene->addWidget(buttons);

    connect(pauseB, QAbstractButton::clicked, this, pause);
    connect(startB, QAbstractButton::clicked, this, start);





    //mainLayout = new QVBoxLayout;
    view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );

    //mainLayout->addWidget(menuBar);
    mainLayout->addWidget(view);

    view->show();

    running = false;
    //menuBar->show();
    //scene->addWidget(menuBar);
    //view->setFixedSize(800, 600);
}

void WorldView::update()
{
    while(! _world->changedCells->isEmpty()) {
        Cell * tmpCell = _world->changedCells->pop();

        if (ColorHash.contains(tmpCell->getType()) && ColorHash[tmpCell->getType()].isValid())
            tmpCell->setBrush(QBrush(ColorHash[tmpCell->getType()]));
        else
            tmpCell->setBrush(QBrush(ColorHash[UNKNOWN]));
    }

    _world->eventsText->appendPlainText(*_world->_eventsText);
    _world->_eventsText->clear();
    view->update();
}

void WorldView::close()
{
    QApplication::quit();
}

void WorldView::pause()
{
    //qDebug() << "Pressed";
    emit pauseSignal();
}

void WorldView::start()
{
    if (! running) {
        startB->setStyleSheet("background-color: red;font-size: 20px");
        startB->setText("Pause");
        emit startSignal();
        running = true;
    }
    else {
        startB->setStyleSheet("background-color: green;font-size: 20px");
        startB->setText("Start");
        emit pauseSignal();
        running = false;
    }

}

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

