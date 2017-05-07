/*
 *	程序名：euler26.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 26题(https://projecteuler.net/problem=26)
 */
#include <inttypes.h>
#include <stdio.h>

#define N 1000

int main(void) {
  uint64_t d, max_d, j, numerator, start_numerator;
  uint64_t max_recurring_cycle_len, cycle_digits_num;
  uint64_t cycle_digits[10 * N];
  uint8_t flag;

  max_recurring_cycle_len = 0;
  max_d = 2;
  start_numerator = 10;

  for (d = 2; d < N; d++) {
    numerator = start_numerator;
    while (numerator < d)
      numerator *= 10;
    start_numerator = numerator;

    cycle_digits_num = 0;
    numerator %= d;
    cycle_digits[cycle_digits_num++] = numerator;
    if (numerator == 0) //整除
      continue;

    while (1) {
      numerator *= 10;
      while (numerator < d) {
        numerator *= 10;
        cycle_digits[cycle_digits_num++] = 0;
      }
      numerator %= d;
      if (numerator == 0) //整除
        break;
      cycle_digits[cycle_digits_num++] = numerator;

      flag = 0;
      for (j = 0; j < cycle_digits_num - 1; j++) {
        if (cycle_digits[j] == cycle_digits[cycle_digits_num - 1]) {
          if (cycle_digits_num - 1 - j > max_recurring_cycle_len) {
            max_recurring_cycle_len = cycle_digits_num - 1 - j;
            max_d = d;
          }
          flag = 1;
          break;
        }
      }
      if (flag == 1)
        break;
    }
  }
  printf("%" PRIu64 "\n", max_d);
  return 0;
}
