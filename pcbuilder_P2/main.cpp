#include <iostream>
#include "componente.h"
#include "contenitore.h"
using namespace std;

int main()
{

    Componente Tastiera(120, "corsair");
    Componente Ciao (299, "jhonny");

    contenitore<Componente> lista(Tastiera);
    lista.add_coda(Ciao);
    cout<<lista.get_last();

    cout << "Hello World!" << endl;
    return 0;


}
