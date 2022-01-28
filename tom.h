#ifndef TOM_H
#define TOM_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QList>
#include <QGraphicsScene>
#include <jerry.h>
#include <QVector>
class tom : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    private:

        int boardData[11][11];
    public: 
        int Graph[59][59];
        const int COUNT = 59;
        static int row;
       static int column;
        QGraphicsPixmapItem losescreen;
        tom(int data[11][11]);
    public slots:
        int convertpos();
         QVector<QVector<int>> Dijkstra(int Graph[59][59], int startVertex);
        void movetom();
};
#endif
