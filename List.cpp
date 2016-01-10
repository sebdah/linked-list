#include <stddef.h>
#include <iostream>
#include "List.hpp"

List::List() {
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

void List::setFirst(Node* node) {
  first = node;
}

void List::setLast(Node* node) {
  last = node;
}

Node List::popFirst() {
  if (hasFirst()) {
    Node oldFirst = *getFirst();

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

  Node currentNode = *getFirst();

  std::cout << currentNode.getData() << std::endl;

  while (currentNode.hasNext()) {
    std::cout << currentNode.getNext()->getData() << std::endl;
    currentNode = *currentNode.getNext();
  }
}

void List::pushFirst(const T& data) {
  Node* newFirst = new Node(data);

  if (hasFirst()) {
    // Update the current firsts reference to prev
    getFirst()->setPrev(newFirst);

    // Set next node to the current next for the new first
    newFirst->setNext(getFirst());
  } else {
    // Set the new first as first as last if empty
    setLast(newFirst);
  }

  // Set the new first as first
  setFirst(newFirst);
}

void List::pushLast(const T& data) {
  Node* newLast = new Node(data);

  if (hasLast()) {
    // Update the current previous to reference new next
    getLast()->setNext(newLast);

    // Set previos node for new last
    newLast->setPrev(getLast());
  } else {
    setFirst(newLast);
  }

  setLast(newLast);
}
