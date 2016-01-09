#include <stddef.h>
#include "List.hpp"

List::List() {
  setFirst(NULL);
  setLast(NULL);
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

void List::setFirst(Node* node) {
  first = node;
}

void List::setLast(Node* node) {
  last = node;
}

Node* List::popFirst() {
  if (hasFirst()) {
    Node* oldFirst = getFirst();

    if (getFirst()->hasNext()) {
      Node* next = oldFirst->getNext();

      next->setPrev(NULL);
      delete getFirst();
      setFirst(next);
    } else {
      delete getFirst();
      setFirst(NULL);
    }

    return oldFirst;
  }

  return NULL;
}

Node* List::popLast() {
  if (hasLast()) {
    Node* oldLast = getLast();

    if (getLast()->hasPrev()) {
      Node* prev = oldLast->getPrev();

      prev->setNext(NULL);
      delete getLast();
      setLast(prev);
    } else {
      delete getLast();
      setLast(NULL);
    }

    return oldLast;
  }

  return NULL;
}

void List::pushFirst(const T& data) {
  Node* newFirst = new Node(data);

  if (hasFirst()) {
    // Update the current firsts reference to prev
    getFirst()->setPrev(newFirst);

    // Set next node to the current next for the new first
    newFirst->setNext(getFirst());
  }

  if (!hasLast()) {
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
  }

  if (!hasFirst()) {
    setFirst(newLast);
  }

  setLast(newLast);
}
