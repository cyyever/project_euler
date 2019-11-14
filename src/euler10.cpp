/*
 *	程序名：euler10.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 10题(https://projecteuler.net/problem=10)
 */

#include <cyy/math/prime.hpp>
#include <iostream>

using namespace std;

int main() {
  uint64_t sum = 0;

  for (auto prime:cyy::math::primes().all()) {
	  if(prime>=2000000) {
		  break;
	  }
	  printf("%d\n",(int)prime);
	  sum += prime;
  }
  cout << sum << endl;
  return 0;
}
