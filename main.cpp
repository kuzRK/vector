#include "top-it-vector.hpp"
#include <cstddef>
#include <ios>
#include <iostream>
#include <utility>

bool testDefaultVector()
{
  topit::Vector< int > v;
  bool c = v.isEmpty();
  return c;
}

bool testVectorWithValue()
{
  topit::Vector< int > v;
  v.pushBack(1);
  return !v.isEmpty();
}

bool testCopyConstructor()
{
  topit::Vector< int > v;
  v.pushBack(1);
  topit::Vector< int > yay = v;
  bool isAllEqual = v.getSize() == yay.getSize();
  for (size_t i = 0; i < v.getSize(); i++) {
    isAllEqual = isAllEqual && v[i] == yay[i];
  }
  return isAllEqual;
}

bool testElementAccess()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  return v[0] == 1 && v[1] == 2;
}
bool testPushBack()
{
  topit::Vector< int > v;
  v.pushBack(10);
  v.pushBack(20);
  v.pushBack(30);
  return v.getSize() == 3 && v[0] == 10 && v[1] == 20 && v[2] == 30;
}
bool testPushFront()
{
  topit::Vector< int > v;
  v.pushBack(2);
  v.pushBack(3);
  v.pushFront(1);
  return v.getSize() == 3 && v[0] == 1 && v[1] == 2 && v[2] == 3;
}
bool testPopBack()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  v.pushBack(3);
  v.pop_back();
  return v.getSize() == 2 && v[0] == 1 && v[1] == 2;
}
bool testGetCapacity()
{
  topit::Vector< int > v;
  v.pushBack(1);
  v.pushBack(2);
  return v.getCapacity() == v.getSize();
}
bool testSwap()
{
  topit::Vector< int > a;
  a.pushBack(1);
  a.pushBack(2);
  topit::Vector< int > b;
  b.pushBack(9);
  a.swap(b);
  return a.getSize() == 1 && a[0] == 9 && b.getSize() == 2 && b[0] == 1 && b[1] == 2;
}
int main()
{
  using test_t = bool(*)();
  using pair_t = std::pair< const char*, test_t >;
  pair_t tests[] = {
    {"Default vector is empty", testDefaultVector},
    {"Default vector is not empty", testVectorWithValue},
    {"Inbound access elements", testCopyConstructor},
    {"Sizes must be equal", testElementAccess}
    {"Wrong order after 3 pushbacks", testPushBack},
    {"pushFront did not insert at position 0", testPushFront},
    {"pop_back did not remove last element", testPopBack},
    {"Capacity does not equal Size", testGetCapacity},
    {"swap did not exchanges contents", testSwap},
  };
  const size_t count = sizeof(tests) / sizeof(pair_t);
  std::cout << std::boolalpha;
  bool pass = true;
  for (size_t i = 0; i < count; i++) {
    bool res = tests[i].second();
    std::cout << res << ": ";
    std::cout << tests[i].first << '\n';
    pass = pass && res;
  }
  std::cout << "Result: " << pass << '\n';
}
