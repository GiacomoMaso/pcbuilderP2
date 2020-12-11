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
