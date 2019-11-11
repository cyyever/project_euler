/*
 *	程序名：euler250.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 250题(https://projecteuler.net/problem=250)
 */

#include <iostream>
#include <set>

int main(void) {
  constexpr size_t max_d = 12000;
  std::set<size_t> unused_n[max_d + 1];
  size_t cnt = 0;

  for (size_t d = 2; d <= max_d; d++) {
    auto min_n = d / 3 + 1;
    auto max_n = (d - 1) / 2;

    for (size_t n = min_n; n <= max_n; n++) {
      auto it = unused_n[d].find(n);
      if (it != unused_n[d].end()) {
        continue;
      }
      cnt++;
      for (size_t next_d = d + d, next_n = n + n; next_d <= max_d;
           next_d += d, next_n += n) {
        unused_n[next_d].insert(next_n);
      }
    }
  }

  std::cout << cnt << std::endl;
  return 0;
}
