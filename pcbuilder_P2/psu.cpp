#include "psu.h"

Psu::Psu(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p,unsigned int re, unsigned int w, unsigned int r, std::string mod)
    : Componente(na,q,m,mo,p,re), watt(w), rating(r), modularita(mod) {}

unsigned int Psu::get_watt() const{
    return watt;
}

unsigned int Psu::get_rating() const{
    return rating;
}

std::string Psu::get_mod() const{
    return modularita;
}

Psu* Psu::clone() const{
    return new Psu(*this);
}
