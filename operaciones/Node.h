#ifndef Node_h
#define Node_h
template <class T>
class Node {
public:
    Node(T data);
    Node(T data, Node<T> *next);
    T getData();
    Node<T>* getNext();
    void setData(T data);
    void setNext(Node<T> *next);
    
private:
    T data;
    Node<T> *next;
};
////////////////////////////////
// constructores
template <class T>
Node<T>::Node(T data) { // nombre de la clase y metodo
    this->data = data;
    this->next = NULL;
}
template <class T>
Node<T>::Node(T data, Node<T> *next) {
    this->data = data;
    this->next = next;
}
////////////////////////////////
// gets
template <class T>
T Node<T>::getData() {
    return data;
}
template <class T>
Node<T>* Node<T>::getNext() {
    return next;
}
////////////////////////////////
// sets
template <class T>
void Node<T>::setData(T data) {
    this->data=data;
}
template <class T>
void Node<T>::setNext(Node<T>* next) {
    this->next=next;
}
#endif /* Node_h */
