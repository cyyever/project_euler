/*
 *	程序名：euler3.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 3题(https://projecteuler.net/problem=3)
 */

#include <iostream>
#include <cyy/math/my_math.h>

using namespace my_math;
using namespace std;

int main() {
  auto primes = get_primes(1000000);

  for (auto it = --primes.end();; it--) {
    if (600851475143 % (*it) == 0) {
      cout << *it << endl;
      break;
    }
  }
  return 0;
}
