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

    time_t now = time(0);
    tm *ltm = localtime(&now);
    unsigned int year=1900+ ltm->tm_year;
    std::cout<<year;

    if(realese_date ==year){
        score=10;
    }
    else if(realese_date == year-1){
        score=9;
    }
    else if(realese_date >= year-3 && realese_date < year-1){
        score=8;
    }

    else if(realese_date >= year-4 && realese_date < year-3){
        score=7;
    }

    else if(realese_date >= year-9 && realese_date < year-4){
        score=6;
    }

    else if(realese_date >= year-11 && realese_date < year-9){
        score=5;
    }

    else if(realese_date >= year-15 && realese_date < year-11){
        score=4;
    }
    else if(realese_date >= year-20 && realese_date < year-15){
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


