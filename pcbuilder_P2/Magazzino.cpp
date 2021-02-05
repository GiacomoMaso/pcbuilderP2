#include "Magazzino.h"

//void Magazzino::add_compoenente (Item* obj) {lista_ogg.add_coda(Smartptr<Item*>(obj));}

void Magazzino::filtroCpu() {
    for(contenitore<Smartptr<Item>>::Iteratore it=lista_ogg.begin(); it != lista_ogg.end(); it++){

        Item* provv=*it;
        if(dynamic_cast<Cpu*>(provv)){
            lista_filtrata.add_coda(provv);
        }
    }
}
