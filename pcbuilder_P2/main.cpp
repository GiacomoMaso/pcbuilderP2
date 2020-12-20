#include <iostream>
#include "componente.h"
#include "contenitore.h"
using namespace std;

int main()
{

    Componente Tastiera(120, "corsair");
    Componente Ciao (299, "jhonny");
    Componente Ciao1 (299, "jhonny2");
    Componente Ciao2 (299, "jhonny3");
    Componente Ciao3 (299, "jhonny4");
    Componente Ciao4 (299, "jhonny5");
    Componente Ciao5 (299, "jhonny6");
    Componente Ciao6 (299, "jhonny7");
    Componente Ciao7 (299, "jhonny8");
    Componente Ciao8 (299, "jhonny9");
    Componente Ciao9 (299, "jhonnyfinal");

    contenitore<Componente> lista(Ciao);
    lista.add_coda(Ciao1);
    lista.add_coda(Ciao2);
    lista.add_coda(Ciao3);
    lista.add_coda(Ciao4);
    lista.add_coda(Ciao5);
    lista.add_coda(Ciao6);
    lista.add_coda(Ciao7);
    lista.add_inizio(Ciao8);
    lista.add_coda(Ciao9);


    for( contenitore<Componente>::Iteratore it=lista.begin(); it!=lista.end(); ++it){
            cout<< it->get_obj();
    }





    cout << "Hello World!" << endl;
    return 0;


}
