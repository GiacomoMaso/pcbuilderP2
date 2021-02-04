#include "item.h"


Item::Item(std::string n, unsigned int q) : name(n), quantità(q)  {}

std::string Item::get_name() const {return name;}


