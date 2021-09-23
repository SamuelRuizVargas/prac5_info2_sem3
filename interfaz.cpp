#include "interfaz.h"
#include "ui_interfaz.h"

Interfaz::Interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interfaz)
{
    ui->setupUi(this);
    //Se crea la escena
    scene = new QGraphicsScene;
    //Fondo verde
    QPen pen;
    QBrush brush2(Qt::darkGreen,Qt::SolidPattern);
    scene->addRect(0,0,1550,650, pen, brush2);
    //Se grafica el mapa estatico
    QImage bloq_esta(PATH_BLOQ);
    QBrush brush_im(bloq_esta);
    dibujarBordes(pen,brush_im);
    dibujarIntermedios(pen,brush_im);


    //referencia 0,0
    scene->addRect(0,0,1,1, QPen(Qt::blue, 3, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin), QBrush(Qt::blue,Qt::SolidPattern));


    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::dibujarBordes(QPen pen, QBrush brush, std::string ruta)//dibuja los bordes del mapa
{
    ifstream archivo;
    string coorde,numero,int1,int2,int3,int4,digi;
    int ente1,ente2,ente3,ente4,len,conta;
    archivo.open(ruta, ios::in);
    while(!archivo.eof())
    {
        if (archivo.eof())
            break;
        getline(archivo,coorde);
        len=coorde.length();
        conta=0;
        for (int i=0; i<=len;i++)
        {
            digi=coorde[i];
            if (digi!="," and digi[0]!='\000' )
            {
                numero+=digi;
            }
            else
            {
                conta+=1;
                if(conta==1)
                    int1+=numero;
                else if(conta==2)
                    int2+=numero;
                else if(conta==3)
                    int3+=numero;
                else if(conta==4)
                    int4+=numero;
                numero.erase();
            }
        }
        ente1=atoi(int1.c_str());
        ente2=atoi(int2.c_str());
        ente3=atoi(int3.c_str());
        ente4=atoi(int4.c_str());
        int1.erase();
        int2.erase();
        int3.erase();
        int4.erase();
        bloq_solidos.append(new solidos(ente1,ente2,ente3,ente4));
        scene->addRect(ente1,ente2,ente3,ente4, pen, brush);
    }
    archivo.close();
}

void Interfaz::dibujarIntermedios(QPen pen, QBrush brush)//dibuja los solidos interiores del mapa
{
    int x_ini=100, y_ini=100;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<14;j++)
        {
            bloq_solidos.append(new solidos(x_ini,y_ini,50,50));
            scene->addRect(x_ini,y_ini,50,50, pen, brush);
            x_ini+=100;
        }
        x_ini=100;
        y_ini+=100;
    }
}


