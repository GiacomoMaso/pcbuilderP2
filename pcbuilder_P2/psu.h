#ifndef PSU_H
#define PSU_H
#include "componente.h"
#include<string>

class Psu : public Componente {
private:
    unsigned int watt;
    std::string rating;
    std::string modularita;
public:
    Psu(std::string ="",unsigned int =0, std::string ="", std::string ="", unsigned int =0,unsigned int =0, unsigned int =0, std::string="", std::string ="");
    virtual Psu* clone() const;
    virtual unsigned int product_score() const;
    unsigned int get_watt() const;
    std::string get_rating() const;
    std::string get_mod() const;

};

#endif // PSU_H
