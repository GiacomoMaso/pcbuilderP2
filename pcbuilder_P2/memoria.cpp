#include "memoria.h"

Memoria::Memoria(double p, std::string n, unsigned int t, unsigned int c )
        : Componente(p,n), type_memory(t), capacity(c){}

unsigned int Memoria::get_type_memory() const{
    return type_memory;
}

unsigned int Memoria::get_capacity() const{
    return capacity;
}

Memoria* Memoria::clone() const {
    return new Memoria(*this);
}
