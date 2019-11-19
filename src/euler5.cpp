/*
 *	程序名：euler5.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 5题(https://projecteuler.net/problem=5)
 */

#include <cyy/math/all.hpp>
#include <iostream>

using namespace std;

int main() {

  auto primes = cyy::math::primes();

  uint64_t product = 1;
  for (auto prime : primes.till(20)) {

    auto factor = prime;
    while (factor * prime <= 20)
      factor *= prime;
    product *= factor;
  }
  cout << product << endl;
  return 0;
}
