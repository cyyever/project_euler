/*
 *	程序名：euler105.cpp
 *	日期：2017-05-13
 *	功能：解决eulerproject 105题(https://projecteuler.net/problem=105)
 */

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>

std::pair<bool, uint64_t> is_special_sum_set(const std::vector<uint64_t> set);

int main(void) {
  std::ifstream in_file("p105_sets.txt");
  std::vector<uint64_t> set;
  char seq;
  uint64_t sum = 0;
  while (true) {
    uint64_t elem = 0;
    in_file >> elem;

    set.push_back(elem);

    int c = in_file.peek();
    if (c == ',') {
      in_file >> seq;
      continue;
    }

    auto res = is_special_sum_set(set);
    if (res.first) {
      sum += res.second;
    }
    if (c == EOF) {
      break;
    }
    set.clear();
  }
  std::cout << sum << std::endl;
  return 0;
}

std::pair<bool, uint64_t> is_special_sum_set(const std::vector<uint64_t> set) {
  static std::vector<uint64_t> sums;
  static std::vector<uint64_t> elem_cnt;

  auto subset_cnt = (1ULL << set.size());
  sums.resize(subset_cnt);
  for (auto &sum : sums) {
    sum = 0;
  }

  elem_cnt.resize(subset_cnt, 0);
  for (size_t i = subset_cnt - 1; i >= 1 && elem_cnt[i] == 0; i--) {
    size_t j = i;
    while (j) {
      elem_cnt[i] += (j & 1);
      j >>= 1;
    }
  }

  uint64_t mask = 1;
  for (const auto &elem : set) {
    for (size_t i = 1; i < subset_cnt; i++) {
      if (i & mask) {
        sums[i] += elem;
      }
    }
    mask <<= 1;
  }

  for (size_t i = 1; i < subset_cnt; i++) {
    for (size_t j = i + 1; j < subset_cnt; j++) {
      if (i & j) {
        continue;
      }
      if (sums[i] == sums[j]) {
        return {false, 0};
      }
      if (elem_cnt[i] > elem_cnt[j] && sums[i] < sums[j]) {
        return {false, 0};
      }
      if (elem_cnt[i] < elem_cnt[j] && sums[i] > sums[j]) {
        return {false, 0};
      }
    }
  }
  return {true, sums.back()};
}
