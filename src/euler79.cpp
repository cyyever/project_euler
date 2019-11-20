/*!
 * \file euler79.cpp
 */
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

namespace {
  std::string min_passcode;
  std::string get_front_by_frequency(const std::vector<std::string> &keys) {
    size_t counts[10]{};
    std::multimap<size_t, char, std::greater<size_t>> order;
    for (auto const &key : keys) {
      if (!key.empty()) {
        counts[key[0] - '0']++;
      }
    }
    for (size_t i = 0; i < 10; i++) {
      if (counts[i] != 0) {
        order.emplace(counts[i], '0' + i);
      }
    }
    std::string res;
    for (auto const &[_, c] : order) {
      res.push_back(c);
    }
    return res;
  }
  size_t max_key_len(const std::vector<std::string> &keys) {
    size_t len = 0;
    for (auto const &key : keys) {
      len = std::max(len, key.size());
    }
    return len;
  }

  void guess_passcode(const std::string &prefix,
                      const std::vector<std::string> &keys) {
    if (prefix.size() + max_key_len(keys) >= min_passcode.size()) {
      return;
    }
    for (auto c : get_front_by_frequency(keys)) {
      auto new_prefix = prefix;
      new_prefix.push_back(c);
      std::vector<std::string> new_keys;
      for (auto const &key : keys) {
        if (key[0] == c) {
          if (key.size() > 1) {
            new_keys.emplace_back(key.begin() + 1, key.end());
          }
        } else {
          new_keys.push_back(key);
        }
      }
      if (new_keys.empty()) {
        min_passcode = new_prefix;
        continue;
      }
      guess_passcode(new_prefix, new_keys);
    }
  }
} // namespace

int main() {
  std::ifstream is(std::filesystem::path(DATA_DIR) / "p079_keylog.txt");
  std::vector<std::string> keys;
  std::string key;
  size_t total_len = 0;
  while (is >> key) {
    total_len += key.size();
    keys.emplace_back(std::move(key));
  }
  min_passcode.resize(total_len);
  guess_passcode("", keys);
  std::cout << min_passcode << std::endl;
  return 0;
}
