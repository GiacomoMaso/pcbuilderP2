#include "item.h"


Item::Item(std::string n, unsigned int q) : name(n), quantita(q)  {}

std::string Item::get_name() const{
    return name;
};

unsigned int Item::get_quantita() const{
    return quantita;
}

void Item::addQuantita(const int & q){
    quantita=quantita+q;
}

void Item::removeOneItem(){
    quantita=quantita-1;
}




