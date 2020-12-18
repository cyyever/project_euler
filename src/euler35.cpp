/*
 *	程序名：euler35.c
 *	日期：2014-11-20
 *	功能：解决eulerproject 35题(https://projecteuler.net/problem=35)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>

#define N 1000000

int main() {
  uint8_t primes[N + 1];
  size_t i, j, next_rotation, find_flag;
  uint64_t power, count;

  //标识质数
  for (i = 2; i <= N; i++)
    primes[i] = 1;
  for (i = 2; i <= N; i++) {
    if (primes[i])
      for (j = i * 2; j <= N; j += i)
        primes[j] = 0;
  }

  //找出具有指定性质的质数
  power = 1;
  count = 0;
  for (i = 2; i <= N; i++) {
    if (primes[i]) {
      while (power * 10 < i)
        power *= 10;

      find_flag = 1;

      next_rotation = i / 10 + (i % 10) * power;
      while (next_rotation != i) {
        if (!primes[next_rotation]) {
          find_flag = 0;
          break;
        }
        next_rotation = next_rotation / 10 + (next_rotation % 10) * power;
      }

      if (find_flag)
        count++;
    }
  }
  printf("%" PRIu64 "\n", count);
  return 0;
}
