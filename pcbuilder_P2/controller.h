#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainwindow.h"


#include "Magazzino.h"
#include "listamagazzinoview.h"


class Controller : public QObject{
Q_OBJECT


private:
    Magazzino* m;
    Mainwindow* view;
    ListaMagazzinoView* lista_vista;
    QStringList* list;



public:
    Controller(QStringList* list=nullptr);
    void prova();

public slots:
    //void listaMagazzinoView();
    void loadMagazzinoView();

};

#endif // CONTROLLER_H
