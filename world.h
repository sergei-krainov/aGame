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

#define WIDTH 800
#define HEIGHT 600
#define TILESIDE 25
#define NUMCELLS 100

class World : public QObject
{
private:
    static const qint32 columns = WIDTH/TILESIDE;
    static const qint32 rows    = HEIGHT/TILESIDE;
    //quint32 map[WIDTH/TILESIDE][HEIGHT/TILESIDE];
    Cell *cells[columns][rows];

public:
    World();

    QPlainTextEdit * eventsText;
    QStack<Cell*> * changedCells;

    qint32 getColumns() {return columns;}
    qint32 getRows() {return rows;}
    qint32 getTileside() {return TILESIDE;}
    Cell *getCell(qint32, qint32);
    void setCell(Cell*);

    void createMap();

public slots:
    void openMapFile();
};

#endif // WORLD_H
