/*
 *	程序名：euler5.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 5题(https://projecteuler.net/problem=5)
 */

#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main() {
  uint64_t product, factor;

  auto primes = get_primes(20);

  product = 1;
  for (auto it = primes.begin(); it != primes.end(); it++) {
    factor = *it;
    while (factor * (*it) <= 20)
      factor *= (*it);
    product *= factor;
  }
  cout << product << endl;
  return 0;
}
