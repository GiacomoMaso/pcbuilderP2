#include "case.h"

Case::Case(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p, std::string c, std::string mb)
    : Componente(na,q,m,mo,p), case_dim(c), mb_supported(mb) {}

std::string Case::get_case_dim() const{
    return case_dim;
}

std::string Case::get_mb_supported() const{
    return  mb_supported;
}

Case* Case::clone () const {
    return new Case(*this);
}
