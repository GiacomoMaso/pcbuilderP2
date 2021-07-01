#ifndef COMPONENTE_H
#define COMPONENTE_H
#include<iostream>
#include "item.h"

class Componente : public Item {
private:
   std::string marca;
   std::string modello;
   double price;
   unsigned int realese_date;
public:
    Componente(std::string ="",unsigned int =0, std::string ="", std::string ="", unsigned int =0, unsigned int =0 );
    virtual Componente* clone () const;
    double get_price() const;
    bool operator==(const Componente&) const;
    std::string get_marca() const;
    virtual unsigned int product_score () const;
    friend std::ostream& operator<<( std::ostream&, const Componente& );


    //virtual double price_modify () const;
    //virtual std::string build_name() const;
};

#endif // COMPONENTE_H
