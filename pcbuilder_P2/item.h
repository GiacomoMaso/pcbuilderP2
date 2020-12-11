#ifndef ITEM_H
#define ITEM_H
#include<string>


class Item{
public:
    virtual Item* clone () const = 0 ;
    virtual std::string  get_name () const = 0;
    //virtual double get_price () const = 0;

};

#endif // ITEM_H
