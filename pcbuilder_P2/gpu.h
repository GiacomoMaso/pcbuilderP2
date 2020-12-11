#ifndef GPU_H
#define GPU_H
#include "componente.h"

class Gpu : public Componente {
private:
    unsigned int vram;
    unsigned int gpu_clock;
    unsigned int type_ram;
public:
    Gpu(double = 0, std::string ="", unsigned int =0, unsigned int =0, unsigned int =0 );
    virtual Gpu* clone() const;
    unsigned int get_vram() const;
    unsigned int get_gpu_clock() const;
    unsigned int get_type_ram() const;
};

#endif // GPU_H
