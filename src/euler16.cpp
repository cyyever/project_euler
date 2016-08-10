/*
 *	程序名：euler16.cpp
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 16题(https://projecteuler.net/problem=16)
 */

#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main() {
  uint64_t digit_sum;
  string power_str;

  power_str = static_cast<string>(power(2, 1000));

  digit_sum = 0;
  for (auto it = power_str.begin(); it != power_str.end(); it++)
    digit_sum += static_cast<unsigned char>(*it) - '0';
  cout << digit_sum << endl;
  return 0;
}
