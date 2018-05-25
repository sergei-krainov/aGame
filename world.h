#ifndef WORLD_H
#define WORLD_H

#include "cell.h"
#include <QtGlobal>
#include <QGraphicsRectItem>
#include <QVBoxLayout>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QHash>
#include <QPlainTextEdit>
#include <QStack>
#include <QFileDialog>
#include <QMessageBox>
#include <QTimer>

#define WIDTH 800
#define HEIGHT 600
#define TILESIDE 25
#define NUMCELLS 100
#define TIMEOUT 1000

class World : public QObject
{
private:
    static const qint32 columns = WIDTH/TILESIDE;
    static const qint32 rows    = HEIGHT/TILESIDE;
    //quint32 map[WIDTH/TILESIDE][HEIGHT/TILESIDE];
    Cell *cells[columns][rows];
    QTimer * timer;

public:
    World();

    QPlainTextEdit * eventsText;
    QStack<Cell*> * changedCells;
    QString * _eventsText;

    qint32 getColumns() {return columns;}
    qint32 getRows() {return rows;}
    qint32 getTileside() {return TILESIDE;}
    Cell *getCell(qint32, qint32);
    void setCell(Cell*);

    void createMap();

public slots:
    void openMapFile();
    void pause();
};

#endif // WORLD_H
