#include "ram.h"

Ram::Ram(double p, std::string n, unsigned int type, unsigned int cap, unsigned int clo, unsigned int lat)
    : Memoria(p,n,type,cap), clock(clo), latency(lat) {}

unsigned int Ram::get_clock() const{
    return clock;
}

unsigned int Ram::get_latency() const{
    return latency;
}

Ram* Ram::clone() const{
    return new Ram(*this);
}
