/*
 *	程序名：euler70.cpp
 *	日期：2017-05-04
 *	功能：解决eulerproject 70题(https://projecteuler.net/problem=70)
 */

#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

static bool inline is_permutation(uint64_t a, uint64_t b) {
  std::vector<size_t> a_dight_cnt(10, 0);
  std::vector<size_t> b_dight_cnt(10, 0);

  while (a) {
    a_dight_cnt[a % 10]++;
    a /= 10;
  }

  while (b) {
    b_dight_cnt[b % 10]++;
    b /= 10;
  }
  return memcmp(a_dight_cnt.data(), b_dight_cnt.data(), 10 * sizeof(size_t)) ==
         0;
}

int main() {
  //参看https://en.wikipedia.org/wiki/Euler%27s_totient_function 获取函数公式
  const size_t N = 10000000;
  std::vector<bool> is_prime(N, true);
  std::vector<uint64_t> totient(N, 1);

  for (size_t i = 1; i < N; i++) {
    totient[i] = i;
  }

  size_t n = 1;
  double min_ratio = 2.0;

  for (size_t i = 2; i < N; i++) {
    if (is_prime[i]) {
      for (size_t j = i + i; j < N; j += i) {
        is_prime[j] = false;
        totient[j] = totient[j] * (i - 1) / i;
      }
    } else { //质数肯定不是permutation
      if (totient[i] * 10 > i) {
        double ratio = static_cast<double>(i) / totient[i];
        if (ratio < min_ratio && is_permutation(i, totient[i])) {
          min_ratio = ratio;
          n = i;
        }
      }
    }
  }

  std::cout << n << std::endl;
  return 0;
}
