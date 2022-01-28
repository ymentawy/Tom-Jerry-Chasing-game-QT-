#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include"cheese.h"
#include"jerry.h"
#include"tom.h"
#include"powerups.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsView view;
    view.setFixedSize(650, 650);
    view.setWindowTitle("Maze Game");
    view.setBackgroundBrush(QBrush(Qt::black));

    QGraphicsScene scene;

    int boardData[11][11];
    QFile file("Gametext.txt");
    file.open(QIODevice::ReadOnly);

    QString temp;
    QTextStream stream(&file);
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
        {
            stream >> temp;
            boardData[i][j] = temp.toInt();
        }

    QPixmap bricksImage("Bricks.png"), grassImage("Grass.png");
    bricksImage = bricksImage.scaledToWidth(50);
    bricksImage = bricksImage.scaledToHeight(50);
    grassImage = grassImage.scaledToWidth(50);
    grassImage = grassImage.scaledToHeight(50);
    QGraphicsPixmapItem boardImages[11][11];
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
        {
            if (boardData[i][j] < 0)
                boardImages[i][j].setPixmap(bricksImage);
            else
                boardImages[i][j].setPixmap(grassImage);
             boardImages[i][j].setPos(50 + 50 * j, 50 + 50 * i);
            scene.addItem(&boardImages[i][j]);
        }
    cheese food1(100,500);
      scene.addItem(&food1);
     cheese food2(500,100);      
  scene.addItem(&food2);
      cheese food3(100,100);
          scene.addItem(&food3);
             cheese food4(500,500);
    scene.addItem(&food4);

    powerups powerup1(100,250);
        scene.addItem(&powerup1);
     powerups powerup2(500,250);
scene.addItem(&powerup2);



       jerry p1(boardData);
       scene.addItem(&p1);

       tom enemy(boardData);
       scene.addItem(&enemy);
         scene.addItem(&p1.Showlives);

       p1.setFlag(QGraphicsPixmapItem::ItemIsFocusable);
       p1.setFocus();
    view.setScene(&scene);
    view.show();

    return a.exec();
}
