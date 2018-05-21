#include "world.h"
#include "cell.h"
#include <QtDebug>

World::World()
{
    quint32 i,j;

    //QHash<qint32, QColor> ColorHash
    //ColorHash.insert(0, Qt::white);
    //ColorHash.insert(1, Qt::black);
    //ColorHash.insert(2, Qt::red);
    //ColorHash.insert(3, Qt::blue);

    changedCells = new QStack<Cell*>;
    //changedCells->resize(rows*columns);

    eventsText = new QPlainTextEdit();

    /* quint32 tile_map[columns][rows] = {
    quint32 tile_map[columns*rows] = {
        1,0,1,0,1,0,5,2,3,6
    }; */




    for (j = 0; j < rows; ++j) {
        for (i = 0; i < columns; ++i) {
            cells[i][j] = new Cell(i,j);
            //cells[i][j]->setType(tile_map[i + j*columns]);
            cells[i][j]->setType(FREE);
            changedCells->push(cells[i][j]);
        }
    }

}

Cell *World::getCell(qint32 x, qint32 y)
{
    if (x < 0 || x > columns)
        return NULL;

    if (y < 0 || y > rows)
        return NULL;

    return cells[x][y];
}

void World::setCell(Cell * cell)
{
    //cell->setType();

    qint32 x, y;

    x = cell->getX();
    y = cell->getY();


    this->cells[x][y]->setType(cell->getType());
    changedCells->push(cells[x][y]);
}

void World::openMapFile()
{
    QString fileName = QFileDialog::getOpenFileName(0, "Open the file",".","*.csv");
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
        QMessageBox::warning(0, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    for (qint32 j = 0; j < rows; ++j) {
        for (qint32 i = 0; i < columns; ++i) {
            //cells[i][j] = NULL;
            cells[i][j]->setType(FREE);
            //cells[i][j]->setType(tile_map[i + j*rows]);
            //changedCells->push(cells[i][j]);
        }
    }

    //setWindowTitle(fileName);
    QTextStream in(&file);

    quint32 i = 0, j = 0;
    //QVector<quint32> * v = new QVector<quint32>;
    //QVector<quint32>::const_iterator it;

    while(!in.atEnd()) {
        QString s = in.readLine();

        QStringList list = s.split(",");
        for (QStringList::const_iterator it_local = list.begin(); j < rows && (it_local != list.end()); ++it_local) {
            //qDebug() << "mmm?" << (i + 1)*(j + 1) << (rows * columns);
            if (*it_local != "") {
                //qDebug() << "i;j" << i << j;
                cells[i][j]->setType((*it_local).toInt());
                changedCells->push(cells[i][j]);

                if (i == (columns - 1)) {
                    j++;
                    i = 0;
                }
                else {
                    i++;
                }
            }
        }
    }

    file.close();
}
