#include "componente.h"

Componente::Componente(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p, unsigned int re) :
       Item(na,q) , marca(m), modello(mo), price(p), realese_date(re) {}


double Componente::get_price()const {
    return price;
}

Componente* Componente::clone () const {
    return new Componente(*this);
}

std::ostream& operator<<( std::ostream& os, const Componente& c ) {
    os<< "Nome: "<< c.get_marca()<< " " << std::endl;
    return os;
};

std::string Componente::get_marca() const {
    return marca;
}

unsigned int Componente::product_score() const{
    unsigned int score=0;
    if(realese_date ==2021){
        score=10;
    }
    else if(realese_date == 2020){
        score=9;
    }
    else if(realese_date > 2018 && realese_date < 2020){
        score=8;
    }

    else if(realese_date > 2016 && realese_date < 2018){
        score=7;
    }

    else if(realese_date > 2013 && realese_date < 2016){
        score=6;
    }

    else if(realese_date > 2010 && realese_date < 2013){
        score=5;
    }

    else if(realese_date > 2005 && realese_date < 2010){
        score=4;
    }
    else if(realese_date > 2000 && realese_date < 2005){
        score=3;
    }

    return score;
}



/*
bool Componente::operator==(const Componente& o) const {
    if(price==o.price && get_name()==o.get_name()) return true;
    return false;
}
*/


