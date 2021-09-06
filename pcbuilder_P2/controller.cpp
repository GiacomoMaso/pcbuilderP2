#include "controller.h"


Controller::Controller(/*QStringList* list*/) : m(new Magazzino()), view( new Mainwindow()), lista_vista(new ListaMagazzinoView()),select_add_view(new SelectAddObjectView()), list(/*nullptr*/)
{
    view->show();
    set_style();


    connect(view, SIGNAL(visualizzaComponentiPressed()), this, SLOT(loadMagazzinoView()));
    connect(view, SIGNAL(aggiungiComponentiPressed()), this, SLOT(load_select_add_obj_view()));
    connect(lista_vista, SIGNAL(closing()), view, SLOT(show()));
    connect(select_add_view, SIGNAL(closing()), view, SLOT(show()));
    connect(lista_vista, SIGNAL(delete_obj_to_controller(std::string)), this, SLOT(delete_obj_to_controller(std::string)));
    connect(lista_vista, SIGNAL(item_to_view(std::string)), this, SLOT(item_to_view(std::string)));
    connect(select_add_view, SIGNAL(signal_tipo_ogg_add(std::string)), this, SLOT(load_form_view(std::string)));
    connect(lista_vista, SIGNAL(get_quantita_item(std::string)), this, SLOT(get_quantita_for_view(std::string)));



}



void Controller::loadMagazzinoView(){
    std::cout<<"prova ubuntu"<<std::endl;
    if(list==nullptr){
        std::cout<<"ciao nullptr"<<std::endl;
    list=m->get_lista_view();
    lista_vista->loadMagazzinoview(list); }
    view->hide();
    lista_vista->show();
}

void Controller::delete_obj_to_controller(std::string x){
    bool empty;
    empty=m->delete_by_name(x);
    std::cout<<"ebmty_del"<<empty<<std::endl;
    if(empty){
        delete list;
        list=nullptr;
    }
}

void Controller::item_to_view(std::string x){
    std::cout<<"ciao bello"<<std::endl;
    item_view=new ViewSingleItem();
    connect(item_view, SIGNAL(closing()), lista_vista, SLOT(show()));
    QStringList* provv=m->get_item_to_view(x);
    item_view->load_view_item(provv);
    lista_vista->hide();


    item_view->show();
}

void Controller::load_select_add_obj_view(){
    view->hide();
    select_add_view->show();
}

void Controller::load_form_view(std::string x){
    form_view=new FormView();
    form_view->build_form(x);
    select_add_view->hide();
    form_view->setStyleSheet(styleSheet);
    form_view->show();

    connect(form_view, SIGNAL(closing()), select_add_view, SLOT(show()));
    connect(form_view, SIGNAL(add_item(QStringList*)), this, SLOT(add_item_to_model(QStringList*)));
}

void Controller::add_item_to_model(QStringList* list_item){
    bool new_item=m->add_item(list_item);
    if(new_item){

        QString item_name=list_item->at(1);
        if(list){
            list->push_back(item_name);
            lista_vista->add_item_to_layout(item_name);
         }
        else{
            list=new QStringList;
            list=m->get_lista_view();
            lista_vista->loadMagazzinoview(list);
        }


    }
    delete list_item;
}

void Controller::get_quantita_for_view(std::string x){
    unsigned int quantita=m->get_quantita_item(x);
    lista_vista->set_quantita_item(quantita);
}

void Controller::set_style () {
    QFile styleFile(":/style_folder/style.css");
       if(styleFile.open(QIODevice::ReadOnly))
       {
           QTextStream textStream(&styleFile);
           /*QString */styleSheet = textStream.readAll();
           styleFile.close();
//           setStyleSheet(styleSheet);
       }
    qDebug()<<"CIAO"<<styleFile.open(QIODevice::ReadOnly);

}
