/*
 *	程序名：euler10.cpp
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 10题(https://projecteuler.net/problem=10)
 */

#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main() {
  auto primes = get_primes(2000000);
  uint64_t sum = 0;

  for (auto it = primes.begin(); it != primes.end(); it++)
    sum += *it;
  cout << sum << endl;
  return 0;
}
