/*
 *	程序名：euler117.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 117题(https://projecteuler.net/problem=117)
 */

#include <iostream>
#include <vector>

int main(void) {
  std::vector<uint64_t> counts{1};

  for (size_t i = 1; i <= 50; i++) {
    uint64_t count = 0;
    count = counts[i - 1];
    if (i >= 2) {
      count += counts[i - 2];
    }
    if (i >= 3) {
      count += counts[i - 3];
    }
    if (i >= 4) {
      count += counts[i - 4];
    }
    counts.push_back(count);
  }

  std::cout << counts.back() << std::endl;
  return 0;
}
