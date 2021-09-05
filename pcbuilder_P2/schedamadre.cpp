#include "schedamadre.h"

SchedaMadre::SchedaMadre(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p,unsigned int re, std::string ga, std::string s_mb, unsigned int sata_p, unsigned int nvme_p)
            : Componente(na,q,m,mo,p,re), grandezza(ga), socket_mb(s_mb), sata_port(sata_p), nvme_port(nvme_p) {}


std::string SchedaMadre::get_grandezza() const{
    return grandezza;
}

std::string SchedaMadre::get_socket_mb() const{
    return socket_mb;
}

unsigned int SchedaMadre::get_sata_port() const{
    return sata_port;
}

unsigned int SchedaMadre::get_nvme_port() const{
    return nvme_port;
}

SchedaMadre* SchedaMadre::clone() const{
    return new SchedaMadre(*this);
}
