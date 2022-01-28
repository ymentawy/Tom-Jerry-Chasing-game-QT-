#include "powerups.h"

powerups::powerups(int x,int y)
{
        QPixmap foodImage("powerup.png");
            foodImage = foodImage.scaledToWidth(50);
            foodImage = foodImage.scaledToHeight(50);
            setPixmap(foodImage);
            setPos(x, y);
}
