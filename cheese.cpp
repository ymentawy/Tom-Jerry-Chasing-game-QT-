#include "cheese.h"

cheese::cheese(int x,int y)
{
    QPixmap foodImage("cheese.png");
        foodImage = foodImage.scaledToWidth(50);
        foodImage = foodImage.scaledToHeight(50);
        setPixmap(foodImage);
        setPos(x, y);
}
