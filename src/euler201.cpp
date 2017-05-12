/*
 *	程序名：euler201.cpp
 *	日期：2017-05-12
 *	功能：解决eulerproject 201题(https://projecteuler.net/problem=201)
 */

#include <iostream>
#include <array>
#include <vector>

int main(void) {
  uint64_t min_sum = 0;
  for (uint64_t i = 1; i <= 50; i++) {
    min_sum += i * i;
  }

  uint64_t max_sum = 0;
  for (uint64_t i = 51; i <= 100; i++) {
    max_sum += i * i;
  }
  std::vector<std::array<size_t,51>> subset_sums(max_sum + 1);

  for (size_t i = 1; i <= 100; i++) {
    auto square = i * i;

    for (size_t j = max_sum; j >= square; j--) {
      for(size_t k=0;k<=49;k++) {
	subset_sums[j][k+1] += subset_sums[j-square][k];
      }
    }
    subset_sums[square][1]++;
  }

  uint64_t unique_sum_sum = 0;
  for (size_t i = min_sum; i <= max_sum; i++) {
    if (subset_sums[i][50] == 1) {
      unique_sum_sum += i;
    }
  }
  std::cout << unique_sum_sum << std::endl;
  return 0;
}
