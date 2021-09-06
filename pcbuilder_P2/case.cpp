#include "case.h"

Case::Case(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p, unsigned int re, std::string c, std::string mb)
    : Componente(na,q,m,mo,p,re), case_dim(c), mb_supported(mb) {}

std::string Case::get_case_dim() const{
    return case_dim;
}

std::string Case::get_mb_supported() const{
    return  mb_supported;
}

Case* Case::clone () const {
    return new Case(*this);
}

unsigned int Case::product_score() const{
    unsigned int score=0;
    if(case_dim=="Full-tower") score=score+5;
    else if(case_dim=="Mid-tower")score=score+4;
    else if(case_dim=="Mini-tower")score=score+3;
    if(mb_supported=="ATX") score=score+5;
    else if(mb_supported=="MicroATX") score=score+4;
    else if(mb_supported=="MiniATX") score=score+3;

    return score;
}
