#include "bomba.h"

bomba::bomba()
{
    posx=0;
    posy=0;
    setPos(posx,posy);
}

bomba::bomba(int x, int y)
{
    posx=x;
    posy=y;
    setPos(posx,posy);
}

QRectF bomba::boundingRect() const
{
    return QRectF(0,0,50,50);
}

void bomba::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(PATH_BOMB);
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

bool bomba::destruir()
{
    return true;
}

bomba::~bomba()
{

}
