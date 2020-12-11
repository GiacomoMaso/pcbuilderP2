#ifndef PSU_H
#define PSU_H
#include "componente.h"
#include<string>

class Psu : public Componente {
private:
    unsigned int watt;
    unsigned int rating;
    std::string modularità;
public:
    Psu(double =0, std::string ="", unsigned int =0, unsigned int =0, std::string ="");
    unsigned int get_watt() const;
    unsigned int get_rating() const;
    std::string get_mod() const;
    virtual Psu* clone() const;
};

#endif // PSU_H
