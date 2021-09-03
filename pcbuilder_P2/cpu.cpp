#include "cpu.h"

Cpu::Cpu(std::string na, unsigned int q, std::string m, std::string mo,  unsigned int p, unsigned int re, std::string se, unsigned int gh, unsigned int core, std::string i_a, std::string soc )
    : Componente(na,q,m,mo,p,re), serie(se), ghz(gh), core_number(core), intel_AMD(i_a), socket(soc) {}

unsigned int Cpu::get_ghz () const{
    return ghz;
}

unsigned int Cpu::get_core_number () const{
    return core_number;
}

std::string Cpu::get_intel_AMD() const {
    return intel_AMD;
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
