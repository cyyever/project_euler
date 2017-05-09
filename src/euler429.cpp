/*
 *	程序名：euler429.cpp
 *	日期：2017-05-08
 *	功能：解决eulerproject 429题(https://projecteuler.net/problem=429)
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

/*
 *	功能：计算(base^power)%modulus
 * 	参数：
 *		base：底数
 *		power：指数
 *		modulus：模数
 * 	返回值：
 * 		乘方
 */
static uint64_t power(uint64_t base, uint64_t power, uint64_t modulus) {
  uint64_t res = 1;
  uint64_t tmp_base = base;

  while (power) {
    if (power & 1) {
      res *= tmp_base;
      if (res >= modulus) {
        res %= modulus;
      }
    }
    power >>= 1;
    tmp_base *= tmp_base;
    if (tmp_base >= modulus) {
      tmp_base %= modulus;
    }
  }
  return res;
}

int main(void) {
  constexpr uint64_t modulus = 1000000009;
  constexpr uint64_t N = 100000000;
  std::vector<bool> is_prime(N + 1, true);
  uint64_t sum = 1;

  for (uint64_t i = 2; i <= N; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (uint64_t j = i + i; j <= N; j += i) {
      is_prime[j] = false;
    }

    uint64_t cnt = 0;
    uint64_t a = N;
    while (a) {
      a /= i;
      cnt += a;
    }
    sum *= (1 + power(i, cnt * 2, modulus));
    sum %= modulus;
  }

  std::cout << sum << std::endl;
  return 0;
}
