#include "mainwindow.h"

Mainwindow::Mainwindow(QWidget *p) : QWidget(p)
{
    setWindowTitle("Pc Builder");
    setMinimumSize(800, 600);
    QVBoxLayout* layout= new QVBoxLayout;
    setLayout(layout);



    QMenuBar* menuBar=new QMenuBar(this);
    QMenu* carica=new QMenu("Carica", menuBar);
    QMenu* salva= new QMenu("Salva", menuBar);
    QPushButton* add_obj= new QPushButton("Aggiungi Componente", this);
    QPushButton* delete_obj= new QPushButton("Elimina Componente", this);
    QPushButton* view_obj= new QPushButton("Visualizza Componenti", this);
    add_obj->setMaximumSize(400,100);
    delete_obj->setMaximumSize(400,100);
    view_obj->setMaximumSize(400,100);
    add_obj->setMinimumSize(400,100);
    delete_obj->setMinimumSize(400,100);
    view_obj->setMinimumSize(400,100);

    menuBar->addMenu(carica);
    menuBar->addMenu(salva);
    menuBar->setNativeMenuBar(false);
    menuBar->setGeometry(0,0,800,30);


    layout->addWidget(add_obj);
    layout->addWidget(delete_obj);
    layout->addWidget(view_obj);
    layout->setAlignment(add_obj, Qt::AlignHCenter);
    layout->setAlignment(delete_obj, Qt::AlignHCenter);
    layout->setAlignment(view_obj, Qt::AlignHCenter);








}
