/*
 *	程序名：euler20.cpp
 *	日期：2014-11-17
 *	功能：解决eulerproject 20题(https://projecteuler.net/problem=20)
 */
#include <cyy/math/arithmetic.hpp>
#include <iostream>

using namespace std;

int main() {
  uint64_t digit_sum;
  string factorial_str = cyy::math::factorial(100).to_string();

  digit_sum = 0;
  for (auto const c : factorial_str)
    digit_sum += static_cast<uint64_t>(c - '0');
  cout << digit_sum << endl;
  return 0;
}
