#include "memoria.h"

Memoria::Memoria(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p,unsigned int re, std::string ty, unsigned int c )
        : Componente(na,q,m,mo,p,re), type_memory(ty), capacity(c) {}

std::string Memoria::get_type_memory() const{
    return type_memory;
}

unsigned int Memoria::get_capacity() const{
    return capacity;
}

Memoria* Memoria::clone() const {
    return new Memoria(*this);
}
