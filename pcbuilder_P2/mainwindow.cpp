#include "mainwindow.h"

Mainwindow::Mainwindow(QWidget *parent) : QMainWindow(parent), header(new QLabel(this))
{
    setWindowTitle("Pc Builder");
    setMinimumSize(800, 600);
    header->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    header->setText("PC Builder");
    header->setAlignment(Qt::AlignCenter);
    QWidget* central=new QWidget(this);
   QVBoxLayout* layout= new QVBoxLayout;






    QMenuBar* menuBar=new QMenuBar(this);
    QMenu* carica=new QMenu("Carica", menuBar);
    QMenu* salva= new QMenu("Salva", menuBar);
    add_obj=new QPushButton("Aggiungi Componente", this);

    view_obj= new QPushButton("Visualizza Componenti", this);
    add_obj->setMaximumSize(400,100);

    view_obj->setMaximumSize(400,100);
    add_obj->setMinimumSize(400,100);

    view_obj->setMinimumSize(400,100);

    menuBar->addMenu(carica);
    menuBar->addMenu(salva);
   menuBar->setNativeMenuBar(false);
    menuBar->setGeometry(0,0,800,30);

    layout->addWidget(header);
    layout->addWidget(add_obj);

    layout->addWidget(view_obj);
    layout->setAlignment(add_obj, Qt::AlignHCenter);
    layout->setAlignment(delete_obj, Qt::AlignHCenter);
    layout->setAlignment(view_obj, Qt::AlignHCenter);


    central->setLayout(layout);
    setCentralWidget(central);
    setMenuWidget(menuBar);

   connect(view_obj, SIGNAL(clicked()), this, SIGNAL(visualizzaComponentiPressed()));








}

void Mainwindow::openSubview(){

    hide();
    prova->show();

}










