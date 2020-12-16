#ifndef CONTENITORE_H
#define CONTENITORE_H

template< class T>
class contenitore {
private:
    class Nodo {
    private:
        T obj;
        Nodo* next;
        Nodo* prec;
    public:
        Nodo(const T&  , Nodo*, Nodo* ) ;
    };

    Nodo* first;
    Nodo* last;
public:
    contenitore(Nodo*);
    ~contenitore();
    void add_coda(Nodo*);
};

template<class T>
contenitore<T>::Nodo::Nodo(const T& o, Nodo* n, Nodo* p) : obj(o), next(n),prec(p) {}; // forse da fare inline per valori di default

template <class T>
contenitore<T>::contenitore(Nodo* x) : first(x), last(x) {};

template <class T>
contenitore<T>::~contenitore() {delete first;};

template <class T>
void contenitore<T>::add_coda(Nodo* ogg) {
    last->next=ogg;
    ogg=last;
}





#endif // CONTENITORE_H
