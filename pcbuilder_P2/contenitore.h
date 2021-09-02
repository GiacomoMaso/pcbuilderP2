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
        Nodo(const T&  , Nodo*, Nodo* );
        T get_obj() const;
        bool operator==(const Nodo&) const;

    };

    Nodo* first;
    Nodo* last;
public:

    class Iteratore {
        friend class contenitore;
    private:
        Nodo* p;
        Iteratore();
        Iteratore(Nodo*);
    public:

        Iteratore& operator++();
        Iteratore operator ++(int);
        Iteratore& operator--();
        Iteratore operator--(int);
        T& operator*()const;
        T* operator->() const;
        bool operator== (const Iteratore&) const;
        bool operator!= (const Iteratore&) const;

    };

    class Const_iteratore {
        friend class contenitore;
    private:
        const Nodo* p;
        Const_iteratore();
        Const_iteratore(Nodo*);
    public:
        Const_iteratore& operator++();
        Const_iteratore operator ++(int);
        Const_iteratore& operator--();
        Const_iteratore operator--(int);
        const T& operator*()const;
        const T* operator->() const;
        bool operator== (const Const_iteratore&) const;
        bool operator!= (const Const_iteratore&) const;

    };

    contenitore(const T&);
    contenitore(T*);
    ~contenitore();
    Nodo& operator [](int);
    void add_coda(const T&);
    void add_inizio(const T&);
    Iteratore begin();
    Iteratore end();
    Const_iteratore inizio() const;
    Const_iteratore fine() const ;
    T get_last() const;  // solo per testing
    Nodo* remove_node(Nodo*);
    void delete_node(Iteratore& );

};

template<class T>
contenitore<T>::Nodo::Nodo(const T& o) : obj(o), next(nullptr), prec(nullptr) {}

template<class T>
contenitore<T>::Nodo::Nodo(const T& o, Nodo* n, Nodo* p) : obj(o), next(n),prec(p) {}; // forse da fare inline per valori di default

template <class T>
T contenitore<T>::Nodo::get_obj() const {
    return obj;
}


template <class T>
contenitore<T>::contenitore(const T& x) : first(new Nodo(x,0,0)) {last=first; };// da verificare

template <class T>
contenitore<T>::contenitore( T* x) : first(new Nodo(x,0,0)) {last=first; };

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

template<class T>
contenitore<T>::Iteratore::Iteratore() : p(nullptr) {}

template<class T>
contenitore<T>::Const_iteratore::Const_iteratore() : p(nullptr) {}

template<class T>
contenitore<T>::Iteratore::Iteratore(Nodo* x) : p(x) {}

template<class T>
contenitore<T>::Const_iteratore::Const_iteratore(Nodo* x) : p(x) {}

template <class T>
typename contenitore<T>::Iteratore contenitore<T>::begin() {
   /* Iteratore ciao;
    punt.p=first;
    */
    Iteratore punt (first);
    return punt;
}

template <class T>
typename contenitore<T>::Iteratore contenitore<T>::end() { //da capire come gestire end iteratore
    /*Iteratore punt;
    punt.p=last;
    return punt;*/

    return Iteratore(nullptr);
}

template <class T>
typename contenitore<T>::Const_iteratore contenitore<T>::inizio() const  {
//    Const_iteratore punt;
//        punt.p=first;
//        return punt;
    Const_iteratore punt(first);
    return punt;
}

template <class T>
typename contenitore<T>::Const_iteratore contenitore<T>::fine() const  { //da capire come gestire end iteratore
    /*Iteratore punt;
    punt.p=last;
    return punt;
    */
    return Const_iteratore(nullptr);
}

template<class T>
typename contenitore<T>::Iteratore& contenitore<T>::Iteratore::operator++(){
    if(p) {
        p=p->next;
        return *this;
    }
//    else{
        return *this;
//    }
}

template<class T>
typename contenitore<T>::Iteratore contenitore<T>::Iteratore::operator++(int){
    Iteratore aux(nullptr);
    if(p) {
        aux=*this;
        p=p->next;
    }
    return aux;
}

template<class T>
typename contenitore<T>::Iteratore& contenitore<T>::Iteratore::operator--(){
    if(p) {
        p=p->prec;
        return *this;
    }
    return *this;
}

template<class T>
typename contenitore<T>::Iteratore contenitore<T>::Iteratore::operator--(int){
    Iteratore aux(nullptr);
    if(p) {
        aux=*this;
        p=p->prec;
    }
    return aux;

}

template<class T>
T& contenitore<T>::Iteratore::operator*() const {
    return p->obj;
}

template<class T>
T* contenitore<T>::Iteratore::operator->() const { //forse tutto sbagliato
    return p;
}

template<class T>
typename contenitore<T>::Const_iteratore& contenitore<T>::Const_iteratore::operator++(){
    if(p) {
        p=p->next;
        return *this;
    }
    return *this;
}

template<class T>
typename contenitore<T>::Const_iteratore contenitore<T>::Const_iteratore::operator++(int){
    Const_iteratore aux(nullptr);
    if(p) {
        aux=*this;
        p=p->next;
        return aux;
    }
    return aux;
}

template<class T>
typename contenitore<T>::Const_iteratore& contenitore<T>::Const_iteratore::operator--(){
    if(p) {
        p=p->prec;
        return *this;
    }
    return nullptr;
}

template<class T>
typename contenitore<T>::Const_iteratore contenitore<T>::Const_iteratore::operator--(int){
    Iteratore aux(nullptr);
    if(p) {
        aux=*this;
        p=p->prec;
        return aux;
    }
    return *this;
}

template<class T>
const T& contenitore<T>::Const_iteratore::operator*() const {
    return p->obj;
}

template<class T>
const T* contenitore<T>::Const_iteratore::operator->() const { //forse tutto sbagliato
    return p;
}

template <class T>
bool contenitore<T>::Nodo::operator==(const Nodo& o) const { // per funzionare bisogna fare overloading operatore su ogg
    return obj==o.obj;
}

template<class T>
bool contenitore<T>::Iteratore::operator==(const Iteratore& i) const { // da verificare
    return this->p==i.p;
}

template<class T>
bool contenitore<T>::Iteratore::operator!=(const Iteratore& i) const { // da verificare
    return this->p!=i.p;
}

template<class T>
bool contenitore<T>::Const_iteratore::operator==(const Const_iteratore& i) const { // da verificare
    return this->p==i.p;
}

template<class T>
bool contenitore<T>::Const_iteratore::operator!=(const Const_iteratore& i) const { // da verificare
    return this->p!=i.p;
}

template<class T>
typename contenitore<T>::Nodo* contenitore<T>::remove_node(Nodo* x) {
Nodo* provv=x->next;
x->obj=x->next->obj;
x->next=x->next->next;
delete provv;
return x;
    //Nodo* provv=x;
    //if(x->prec){
        //x->prec->next=x->next;
        //delete provv;
        //return x;


}

template<class T>
void contenitore<T>::delete_node( Iteratore& it){
    Nodo* provv=it.p;
    if(!it.p->prec && !it.p->next){
        it.p=nullptr;
        first=nullptr;
        last=nullptr;

    }
    else if(!it.p->prec){
        it.p->next->prec=nullptr;
        first=it.p->next;
        it.p=it.p->next;
    }
    else if(!it.p->next){
        it.p->prec->next=nullptr;
        it.p=it.p->prec;

    }
    else{
    it.p->prec->next=it.p->next;
    it.p->next->prec=it.p->prec;
    it.p=it.p->prec;}
    delete provv;
}




#endif // CONTENITORE_H
