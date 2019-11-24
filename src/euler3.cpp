/*
 *	程序名：euler3.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 3题(https://projecteuler.net/problem=3)
 */

#include <cyy/math/all.hpp>
#include <iostream>
#include <range/v3/view.hpp>

using namespace std;

int main() {
  uint64_t max_prime = 0;
  uint64_t num = 600851475143;
  for (auto prime : cyy::math::primes()) {
    if (num % prime == 0) {
      max_prime = prime;
      while (num % prime == 0) {
        num /= prime;
        if (num == 1) {
          goto end;
        }
      }
    }
  }
end:
  cout << max_prime << endl;
  return 0;
}
