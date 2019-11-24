/*
 *	程序名：euler10.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 10题(https://projecteuler.net/problem=10)
 */

#include <cyy/math/all.hpp>
#include <iostream>

using namespace std;

int main() {
  uint64_t sum = 0;

  auto primes = cyy::math::primes();

  for (auto prime : primes) {
    if (prime >= 2000000) {
      break;
    }
    sum += prime;
  }
  cout << sum << endl;
  return 0;
}
