#include "schedamadre.h"

SchedaMadre::SchedaMadre(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p, std::string ga, std::string s_mb, unsigned int sata_p, unsigned int nvme_p)
            : Componente(na,q,m,mo,p), grandezza(ga), socket_mb(s_mb), sata_port(sata_p), nvme_port(nvme_p) {}
