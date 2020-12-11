#ifndef MEMORIA_H
#define MEMORIA_H
#include "componente.h"
#include<string>

class Memoria : public Componente {
private:
    unsigned int type_memory;
    unsigned int capacity;
public:
    Memoria(double = 0, std::string ="", unsigned int =0, unsigned int=0 );
    unsigned int get_type_memory() const;
    unsigned int get_capacity() const;
    virtual Memoria* clone() const;
};

#endif // MEMORIA_H
