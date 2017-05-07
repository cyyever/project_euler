/*
 *	程序名：euler71.cpp
 *	日期：2017-05-04
 *	功能：解决eulerproject 71题(https://projecteuler.net/problem=71)
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  const size_t max_denominator = 1000000;
  size_t result_denominator = 1;
  size_t result_numerator = 0;

  //我们按照分母来遍历
  for (size_t denominator = 3; denominator <= max_denominator; denominator++) {
    size_t numerator = (denominator - 1) / 2;
    while (numerator >= 1) {
      // numerator/denominator < 3/7
      if (7 * numerator < 3 * denominator) {
        break;
      }
      numerator--;
    }

    if (numerator > 0) {
      if (result_denominator * numerator > denominator * result_numerator) {
        result_denominator = denominator;
        result_numerator = numerator;
      }
    }
  }

  std::cout << result_numerator << std::endl;
  return 0;
}
