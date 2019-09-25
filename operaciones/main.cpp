#include <iostream>
using namespace std;
#include "LinkedList.h"
int main() {
    LinkedList<string> miLista;
    
    
    miLista.addFirst("H");
    miLista.add("O",1);
    miLista.add("L",2);
    miLista.add("A",3);
    
    LinkedList<string> miLista2;
    miLista2.addFirst("H");
    miLista2.add("O",1);
    miLista2.add("L",2);
    miLista2.add("A",3);
    
    miLista+=miLista2;
    
    miLista.print();
    miLista2.print();

    return 0;
}
