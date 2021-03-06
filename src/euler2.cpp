/*
 *	程序名：euler2.c
 *	日期：2014-11-17
 *	功能：解决eulerproject 2题(https://projecteuler.net/problem=2)
 */
#include <cinttypes>
#include <cstdio>

int main() {
  uint64_t i = 1, j = 2, sum = 2, k = 0;
  while (j < 4000000) {
    k = i + j;
    i = j;
    j = k;
    if (j % 2 == 0)
      sum += j;
  }
  printf("%" PRIu64 "\n", sum);
  return 0;
}
