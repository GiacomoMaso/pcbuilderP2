#include <iostream>
#include "item.h"
#include "contenitore.h"
#include "smartptr.h"
#include "cpu.h"
#include "gpu.h"
#include "case.h"
#include "componente.h"
#include "Magazzino.h"
#include "schedamadre.h"

using namespace std;

int main()
{
    Cpu* a1=new Cpu("cpu",3, "intel", "i9", 13 ,2012,"ape",50, 500, "pollo", "mele");
    Cpu* a2=new Cpu("cpu",3, "intel", "i7", 13 ,2012,"ape",50, 500, "pollo", "mele");
    Cpu* a3=new Cpu("cpu",3, "intel", "i5", 13 ,2012,"ape",50, 500, "pollo", "mele");
    Cpu* a4=new Cpu("cpu",3, "intel", "i3", 13 ,2012,"ape",50, 500, "pollo", "mele");
    Cpu* a5=new Cpu("cpu",3, "intel", "pentium", 13 ,2012,"ape",50, 500, "pollo", "mele");
    Gpu* g1=new Gpu("gpu",3, "Nvidia", "1060", 13 ,2012, "random", 16, 51);
    Gpu* g2=new Gpu("gpu",3, "Nvidia", "1070", 13 , 2012, "random", 16, 51);
    Gpu* g3=new Gpu("gpu",3, "Nvidia", "1080", 13 , 2012, "random", 16, 51);
    Gpu* g4=new Gpu("gpu",3, "Nvidia", "Titan", 13 , 2012, "random", 16, 51);
    Case* g5=new Case("case",3, "ciao", "tony",14, 2012, "ggg", "abc");
    SchedaMadre* g6=new SchedaMadre( "SchedaMadre" , 3 , "bello", "mario", 25, 2012,"abc", "ccdf", 23, 28);

    Smartptr<Item> ciao(a1);
    Smartptr<Item> ciao2(a2);
    Smartptr<Item> ciao3(a3);
    Smartptr<Item> ciao4(a4);
    Smartptr<Item> ciao5(a5);
    Smartptr<Item> ciao6(g1);
    Smartptr<Item> ciao7(g2);
    Smartptr<Item> ciao8(g3);
    Smartptr<Item> ciao9(g4);
    Smartptr<Item> ciao10(g5);
    Smartptr<Item> ciao11(g6);



    Magazzino tony(ciao);
    tony.add_compoenente(ciao9);
    tony.add_compoenente(ciao3);
    tony.add_compoenente(ciao4);
    tony.add_compoenente(ciao5);
    tony.add_compoenente(ciao6);
    tony.add_compoenente(ciao10);
    tony.add_compoenente(ciao7);
    tony.add_compoenente(ciao8);
    tony.add_compoenente(ciao2);
    tony.add_compoenente(ciao11);




    //tony.filtroSchedaMadre();

    //contenitore<Item*>* ape=tony.get_filtro();
    //contenitore<Smartptr<Item>>* test=tony.get_lista();
    //Smartptr<Item> prova=test->get_last();






//for(auto it=ape->begin(); it!=ape->end() ; it++ ){

//    cout<<(*it)->get_name()<<endl;
//  }




cout << "Hello World!" << endl;
    return 0;


}
