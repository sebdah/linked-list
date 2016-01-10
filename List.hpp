#include <stddef.h>
#include <iostream>
#include "Node.hpp"

template <class T>
class List
{
  private:
    bool debug;
    Node<T>* first;
    Node<T>* last;

  public:
    List();
    ~List();

    void empty();
    Node<T>* getFirst();
    Node<T>* getLast();
    bool hasFirst();
    bool hasLast();
    void insertAfter(int, const T&);
    void insertBefore(int, const T&);
    Node<T> popFirst();
    Node<T> popLast();
    void print();
    void printNode(Node<T>*);
    void pushFirst(const T&);
    void pushLast(const T&);
    void setDebug(bool);
    void setFirst(Node<T>*);
    void setLast(Node<T>*);
};

template <class T>
List<T>::List() {
  setDebug(false);
  setFirst(NULL);
  setLast(NULL);
}

template <class T>
List<T>::~List() {
  empty();
}

template <class T>
void List<T>::empty() {
  while (hasFirst()) {
    popFirst();
  }
}

template <class T>
Node<T>* List<T>::getFirst() {
  return first;
}

template <class T>
Node<T>* List<T>::getLast() {
  return last;
}

template <class T>
bool List<T>::hasFirst() {
  if (first) {
    return true;
  }

  return false;
}

template <class T>
bool List<T>::hasLast() {
  if (last) {
    return true;
  }

  return false;
}

template <class T>
void List<T>::insertAfter(int target, const T& data) {
  if (!hasFirst()) {
    return;
  }

  Node<T>* currentNode = getFirst();
  Node<T>* newNode = new Node<T>(data);

  for (int i = 0; i <= target; i++) {
    if (i == target) {
      newNode->setPrev(currentNode);

      if (currentNode->hasNext()) {
        newNode->setNext(currentNode->getNext());
        currentNode->getNext()->setPrev(newNode);
      }

      currentNode->setNext(newNode);

      return;
    }

    if (!currentNode->hasNext()) {
      return;
    }

    currentNode = currentNode->getNext();
  }

  delete currentNode;
}

template <class T>
void List<T>::insertBefore(int target, const T& data) {
  if (!hasFirst()) {
    return;
  }

  Node<T>* currentNode = getFirst();
  Node<T>* newNode = new Node<T>(data);

  for (int i = 0; i <= target; i++) {
    if (i == target) {
      if (currentNode->hasPrev()) {
        currentNode->getPrev()->setNext(newNode);
        newNode->setPrev(currentNode->getPrev());
      }

      newNode->setNext(currentNode);
      currentNode->setPrev(newNode);

      return;
    }

    if (!currentNode->hasNext()) {
      return;
    }

    currentNode = currentNode->getNext();
  }

  delete currentNode;
}

template <class T>
Node<T> List<T>::popFirst() {
  if (hasFirst()) {
    Node<T> oldFirst = *getFirst();

    if (getFirst() == getLast()) {
      setLast(NULL);
    }

    delete getFirst();

    if (oldFirst.hasNext()) {
      oldFirst.getNext()->setPrev(NULL);
      setFirst(oldFirst.getNext());
    } else {
      setFirst(NULL);
    }

    return oldFirst;
  }

  return NULL;
}

template <class T>
Node<T> List<T>::popLast() {
  if (hasLast()) {
    Node<T> oldLast = *getLast();

    if (getFirst() == getLast()) {
      setFirst(NULL);
    }

    delete getLast();

    if (oldLast.hasPrev()) {
      oldLast.getPrev()->setNext(NULL);
      setLast(oldLast.getPrev());
    } else {
      setLast(NULL);
    }

    return oldLast;
  }

  return NULL;
}

template <class T>
void List<T>::print() {
  if (!hasFirst()) {
    return;
  }

  Node<T>* currentNode = getFirst();

  if (!currentNode->hasNext()) {
    printNode(currentNode);
  }

  while (currentNode->hasNext()) {
    printNode(currentNode);
    currentNode = currentNode->getNext();
  }
}

template <class T>
void List<T>::printNode(Node<T>* node) {
    int next = -1;
    if (getFirst()->hasNext()) {
      next = node->getNext()->getData();
    }

    int prev = -1;
    if (node->hasPrev()) {
      prev = node->getPrev()->getData();
    }

    if (debug) {
      std::cout << "DEBUG: "
        << "Node<T>: " << node->getData()
        << " (prev: " << prev << ", next: " << next << ")"
        << std::endl;
    }
}

template <class T>
void List<T>::pushFirst(const T& data) {
  Node<T>* newFirst = new Node<T>(data);

  if (debug) {
    std::cout << "DEBUG: "
      << "Pushing "
      << newFirst
      << " to first"
      << std::endl;
  }

  if (hasFirst()) {
    getFirst()->setPrev(newFirst);
    newFirst->setNext(getFirst());
  }

  if (!hasLast()) {
    setLast(newFirst);
  }

  setFirst(newFirst);
}

template <class T>
void List<T>::pushLast(const T& data) {
  Node<T>* newLast = new Node<T>(data);

  if (debug) {
    std::cout << "DEBUG: "
      << "Pushing "
      << newLast
      << " to last"
      << std::endl;
  }

  if (hasLast()) {
    getLast()->setNext(newLast);
    newLast->setPrev(getLast());
  }

  if (!hasFirst()) {
    setFirst(newLast);
  }

  setLast(newLast);
}

template <class T>
void List<T>::setDebug(bool debug) {
  this->debug = debug;
}

template <class T>
void List<T>::setFirst(Node<T>* node) {
  if (debug) {
    std::cout << "DEBUG: "
      << "Setting first to "
      << node
      << std::endl;
  }

  first = node;
}

template <class T>
void List<T>::setLast(Node<T>* node) {
  if (debug) {
    std::cout << "DEBUG: "
      << "Setting last to "
      << node
      << std::endl;
  }

  last = node;
}
