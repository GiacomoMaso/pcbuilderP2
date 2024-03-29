#ifndef MEMORIA_H
#define MEMORIA_H
#include "componente.h"
#include<string>

class Memoria : public Componente {
private:
    std::string type_memory;
    unsigned int capacity;  //potrebbe essere string per indicare unità di misura GB/MB
public:
    Memoria(std::string ="",unsigned int q=0, std::string ="", std::string ="", unsigned int p=0,unsigned int re=0, std::string ="", unsigned int=0 );
    std::string get_type_memory() const;
    unsigned int get_capacity() const;
    virtual Memoria* clone() const;
};

#endif // MEMORIA_H
