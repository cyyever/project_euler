/*
 *	程序名：euler6.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 6题(https://projecteuler.net/problem=6)
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  uint64_t n;

  n = 100;

  printf("%" PRIu64 "\n",
         n * n * (n + 1) * (n + 1) / 4 - n * (n + 1) * (2 * n + 1) / 6);
  return 0;
}
