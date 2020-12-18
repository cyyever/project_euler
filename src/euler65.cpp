/*
 *	程序名：euler65.cpp
 *	日期：2017-07-23
 *	功能：解决eulerproject 65题(https://projecteuler.net/problem=65)
 */

#include <iostream>

#include <cyy/math/all.hpp>

using namespace std;

static uint64_t get_con_frac_element(uint64_t n) {
  if (n == 1) {
    return 2;
  } else if ((n - 1) % 3 != 2) {
    return 1;
  } else {
    return n / 3 * 2;
  }
}

int main() {
  cyy::math::integer n, d;

  n = get_con_frac_element(100);
  d = 1;
  for (uint64_t i = 99; i >= 1; i--) {
    auto tmp = n;
    n = n * get_con_frac_element(i) + d;
    d = std::move(tmp);
  }

  //可以证明n和d是互质的，所以没必要简化分数
  size_t sum = 0;
  for (const auto &c : n.to_string()) {
    sum += c - '0';
  }

  std::cout << sum << std::endl;
  return 0;
}
