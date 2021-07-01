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
