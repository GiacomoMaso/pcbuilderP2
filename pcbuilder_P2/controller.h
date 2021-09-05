#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainwindow.h"
#include "Magazzino.h"
#include "listamagazzinoview.h"
#include "viewsingleitem.h"
#include "selectaddobjectview.h"
#include "formview.h"



class Controller : public QObject{
Q_OBJECT


private:
    Magazzino* m;
    Mainwindow* view;
    ListaMagazzinoView* lista_vista;
    ViewSingleItem* item_view;
    SelectAddObjectView* select_add_view;
    FormView* form_view;
    QStringList* list;



public:
    Controller(/*QStringList* list=nullptr*/);
    void prova();


public slots:
    //void listaMagazzinoView();
    void loadMagazzinoView();
    void delete_obj_to_controller(std::string );
    void item_to_view(std::string);
    void load_select_add_obj_view();
    void load_form_view(std::string);

};

#endif // CONTROLLER_H
