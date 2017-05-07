/*
 *	程序名：euler29.c
 *	日期：2016-02-11
 *	功能：解决eulerproject 29题(https://projecteuler.net/problem=29)
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define N 100

int main(void) {
  uint64_t a, b, i, j;
  uint64_t power;
  uint64_t counts[N];
  uint8_t base[N + 1];

  for (a = 2; a <= N; a++)
    base[a] = 1;

  for (i = 0; i < N; i++)
    counts[i] = 0;

  counts[1] = N - 1;
  for (a = 2; a <= N; a++) {
    if (base[a] == 0)
      continue;
    counts[0] += counts[1];
    //如果这个数的n次方在这边，我们必须剔除重复的
    for (power = a * a, i = 2; power <= N; power *= a, i++) {
      base[power] = 0;
      if (counts[i] == 0) {
        for (b = 2; b <= N; b++) {
          for (j = 1; j < i; j++) {
            if (b * i % j == 0 && b * i / j <= N)
              break;
          }
          if (j == i)
            counts[i]++;
        }
      }
      counts[0] += counts[i];
    }
  }
  printf("%" PRIu64 "\n", counts[0]);
  return 0;
}
