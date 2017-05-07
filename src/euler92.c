/*
 *	程序名：euler92.c
 *	日期：2015-04-26
 *	功能：解决eulerproject 92题(https://projecteuler.net/problem=92)
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

static uint64_t get_sum_of_square_digit(uint64_t n);

int main(void) {
  uint64_t i, j, pre_sum_of_square_digit, sum_of_square_digit = 0, count_89;
  uint8_t search_table[7 * 81 + 1];
  //注意到1千万以下的数的digit平方和不会超出7*81，因此我们可以先算出1到7*81的查找表，剩下的工作就很简单了
  for (i = 1; i <= 7 * 81; i++) //初始化查找表
    search_table[i] = 0;

  search_table[1] = 1;
  search_table[89] = 89;
  count_89 = 0;
  for (i = 2; i <= 7 * 81; i++) //初始化查找表
  {
    if (search_table[i] == 1)
      continue;
    if (search_table[i] == 89) {
      count_89++;
      continue;
    }
    pre_sum_of_square_digit = i;
    while (1) {
      search_table[pre_sum_of_square_digit] = 2; //跟踪本次chain
      sum_of_square_digit = get_sum_of_square_digit(pre_sum_of_square_digit);
      if (search_table[sum_of_square_digit] == 1 ||
          search_table[sum_of_square_digit] == 89)
        break;
      pre_sum_of_square_digit = sum_of_square_digit;
    }
    for (j = 2; j <= 7 * 81; j++) //初始化查找表
    {
      if (search_table[j] == 2)
        search_table[j] = search_table[sum_of_square_digit];
    }
    if (search_table[i] == 89)
      count_89++;
  }

  //开始迭代到一千万，我们优化一下数字的digit的平方和的计算
  for (i = 7 * 81 + 1; i <= 7 * 81 + 3; i++) {
    sum_of_square_digit = get_sum_of_square_digit(i);
    if (search_table[sum_of_square_digit] == 89)
      count_89++;
  }
  pre_sum_of_square_digit = sum_of_square_digit;
  for (i = 7 * 81 + 4, j = 1; i < 10000000; i++, j++) {
    if (j <= 9)
      sum_of_square_digit = pre_sum_of_square_digit + 2 * j - 1;
    else {
      j = 0;
      sum_of_square_digit = get_sum_of_square_digit(i);
    }
    if (search_table[sum_of_square_digit] == 89)
      count_89++;
    pre_sum_of_square_digit = sum_of_square_digit;
  }

  printf("%" PRIu64 "\n", count_89);
  return 0;
}

/*
 *	功能：计算传入数字的digit的平方和
 *	参数：
 *		n：要计算的数字
 *	返回值：
 *		数字的digit的平方和
 */
static uint64_t get_sum_of_square_digit(uint64_t n) {
  uint64_t sum, digit;

  sum = 0;
  while (n) {
    digit = n % 10;
    sum += digit * digit;
    n /= 10;
  }
  return sum;
}
