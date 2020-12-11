#include "cpu.h"

Cpu::Cpu(double p, std::string n, unsigned int gh, unsigned int core, std::string i_a, std::string soc)
    : Componente(p,n), ghz(gh), core_number(core), intel_AMD(i_a), socket(soc) {}

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
