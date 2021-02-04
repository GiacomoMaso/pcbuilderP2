#ifndef SCONTRINO_H
#define SCONTRINO_H
#include "contenitore.h"
#include "smartptr.h"
#include "item.h"

class Scontrino {
private:
   contenitore<Smartptr<Item>> list;
   double totale;
public:

};
