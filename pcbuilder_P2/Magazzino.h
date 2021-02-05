#ifndef MAGAZZINO_H
#define MAGAZZINO_H
#include "contenitore.h"
#include "item.h"
#include "smartptr.h"
#include "cpu.h"

class Magazzino {
private:
    contenitore<Smartptr<Item>> lista_ogg;
    contenitore<Item*> lista_filtrata;
public:
    void add_compoenente (Item*);
    void filtroMarca(std::string);
    void filtroCpu();
    /*void filtroGpu();
    void filtroCase();
    void filtroSchedaMadre();
    void filtroPsu();
    void filtroPrezzo();
    */
};

#endif // MAGAZZINO_H
