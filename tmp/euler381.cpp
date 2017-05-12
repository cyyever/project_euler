/*
 *	程序名：euler381.cpp
 *	日期：2017-05-12
 *	功能：解决eulerproject 381题(https://projecteuler.net/problem=381)
 */

#include <iostream>
#include <vector>

int main(void) {
  //根据数论，我们知道(p-1)!mod(p)=-1，(p-2)!mod(p)=1
  //于是我们可以找出其它的模

  const uint64_t N = 100000000;
  std::vector<bool> is_prime(N + 1, true);

  uint64_t total_sum = 0;
  for (uint64_t i = 2; i < N; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (uint64_t j = i + i; j < N; j += i) {
      is_prime[j] = false;
    }
    if (i < 5) {
      continue;
    }

    uint64_t last_mod = 1;
    uint64_t sum = 0;
    auto prime = i;

    for (uint64_t k = prime - 2; k >= prime - 4; k--) {
      uint64_t tmp = 0;
      for (uint64_t j = 1; j < prime; j++) {
        tmp += k;
        if (tmp >= prime) {
          tmp -= prime;
        }
        if (tmp == last_mod) {
          last_mod = j;
          sum += j;
          break;
        }
      }
    }
    total_sum += (sum % prime);
  }

  std::cout << total_sum << std::endl;
  return 0;
}
