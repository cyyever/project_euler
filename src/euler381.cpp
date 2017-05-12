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

    //计算x*(-2) mod(p) = 1
    last_mod = prime / 2;
    sum += last_mod;

    //计算x*(-3) mod(p) = last_mod

    if (prime % 3 == 1) {
      last_mod = ((prime / 3) * last_mod) % prime;
    } else { //==2
      last_mod = ((prime / 3 + 1) * (prime - last_mod)) % prime;
    }
    sum += last_mod;

    //计算x*(-4) mod(p) = last_mod
    auto tmp = prime % 4;

    if (tmp == 1) {
      last_mod = ((prime / 4) * last_mod) % prime;
    } else { //==3
      last_mod = ((prime / 4 + 1) * (prime - last_mod)) % prime;
    }

    sum += last_mod;
    while (sum >= prime) {
      sum -= prime;
    }
    total_sum += sum;
  }

  std::cout << total_sum << std::endl;
  return 0;
}
