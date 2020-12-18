/*
 *	程序名：euler122.cpp
 *	日期：max_k+17-07-22
 *	功能：解决eulerproject 122题(https://projecteuler.net/problem=122)
 */

#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

int main() {

  constexpr size_t max_k = 200;

  size_t m[max_k + 1]{};
  std::set<std::set<size_t>> exp_masks[max_k + 1];

  m[1] = 1;
  exp_masks[1].insert({1});

  for (size_t k = 2; k <= max_k; k++) {
    if (k & 1) {
      m[k] = m[(k - 1) / 2] + 2;
    } else {
      m[k] = m[k / 2] + 1;
    }

    for (size_t i = 1; i <= k - i; i++) {
      if (m[i] + 1 > m[k] || m[k - i] + 1 > m[k]) {
        continue;
      }

      for (auto const &exp_mask_a : exp_masks[i]) {

        for (auto const &exp_mask_b : exp_masks[k - i]) {

          auto new_exp_mask = exp_mask_a;
          new_exp_mask.insert(exp_mask_b.begin(), exp_mask_b.end());
          new_exp_mask.insert(k);

          if (m[k] > new_exp_mask.size()) {
            exp_masks[k].clear();
            exp_masks[k].insert(new_exp_mask);
            m[k] = new_exp_mask.size();
          } else if (m[k] == new_exp_mask.size()) {
            exp_masks[k].insert(new_exp_mask);
          }
        }
      }
    }
  }

  size_t sum = 0;
  for (size_t k = 1; k <= max_k; k++) {
    sum += m[k] - 1;
  }
  std::cout << sum << std::endl;
  return 0;
}
