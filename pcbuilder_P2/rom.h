#ifndef ROM_H
#define ROM_H
#include "memoria.h"
#include <string>

class Rom : public Memoria {
private:

    double mb_write;
    double mb_read;
    double size;
public:
    Rom(std::string ="",unsigned int =0, std::string ="", std::string ="", unsigned int =0,unsigned int =0, std::string ="", unsigned int=0, double=0, double=0, double=0);
    double get_mb_write() const;
    double get_mb_read() const;
    double get_size() const;
    virtual Rom* clone() const;
};

#endif // ROM_H
