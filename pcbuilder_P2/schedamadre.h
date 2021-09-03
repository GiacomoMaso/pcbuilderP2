#ifndef SCHEDAMADRE_H
#define SCHEDAMADRE_H
#include "componente.h"

class SchedaMadre : public Componente {
private:
    std::string grandezza;
    std::string socket_mb;
    unsigned int sata_port;
    unsigned int nvme_port;

public:
    SchedaMadre(std::string ="",unsigned int =0, std::string ="", std::string ="", unsigned int =0,unsigned int =0, std::string ="", std::string ="", unsigned int =0, unsigned int=0);
    std::string get_grandezza() const;
    std::string get_socket_mb() const;
    unsigned int get_sata_port() const;
    unsigned int get_nvme_port() const;

};

#endif // SCHEDAMADRE_H
