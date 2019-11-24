/*
 *	程序名：euler56.cpp
 *	日期：2014-11-20
 *	功能：解决eulerproject 56题(https://projecteuler.net/problem=56)
 */

#include <cyy/math/all.hpp>
#include <iostream>

using namespace std;

int main() {
  uint64_t max_digit_sum = 0;
  uint32_t a, b;
  cyy::math::integer power;
  cyy::math::integer threshold = 0;
  uint64_t last_nine_num = 0;
  uint32_t last_b = 2;
  for (a = 99; a >= 2; a--) {
    for (b = last_b, power = cyy::math::exponent(cyy::math::integer(a), b);
         b < 100; b++, power *= a) {
      if (power < threshold) {
        last_b = b + 1;
        continue;
      }
      uint64_t digit_sum = 0;
      for (auto const c : power.to_string())
        digit_sum += static_cast<uint64_t>(c - '0');
      if (digit_sum > max_digit_sum) {
        max_digit_sum = digit_sum;
        auto nine_num = max_digit_sum / 9;
        while (last_nine_num < nine_num) {
          threshold *= 10;
          threshold += 9;
          last_nine_num++;
        }
      }
    }
  }
  cout << max_digit_sum << endl;
  return 0;
}
