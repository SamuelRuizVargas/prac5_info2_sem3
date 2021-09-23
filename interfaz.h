#ifndef INTERFAZ_H
#define INTERFAZ_H
#include <QMainWindow>
#include <QGraphicsScene>
#include <vector>
#include "solidos.h"
#include <fstream>

using namespace std;

#define PATH_BLOQ "../practica5/imagenes/bloque.png"
#define PATH_SOLID "../practica5/posiciones/posxposy.txt"

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
    QGraphicsScene *scene;
    void dibujarBordes(QPen, QBrush, std::string=PATH_SOLID);
    void dibujarIntermedios(QPen, QBrush);
    QList<solidos*> bloq_solidos;
};
#endif // INTERFAZ_H
