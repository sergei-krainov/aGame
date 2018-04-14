#include <QApplication>
#include <game.h>
#include <QtDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QVBoxLayout>



#include <QGraphicsRectItem>
#include <QTimer>


#define WIDTH 800
#define HEIGHT 600
#define TILESIDE 25
#define NUMCELLS 100

enum tile_type {EMPTY, WALL, BOT};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "TEST";

    Game * game = new Game;


    return a.exec();
}
