#include "cpu.h"

Cpu::Cpu(std::string na, unsigned int q, std::string m, std::string mo,  unsigned int p, unsigned int re, std::string se, double gh, unsigned int core, std::string soc )
    : Componente(na,q,m,mo,p,re), serie(se), ghz(gh), core_number(core), socket(soc) {}

double Cpu::get_ghz () const{
    return ghz;
}

unsigned int Cpu::get_core_number () const{
    return core_number;
}


std::string Cpu::get_socket() const {
    return socket;
}

Cpu* Cpu::clone () const {
    return new Cpu(*this);
}

std::string Cpu::get_serie() const{
    return serie;
}

unsigned int Cpu::product_score() const{
    unsigned int score=0;
    if(ghz>5) score=score+5;
    else if(ghz>=4)score=score+4;
    else if(ghz>=3)score=score+3;
    if(core_number>=10)score=score+5;
    else if(core_number>=8) score=score+4;
    else if(core_number>=4) score=score+3;

    return score;

}
