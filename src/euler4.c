/*
 *	程序名：euler4.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 4题(https://projecteuler.net/problem=4)
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

static uint64_t max_palindromic;

static uint8_t is_palindromic(uint64_t num);

int main(void) {
  uint64_t i, j, product;
  ;

  for (i = 999; i >= 101; i--) {
    if (i * i < max_palindromic)
      break;
    for (j = i; j >= 101; j--) {
      product = i * j;
      if (product < max_palindromic)
        break;
      if (is_palindromic(product)) {
        max_palindromic = product;
        break;
      }
    }
  }
  printf("%" PRIu64 "\n", max_palindromic);
  return 0;
}

/*
 *	功能：判断指定数字是否是回文
 *	参数：
 *		num：要判断的数字
 *	返回值：
 *		1：回文
 *		0：不是回文
 */
uint8_t is_palindromic(uint64_t num) {
  static uint64_t base[10];
  uint64_t i, first_digit, last_digit, base_end;

  if (base[0] == 0) {
    base[0] = 1;
    for (i = 1; i < 10; i++)
      base[i] = base[i - 1] * 10;
  }

  if (num % 10 == 0)
    return 0;

  base_end = 0;
  for (i = 0; i < 10; i++) {
    if (base[i] <= num && base[i + 1] > num) {
      base_end = i;
      break;
    }
  }

  while (num) {
    last_digit = num / base[base_end];
    first_digit = num % 10;
    if (first_digit != last_digit)
      return 0;
    num = num % base[base_end];
    num = num / 10;
    base_end -= 2;
  }
  return 1;
}
