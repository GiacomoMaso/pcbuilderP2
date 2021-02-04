#include "componente.h"

Componente::Componente(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p) :
       Item(na,q) , marca(m), modello(mo), price(p) {}


double Componente::get_price()const {
    return price;
}

Componente* Componente::clone () const {
    return new Componente(*this);
}

/*std::ostream& operator<<( std::ostream& os, const Componente& c ) {
    os<< "Nome: "<< c.get_name()<< " " << "Prezzo: "<< c.get_price() << std::endl;
    return os;
};

bool Componente::operator==(const Componente& o) const {
    if(price==o.price && get_name()==o.get_name()) return true;
    return false;
}
*/
