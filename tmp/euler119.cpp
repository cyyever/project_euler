/*
 *	程序名：euler119.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 119题(https://projecteuler.net/problem=119)
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

bool check_digit_sum(uint64_t num, uint64_t sum) {
  /*
  if(num%3!=sum%3) {
    return false;
  }
  */
  while (num) {
    auto digit = num % 10;
    num /= 10;
    if (digit > sum) {
      return false;
    }
    sum -= digit;
  }
  return sum == 0;
}

int main(void) {
  std::multimap<uint64_t, uint64_t> powers;

  powers.emplace(4, 2);

  uint64_t next_square = 9;
  uint64_t next_number = 3;
  uint64_t term_number=0;
  while (true) {

    uint64_t min_power = next_square;
    uint64_t number = next_number;

    if (min_power > powers.begin()->first) {
      min_power = powers.begin()->first;
      number = powers.begin()->second;
      powers.erase(powers.begin());
    } else {
      next_number++;
      next_square = next_number * next_number;
    }
    powers.emplace(min_power * number, number);

    if (min_power < 10) {
      continue;
    }
    /*
    if (min_power > 6722988818432)
      std::cout << number << " " << min_power << std::endl;

      */
    if (check_digit_sum(min_power, number)) {
      term_number++;
      if(term_number==28) {
      std::cout << min_power << std::endl;
      return 0;
      }
    }
  }
  return 0;
}
