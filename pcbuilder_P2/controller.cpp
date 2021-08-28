#include "controller.h"
#include "Magazzino.h"

Controller::Controller() : view( new Mainwindow())
{
    view->show();
    prova();

}

void Controller::prova() {
//Gpu* provv= new Gpu("ciao",10,"bello","come",12,10,"anto",13,14,"ciao");
//Gpu* g4=new Gpu("gpu",3, "Nvidia", "Titan", 13 , 2012, "random", 16,12 ,"ciao");
//Smartptr<Item> ciao(g4);
Magazzino* tony=new Magazzino();
//tony->load_database();
//std::cout<<"ciao"<<std::endl;

}
