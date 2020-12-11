#ifndef SCONTO_H
#define SCONTO_H
#include "item.h"
#include<string>

class Sconto : public Item{
private:
    std::string name;
    unsigned int percentuale;
public:
    Sconto(std::string ="", unsigned int=0);
    std::string get_name() const;
    unsigned int get_percentuale () const;
    virtual Sconto* clone() const;
};

#endif // SCONTO_H
