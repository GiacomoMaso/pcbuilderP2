#ifndef CPU_H
#define CPU_H
#include "componente.h"
#include<string>

class Cpu : public Componente {
private:
    std::string serie;
    double ghz;
    unsigned int core_number;
//    std::string intel_AMD;
    std::string socket;
public:
    Cpu(std::string ="",unsigned int q=0, std::string ="", std::string ="", unsigned int p=0 , unsigned int re=0, std::string ="", double =0, unsigned int =0, std::string ="" );
    virtual Cpu* clone() const;
    virtual unsigned int product_score() const;
    double get_ghz () const;
    unsigned int get_core_number () const;
    std::string get_socket () const;
    std::string get_serie() const;

};

#endif // CPU_H
