#include "ram.h"

Ram::Ram(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p,unsigned int re, std::string ty, unsigned int c, unsigned int clo, unsigned int lat)
    : Memoria(na,q,m,mo,p,re,ty,c), clock(clo), latency(lat) {}

unsigned int Ram::get_clock() const{
    return clock;
}

unsigned int Ram::get_latency() const{
    return latency;
}

Ram* Ram::clone() const{
    return new Ram(*this);
}

//unsigned int Ram::get_num_per_pacco() const{
//    return num_per_pacco;
//}

unsigned int Ram::product_score() const{
    unsigned int score=0;
    if(clock>=3200) score=score+5;
    else if(clock>=3000) score=score+4;
    else if(clock>=2800) score=score+3;
    else if(clock>=2500) score=score+2;
    else score=score+1;
    if(latency<=14) score=score+5;
    else if(latency<=15) score=score+4;
    else if(latency<=16) score=score+3;
    else score=score+2;

    return score;
}
