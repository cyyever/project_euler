/*
 *	程序名：euler78.c
 *	日期：2015-09-18
 *	功能：解决eulerproject 78题(https://projecteuler.net/problem=78)
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 60000

int main(void) {
  size_t i, j;
  uint32_t *sum_nums;

  sum_nums = malloc((N + 1) * sizeof(*sum_nums));
  if (!sum_nums) {
    printf("malloc failed:%m\n");
    return -1;
  }
  for (i = 0; i <= N; i++)
    sum_nums[i] = 1;

  //把N个硬币分成不同的堆的次数相当于(1/1-x)(1/1-x^2)...(1/1-x^N)的生成函数对应的x^N的系数
  for (i = 2; i <= N; i++) {
    sum_nums[i] += sum_nums[0];
    if (sum_nums[i] >= 1000000)
      sum_nums[i] -= 1000000;
    if (sum_nums[i] == 0) {
      printf("%zu\n", i);
      break;
    }
    for (j = i + 1; j <= N; j++) {
      sum_nums[j] += sum_nums[j - i];
      if (sum_nums[j] >= 1000000)
        sum_nums[j] -= 1000000;
    }
  }
  return 0;
}
