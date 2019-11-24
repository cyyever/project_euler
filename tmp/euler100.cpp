/*
 *	程序名：euler100.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 100题(https://projecteuler.net/problem=100)
 */

#include <algorithm>
#include <cyy/math/all.hpp>
#include <iostream>
#include <utility>

int main(void) {
  uint64_t n = 1000000000000;

  auto total = cyy::math::integer(n) * (n - 1);
  auto a = static_cast<uint64_t>(n / 1.414);
  auto lower = cyy::math::integer(a) * ((a - 1) * 2);
  while (true) {
    auto res = lower.compare(total);
    if (res < 0) {
      lower += 4 * a;
      a++;
    } else if (res == 0) {
      std::cout << a << std::endl;
      return 0;
    } else {
      total += 2 * n;
      n++;
    }
  }
  return 0;
}
