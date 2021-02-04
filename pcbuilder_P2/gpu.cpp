#include "gpu.h"

Gpu::Gpu(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p, std::string vari, unsigned int v, unsigned int g, unsigned int type)
    : Componente(na,q,m,mo,p), variante(vari), vram(v), gpu_clock(g), type_ram(type) {}

unsigned int Gpu::get_vram() const{
    return vram;
}

unsigned int Gpu::get_gpu_clock() const{
    return gpu_clock;
}

unsigned int Gpu::get_type_ram() const{
    return type_ram;
}

Gpu* Gpu::clone() const{
    return new Gpu(*this);
}

