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
  uint64_t num, prime, finded_prime, distance;
  ssize_t i, digit_num, replace_digit_num;
  size_t count;
  char replace_digit, digit;
  string num_str;

  // x x+n x+2n x+3n
  //由于我们要获得8个质数的家族，那么在0-9中，不管我们怎么分，至少有4个数是连续的，如果我们替换的digit数量不是3的倍数，总会出现一个数能被3整除，那么它肯定不是质数，矛盾，同时要替换的digit不能出现在最低位，不然4个连续的数有一个会被2整除，那么它肯定不是质数

  digit_num = 4;
  prime = 0;
  finded_prime = UINT64_MAX;

  while (1) {
    num_str = string(digit_num, '0');
    for (replace_digit_num = 3; replace_digit_num < digit_num;
         replace_digit_num += 3) {
      first_combination = true;

      for (auto const &combination :
           cyy::math::all_combinations(digit_num - 1, replace_digit_num)) {
        for (i = 0; i < digit_num - 1; i++)
          num_str[i] = '0' + combination[i];
        num_str[digit_num - 1] = '0';
        distance = stoull(num_str);
        if (combination[0] == 1) //首位从1开始替换
          replace_digit = '1';
        else
          replace_digit = '0';
        num_str[0] = '1';
        num_str[digit_num - 1] = '1';
        while (1) {
          for (auto n : combination) {
            num_str[n - 1] = replace_digit;
          }
          num = stoull(num_str);
          count = 0;
          digit = replace_digit;
          do {
            if (cyy::math::primes().has(num)) {
              if (count == 0)
                prime = num;
              count++;
            }
            digit++;
            num += distance;
          } while (digit <= '9' && count + '9' - digit + 1 >= 8);

          if (count == 8) //我们已经找到一个，但是无法确定它是不是最小的
          {
            if (prime < finded_prime)
              finded_prime = prime;
          }

          if (num_str[digit_num - 1] < '8') {
            if (num_str[digit_num - 1] == '3')
              num_str[digit_num - 1] = '7';
            else
              num_str[digit_num - 1] += 2;
            continue;
          }

          for (i = digit_num - 1; i >= 0; i--) {
            if (!combination[i] && num_str[i] < '9') {
              num_str[i]++;
              num_str.replace(i + 1, digit_num - i - 1, digit_num - i - 1, '0');
              num_str[digit_num - 1] = '1';
              break;
            }
          }
          if (i < 0)
            break;
        }
      }
    }
    if (finded_prime != UINT64_MAX)
      break;
    digit_num++;
  }
  cout << finded_prime << endl;
  return 0;
}
