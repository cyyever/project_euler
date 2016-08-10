/*
 *	程序名：euler52.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 52题(https://projecteuler.net/problem=52)
 */
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_num_mask(uint64_t num, uint64_t *num_mask);

int main(void) {
  uint64_t i, j, res, num_mask, num_mask2, find_flag;

  for (i = 100; i; i++) //至少要从3位数开始才会有6个不同顺序的digit
  {
    res = i;
    if (get_num_mask(res, &num_mask) != 0)
      continue;

    find_flag = 1;
    for (j = 0; j < 5; j++) {
      res += i;
      if (get_num_mask(res, &num_mask2) != 0) {
        find_flag = 0;
        break;
      }

      if (num_mask != num_mask2) {
        find_flag = 0;
        break;
      }
    }
    if (find_flag)
      break;
  }
  printf("%" PRIu64 "\n", i);
  return 0;
}

/*
 *	功能：获取指定数字的掩码
 *	参数：
 *		num：数字
 *		num_mask：数字掩码
 *	返回值：
 *		1：数字有重复位数
 *		0：成功
 */
int get_num_mask(uint64_t num, uint64_t *num_mask) {
  uint64_t digit;

  *num_mask = 0;

  while (num) {
    digit = num % 10;
    if (((*num_mask) & (1 << digit)) != 0)
      return 1;
    (*num_mask) |= (1 << digit);
    num /= 10;
  }
  return 0;
}
