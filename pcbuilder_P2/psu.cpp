#include "psu.h"

Psu::Psu(double p, std::string n, unsigned int w, unsigned int r, std::string mod)
    : Componente(p,n), watt(w), rating(r), modularità(mod) {}

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
