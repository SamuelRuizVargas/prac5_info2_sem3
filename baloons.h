#ifndef BALOONS_H
#define BALOONS_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_BALL "../practica5/imagenes/enemigo.png"

class baloons : public QGraphicsItem
{
    int h=50;
    int a=50;
    bool movi_original=true;
    int posx;
    int posy;
    int velocidad=1;

public:
    baloons();
    baloons(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void movOriginal();
    bool getMov();
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    ~baloons();
};

#endif // BALOONS_H
