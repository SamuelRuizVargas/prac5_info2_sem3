#ifndef EXPLOSION_H
#define EXPLOSION_H

#include <QGraphicsItem>
#include <QPainter>

#define PATH_EXP_CEN "../practica5/imagenes/explo_centro.png"
#define PATH_EXP_ARR "../practica5/imagenes/explo_arriba.png"
#define PATH_EXP_ABA "../practica5/imagenes/explo_abajo.png"
#define PATH_EXP_IZQ "../practica5/imagenes/explo_izquierda.png"
#define PATH_EXP_DER "../practica5/imagenes/explo_derecha.png"

using namespace std;

class explosion : public QGraphicsItem
{
    int h=50;
    int a=50;
    int posx;
    int posy;
    bool cen=false;
    bool arr=false;
    bool aba=false;
    bool izq=false;
    bool der=false;


public:
    explosion();
    explosion(string,int,int);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    ~explosion();
};

#endif // EXPLOSION_H
