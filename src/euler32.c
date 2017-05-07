/*
 *	程序名：euler32.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 32题(https://projecteuler.net/problem=32)
 */
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int get_next_part_pandigital_num(uint8_t *digits, uint8_t digit_num);

int main(void) {
  size_t i, j, k;
  uint64_t a, b, c, sum;
  uint8_t digits[] = {1, 2, 3, 4, 5}, *c_flags;
  char str[20];
  int flag;

  c_flags = calloc(100000, 1);
  if (!c_flags) {
    printf("calloc failed:%m");
    return 0;
  }

  //令a*b=c，则c的位数是a和b的位数和或少1
  //为了满足等式，根据观察可知两个乘数的位数之和必须为5，可以指定a4位b1位或a3位b2位
  //因此我们迭代5位的部分pandigital数
  sum = 0;
  do {
    for (j = 0; j < 2; j++) {
      if (j == 0) {
        a = digits[0];
        for (i = 1; i < 4; i++)
          a = a * 10 + digits[i];
        b = digits[4];
      } else {
        a = digits[0];
        for (i = 1; i < 3; i++)
          a = a * 10 + digits[i];
        b = digits[3] * 10 + digits[4];
      }

      c = a * b;
      //检查pandigital
      sprintf(str, "%" PRIu64 "%" PRIu64 "%" PRIu64, a, b, c);
      if (strlen(str) != 9)
        continue;
      flag = 1;
      for (k = 1; k <= 9; k++) {
        if (!strchr(str, '0' + k)) {
          flag = 0;
          break;
        }
      }
      if (flag == 1) {
        if (!c_flags[c]) {
          sum += c;
          c_flags[c] = 1;
        }
        break;
      }
    }
  } while (get_next_part_pandigital_num(digits, 5));
  printf("%" PRIu64 "\n", sum);
  free(c_flags);
  return 0;
}

/*
 *	功能：获取下一个部分pandigital数
 *	参数：
 *		digits：当前部分pandigital数
 *		digit_num：需要满足的位数
 *	返回值：
 *		1：成功
 *		0：已经到达最大数
 */
static int get_next_part_pandigital_num(uint8_t *digits, uint8_t digit_num) {
  ssize_t i, j, k;
  uint16_t mask;
  int flag;

  mask = 0;
  for (i = 1; i <= 9; i++)
    mask |= (1 << i);
  for (i = 0; i < digit_num; i++)
    mask &= ~(1 << digits[i]);

  i = digit_num - 1;
  flag = 0;
  while (i >= 0) {
    if (digits[i] < 9) {
      for (j = i; j < digit_num; j++)
        mask |= (1 << digits[j]);

      for (j = digits[i] + 1; j <= 9; j++) {
        if (mask & (1 << j)) {
          digits[i] = (uint8_t)j;
          mask &= ~(1 << j);
          flag = 1;
          break;
        }
      }

      if (flag == 0) {
        i--;
        continue;
      }

      for (j = i + 1; j < digit_num; j++) {
        for (k = 1; k <= 9; k++) {
          if (mask & (1 << k)) {
            digits[j] = (uint8_t)k;
            mask &= ~(1 << k);
            break;
          }
        }
      }
      return 1;
    }
    i--;
  }
  return 0;
}
