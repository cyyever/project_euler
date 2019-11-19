/*
 *	��������euler58.cpp
 *	���ߣ���ԴԴ
 *	���ڣ�2016-03-06
 *	���ܣ����eulerproject 58��(https://projecteuler.net/problem=58)
 */
#include <cyy/math/all.hpp>
#include <iostream>

using namespace std;

int main() {
  uint64_t side_length;
  size_t prime_cnt = 0, num, i, num_cnt;
  auto prime_colloction = cyy::math::primes();
  auto all = prime_colloction.all();
  auto it = all.begin();

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
