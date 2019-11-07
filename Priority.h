// A01282531
// Helena Ruiz Ramirez
// 10 de noviembre de 2019
// Tarea: Priority Queue with a Heap
// Descripcion Breve: Clase 'Priority' para crear listas estilo 'heap' que simulan el comportamiento de un 'priority_queue'.
#ifndef Priority_h
#define Priority_h
#include <vector>
using namespace std;
class Priority{
public:
    Priority(); //constructor default
    Priority(bool p); // constructor con prioridad, t - max, f - min
    void push(int n);
    void pop();
    int top();
    int size();
    bool empty();
private:
    vector<int> heap; // vector para almacenar los datos con cierta prioridad
    int tam; // tamaño del priority queue sin contar el subindice 0
    bool p; // priority: max or min
};
Priority::Priority(){ // inicializa un vector vacio
    heap.push_back(-1); // indica que el heap esta vacio
    tam=0;
    p=true; // orden mayor cuando no se especifica
}
Priority::Priority(bool p){ // inicializa un vector vacio con una prioridad 'p' definida (max/min)
    heap.push_back(-1);
    tam=0;
    this->p=p;
}
void Priority::push(int n){ // agrega un dato al final del vector/fila
    heap.push_back(n); // agrega el dato al final del vector
    tam++; // incrementa el tamaño de la fila
    for (int i=(tam/2);i>0;i--){ // k = tam/2 ; indica donde comenzar a buscar
        if (p){ // si la prioridad es max
            if ( heap[i*2]>heap[i] || ( heap[(i*2)+1]>heap[i] && ((i*2)+1)<=tam ) ) { // si alguno de los hijos es mayor, lo reemplaza
                if ( ((i*2)+1) > tam ) { // si el hijo der era basura (no existe), no se toma en cuenta y se cambia con el hijo izq
                    swap(heap[i],heap[i*2]);
                } else {
                    ( heap.at(i*2) > heap.at((i*2)+1) ) ? swap(heap[i],heap[i*2]) : swap(heap[i],heap[(i*2)+1]);
                    // intercambia el dato del hijo mayor
                }
            }
        } else { // si la prioridad es min
            if ( heap[i*2]<heap[i] || ( heap[(i*2)+1]<heap[i] && ((i*2)+1)<=tam ) ) { // si alguno de los hijos es menor, lo reemplaza
                if ( ((i*2)+1) > tam ) {
                    swap(heap[i],heap[i*2]);
                } else {
                    ( heap.at(i*2) < heap.at((i*2)+1) ) ? swap(heap[i],heap[i*2]) : swap(heap[i],heap[(i*2)+1]);
                    // intercambia el dato del hijo menor
                }
            }
        }
    }
}
void Priority::pop(){
    swap(heap[1],heap[tam]); // cambia el ultimo valor con el primero
    heap.pop_back(); // hace un pop desde atras ya que se intercambio el primer dato
    tam--;
    for (int i=1;i<=(tam/2);i++){
        if (p) { // si es un 'max priority', reordena el nuevo 'top' haciendo un 'swap' con sus descendientes mayores
            if ( heap[i]<heap[i*2] || (heap[i]<heap[(i*2)+1] && ((i*2)+1)<=tam) ) { // checa si es menor que sus hijos
                if ( ((i*2)+1) > tam ) { // si solo tiene un hijo, cambia con el
                    swap(heap[i],heap[i*2]);
                } else { // cambia con el hijo mas grande
                    ( heap.at(i*2) > heap.at((i*2)+1) ) ? swap(heap[i],heap[i*2]) : swap(heap[i],heap[(i*2)+1]);
                }
            }
        } else { // si es un 'min priority', reordena el nuevo 'top' haciendo un 'swap' con sus descendientes menores
            if ( heap[i]>heap[i*2] || (heap[i]>heap[(i*2)+1] && ((i*2)+1)<=tam) ) { // checa si es mayor que sus hijos
                if ( ((i*2)+1) > tam ) {
                    swap(heap[i],heap[i*2]);
                } else { // cambia con el hijo mas chico
                    ( heap.at(i*2) < heap.at((i*2)+1) ) ? swap(heap[i],heap[i*2]) : swap(heap[i],heap[(i*2)+1]);
                }
            }
        }
    }
}
int Priority::top(){ // regresa el primer dato en la fila/vector (despues del subindice 0)
    return heap.at(1); // puede ser el dato + grande o pequeño, depende de 'p'
}
int Priority::size(){ // regresa el tamaño del vector/fila
    return this->tam; // sin contar el subindice 0
}
bool Priority::empty(){
    if (tam==0){ // sin contar el subindice 0, que siempre estara vacio
        return true;
    } else {
        return false;
    }
}
#endif /* Priority_h */
