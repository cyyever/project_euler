/*
 *	程序名：euler16.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 16题(https://projecteuler.net/problem=16)
 */

#include <cyy/math/integer.hpp>
#include <iostream>

using namespace std;

int main() {
  cyy::math::integer a = 1;
  a.multiply_2(1000);
  uint64_t digit_sum = 0;
  while (a!=0) {
    digit_sum += a % 10;
    a /= 10;
  }
  cout << digit_sum << endl;
  return 0;
}
