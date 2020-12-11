#include "sconto.h"

Sconto::Sconto(std::string n, unsigned int p) : name(n), percentuale(p) {}

std::string Sconto::get_name() const {
    return name;
}

unsigned int Sconto::get_percentuale() const{
    return percentuale;
}

Sconto* Sconto::clone() const{
    return new Sconto(*this);
}
