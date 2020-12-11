#include "gpu.h"

Gpu::Gpu(double p, std::string n, unsigned int v, unsigned int g, unsigned int type)
    : Componente(p,n), vram(v), gpu_clock(g), type_ram(type) {}

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

