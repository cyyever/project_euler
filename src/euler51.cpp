/*
 *	程序名：euler51.cpp
 *	日期：2016-02-23
 *	功能：解决eulerproject 51题(https://projecteuler.net/problem=51)
 */

#include <cyy/math/all.hpp>
#include <iostream>
#include <string>

using namespace std;

int main() {

  // x x+n x+2n x+3n
  //由于我们要获得8个质数的家族，那么在0-9中，不管我们怎么分，至少有4个数是连续的，如果我们替换的digit数量不是3的倍数，总会出现一个数能被3整除，那么它肯定不是质数，矛盾，同时要替换的digit不能出现在最低位，不然4个连续的数有一个会被2整除，那么它肯定不是质数
  auto prime_collection = cyy::math::primes();
  for (auto prime : prime_collection.from(1000)) {
    const auto prime_str = std::to_string(prime);
    const auto digit_num = prime_str.size();
    for (uint64_t replace_digit_num = 3; replace_digit_num <= digit_num - 1;
         replace_digit_num += 3) {
      for (auto const &combination :
           cyy::math::all_combinations(digit_num - 1, replace_digit_num)) {

        char digit = '\0';
        bool can_replace = true;
        for (auto index : combination) {
          if (digit == '\0') {
            digit = prime_str[index - 1];
          } else if (digit != prime_str[index - 1]) {
            can_replace = false;
            break;
          }
        }
        if (!can_replace) {
          continue;
        }
        uint64_t digit_sum = 0;
        for (auto c : prime_str) {
          digit_sum += c - '0';
        }
        if (digit_sum % 3 == 0) {
          continue;
        }

        char start_digit = '0';

        if (combination[0] == 1) {
          start_digit = '1';
        }
        size_t cnt = 1;
        for (char d = start_digit; d <= '9'; d++) {
          auto new_str = prime_str;
          for (auto index : combination) {
            new_str[index - 1] = d;
          }
          if (new_str != prime_str &&
              cyy::math::primes().has(std::stoull(new_str))) {
            cnt++;
          }
        }
        if (cnt == 8) {
          std::cout << prime_str << std::endl;
          return 0;
        }
      }
    }
  }

  return 0;
}
