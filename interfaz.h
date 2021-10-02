#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QKeyEvent>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <QTimer>
#include <time.h>

#include "solidos.h"
#include "destructibles.h"
#include "bomber.h"
#include "bomba.h"
#include "explosion.h"
#include "puerta.h"

using namespace std;

#define PATH_SOLID "../practica5/posiciones/posxposy_soli.txt"
#define PATH_LADRI "../practica5/posiciones/posxposy_destru.txt"

QT_BEGIN_NAMESPACE
namespace Ui { class Interfaz; }
QT_END_NAMESPACE

class Interfaz : public QMainWindow
{
    Q_OBJECT

public:
    Interfaz(QWidget *parent = nullptr);
    ~Interfaz();

public slots:
    void eliminarBomba();
    void eliminarExplo();

private:
    Ui::Interfaz *ui;
    bomber *bombardero;
    bomba *bomb;
    explosion *exp_actu;
    QGraphicsScene *scene;
    QList<solidos*> bloq_solidos;
    QList<bomba*> bombs;
    QList<destructibles*> bloq_destru;
    QList<explosion*> rango_explo;
    QTimer *timer;
    QTimer *timer_2;

    void keyPressEvent(QKeyEvent *evento);
    bool EvaluarColision();
    bool EvaluarColisionExp();
    bool sobrepasa(int);
    void dibujarBordes(std::string=PATH_SOLID);
    void dibujarIntermedios();
    void dibujarLadrillos(std::string=PATH_LADRI);
};
#endif // INTERFAZ_H
