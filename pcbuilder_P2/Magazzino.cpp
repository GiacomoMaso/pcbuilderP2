#include "Magazzino.h"
#include <iostream>
#include "item.h"
#include "contenitore.h"
#include "smartptr.h"
#include "cpu.h"
#include "gpu.h"
#include "case.h"
#include "componente.h"
#include "schedamadre.h"

Magazzino::Magazzino(const Smartptr<Item>& p) : lista_ogg(new contenitore<Smartptr<Item>>(p)) {}

void Magazzino::add_compoenente (const Smartptr<Item>& p) {lista_ogg->add_coda(p);}

void Magazzino::filtroCpu() {

    for( contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        Item* provv=*it;
        if(dynamic_cast<Cpu*>(provv)){
            if(lista_filtrata) {
                lista_filtrata->add_coda(provv);
            }
            else{
                lista_filtrata=new contenitore<Item*>(provv);
            }
        }

    }


//    for( contenitore<Item*>::Const_iteratore it=lista_filtrata->inizio(); it!=lista_filtrata->fine() ; it++){
//            std::cout<<(*it)->get_name()<<std::endl;
//    }

}


void Magazzino::filtroGpu() {

    for( contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        Item* provv=*it;
        if(dynamic_cast<Gpu*>(provv)){
            if(lista_filtrata) {
                lista_filtrata->add_coda(provv);
            }
            else{
                lista_filtrata=new contenitore<Item*>(provv);
            }
        }

    }


//    for( contenitore<Item*>::Const_iteratore it=lista_filtrata->inizio(); it!=lista_filtrata->fine() ; it++){
//            std::cout<<(*it)->get_name()<<std::endl;
//    }

}

void Magazzino::filtroCase() {

    for( contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        Item* provv=*it;
        if(dynamic_cast<Case*>(provv)){
            if(lista_filtrata) {
                lista_filtrata->add_coda(provv);
            }
            else{
                lista_filtrata=new contenitore<Item*>(provv);
            }
        }
    }


//    for( contenitore<Item*>::Const_iteratore it=lista_filtrata->inizio(); it!=lista_filtrata->fine() ; it++){
//            std::cout<<(*it)->get_name()<<std::endl;
//    }

}

void Magazzino::filtroSchedaMadre() {

    for( contenitore<Smartptr<Item>>::Const_iteratore it=lista_ogg->inizio(); it!=lista_ogg->fine(); it++){
        Item* provv=*it;
        if(dynamic_cast<SchedaMadre*>(provv)){
            if(lista_filtrata) {
                lista_filtrata->add_coda(provv);
            }
            else{
                lista_filtrata=new contenitore<Item*>(provv);
            }
        }
    }


    for( contenitore<Item*>::Const_iteratore it=lista_filtrata->inizio(); it!=lista_filtrata->fine() ; it++){
            std::cout<<(*it)->get_name()<<std::endl;
    }

}


contenitore<Item*>* Magazzino::get_filtro() {
    return lista_filtrata;
}

contenitore<Smartptr<Item>>* Magazzino::get_lista() {
    return lista_ogg;
}
