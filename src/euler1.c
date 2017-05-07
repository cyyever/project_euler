/*
 *	程序名：euler1.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 1题(https://projecteuler.net/problem=1)
 */
#include <inttypes.h>
#include <stdio.h>

#define N 1000
int main(void) {
  uint64_t sum, n;

  sum = 0;

  n = (N - 1) / 3;
  sum += 3 * n * (n + 1) / 2;

  n = (N - 1) / 5;
  sum += 5 * n * (n + 1) / 2;

  n = (N - 1) / 15;
  sum -= 15 * n * (n + 1) / 2;

  printf("%" PRIu64 "\n", sum);
  return 0;
}
