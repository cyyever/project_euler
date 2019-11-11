/*
 *	程序名：euler65.cpp
 *	日期：2017-07-23
 *	功能：解决eulerproject 65题(https://projecteuler.net/problem=65)
 */

#include <cyy/math/my_math.h>
#include <iostream>

using namespace my_math;
using namespace std;

int get_con_frac_element(size_t n) {
  if (n == 1) {
    return 2;
  } else if ((n - 1) % 3 != 2) {
    return 1;
  } else {
    return n / 3 * 2;
  }
}

int main() {

  my_int n, d;

  n = get_con_frac_element(100);
  d = 1;
  for (size_t i = 99; i >= 1; i--) {
    auto tmp = n;
    n = n * get_con_frac_element(i) + d;
    d = tmp;
  }

  //可以证明n和d是互质的，所以没必要简化分数
  std::string n_str = n;

  size_t sum = 0;
  for (const auto &c : n_str) {
    sum += c - '0';
  }

  std::cout << sum << std::endl;
  return 0;
}
