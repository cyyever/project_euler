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
    size_t a = M;
    size_t b = N;
    size_t c = M-N;
    while (true) {
      a/=i;
      if (a== 0) {
        break;
      }
      b/=i;
      c/=i;
      m_cnt +=a;
      n_cnt +=b;
      m_subtract_n_cnt += c;
    }
    sum += (m_cnt - n_cnt - m_subtract_n_cnt) * i;
  }
  std::cout << sum << std::endl;
  return 0;
}
