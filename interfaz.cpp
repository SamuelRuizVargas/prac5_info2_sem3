#include "interfaz.h"
#include "ui_interfaz.h"

Interfaz::Interfaz(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Interfaz)
{
    ui->setupUi(this);

    scene = new QGraphicsScene;

    QPen pen(Qt::darkGray, 3, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin);
    QBrush brush(Qt::darkGray,Qt::SolidPattern);
    scene->addRect(0,0,2000,50, pen, brush);
    scene->addRect(0,600,2000,50, pen, brush);
    scene->addRect(0,0,50,600, pen, brush);
    scene->addRect(0,0,1,1, QPen(Qt::blue, 3, Qt::SolidLine, Qt::SquareCap, Qt::MiterJoin), QBrush(Qt::blue,Qt::SolidPattern));//0,0


    ui->graphicsView->setScene(scene);
}

Interfaz::~Interfaz()
{
    delete ui;
}

