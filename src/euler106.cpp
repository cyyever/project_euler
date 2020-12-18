/*
 *	程序名：euler106.cpp
 *	日期：2017-05-13
 *	功能：解决eulerproject 106题(https://projecteuler.net/problem=106)
 */

#include <array>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
  constexpr size_t N = 12;

  auto subset_cnt = (1ULL << N);
  std::vector<std::array<size_t, N>> delta(subset_cnt);
  std::vector<uint64_t> elem_cnt(subset_cnt);

  for (size_t i = 1; i < subset_cnt; i++) {
    for (size_t j = 1, mask = 1; j <= N; j++, mask <<= 1) {
      if (i & mask) {
        elem_cnt[i]++;
        for (size_t k = 0; k < j; k++) {
          delta[i][k]++;
        }
      }
    }
  }

  size_t cnt = 0;
  for (size_t i = 1; i < subset_cnt; i++) {
    for (size_t j = i + 1; j < subset_cnt; j++) {
      if (i & j) {
        continue;
      }
      if (elem_cnt[i] != elem_cnt[j]) {
        continue;
      }

      bool more_delta[2]{false, false};

      for (size_t k = 0; k < N; k++) {
        if (delta[i][k] > delta[j][k]) {
          more_delta[0] = true;
        } else if (delta[i][k] < delta[j][k]) {
          more_delta[1] = true;
        }
      }

      if (more_delta[0] && more_delta[1]) {
        cnt++;
      }
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
