#ifndef ITEM_H
#define ITEM_H
#include<string>


class Item{
  private:
    std::string name;
    unsigned int quantità;
  public:
    Item(std::string = "", unsigned int =0 );
    virtual Item* clone () const = 0 ;
    virtual std::string  get_name () const ;
    //virtual double get_price () const = 0;

};

#endif // ITEM_H
