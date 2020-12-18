/*
 *	程序名：euler27.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 27题(https://projecteuler.net/problem=27)
 */
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>

int main() {
  /* int a, b, n; */

  constexpr size_t N = 200000;
  std::vector<bool> primes(N + 1, true);

  //标识质数
  for (size_t i = 2; i <= N; i++) {
    if (primes[i]) {
      for (size_t j = i * 2; j <= N; j += i)
        primes[j] = false;
    }
  }

  size_t max_prime_num = 0;
  int max_a = -1000;
  int max_b = 3;
  for (int a = -1000; a <= 1000; a++) {
    //我们从3开始，因为n=0时为b，显然可以跳过非质数
    //如果b为2，那么n=2时显然不是质数
    for (int b = 3; b <= 1000; b += 2) {
      auto formula_res = b; // n=0时取b
      if (!primes[formula_res])
        continue;

      size_t prime_num = 1;
      int n;
      for (n = 1;; n++) {
        formula_res += a + 2 * n - 1;
        if (formula_res < 2)
          break;
        if (!primes[formula_res])
          break;
      }
      prime_num += n - 1;
      if (prime_num > max_prime_num) {
        max_a = a;
        max_b = b;
        max_prime_num = prime_num;
      }
    }
  }

  std::cout << max_a * max_b << std::endl;
  return 0;
}
