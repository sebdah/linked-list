#include <iostream>
#include "List.hpp"

int main() {
  List* list = new List();

  list->pushFirst(4);
  list->pushFirst(3);
  list->pushFirst(2);
  list->pushFirst(1);
  // 1,2,3,4
  list->pushLast(5);
  list->pushLast(6);
  list->pushLast(7);
  list->pushLast(8);
  // 1,2,3,4,5,6,7,8

  //std::cout << "First: " << list->getFirst()->getData() << std::endl;
  //if (list->getFirst() == list->popFirst()) {
    //std::cout << "OK - getFirst == popFirst" << std::endl;
  //}

  //std::cout << "Last: " << list->getLast()->getData() << std::endl;
  //if (list->getLast() == list->popLast()) {
    //std::cout << "OK - getLast == popLast" << std::endl;
  //}

  list->empty();

  delete list;

  return 0;
}
