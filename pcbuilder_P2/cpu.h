#ifndef CPU_H
#define CPU_H
#include "componente.h"
#include<string>

class Cpu : public Componente {
private:
    unsigned int ghz;
    unsigned int core_number;
    std::string intel_AMD;
    std::string socket;
public:
    Cpu(double = 0, std::string ="", unsigned int =0, unsigned int =0, std::string ="", std::string ="" );
    virtual Cpu* clone() const;
    unsigned int get_ghz () const;
    unsigned int get_core_number () const;
    std::string get_intel_AMD () const;
    std::string get_socket () const;
};

#endif // CPU_H
