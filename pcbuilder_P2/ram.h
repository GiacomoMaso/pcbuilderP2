#ifndef RAM_H
#define RAM_H
#include<string>
#include "memoria.h"

class Ram : public Memoria {
private:
    unsigned int clock;
    unsigned int latency;
    unsigned int num_per_pacco;
public:
    Ram(std::string ="",unsigned int =0, std::string ="", std::string ="", unsigned int =0,unsigned int =0, std::string ="", unsigned int=0, unsigned int=0, unsigned int=0, unsigned int=0);
    unsigned int get_clock() const;
    unsigned int get_latency() const;
    unsigned int get_num_per_pacco() const;
    virtual Ram* clone() const;
};

#endif // RAM_H
