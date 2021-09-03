#include "item.h"


Item::Item(std::string n, unsigned int q) : name(n), quantita(q)  {}

std::string Item::get_name() const{
    return name;
};

unsigned int Item::get_quantita() const{
    return quantita;
}




