/*
 *	程序名：euler25.cpp
 *	日期：2014-11-17
 *	功能：解决eulerproject 25题(https://projecteuler.net/problem=25)
 */
#include <cyy/math/all.hpp>
#include <iostream>

using namespace std;

int main() {
  cyy::math::integer a = 1, b = 1;
  uint64_t i = 2;
  cyy::math::integer threshold(std::string(999, '9'));

  while (true) {
    i++;
    a += b;
    if (a > threshold)
      break;
    i++;
    b += a;
    if (b > threshold)
      break;
  }
  cout << i << endl;
  return 0;
}
