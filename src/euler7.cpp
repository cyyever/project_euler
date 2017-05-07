/*
 *	程序名：euler7.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 7题(https://projecteuler.net/problem=7)
 */

#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main() {
  auto primes = get_primes(2000000);

  cout << primes[10000] << endl;
  return 0;
}
