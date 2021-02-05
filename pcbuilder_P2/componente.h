#ifndef COMPONENTE_H
#define COMPONENTE_H
#include<iostream>
#include "item.h"

class Componente : public Item {
private:
   std::string marca;
   std::string modello;
   double price;
public:
    Componente(std::string ="",unsigned int =0, std::string ="", std::string ="", unsigned int =0 );
    virtual Componente* clone () const;
    double get_price() const;
    //virtual double price_modify () const;
    bool operator==(const Componente&) const;
    friend std::ostream& operator<<( std::ostream&, const Componente& );
    //virtual std::string build_name() const;

};

#endif // COMPONENTE_H
