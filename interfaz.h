#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <QGraphicsScene>
#include <QMainWindow>
#include <QKeyEvent>
#include <fstream>
#include <vector>

#include "solidos.h"
#include "destructibles.h"
#include "bomber.h"

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

private:
    Ui::Interfaz *ui;
    bomber *bombardero;
    QGraphicsScene *scene;
    void keyPressEvent(QKeyEvent *evento);
    bool EvaluarColision();
    bool sobrepasa();
    void dibujarBordes(std::string=PATH_SOLID);
    void dibujarIntermedios();
    void dibujarLadrillos(std::string=PATH_LADRI);
    QList<solidos*> bloq_solidos;
    QList<destructibles*> bloq_destru;
};
#endif // INTERFAZ_H
