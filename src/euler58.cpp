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
  uint64_t layer_num, side_length;
  size_t prime_cnt, num, i, num_cnt;

  for (layer_num = 2, side_length = 3, num_cnt = 5;;
       layer_num++, side_length += 2, num_cnt += 4) {
    num = side_length * side_length;
    for (i = 0; i < 3; i++) {
      num -= (side_length - 1);
      if (cyy::math::primes().has(num))
        prime_cnt++;
    }
    if (prime_cnt * 10 < num_cnt)
      break;
  }
  cout << side_length << endl;
  return -1;
}
