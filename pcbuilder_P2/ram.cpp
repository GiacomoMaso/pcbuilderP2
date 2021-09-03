#include "ram.h"

Ram::Ram(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p,unsigned int re, std::string ty, unsigned int c, unsigned int clo, unsigned int lat, unsigned int n_sc)
    : Memoria(na,q,m,mo,p,re,ty,c), clock(clo), latency(lat), num_per_pacco(n_sc) {}

unsigned int Ram::get_clock() const{
    return clock;
}

unsigned int Ram::get_latency() const{
    return latency;
}

Ram* Ram::clone() const{
    return new Ram(*this);
}

unsigned int Ram::get_num_per_pacco() const{
    return num_per_pacco;
}
