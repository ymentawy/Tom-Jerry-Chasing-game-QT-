#ifndef JERRY_H
#define JERRY_H
#include <QObject>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QPixmap>
#include <QList>
#include <QGraphicsScene>
#include <tom.h>
#include <QGraphicsTextItem>
#include <QGraphicsOpacityEffect>
#include"cheese.h"
class jerry : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    private:

        int boardData[11][11];
    public:
        int food_counter=0;
        int currentfood=0;
   static bool gameended;
QGraphicsTextItem Showlives;
static int lives;
static int row;
static int column;
static bool isinvisible;
    cheese *food1;
      QGraphicsPixmapItem *cheesepic;
 QGraphicsPixmapItem losescreen;
  QGraphicsPixmapItem winscreen;
        jerry(int data[11][11]);
    public slots:
        void disableinvisible();
        static void settext();
       void endgame();
       void showlosescreen();
         void showwinscreen();
       void checkcollision();
       void returnfood();
        void keyPressEvent(QKeyEvent* event);
};


#endif
