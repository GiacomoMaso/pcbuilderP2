#include <iostream>
#include "item.h"
#include "contenitore.h"
#include "smartptr.h"
#include "cpu.h"
#include "gpu.h"
#include "componente.h"
using namespace std;

int main()
{
    Cpu* a1=new Cpu("jhonny",3, "intel", "i9", 13 ,"ape",50, 500, "pollo", "mele");
    Cpu* a2=new Cpu("jhonny",3, "intel", "i7", 13 ,"ape",50, 500, "pollo", "mele");
    Cpu* a3=new Cpu("jhonny",3, "intel", "i5", 13 ,"ape",50, 500, "pollo", "mele");
    Cpu* a4=new Cpu("jhonny",3, "intel", "i3", 13 ,"ape",50, 500, "pollo", "mele");
    Cpu* a5=new Cpu("jhonny",3, "intel", "pentium", 13 ,"ape",50, 500, "pollo", "mele");
    Smartptr<Item> ciao(a1);
    Smartptr<Item> ciao2(a2);
    Smartptr<Item> ciao3(a3);
    Smartptr<Item> ciao4(a4);
    Smartptr<Item> ciao5(a5);



    cout << "Hello World!" << endl;
    return 0;


}
