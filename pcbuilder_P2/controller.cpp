#include "controller.h"


Controller::Controller(QStringList* list) : m(new Magazzino()), view( new Mainwindow()), lista_vista(new ListaMagazzinoView())
{
    view->show();
    //prova();

    connect(view, SIGNAL(visualizzaComponentiPressed()), this, SLOT(loadMagazzinoView()));
    connect(lista_vista, SIGNAL(closing()), view, SLOT(show()));

}

void Controller::prova() {
//Gpu* provv= new Gpu("ciao",10,"bello","come",12,10,"anto",13,14,"ciao");
//Gpu* g4=new Gpu("gpu",3, "Nvidia", "Titan", 13 , 2012, "random", 16,12 ,"ciao");
//Smartptr<Item> ciao(g4);
//Magazzino* tony=new Magazzino();
//tony->load_database();
//std::cout<<"ciao"<<std::endl;

}

//void Controller::listaMagazzinoView() {
//    std::cout<<"ciao bello"<<std::endl;
//    view->openSubview();
//}

void Controller::loadMagazzinoView(){
    if(!list){
    list=m->get_lista_view();
    lista_vista->loadMagazzinoview(list); }
    view->hide();
    lista_vista->show();
}
