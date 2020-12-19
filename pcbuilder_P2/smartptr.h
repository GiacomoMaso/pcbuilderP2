#ifndef SMARTPTR_H
#define SMARTPTR_H

template<class T>
class Smartptr {
private:
    T* ptr;
public:
    Smartptr(const T*);
    ~Smartptr();
};

template <class T>
Smartptr<T>::Smartptr (const T* p) : ptr(new T(*p)){}

template <class T>
Smartptr<T>::~Smartptr() {
    delete ptr;
}
#endif // SMARTPTR_H
