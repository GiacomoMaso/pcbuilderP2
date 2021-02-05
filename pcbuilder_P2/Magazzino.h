#ifndef MAGAZZINO_H
#define MAGAZZINO_H
#include "contenitore.h"
#include "item.h"


class Magazzino {
private:
    contenitore<Item*> lista_ogg;
public:
    void add_compoenente (Item*);
};

#endif // MAGAZZINO_H
