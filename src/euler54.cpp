/*
 *	程序名：euler54.cpp
 *	功能：解决eulerproject 54题(https://projecteuler.net/problem=54)
 */

#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <range/v3/all.hpp>
#include <set>
#include <string>
#include <vector>

namespace {
  struct hand {
    std::map<char, std::set<int>> suits;
    void remove_value(int v) {
      std::string empty_suit;
      for (auto &[c, suit_values] : suits) {
        suit_values.erase(v);
        if (suit_values.empty()) {
          empty_suit.push_back(c);
        }
      }

      for (auto c : empty_suit) {
        suits.erase(c);
      }
    }
    size_t count(int v) const {
      size_t suit_cnt = 0;
      for (auto &[_, suit_values] : suits) {
        suit_cnt += suit_values.count(v);
      }
      return suit_cnt;
    }
    size_t size() const {
      size_t size = 0;
      for (auto &[_, suit_values] : suits) {
        size += suit_values.size();
      }

      return size;
    }
    std::set<int> all_values() const {
      std::set<int> res;
      for (const auto &[_, suit_values] : suits) {
        std::set<int> tmp;
        ranges::set_union(res, suit_values, tmp);
        res = std::move(tmp);
      }
      return res;
    }
  };

  struct seq {
    int level;
    int value;
  };

  std::vector<seq> process_hand(hand h) {
    if (h.size() == 0) {
      return {};
    }
    if (h.size() == 5) {
      // Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
      for (auto &[suit, values] : h.suits) {
        std::set<int> flush{10, 11, 12, 13, 14};
        if (values == flush) {
          seq s;
          s.level = 1;
          s.value = 14;
          return {s};
        }
      }
      // Straight Flush: All cards are consecutive values of same suit.
      if (h.suits.size() == 1) {
        for (const auto &[suit, values] : h.suits) {
          if (values.size() == 5) {
            auto min_value = *values.begin();
            std::set<int> flush{min_value, min_value + 1, min_value + 2,
                                min_value + 3, min_value + 4};
            if (values == flush) {
              seq s;
              s.level = 2;
              s.value = 14;
              return {s};
            }
          }
        }
      }
    }

    // Four of a Kind: Four cards of the same value.
    if (h.suits.size() == 4) {
      auto it = h.suits.begin();
      auto values = it->second;
      it++;
      for (; it != h.suits.end(); it++) {
        auto tmp = std::move(values);
        values.clear();
        ranges::set_intersection(tmp, it->second, values);
      }
      if (!values.empty()) {
        std::vector<seq> tmp;
        for (auto c : values) {
          seq s;
          s.level = 3;
          s.value = c;
          tmp.push_back(s);
          h.remove_value(c);
        }
        auto remain = process_hand(h);
        remain.insert(remain.end(), tmp.begin(), tmp.end());
        return remain;
      }
    }

    if (h.size() == 5) {
      // Full House: Three of a kind and a pair.
      for (auto k : {13, 12, 11}) {
        if (h.count(k) == 3) {
          for (int p = 14; p >= 2; p--) {
            if (p == k) {
              continue;
            }
            if (h.count(p) == 2) {
              seq s;
              s.level = 4;
              s.value = k;
              return {s};
            }
          }
        }
      }

      // All cards of the same suit.
      if (h.suits.size() == 1) {
        seq s;
        s.level = 5;
        s.value = *h.suits[0].values.rbegin();
        return { s }
      }
    }

    auto values = h.values();

    // Straight: All cards are consecutive values.
    if (values.size() == 5) {
      auto min_value = *values.begin();
      if (values == std::set<int>{min_value, min_value + 1, min_value + 2,
                                  min_value + 3, min_value + 4}) {
        seq s;
        s.level = 6;
        s.value = *values.begin();
        return { s }
      }
    }

    // Three of a Kind: Three cards of the same value.
    if (values.size() >= 3) {
      for (int p = 14; p >= 2; p--) {
        if (h.count(p) == 3) {
          seq s;
          s.level = 7;
          s.value = p;
          h.remove_value(p);
          auto remain = process_hand(h);
          remain.push_back(s);
          return remain;
        }
      }
    }

    // Two Pairs: Two different pairs.
    if (values.size() >= 4) {
      for (int p = 14; p >= 2; p--) {
        if (h.count(p) >= 2) {
          for (int q = p - 1; q >= 2; q--) {
            if (h.count(q) >= 2) {
              seq s;
              s.level = 8;
              s.value = p * 15 + q;
              h.remove_value(p);
              h.remove_value(q);
              auto remain = process_hand(h);
              remain.push_back(s);
              return remain;
            }
          }
        }
      }
    }

    // One Pair: Two cards of the same value.
    if (values.size() >= 2) {
      for (int p = 14; p >= 2; p--) {
        if (h.count(p) >= 2) {
          seq s;
          s.level = 9;
          s.value = p;
          h.remove_value(p);
          auto remain = process_hand(h);
          remain.push_back(s);
          return remain;
        }
      }
    }

    // High Card: Highest value card.
    seq s;
    s.level = 9;
    s.value = *values.rbegin();
    h.remove_value(s.value);
    auto remain = process_hand(h);
    remain.push_back(s);
    return remain;
  }

} // namespace
int main(void) {
  std::ifstream in_file(std::filesystem::path(DATA_DIR) / "p054_poker.txt");

  std::string card;
  size_t cnt = 0;
  while (true) {
    hand a, b;
    for (size_t i = 0; i < 10; i++) {
      in_file >> card;
      if (in_file.eof()) {
        goto end;
      }
      hand *h = &b;
      if (i < 5) {
        h = &a;
      }
      if (card[0] == 'J') {
        h->suits[card[1]].insert(11);
      } else if (card[0] == 'Q') {
        h->suits[card[1]].insert(12);
      } else if (card[0] == 'K') {
        h->suits[card[1]].insert(13);
      } else if (card[0] == 'A') {
        h->suits[card[1]].insert(14);
      }
    }
    auto a_seqs = process_hand(a);
    auto b_seqs = process_hand(b);
    auto a_it = a_seqs.rbegin();
    auto b_it = b_seqs.rbegin();
    while (true) {
      if (a_it->level < b_it->level) {
        cnt++;
        break;
      }
      if (a_it->level > b_it->level) {
        break;
      }
      if (a_it->value > b_it->value) {
        cnt++;
        break;
      }
      if (a_it->value < b_it->value) {
        break;
      }
      a_it++;
      b_it++;
    }
  }
end:
  std::cout << cnt << std::endl;
  return 0;
}
