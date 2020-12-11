#include "rom.h"

Rom::Rom(double p, std::string n, unsigned int t, unsigned int c, double m_w, double m_r, double s)
    : Memoria(p,n,t,c), mb_write(m_w), mb_read(m_r), size(s) {}

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
