// A01282531
// Helena Ruiz Ramirez
// 16 de septiembre de 2019
// Tarea: Operadores de Linked List
#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"
using namespace std;
template <class T>
class LinkedList {
    public:
        // constructor y destructor
        LinkedList();
        ~LinkedList();
        // informacion de la lista
        bool isEmpty();
        int getSize() const;
        // metodos add
        void addFirst(T data);
        void addLast(T data);
        bool add(T data,int pos);
        // metodos delete
        void deleteFirst();
        void deleteLast();
        void del(int pos);
        int deleteAll();
    
        // metodos de modificacion
        T get(int pos);
        T set(T data, int pos);
        bool change(int pos1, int pos2);
        // muestra
        void print();
        /////////////////
        // Operadores de la tarea 5
        void reverse();
        bool operator==(const LinkedList<T> &list);
        void operator+=(T d);
        void operator+=(const LinkedList<T> &listt);
        void copyList(const LinkedList<T> &list);
        void shift(int);
    private:
        Node<T> *head;
        int size;
        void deleteHelper();
};
////////////////////////////////
// constructor y destructor
template <class T>
LinkedList<T>::LinkedList() {
    head=NULL;
    size=0;
}
template <class T>
LinkedList<T>::~LinkedList(){
    deleteHelper();
}
////////////////////////////////
// metodos
template <class T>
bool LinkedList<T>::isEmpty() {
    return (head==NULL);
}
template <class T>
int LinkedList<T>::getSize() const {
    return size;
}
////////////////////////////////
// add
template <class T>
void LinkedList<T>::addFirst(T data) {
    head = new Node<T>(data, head);
    size++;
}
template <class T>
void LinkedList<T>::addLast(T data){
    if (this->isEmpty()){
        addFirst(data);
    } else {
        Node<T> *curr = head;
        while (curr->getNext() != NULL){
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}
template<class T>
bool LinkedList<T>::add(T data,int pos) {
    if (pos>size) return false;
    if (pos==0) {
        addFirst(data);
    } else if ( pos==size ) {
        addLast(data);
    } else {
        Node<T> *curr = head;
        for (int i=1;i<pos;i++) {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    return true;
}
////////////////////////////////
// delete
template <class T>
void LinkedList<T>::deleteFirst() {
    if (!this->isEmpty()){
        Node<T> *curr=head;
        head = head->getNext();
        delete curr;
        size--;
    }
}
template <class T>
void LinkedList<T>::deleteLast() {
    if (size<=1) {
        deleteFirst();
    } else {
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != NULL){
            curr = curr->getNext();
        }
        delete curr->getNext();
        curr->setNext(NULL);
        size--;
    }
}
template <class T>
void LinkedList<T>::del(int pos) {
    if (pos<size) {
        if (pos==0) {
            deleteFirst();
        } else if (pos==(size-1)){
            deleteLast();
        } else {
            Node<T> *curr = head;
            for (int i=1;i<pos;i++) {
                curr = curr->getNext();
            }
            Node<T> *temp = curr->getNext();
            curr-> setNext(temp->getNext());
            delete temp;
            size--;
        }
    }
}
template <class T>
int LinkedList<T>::deleteAll() {
    int cant = size;
    deleteHelper();
    size=0;
    return cant;
}
template <class T>
void LinkedList<T>::deleteHelper() {
    Node<T> *curr = head;
    while( !this->isEmpty() ) {
        head = head->getNext();
        delete curr;
        curr = head;
    }
}
////////////////////////////////
// operaciones generales
template<class T>
T LinkedList<T>::get(int pos) {
    Node <T> *curr = head;
    if (this->isEmpty()) {
        return NULL;
    } else if (pos>size) {
        return NULL;
    } else if (pos==0) {
        return curr->getData();
    } else {
        for (int i=0;i<pos;i++) {
            curr = curr->getNext();
        }
        return curr->getData();
    }
}
template<class T>
T LinkedList<T>::set(T data,int pos) {
    Node <T> *curr = head;
    T prevData;
    if (this->isEmpty()) {
        return NULL;
    } else if (pos>size) {
        return NULL;
    } else if (pos==0) {
        prevData = curr->getData();
        curr->setData(data);
        return prevData;
    } else {
        for (int i=0;i<pos;i++) {
            curr = curr->getNext();
        }
        prevData = curr->getData();
        curr->setData(data);
        return prevData;
    }
}
template <class T>
bool LinkedList<T>::change(int pos1, int pos2) {
    if ( pos1 == pos2 ) {
        return true;
    }
    int posMen = ( pos1 < pos2 ? pos1 : pos2 );
    int posMay = ( pos1 > pos2 ? pos1 : pos2 );
    Node<T> *curr = head;
    for( int i = 0; i < posMen; i++ ) {
        curr = curr->getNext();
    }
    Node<T> *curr2 = curr;
    for( int i = posMen; i < posMay; i++ ) {
        curr2 = curr2->getNext();
    }
    T temp = curr->getData();
    curr->setData(curr2->getData());
    curr2->setData(temp);
    return true;
}
////////////////////////////////
// operaciones de muestra
template <class T>
void LinkedList<T>::print() {
    Node<T> *curr = head;
    while( curr != NULL ) {
        cout << curr->getData() << " ";
        curr = curr->getNext();
    }
    cout << endl;
}
////////////////////////////////////////////////////////////////
// OPERADORES DE LA TAREA 5
// reverse: invierte la lista (h o l a --> a l o h)
template <class T>
void LinkedList<T>::reverse() {
    Node<T> *curr = head; // para invertir la lista, se va a invertir la direccion
    Node<T> *prev = curr;    // de cada nodo uno por uno (de su next a su prev)
    Node<T> *next = curr->getNext();
    curr->setNext(NULL);
    while (next!=NULL) { // curr se cambia a su next, y next agarra el que le sigue a ese.
        curr = next;     // luego, curr apunta al previo, y el previo se cambia a curr.
        next = curr->getNext();
        curr->setNext(prev);
        prev = curr;
    }
    head = prev; // una vez que se tenga el ultimo nodo se cambia head a ese nodo
}
// operator == : checa que dos listas tengan el mismo tamaño/contenido/orden
template <class T>
bool LinkedList<T>::operator==(const LinkedList<T> &list) {
    // checa que tenga el mismo size. si es diferente, entonces las dos listas no son iguales
    if (size != list.getSize()) return false;
    Node<T> *curr1 = head;
    Node<T> *curr2 = list.head;
    T d1,d2;
    while (curr1!=NULL && curr2!=NULL) {
        d1 = curr1->getData();
        d2 = curr2->getData();
        if (d1==d2) {
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        } else { // si se encuentra una diferencia en los datos, regresa falso
            return false;
        }
    }
    return true; // si se checaron todos los nodos y no se encontraron diferencias, regresa verdadero
}
// operator += (T d) : agrega info al final de la lista
template <class T>
void LinkedList<T>::operator+=(T d){
    Node<T> *curr = head;
    if (this->isEmpty()){
        addFirst(d);
    } else {
        while (curr->getNext()!=NULL) {
            curr=curr->getNext();
        } // busca el ultimo nodo y agrega el dato necesario
        curr->setNext(new Node<T>(d));
        size++;
    }
}
// operator += (LinkedList<T> list) : agrega toda una lista al final de la lista
template <class T>
void LinkedList<T>::operator+=(const LinkedList<T> &list){
    Node<T> *curr1;
    Node<T> *curr2 = list.head;
    int size2 = list.getSize();
    if (this->isEmpty()) {
        addFirst(curr2->getData()); // si la lista esta vacia, crea primero su head
        curr2=curr2->getNext();
        curr1 = head;
        for (int i=0;i<size2-1;i++) {
            curr1->setNext(new Node<T>(curr2->getData()));
            curr1=curr1->getNext();
            curr2=curr2->getNext();
            size++;
        }
    } else {
        curr1 = head;
        while (curr1->getNext()!=NULL) {
            curr1=curr1->getNext();
        }
        for (int i=0;i<size2;i++) { // uno por uno, crea un nuevo nodo por cada elemento
            curr1->setNext(new Node<T>(curr2->getData()));  // en la segunda lista
            curr1=curr1->getNext();
            curr2=curr2->getNext();
            size++;
        }
    }
}
// LinkedList (LinkedList list) : copia toda una lista
template <class T>
void LinkedList<T>::copyList(const LinkedList<T> &list) {
    this->deleteAll();  // borra todo lo que estaba antes en la lista para empezar de 0
    int size2 = list.getSize();
    Node<T> *curr1;
    Node<T> *curr2 = list.head;
    addFirst(curr2->getData()); // agrega el primer nodo igual al de la lista a copiar
    curr1 = head;
    curr2=curr2->getNext();
    for (int i=0;i<size2-1;i++) {   // va creando nuevos nodos y moviendo los apuntadores
        curr1->setNext(new Node<T>(curr2->getData()));  // en ambas listas
        curr1=curr1->getNext();
        curr2=curr2->getNext();
    }
}
// shift(int) : mueve 'int' casillas (int=1, [0]-->[1]; int=-1, [1]-->[0]
template <class T>
void LinkedList<T>::shift(int n) {
    int ind=n;
    if (n!=0) { // si n=0, no se mueve nada
        if (n<0) {  // si n<0, el shift es igual a su equivalente positivo menos el size
            ind*=-1;    // por ejemplo, n=-2 es igual a hacer 2 shifts a la derecha si size==4
            ind=size-ind;
        }
        Node<T> *curr=head,
        *next = curr->getNext(), // para saber cuando llegamos al final de la lista
        *prev=NULL, // para indicar el nuevo 'last' que apuntara a NULL
        *nextHead=NULL; // el nuevoHead una vez que se haga el shift
        for (int i=ind;i>0;i--) { // se repite un shift 'ind' numero de veces
            while (next->getNext()!=NULL) {
                curr=next;
                next=curr->getNext();
            }   // llega al final de la fila. curr apunta a el penultimo nodo
            nextHead=next;
            nextHead->setNext(head); // aqui hace el shift del ultimo nodo al primero
            prev=curr;
            prev->setNext(NULL); // declara el nuevo 'last'
            head=nextHead;  // nextHead se convierte en el nuevo 'head'
            curr=head; // se vuelven a declarar curr y next para el sig. ciclo,
            next=curr->getNext();   // ubicando los apuntadores al comienza de la lista ya movida
        }
    }
}
////////////////////////////////////////////////////////////////
#endif /* LinkedList_h */
