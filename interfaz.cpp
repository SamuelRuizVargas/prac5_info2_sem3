#include "interfaz.h"
#include "ui_interfaz.h"

Interfaz::Interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;

    QPen pen;

    QImage bloq_esta(PATH_BLOQ);
    QBrush brush(bloq_esta);
    QBrush brush2(Qt::darkGreen,Qt::SolidPattern);

    scene->addRect(0,0,2000,650, pen, brush2);
    scene->addRect(0,0,2000,50, pen, brush);
    scene->addRect(0,600,2000,50, pen, brush);
    scene->addRect(0,0,50,600, pen, brush);
    scene->addRect(0,0,1,1, QPen(Qt::blue, 3, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin), QBrush(Qt::blue,Qt::SolidPattern));//0,0


    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

Interfaz::~Interfaz()
{
    delete ui;
}

