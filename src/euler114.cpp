/*
 *	程序名：euler114.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 114题(https://projecteuler.net/problem=114)
 */

#include <iostream>
#include <vector>

int main() {
  uint64_t grey_count = 1;
  uint64_t one_red_count = 1;
  uint64_t two_red_count = 1;
  uint64_t more_red_count = 1;

  for (size_t i = 4; i <= 50; i++) {
    auto old_more_red_count = more_red_count;
    more_red_count += two_red_count;
    two_red_count = one_red_count;
    one_red_count = grey_count;
    grey_count += old_more_red_count;
  }

  std::cout << grey_count + more_red_count << std::endl;
  return 0;
}
