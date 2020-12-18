/*
 *	程序名：euler116.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 116题(https://projecteuler.net/problem=116)
 */

#include <iostream>
#include <vector>

int main() {
  std::vector<uint64_t> red_counts;
  std::vector<uint64_t> green_counts;
  std::vector<uint64_t> blue_counts;

  for (size_t i = 0; i <= 50; i++) {
    if (i < 2) {
      red_counts.push_back(0);
    } else {
      red_counts.push_back(red_counts[i - 1] + red_counts[i - 2] + 1);
    }
    if (i < 3) {
      green_counts.push_back(0);
    } else {
      green_counts.push_back(green_counts[i - 1] + green_counts[i - 3] + 1);
    }
    if (i < 4) {
      blue_counts.push_back(0);
    } else {
      blue_counts.push_back(blue_counts[i - 1] + blue_counts[i - 4] + 1);
    }
  }

  std::cout << red_counts.back() + green_counts.back() + blue_counts.back()
            << std::endl;
  return 0;
}
