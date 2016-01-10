#include <iostream>
#include "List.hpp"
#include "Test.hpp"

int main() {
  Test test;

  test.empty();
  test.getFirst();
  test.getLast();
  test.hasFirst();
  test.hasLast();
  test.insertAfter();
  test.insertBefore();
  test.popFirst();
  test.popLast();
  test.pushFirst();
  test.pushLast();

  return 0;
}
