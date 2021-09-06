#include "psu.h"

Psu::Psu(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p,unsigned int re, unsigned int w, std::string r, std::string mod)
    : Componente(na,q,m,mo,p,re), watt(w), rating(r), modularita(mod) {}

unsigned int Psu::get_watt() const{
    return watt;
}

std::string Psu::get_rating() const{
    return rating;
}

std::string Psu::get_mod() const{
    return modularita;
}

Psu* Psu::clone() const{
    return new Psu(*this);
}

unsigned int Psu::product_score() const{
    unsigned int score=0;
    if(watt>=1500) score=score+5;
    else if(watt>=1000) score=score+4;
    else if(watt>=800) score=score+3;
    else if(watt>=500) score=score+2;
    else score=score+1;
    if(rating>="Gold") score=score+3;
    else if(rating>="Silver") score=score+2;
    else if(rating>="Bronze") score=score+1;
    if(modularita=="Si") score=score+2;
    return score;
}
