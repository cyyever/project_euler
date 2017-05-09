/*
 *	程序名：euler401.cpp
 *	日期：2017-05-09
 *	功能：解决eulerproject 401题(https://projecteuler.net/problem=401)
 */

#include <iostream>
#include <list>
#include <vector>

int main(void) {
  constexpr uint64_t N = 1000000000000000;
  constexpr uint64_t M = 1000000000;

  uint64_t sum = 0;
  uint64_t square = 1;
  for (uint64_t i = 1; i <= N; i++) {
    auto num = N / i;
    if (num >= M) {
      num %= M;
    }

    sum += num * square;

    if (sum >= M) {
      sum %= M;
    }
    square += 2 * i + 1;

    if (square >= M) {
      square %= M;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}
