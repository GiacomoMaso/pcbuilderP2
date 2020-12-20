#include "componente.h"

Componente::Componente(double p, std::string n ) : price(p), name(n)   {}

std::string Componente::get_name()const {
    return name;
}

double Componente::get_price()const {
    return price;
}

Componente* Componente::clone () const {
    return new Componente(*this);
}

std::ostream& operator<<( std::ostream& os, const Componente& c ) {
    os<< "Nome: "<< c.get_name()<< " " << "Prezzo: "<< c.get_price() << std::endl;
    return os;
};

bool Componente::operator==(const Componente& o) const {
    if(price==o.price && name==o.name) return true;
    return false;
}
