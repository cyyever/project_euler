/*
 *	程序名：euler87.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 87题(https://projecteuler.net/problem=87)
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>

int main(void) {
  constexpr uint64_t N = 50000000;
  uint64_t prime_limit = static_cast<uint64_t>(sqrt(N)) + 1;

  std::vector<bool> is_prime(N + 1, true);
  std::vector<uint64_t> prime_squre;
  std::vector<uint64_t> prime_cube;
  std::vector<uint64_t> prime_fourth_power;
  std::set<uint64_t> result;

  for (uint64_t i = 2; i <= prime_limit; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (uint64_t j = i + i; j <= prime_limit; j += i) {
      is_prime[j] = false;
    }

    auto square = i * i;
    prime_squre.push_back(square);
    auto cube = i * square;
    if (cube < N) {
      prime_cube.push_back(cube);
      auto fourth_power = square * square;
      if (fourth_power < N) {
        prime_fourth_power.push_back(fourth_power);
      }
    }
  }

  for (auto const &square : prime_squre) {
    for (auto const &cube : prime_cube) {
      uint64_t part_sum = square + cube;
      if (part_sum >= N) {
        break;
      }
      for (auto const &fourth_power : prime_fourth_power) {
        auto sum = part_sum + fourth_power;
        if (sum < N) {
          result.insert(sum);
        } else {
          break;
        }
      }
    }
  }
  std::cout << result.size() << std::endl;
  return 0;
}
