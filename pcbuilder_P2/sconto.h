#ifndef SCONTO_H
#define SCONTO_H
#include "item.h"
#include<string>

class Sconto : public Item{
private:
    unsigned int percentuale;
public:
    Sconto(std::string ="", unsigned int=0);
    unsigned int get_percentuale () const;
    virtual Sconto* clone() const;
};

#endif // SCONTO_H
