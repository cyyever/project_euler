/*
 *	程序名：euler37.c
 *	日期：2014-11-20
 *	功能：解决eulerproject 37题(https://projecteuler.net/problem=37)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define N 1000000

struct num_attr {
  uint8_t is_prime;
  uint8_t is_left_truncatable;
  uint8_t is_right_truncatable;
};

int main() {
  uint64_t i;
  uint64_t j;

  std::vector<num_attr> num_attrs(N + 1, num_attr{});

  for (i = 2; i < N; i++) {
    num_attrs[i].is_prime = 1;
  }

  for (i = 2; i <= 10; i++) {
    if (num_attrs[i].is_prime) {
      num_attrs[i].is_left_truncatable = 1;
      num_attrs[i].is_right_truncatable = 1;
      for (j = i * 2; j < N; j += i) {
        num_attrs[j].is_prime = 0;
      }
    }
  }

  uint64_t sum = 0;
  for (i = 11; i < N; i++) {
    if (num_attrs[i].is_prime) {
      if (num_attrs[i / 10].is_right_truncatable) {
        num_attrs[i].is_right_truncatable = 1;
      }
      uint64_t power10 = 10;
      while (power10 * 10 < i) {
        power10 *= 10;
      }

      if (num_attrs[i % power10].is_left_truncatable) {
        num_attrs[i].is_left_truncatable = 1;
      }

      if (num_attrs[i].is_right_truncatable &&
          num_attrs[i].is_left_truncatable) {
        sum += i;
      }
      for (j = i * 2; j < N; j += i) {
        num_attrs[j].is_prime = 0;
      }
    }
  }

  printf("%" PRIu64 "\n", sum);
  return 0;
}
