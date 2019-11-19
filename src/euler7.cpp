/*
 *	程序名：euler7.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 7题(https://projecteuler.net/problem=7)
 */

#include <cyy/math/all.hpp>
#include <iostream>

using namespace std;

int main() {

  cout << cyy::math::primes().at(10000) << endl;
  return 0;
}
