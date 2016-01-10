#include <stddef.h>

template <class T>
class Node {
  private:
    T data;
    Node<T>* next;
    Node<T>* prev;

  public:
    Node(const T&);

    T getData();
    Node<T>* getNext();
    Node<T>* getPrev();
    bool hasNext();
    bool hasPrev();
    void setData(const T&);
    void setNext(Node<T>*);
    void setPrev(Node<T>*);
};

template <class T>
Node<T>::Node(const T& data) : data(data), next(NULL), prev(NULL) {}

template <class T>
T Node<T>::getData() {
  return data;
}

template <class T>
Node<T>* Node<T>::getNext() {
  return next;
}

template <class T>
Node<T>* Node<T>::getPrev() {
  return prev;
}

template <class T>
bool Node<T>::hasNext() {
  if (next) {
    return true;
  }

  return false;
}

template <class T>
bool Node<T>::hasPrev() {
  if (prev) {
    return true;
  }

  return false;
}

template <class T>
void Node<T>::setData(const T& data) {
  this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T>* next) {
  this->next = next;
}

template <class T>
void Node<T>::setPrev(Node<T>* prev) {
  this->prev = prev;
}
