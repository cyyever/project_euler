/*
 *	程序名：euler111.cpp
 *	日期：2016-02-28
 *	功能：解决eulerproject 111题(https://projecteuler.net/problem=111)
 */

#include <iostream>
#include <ranges>
#include <vector>

#include <cyy/math/all.hpp>

using namespace std;

int main() {
  uint64_t repeated_digit_num, num;
  uint64_t S[10], sum;
  char d, lowest_digit;
  char num_str[11];

  num_str[10] = '\0';
  sum = 0;
  for (d = '0'; d <= '9'; d++) {
    S[d - '0'] = 0;
    if (d == '0')
      lowest_digit = '1';
    else
      lowest_digit = '0';
    for (repeated_digit_num = 9; repeated_digit_num >= 2;
         repeated_digit_num--) {
      for (auto const &combination :
           cyy::math::all_combinations(10, repeated_digit_num)) {
        if (combination[0] == 1 && d == '0')
          continue;
        if (combination.back() == 10) {
          if (((d - '0') & 1) == 0)
            continue;
          else if (d == '5')
            continue;
        }
        for (size_t i = 0; i < 10; i++) {
          num_str[i] = lowest_digit;
        }
        for (auto i : combination) {
          num_str[i - 1] = d;
        }
        if (combination[0] != 1) {
          if (d != '1')
            num_str[0] = '1';
          else
            num_str[0] = '2';
        }

        while (true) {
          num = stoull(num_str);
          if (cyy::math::primes().has(num))
            S[d - '0'] += num;
          int i;
          for (i = 9; i >= 0; i--) {
            if (std::ranges::binary_search(combination, i + 1)) {
              continue;
            }
            if (num_str[i] < '9') {
              num_str[i]++;
              if (num_str[i] == d)
                num_str[i]++;
              if (num_str[i] <= '9') {
                for (int j = i + 1; j < 10; j++) {
                  if (std::ranges::binary_search(combination, j + 1))
                    num_str[j] = d;
                  else
                    num_str[j] = lowest_digit;
                }
                break;
              }
            }
          }
          if (i < 0)
            break;
        }
      }
      if (S[d - '0'] != 0) {
        sum += S[d - '0'];
        break;
      }
    }
  }

  cout << sum << endl;
  return 0;
}
