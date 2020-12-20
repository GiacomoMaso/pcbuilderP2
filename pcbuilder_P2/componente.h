#ifndef COMPONENTE_H
#define COMPONENTE_H
#include<iostream>
#include "item.h"

class Componente : public Item {
private:
   double price;
   std::string name;

public:
    Componente(double = 0, std::string ="" );
    virtual Componente* clone () const;
    double get_price() const;
    std::string get_name()const;
    friend std::ostream& operator<<( std::ostream&, const Componente& );
    bool operator==(const Componente&) const;
};

#endif // COMPONENTE_H
