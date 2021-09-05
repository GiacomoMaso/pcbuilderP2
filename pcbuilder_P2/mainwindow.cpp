#include "mainwindow.h"

Mainwindow::Mainwindow(QWidget *parent) : QMainWindow(parent), header(new QLabel(this))
{
    setWindowTitle("Pc Builder");
    setMinimumSize(800, 600);
    move(QApplication::desktop()->screen()->rect().center() - rect().center());


    header->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    header->setText("PC Builder");
    header->setAlignment(Qt::AlignCenter);
    QWidget* central=new QWidget(this);
   QVBoxLayout* layout= new QVBoxLayout;
   QHBoxLayout* layout_button= new QHBoxLayout;






    QMenuBar* menuBar=new QMenuBar(this);
    QMenu* carica=new QMenu("Carica", menuBar);
    QMenu* salva= new QMenu("Salva", menuBar);
    add_obj=new QPushButton("Aggiungi Componente", this);

    view_obj= new QPushButton("Visualizza Componenti", this);
    header->setMaximumHeight(300);
    add_obj->setMaximumSize(300,80);

    view_obj->setMaximumSize(300,80);
    add_obj->setMinimumSize(300,80);

    view_obj->setMinimumSize(300,80);

    menuBar->addMenu(carica);
    menuBar->addMenu(salva);
   menuBar->setNativeMenuBar(false);
    menuBar->setGeometry(0,0,800,30);


    layout_button->addWidget(add_obj);
    layout_button->addWidget(view_obj);
//    layout->addWidget(add_obj);

//    layout->addWidget(view_obj);
    layout->addWidget(header);
    layout->addLayout(layout_button);
//    layout->setAlignment(add_obj, Qt::AlignHCenter);

//    layout->setAlignment(view_obj, Qt::AlignHCenter);


    central->setLayout(layout);
    setCentralWidget(central);
    setMenuWidget(menuBar);

    set_style();

   connect(view_obj, SIGNAL(clicked()), this, SIGNAL(visualizzaComponentiPressed()));
   connect(add_obj, SIGNAL(clicked()), this, SIGNAL(aggiungiComponentiPressed()));







}

void Mainwindow::openSubview(){

    hide();
    prova->show();

}

void Mainwindow::set_style () {
    QFile styleFile(":/style_folder/style.css");
       if(styleFile.open(QIODevice::ReadOnly))
       {
           QTextStream textStream(&styleFile);
           QString styleSheet = textStream.readAll();
           styleFile.close();
           setStyleSheet(styleSheet);
       }
    qDebug()<<"CIAO"<<styleFile.open(QIODevice::ReadOnly);

}










