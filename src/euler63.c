/*
 *	程序名：euler63.c
 *	日期：2014-11-26
 *	功能：解决eulerproject 63题(https://projecteuler.net/problem=63)
 */
#include <inttypes.h>
#include <stdio.h>

int main(void) {
  unsigned __int128 power10s[100];
  uint64_t count;
  unsigned __int128 base, num, *power10;

  //首先指数的幂只能是1到9，因为10^n的位数为n+1，更不要说更大的数
  //所以我们的目标是解这个方程base^n>10^(n-1)
  // ln(base)*n>ln10*(n-1)
  // ln10/(ln10-ln(base))>n
  //但是我们没法搞对数，只能通过便利来处理

  count = 0;
  power10s[0] = 1;
  for (base = 1; base <= 9; base++) {
    num = 1;
    power10 = power10s;
    while (1) {
      num *= base;
      if (*power10 == 0)
        *power10 = *(power10 - 1) * 10;
      if (num < *power10)
        break;
      count++;
      power10++;
    }
  }

  printf("%" PRIu64, count);
  return 0;
}
