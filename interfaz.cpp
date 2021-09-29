#include "interfaz.h"
#include "ui_interfaz.h"

int inicio=0;


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
    scene->setSceneRect(inicio,-15,700,671);
    //personaje
    bombardero =new bomber();
    scene->addItem(bombardero);
    //Se grafica el mapa estatico
    dibujarBordes();
    dibujarIntermedios();
    //referencia 0,0
    scene->addRect(0,0,1,1, QPen(Qt::blue, 3, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin), QBrush(Qt::blue,Qt::SolidPattern));
    //mostrar escena
    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

Interfaz::~Interfaz()
{
    delete ui;
}

void Interfaz::keyPressEvent(QKeyEvent *evento)//evento de presionar tecla
{
    if(evento->key()==Qt::Key_S)
    {
        bombardero->moveDown();
        if(EvaluarColision())
            bombardero->moveUp();
    }
    else if (evento->key()==Qt::Key_D)
    {
        bombardero->moveRight();
        if(EvaluarColision())
            bombardero->moveLeft();
        else if(sobrepasa())
        {
            inicio+=50;
            scene->setSceneRect(inicio,-15,700,671);//ARREGLAR
        }
    }
    else if(evento->key()==Qt::Key_W)
    {
        bombardero->moveUp();
        if(EvaluarColision())
            bombardero->moveDown();
    }
    else if(evento->key()==Qt::Key_A)
    {
        bombardero->moveLeft();
        if(EvaluarColision())
            bombardero->moveRight();
        else if(sobrepasa())
        {
            inicio-=50;
            scene->setSceneRect(inicio,-15,700,671);//ARREGLAR
        }
    }
}

bool Interfaz::EvaluarColision()//se evalua si el objeto colisiona con otro(s)
{
    QList<solidos*>::iterator it;

    for(it=bloq_solidos.begin(); it!=bloq_solidos.end(); it++)
    {
        if(bombardero->collidesWithItem(*it))
        {
            return true;
        }
    }
    return false;
}

bool Interfaz::sobrepasa()//Dice si el personaje ya paso alguno de los puntos limite
{
    bool sobrepasa=false;
    int x=bombardero->getPOSX();
    int limit_izq=300,limit_dere=1250;
    if(x>limit_izq and x<limit_dere)
    {
        sobrepasa=true;
    }
    return sobrepasa;
}

void Interfaz::dibujarBordes(std::string ruta)//dibuja los bordes del mapa
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
        scene->addItem(bloq_solidos.back());
    }
    archivo.close();
}

void Interfaz::dibujarIntermedios()//dibuja los solidos interiores del mapa
{
    int x_ini=100, y_ini=100;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<14;j++)
        {
            bloq_solidos.append(new solidos(x_ini,y_ini,50,50));
            scene->addItem(bloq_solidos.back());
            x_ini+=100;
        }
        x_ini=100;
        y_ini+=100;
    }
}


