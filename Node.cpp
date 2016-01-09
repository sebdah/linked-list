#include <stddef.h>
#include "Node.hpp"

typedef int T;

Node::Node(const T& data) {
  setData(data);
  setNext(NULL);
  setPrev(NULL);
}

T Node::getData() {
  return data;
}

Node* Node::getNext() {
  return next;
}

Node* Node::getPrev() {
  return prev;
}

bool Node::hasNext() {
  if (next) {
    return true;
  }

  return false;
}

bool Node::hasPrev() {
  if (prev) {
    return true;
  }

  return false;
}

void Node::setData(const T& data) {
  this->data = data;
}

void Node::setNext(Node* next) {
  this->next = next;
}

void Node::setPrev(Node* prev) {
  this->prev = prev;
}
