#ifndef SMARTPTR_H
#define SMARTPTR_H

template<class T>
class Smartptr {
private:
    T* ptr;
public:
    Smartptr(T*);
    Smartptr(const Smartptr&);
    ~Smartptr();
    T& operator *() const;
    T* operator->() const;
    Smartptr& operator=(const Smartptr&);
    bool operator ==(const Smartptr&) const;
    bool operator !=(const Smartptr&) const;
    operator T*() const;
};

/*template <class T>
Smartptr<T>::Smartptr (const T* p) : ptr(p ? new T(*p) : 0) {} //da verificare
*/
template <class T>
Smartptr<T>::Smartptr( T* p) : ptr(p ? p : 0) {}

template <class T>
Smartptr<T>::Smartptr(const Smartptr& o){
    if(o.ptr != nullptr){
        if(ptr) delete ptr;
        //ptr=new T(*(o.ptr));
        ptr=o.ptr->clone();
    }
}

template <class T>
Smartptr<T>::~Smartptr() {
    delete ptr;
}

template<class T>
T& Smartptr<T>::operator*()const {
    return *ptr;
}

template<class T>
T* Smartptr<T>::operator->() const {
    return ptr;
}

template <class T>
Smartptr<T>& Smartptr<T>::operator= (const Smartptr& o){
    if(this != &o ){
        if(ptr) delete ptr;
        ptr=new T(*(o.ptr));
    }
    return *this;
}

template <class T>
bool Smartptr<T>::operator==(const Smartptr& o) const {
    return *(ptr)==*(o.ptr);
}

template <class T>
bool Smartptr<T>::operator!=(const Smartptr& o) const {
    return *(ptr)!=*(o.ptr);
}

template <class T>
Smartptr<T>::operator T *() const {
    return ptr;
}

#endif // SMARTPTR_H
