#include "rom.h"

Rom::Rom(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p,unsigned int re, std::string ty, unsigned int c, double m_w, double m_r, double s)
    : Memoria(na,q,m,mo,p,re,ty,c), mb_write(m_w), mb_read(m_r), size(s) {}

double Rom::get_mb_write() const{
    return mb_write;
}

double Rom::get_mb_read() const{
    return mb_read;
}

double Rom::get_size() const{
    return size;
}

Rom* Rom::clone() const{
    return new Rom(*this);
}

unsigned int Rom::product_score() const{
    unsigned int score=0;
    if(get_capacity()>=2000) score=score+5;
    else if(get_capacity()>=1000) score=score+4;
    else if(get_capacity()>=500) score=score+3;
    else if(get_capacity()>=250) score=score+2;
    else score=score+1;
    if(mb_read >=1000 && mb_write>= 500) score=score+5;
    else if(mb_read>=500 && mb_write>=250) score=score+3;
    else if(mb_read>=250 && mb_write>=125) score=score+2;
    else score=score+1;
    return score;
}
