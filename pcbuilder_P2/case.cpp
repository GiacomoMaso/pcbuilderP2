#include "case.h"

Case::Case(double p, std::string n, std::string c, std::string mb): Componente(p,n), case_dim(c), mb_supported(mb){}

std::string Case::get_case_dim() const{
    return case_dim;
}

std::string Case::get_mb_supported() const{
    return  mb_supported;
}

Case* Case::clone () const {
    return new Case(*this);
}
