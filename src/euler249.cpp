/*
 *	程序名：euler249.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 249题(https://projecteuler.net/problem=249)
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

int main(void) {
  const uint64_t N = 5000;
  const uint64_t modulus = 10000000000000000ULL;
  const uint64_t prime_sum_limit = 1548200;
  std::vector<bool> is_prime(prime_sum_limit + 1, true);
  std::vector<uint64_t> primes;
  std::vector<uint64_t> subset_cnts(prime_sum_limit + 1, 0);
  uint64_t cnt = 0;

  for (size_t i = 2; i <= prime_sum_limit; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (size_t j = i + i; j <= prime_sum_limit; j += i) {
      is_prime[j] = false;
    }
    if (i < N) {
      primes.push_back(i);
    }
  }

  for (auto const &prime : primes) {
  std::vector<uint64_t> tmp(prime_sum_limit + 1, 0);

    for(size_t i=1;i<prime_sum_limit-prime;i++) {
      tmp[i+prime]=subset_cnts[i];
      if (is_prime[i+prime]) {
        cnt += subset_cnts[i];
        if(cnt>=modulus) {
          cnt-=modulus;
        }
      }
    }
    for(size_t i=prime+1;i<prime_sum_limit;i++) {
      //auto prev_cnt=subset_cnts[i-prime];
      subset_cnts[i]+=tmp[i];
        if(subset_cnts[i]>=modulus) {
          subset_cnts[i] -=modulus;
        }
    }
    subset_cnts[prime]++;
    cnt++;
    if(cnt>=modulus) {
          cnt-=modulus;
    }
  }

  std::cout << cnt << std::endl;
  return 0;
}
