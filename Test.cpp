#include <cassert>
#include <iostream>
#include "List.hpp"
#include "Test.hpp"

void Test::empty() {
  List<int> list;

  list.pushFirst(1);
  list.pushFirst(2);
  assert(list.check(2));
  list.empty();
  assert(list.check(0));
}

void Test::getFirst() {
  List<int> list;

  list.pushFirst(1);
  assert(list.check(1));
  assert(list.popFirst().getData() == 1);
}

void Test::getLast() {
  List<int> list;

  list.pushLast(1);
  assert(list.check(1));
  assert(list.popFirst().getData() == 1);
}

void Test::hasFirst() {
  List<int> list;

  assert(list.check(0));
  list.pushFirst(1);
  assert(list.check(1));
}

void Test::hasLast() {
  List<int> list;

  assert(list.check(0));
  list.pushLast(1);
  assert(list.check(1));
}

void Test::insertAfter() {
  List<int> list;

  list.pushFirst(3);
  list.pushFirst(1);
  list.insertAfter(0, 2);
  assert(list.check(3));
  assert(list.popFirst().getData() == 1);
  assert(list.popFirst().getData() == 2);
  assert(list.popFirst().getData() == 3);
}

void Test::insertBefore() {
  List<int> list;

  list.pushFirst(3);
  list.pushFirst(1);
  list.insertBefore(1, 2);
  assert(list.check(3));
  assert(list.popFirst().getData() == 1);
  assert(list.popFirst().getData() == 2);
  assert(list.popFirst().getData() == 3);
}

void Test::popFirst() {
  List<int> list;

  list.pushFirst(3);
  list.pushFirst(1);
  assert(list.check(2));
  assert(list.popFirst().getData() == 1);
  assert(list.popFirst().getData() == 3);
}

void Test::popLast() {
  List<int> list;

  list.pushLast(1);
  list.pushLast(2);
  list.pushLast(3);
  assert(list.check(3));
  assert(list.popLast().getData() == 3);
  assert(list.popLast().getData() == 2);
  assert(list.popLast().getData() == 1);
}

void Test::pushFirst() {
  List<int> list;

  list.pushFirst(1);
  assert(list.check(1));
  assert(list.popFirst().getData() == 1);
}

void Test::pushLast() {
  List<int> list;

  list.pushLast(1);
  assert(list.check(1));
  assert(list.popLast().getData() == 1);
}
