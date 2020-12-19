#ifndef CONTENITORE_H
#define CONTENITORE_H

template< class T>
class contenitore {
    friend class Iteratore;
private:
    class Nodo {
        friend class contenitore;
    private:
        T obj;
        Nodo* next;
        Nodo* prec;
    public:
        Nodo(const T&);
        Nodo(const T&  , Nodo*, Nodo* ) ;
    };

    Nodo* first;
    Nodo* last;
public:

    class Iteratore {
    private:
        Nodo* p;
    public:
        Iteratore& operator++();
        Iteratore operator ++(int);
        Iteratore& operator--();
        Iteratore operator--(int);
        Nodo& operator*()const;
        Nodo* operator->() const;

    };

    contenitore(const T&);
    ~contenitore();
    Nodo& operator [](int);
    void add_coda(const T&);
    void add_inizio(const T&);
    Iteratore begin() const;
    Iteratore end() const;
    T get_last() const;  // solo per testing


};

template<class T>
contenitore<T>::Nodo::Nodo(const T& o) : obj(o), next(nullptr), prec(nullptr) {}

template<class T>
contenitore<T>::Nodo::Nodo(const T& o, Nodo* n, Nodo* p) : obj(o), next(n),prec(p) {}; // forse da fare inline per valori di default

template <class T>
contenitore<T>::contenitore(const T& x) : first(new Nodo(x,0,0)) , last(new Nodo (x,0,0)) {};

template <class T>
contenitore<T>::~contenitore() {delete first;};

template<class T>
typename contenitore<T>::Nodo& contenitore<T>:: operator [] (int limit){  //da verificare
    Iteratore it=this->begin();
    for(int i=0; i<limit; i++){
      if(*it==0) return 0;
        it++;
    }
    return *it;
}

template <class T>
void contenitore<T>::add_coda(const T& ogg) {
    Nodo* provv=new Nodo(ogg,0,last);
    last->next=provv;
    last=provv;
}

template <class T>
void contenitore<T>::add_inizio(const T& ogg) {
    Nodo* provv=new Nodo(ogg,first,0);
    first=provv;
}

template <class T>
T contenitore<T>::get_last() const {
    return last->obj;
};

template <class T>
typename contenitore<T>::Iteratore contenitore<T>::begin() const {
    Iteratore punt;
    punt->p=first;
    return punt;
}

template <class T>
typename contenitore<T>::Iteratore contenitore<T>::end() const { //da capire come gestire end iteratore
    Iteratore punt;
    punt->p=last;
    return punt;
}

template<class T>
typename contenitore<T>::Iteratore& contenitore<T>::Iteratore::operator++(){
    if(p) {
        p=p->next;
        return *this;
    }
}

template<class T>
typename contenitore<T>::Iteratore contenitore<T>::Iteratore::operator++(int){
    Iteratore aux;
    if(p) {
        aux=*this;
        p=p->next;
        return aux;
    }
}

template<class T>
typename contenitore<T>::Iteratore& contenitore<T>::Iteratore::operator--(){
    if(p) {
        p=p->prec;
        return *this;
    }
}

template<class T>
typename contenitore<T>::Iteratore contenitore<T>::Iteratore::operator--(int){
    Iteratore aux;
    if(p) {
        aux=*this;
        p=p->prec;
        return aux;
    }
}

template<class T>
typename contenitore<T>::Nodo& contenitore<T>::Iteratore::operator*() const {
    return *p;
}

template<class T>
typename contenitore<T>::Nodo* contenitore<T>::Iteratore::operator->() const { //forse tutto sbagliato
    return p;
}

#endif // CONTENITORE_H
