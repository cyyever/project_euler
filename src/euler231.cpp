/*
 *	程序名：euler231.cpp
 *	日期：2017-05-07
 *	功能：解决eulerproject 231题(https://projecteuler.net/problem=231)
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

int main(void) {
  constexpr size_t M = 20000000;
  constexpr size_t N = 15000000;

  std::vector<bool> is_prime(M + 1, true);

  uint64_t sum = 0;
  //参看https://en.wikipedia.org/wiki/Euler%27s_totient_function 获取函数公式

  for (size_t i = 2; i <= M; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (size_t j = i + i; j <= M; j += i) {
      is_prime[j] = false;
    }
    size_t m_cnt = 0;
    size_t n_cnt = 0;
    size_t m_subtract_n_cnt = 0;
    size_t a = i;
    while (true) {
      auto res = M / a;
      if (res == 0) {
        break;
      }
      m_cnt += res;
      n_cnt += N / a;
      m_subtract_n_cnt += (M - N) / a;
      a *= i;
    }
    sum += (m_cnt - n_cnt - m_subtract_n_cnt) * i;
  }
  std::cout << sum << std::endl;
  return 0;
}
