#ifndef GPU_H
#define GPU_H
#include "componente.h"

class Gpu : public Componente {
private:
    std::string variante;
    unsigned int vram;
    unsigned int gpu_clock;
    std::string type_ram;
public:
    Gpu(std::string ="",unsigned int q=0, std::string ="", std::string ="", unsigned int p=0,unsigned int re=0, std::string ="", unsigned int =0, unsigned int =0, std::string ="" );
    virtual Gpu* clone() const;
    unsigned int get_vram() const;
    unsigned int get_gpu_clock() const;
    std::string get_type_ram() const;
};

#endif // GPU_H
