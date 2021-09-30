#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QKeyEvent>
#include <fstream>
#include <vector>
#include <QTimer>

#include "solidos.h"
#include "destructibles.h"
#include "bomber.h"
#include "bomba.h"

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

private:
    Ui::Interfaz *ui;
    bomber *bombardero;
    bomba *bomb;
    QGraphicsScene *scene;
    QList<solidos*> bloq_solidos;
    QList<bomba*> bombs;
    QList<destructibles*> bloq_destru;
    QTimer *timer;

    void keyPressEvent(QKeyEvent *evento);
    bool EvaluarColision();
    bool sobrepasa(int);
    void dibujarBordes(std::string=PATH_SOLID);
    void dibujarIntermedios();
    void dibujarLadrillos(std::string=PATH_LADRI);
};
#endif // INTERFAZ_H
