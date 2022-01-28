#include "jerry.h"

#include"powerups.h"
#include <QTimer>
#include <QGraphicsScene>
void settext();
QGraphicsTextItem* Showlives2;
int jerry::lives=0;
int jerry::row=0;
int jerry::column=0;
int tom::row=0;
int tom::column=0;
bool jerry::isinvisible=false;
bool jerry::gameended=false;
jerry::jerry(int data[11][11])
{
    gameended=false;
    Showlives2=&Showlives;
lives=3;
    QPixmap image("jerry.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    setPos(300, 300);
    row = 5;
    column = 5;
    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
            boardData[i][j] = data[i][j];
    QFont f;
    f.setPointSize(15);
     Showlives.setPos(0,0);
    Showlives.setFont(f);
Showlives.setPlainText("3 lives");
Showlives.setDefaultTextColor(Qt::white);
    QPixmap loseimage("lose.png");
setZValue(2);
    loseimage = loseimage.scaledToWidth(450);
   loseimage =loseimage.scaledToHeight(450);
      losescreen.setPixmap(loseimage);
     losescreen.setPos(100, 100);
losescreen.setZValue(3);
winscreen.setZValue(3);
     QPixmap winimage("win.png");

     winimage = winimage.scaledToWidth(450);
    winimage =winimage.scaledToHeight(450);

     winscreen.setPixmap(winimage);
    winscreen.setPos(100, 100);

     QTimer *timer = new QTimer(this);
     connect(timer, SIGNAL(timeout()), this, SLOT(checkcollision()));
     timer->start(100);
}
void jerry::settext()
{ if(lives==2){
        Showlives2->setPlainText("2 lives");
      }else if(lives==1){
         Showlives2->setPlainText("1 lives");
      }else if(lives==0){
          Showlives2->setPlainText("0 lives");
      }
}
void jerry::endgame(){
    gameended=true;
losescreen.setOpacity(0.1f);
  QTimer*  mTimer = new QTimer(this);
  mTimer->setSingleShot(true);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(showlosescreen()));
      mTimer->start(100);
      scene()->addItem(&losescreen);
}
void jerry::showlosescreen(){
    if(losescreen.opacity()<=1){
      losescreen.setOpacity(losescreen.opacity()+0.05f);
      QTimer*  mTimer = new QTimer(this);
      mTimer->setSingleShot(true);
        connect(mTimer, SIGNAL(timeout()), this, SLOT(showlosescreen()));
          mTimer->start(50);
    }
}
void jerry::showwinscreen(){
    if(winscreen.opacity()<=1){
      winscreen.setOpacity(winscreen.opacity()+0.05f);
      QTimer*  mTimer = new QTimer(this);
      mTimer->setSingleShot(true);
        connect(mTimer, SIGNAL(timeout()), this, SLOT(showwinscreen()));
          mTimer->start(30);
    }
}
void jerry::returnfood(){
    QPixmap image("jerry.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    if(currentfood==1){
        food1= new cheese(100,500);
    }else if(currentfood==2){
          food1= new cheese(500,100);
    }else if(currentfood==3){
        food1= new cheese(100,100);
  }else if(currentfood==4){
        food1= new cheese(500,500);
  }
scene()->addItem(food1);
currentfood=0;
}
void jerry::checkcollision()
{
    QList<QGraphicsItem*> items = collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        if (typeid(*items[i]) == typeid(cheese)&&currentfood==0)
        {
            if(column==1&&row==9){
                currentfood=1;
            } if(column==9&&row==1){
                currentfood=2;
            } if(column==1&&row==1){
                currentfood=3;
            } if(column==9&&row==9){
                currentfood=4;
            }
            QPixmap image("jerrycheese.png");
            image = image.scaledToWidth(50);
            image = image.scaledToHeight(50);
            setPixmap(image);
            scene()->removeItem(items[i]);
        } if (typeid(*items[i]) == typeid(tom)&&jerry::isinvisible==false)
        {
            lives=lives-1;

                    if(lives==2){
                      Showlives.setPlainText("2 lives");
                    }else if(lives==1){
                       Showlives.setPlainText("1 lives");
                    }else if(lives==0){
                        Showlives.setPlainText("0 lives");
                    }
                    row=5;
                    column=5;
                    tom::row = 9;
                    tom::column = 5;
                    setPos(300, 300);
                   items[i]->setPos(300,500);
                   if(currentfood!=0){

                       returnfood();
                   }
                   if(lives<=0){
                       endgame();
                   }
        } if (typeid(*items[i]) == typeid(powerups)&&isinvisible==false)
        {

            scene()->removeItem(items[i]);
            setOpacity(0.5);
            isinvisible=true;
          QTimer*  mTimer = new QTimer(this);
              mTimer->setSingleShot(true);
              connect(mTimer, SIGNAL(timeout()), SLOT(disableinvisible()));
              mTimer->start(4000);
        }
    }
if(currentfood!=0){
    if(row==5&&column==5||row==6&&column==5||row==6&&column==4){
  food_counter++;

        cheesepic=new QGraphicsPixmapItem;
      QPixmap cheese("cheese.png");
      cheese = cheese.scaledToWidth(50);
      cheese = cheese.scaledToHeight(50);
      cheesepic->setPixmap(cheese);
        if(food_counter==1){
          cheesepic->setPos(250,300);
        }else if(food_counter==2){
                cheesepic->setPos(300,300);
        }else if(food_counter==3){
              cheesepic->setPos(250,350);
      }else if(food_counter==4){
              cheesepic->setPos(300,350);
      }
        scene()->addItem(cheesepic);
        currentfood=0;
    QPixmap image("jerry.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);
    if(food_counter==4){
        gameended=true;
  scene()->addItem(&winscreen);
  winscreen.setOpacity(0.1f);
    showwinscreen();
    }
    }
}
}
void jerry::disableinvisible(){
    setOpacity(1);
    isinvisible=false;
}
void jerry::keyPressEvent(QKeyEvent* event)
{
    if(gameended==false){ if (event->key() == Qt::Key_Up && boardData[row - 1][column] >= 0)
 {
     row--;
 }
 else if (event->key() == Qt::Key_Down && boardData[row + 1][column] >= 0)
 {
     row++;
 }
 else if (event->key() == Qt::Key_Right && boardData[row][column + 1] >= 0)
 {
     column++;
 }
 else if (event->key() == Qt::Key_Left && boardData[row][column - 1] >= 0)
 {
     column--;
 }
 setPos(50 + 50 * column, 50 + 50 * row);}
}
