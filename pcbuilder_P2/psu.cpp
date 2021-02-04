#include "psu.h"

Psu::Psu(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p, unsigned int w, unsigned int r, std::string mod)
    : Componente(na,q,m,mo,p), watt(w), rating(r), modularità(mod) {}

unsigned int Psu::get_watt() const{
    return watt;
}

unsigned int Psu::get_rating() const{
    return rating;
}

std::string Psu::get_mod() const{
    return modularità;
}

Psu* Psu::clone() const{
    return new Psu(*this);
}
