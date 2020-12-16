#ifndef CONTENITORE_H
#define CONTENITORE_H

template< class T>
class contenitore {
private:
    class Nodo {
        friend class contenitore;
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
    contenitore(const T&);
    ~contenitore();
    void add_coda(const T&);
    T get_last() const;
};

template<class T>
contenitore<T>::Nodo::Nodo(const T& o, Nodo* n, Nodo* p) : obj(o), next(n),prec(p) {}; // forse da fare inline per valori di default

template <class T>
contenitore<T>::contenitore(const T& x) : first(new Nodo(x,0,0)) , last(new Nodo (x,0,0)) {};

template <class T>
contenitore<T>::~contenitore() {delete first;};

template <class T>
void contenitore<T>::add_coda(const T& ogg) {
    Nodo* provv=new Nodo(ogg,0,0);
    last->next=provv;
    last=provv;
}

template <class T>
T contenitore<T>::get_last() const {
    return last->obj;
};




#endif // CONTENITORE_H
