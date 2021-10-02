#include "interfaz.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    /*
     *NOTA: Las rutas a cada textura de los objetos
     *se encuentra en la cabecera de los mismos
    */
    QApplication a(argc, argv);
    Interfaz w;
    w.show();
    return a.exec();
}
