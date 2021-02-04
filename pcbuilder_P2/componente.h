#ifndef COMPONENTE_H
#define COMPONENTE_H
#include<iostream>
#include "item.h"

class Componente : public Item {
private:
   double price;
public:
    Componente(double = 0, std::string ="", unsigned int q=0 );
    virtual Componente* clone () const;
    double get_price() const;
    friend std::ostream& operator<<( std::ostream&, const Componente& );
    bool operator==(const Componente&) const;
};

#endif // COMPONENTE_H
