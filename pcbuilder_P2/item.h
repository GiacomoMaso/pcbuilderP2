#ifndef ITEM_H
#define ITEM_H
#include<string>


class Item{
  private:
    std::string name;
    unsigned int quantita;
  public:
    Item( std::string , unsigned int =0 );
    virtual Item* clone () const = 0 ;
    std::string get_name() const;
    unsigned int get_quantita() const;
    void addQuantita (const int&);
    void removeOneItem();
    virtual unsigned int product_score () const = 0;
    virtual ~Item() {};

    //virtual double get_price () const = 0;
    //virtual double price_modify () const = 0;
     //virtual std::string build_name () const = 0;
};

#endif // ITEM_H
