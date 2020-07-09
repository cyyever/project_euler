/*!
 * \file euler303.cpp
 *
 * \brief https://projecteuler.net/problem=303
 */

#include <algorithm>
#include <cassert>
#include <cyy/math/all.hpp>
#include <iostream>
#include <map>
#include <string>

std::string f(uint64_t n) {
  if (n <= 2) {
    return std::to_string(n);
  }
  std::map<uint64_t, std::string> suffixes;
  suffixes[0] = "0";
  suffixes[1] = "1";
  suffixes[2] = "2";
  uint64_t base = 10 % n;

  size_t suffix_len = 2;
  while (true) {
    decltype(suffixes) new_suffixes;
    for (auto &[remainder, suffix] : suffixes) {
      for (auto digit : {'1', '2'}) {
        auto new_remainder = (remainder + (digit - '0') * base) % n;
        if (new_remainder != 0 && suffixes.contains(new_remainder)) {
          continue;
        }
        auto it = new_suffixes.find(new_remainder);
        if (it != new_suffixes.end()) {
          suffix.push_back(digit);
          assert(suffix.size() == it->second.size());
          auto res = std::lexicographical_compare(
              suffix.rbegin(), suffix.rend(), it->second.rbegin(),
              it->second.rend());
          suffix.pop_back();

          if (!res) {
            continue;
          }
        }
        auto new_suffix = suffix;
        new_suffix.push_back(digit);
        new_suffixes[new_remainder] = new_suffix;
      }
      suffix.push_back('0');
    }
    if (new_suffixes.contains(0)) {
      auto &new_suffix = new_suffixes[0];
      std::ranges::reverse(new_suffix);
      return std::move(new_suffix);
    }

    for (auto const &[k, suffix] : suffixes) {
      if (new_suffixes.contains(k)) {
      }
    }
    suffixes.merge(std::move(new_suffixes));
    for (auto const &[_, suffix] : suffixes) {
      assert(suffix.size() == suffix_len);
    }
    suffix_len++;
    base *= 10;
    base %= n;
  }
  assert(false);
  return "";
}

int main() {
  cyy::math::integer sum = 0;
  for (uint64_t n = 1; n <= 10000; n++) {
    auto str = f(n);
    cyy::math::integer res(f(n));
    sum += res / n;
  }
  std::cout << sum << std::endl;
}
