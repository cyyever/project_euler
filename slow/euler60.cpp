/*!
 * \file euler60.cpp
 *
 * \brief
 */

#include <cyy/math/all.hpp>
#include <iostream>
#include <utility>

using namespace std;

int main() {

  auto prime_c = cyy::math::primes();
  auto some_primes = prime_c.till(10000);
  std::map<uint64_t, std::set<uint64_t>> later_primes;
  std::set<std::pair<uint64_t, uint64_t>> two_element_set;
  std::vector<std::vector<uint64_t>> sub_sets;
  for (auto it = some_primes.begin(); it != some_primes.end(); it++) {
    auto it2 = it;
    it2++;
    auto prime1_str = std::to_string(*it);
    for (; it2 != some_primes.end(); it2++) {
      auto prime2_str = std::to_string(*it2);
      if (prime_c.has(std::stoull(prime1_str + prime2_str)) &&
          prime_c.has(std::stoull(prime2_str + prime1_str))) {
        later_primes[*it].insert(*it2);
        two_element_set.emplace(*it, *it2);
        sub_sets.emplace_back();
        sub_sets.back() = {*it, *it2};
      }
    }
  }

  puts("ddddddddddddd");
  uint64_t min_sum = UINT64_MAX;
  size_t i = 0;
  while (i < sub_sets.size()) {
    auto &sub_set = sub_sets[i];
    uint64_t sum = std::accumulate(sub_set.begin(), sub_set.end(), 0);
    if (sum > min_sum) {
      i++;
      continue;
    }
    if (sub_set.size() == 5) {
      min_sum = std::min(sum, min_sum);
      i++;
      std::cout << min_sum << std::endl;
      puts("vvvvvvv");
      continue;
    }

    bool new_element = false;

    for (auto p : later_primes[sub_set.back()]) {
      if (sum + p > min_sum) {
        break;
      }
      if (std::all_of(sub_set.begin(), sub_set.begin() + sub_set.size() - 1,
                      [=](auto const &ele) {
                        return two_element_set.count(std::pair{ele, p}) != 0;
                      })) {
        sub_set.push_back(p);
        new_element = true;
        break;
      }
    }
    if (!new_element) {
      i++;
    }
  }

  std::cout << min_sum << std::endl;
  return 0;
}
