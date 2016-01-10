#include <stddef.h>
#include <iostream>
#include "List.hpp"

List::List() {
  setDebug(false);
  setFirst(NULL);
  setLast(NULL);
}

List::~List() {
  empty();
}

void List::empty() {
  while (hasFirst()) {
    popFirst();
  }
}

Node* List::getFirst() {
  return first;
}

Node* List::getLast() {
  return last;
}

bool List::hasFirst() {
  if (first) {
    return true;
  }

  return false;
}

bool List::hasLast() {
  if (last) {
    return true;
  }

  return false;
}

void List::insertAfter(int target, const T& data) {
  if (!hasFirst()) {
    return;
  }

  Node* currentNode = getFirst();
  Node* newNode = new Node(data);

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

void List::insertBefore(int target, const T& data) {
  if (!hasFirst()) {
    return;
  }

  Node* currentNode = getFirst();
  Node* newNode = new Node(data);

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

Node List::popFirst() {
  if (hasFirst()) {
    Node oldFirst = *getFirst();

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

Node List::popLast() {
  if (hasLast()) {
    Node oldLast = *getLast();

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

void List::print() {
  if (!hasFirst()) {
    return;
  }

  Node* currentNode = getFirst();

  if (!currentNode->hasNext()) {
    printNode(currentNode);
  }

  while (currentNode->hasNext()) {
    printNode(currentNode);
    currentNode = currentNode->getNext();
  }
}

void List::printNode(Node* node) {
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
        << "Node: " << node->getData()
        << " (prev: " << prev << ", next: " << next << ")"
        << std::endl;
    }
}

void List::pushFirst(const T& data) {
  Node* newFirst = new Node(data);

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

void List::pushLast(const T& data) {
  Node* newLast = new Node(data);

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

void List::setDebug(bool debug) {
  this->debug = debug;
}

void List::setFirst(Node* node) {
  if (debug) {
    std::cout << "DEBUG: "
      << "Setting first to "
      << node
      << std::endl;
  }

  first = node;
}

void List::setLast(Node* node) {
  if (debug) {
    std::cout << "DEBUG: "
      << "Setting last to "
      << node
      << std::endl;
  }

  last = node;
}
