/*
 *	程序名：euler58.cpp
 *	作者：陈源源
 *	日期：2016-03-06
 *	功能：解决eulerproject 58题(https://projecteuler.net/problem=58)
 */
#include <cyy/math/all.hpp>
#include <iostream>

using namespace std;

int main() {
  uint64_t side_length;
  size_t prime_cnt = 0, num, i, num_cnt;
  auto prime_colloction = cyy::math::primes();
  auto it = prime_colloction.begin();

  for (side_length = 3, num_cnt = 5;; side_length += 2, num_cnt += 4) {
    num = side_length * side_length;
    num -= 3 * (side_length - 1);
    for (i = 0; i < 3; i++) {
      while (*it < num) {
        it++;
      }
      if (*it == num)
        prime_cnt++;
      num += side_length - 1;
    }
    if (prime_cnt * 10 < num_cnt)
      break;
  }
  cout << side_length << endl;
  return -1;
}
