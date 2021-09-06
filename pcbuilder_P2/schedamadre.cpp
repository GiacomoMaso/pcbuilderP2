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

unsigned int SchedaMadre::product_score() const{
    unsigned int score=0;
    if(grandezza=="ATX") score=score+5;
    else if(grandezza=="Micro-ATX") score=score+4;
    else if(grandezza=="Mini-ATX") score=score+3;
    else score=score+2;
    if(sata_port>=5) score=score+3;
    else if(sata_port>3)score=score+2;
    else score=score+1;
    if(nvme_port>=3) score=score+2;
    else if(nvme_port>=2) score=score+1;
    return score;

}
