#ifndef BOMBER_H
#define BOMBER_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_BOMBER "../practica5/imagenes/bomberman.png"

class bomber : public QGraphicsItem
{
    int h=50;
    int a=50;
    int posx;
    int posy;
    int velocidad=50;

public:
    bomber();
    bomber(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    int getPOSX();
    int getPOSY();
    ~bomber();
};

#endif // BOMBER_H
