/*
 *	程序名：euler439.cpp
 *	日期：2017-05-09
 *	功能：解决eulerproject 439题(https://projecteuler.net/problem=439)
 */

#include <iostream>
#include <list>
#include <vector>

int main(void) {
  constexpr uint64_t N = 1000;
  std::vector<bool> is_prime(N*N + 1, true);
  std::vector<uint64_t> product(N*N + 1, 1);

  for (uint64_t i = 2; i <= N*N; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (uint64_t j = i ; j <= N*N; j += i) {
      is_prime[j] = false;
      uint64_t factor=1+i;
      auto a=i*i;
      while(j%a==0) {
	factor+=a;
	a*=i;
      }
      product[j]*=factor;
    }
  }
  uint64_t sum=0;
  for (uint64_t i = 1; i <= N; i++) {
    for (uint64_t j=1; j <= N; j++) {
 //     std::cout<<"number="<<i*j<<" product="<<product[i*j]<<std::endl;
      sum+=product[i*j];
    }
  }

  std::cout << sum << std::endl;
  return 0;
}
