#include "gpu.h"

Gpu::Gpu(std::string na,unsigned int q, std::string m, std::string mo,  unsigned int p,unsigned int re, std::string vari, unsigned int v, unsigned int g, std::string type)
    : Componente(na,q,m,mo,p,re), variante(vari), vram(v), gpu_clock(g), type_ram(type) {}

unsigned int Gpu::get_vram() const{
    return vram;
}

unsigned int Gpu::get_gpu_clock() const{
    return gpu_clock;
}

std::string Gpu::get_type_ram() const{
    return type_ram;
}

Gpu* Gpu::clone() const{
    return new Gpu(*this);
}

std::string Gpu::get_variante() const{
    return variante;
}

unsigned int Gpu::product_score() const{
    unsigned int score=0;
    if(vram>=16) score=score+5;
    else if(vram>=8) score=score+4;
    else if(vram>=4) score=score+3;
    else if(vram>=2) score=score+2;
    else score=score+1;
    if(gpu_clock>=1500) score=score+2;
    else if(gpu_clock>=1000) score=score+1;
    if(type_ram=="DDR6") score=score+3;
    else if(type_ram=="DDR5") score=score+2;
    else if(type_ram=="DDR3"|| type_ram=="DDR4") score=score+1;
    return score;
}

