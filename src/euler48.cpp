/*
 *	程序名：euler48.c
 *	日期：2014-11-20
 *	功能：解决eulerproject 48题(https://projecteuler.net/problem=48)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>

int main() {
  unsigned __int128 i, n, power, sum, res;

  sum = 0;
  for (i = 1; i <= 1000; i++) {
    power = i;
    n = i;
    res = 1;
    while (power) {
      if (power & 1)
        res = (res * n) % 10000000000;
      power >>= 1;
      n = (n * n) % 10000000000;
    }
    sum = (sum + res) % 10000000000;
  }

  printf("%" PRIu64 "\n", (uint64_t)sum);
  return 0;
}
