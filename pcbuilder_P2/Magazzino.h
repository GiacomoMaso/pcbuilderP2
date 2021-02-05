#ifndef MAGAZZINO_H
#define MAGAZZINO_H
#include "contenitore.h"
#include "item.h"
#include "smartptr.h"


class Magazzino {
private:

    contenitore<Smartptr<Item>> lista_ogg;
public:
    void add_compoenente (Item*);

};

#endif // MAGAZZINO_H
