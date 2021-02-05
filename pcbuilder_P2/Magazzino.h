#ifndef MAGAZZINO_H
#define MAGAZZINO_H
#include "contenitore.h"
#include "item.h"


class Magazzino {
private:
    contenitore<Item*> lista_ogg;
public:
    void add_compoenente (Item*);
    void delete_componente (std::string);
};

#endif // MAGAZZINO_H
