#ifndef BOMBA_H
#define BOMBA_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_BOMB "../practica5/imagenes/bomba.png"

class bomba : public QGraphicsItem
{
    int h=50;
    int a=50;
    int posx;
    int posy;

public:
    bomba();
    bomba(int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    bool destruir();
    ~bomba();
};

#endif // BOMBA_H
