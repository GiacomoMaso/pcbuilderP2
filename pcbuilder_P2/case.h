#ifndef CASE_H
#define CASE_H
#include "componente.h"
#include<string>

class Case : public Componente {
private:
    std::string case_dim;
    std::string mb_supported;
public:
    Case(double = 0, std::string ="", std::string ="", std::string ="" );
    virtual Case* clone () const;
    std::string get_case_dim() const;
    std::string get_mb_supported() const;
};

#endif // CASE_H
