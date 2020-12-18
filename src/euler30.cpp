/*
 *	程序名：euler30.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 26题(https://projecteuler.net/problem=26)
 */
#include <cinttypes>
#include <cstdio>

int main() {
  uint64_t digit_fifth_powers[10], i, j, max_i, sum, digit_sum;

  //先计算位的五次方
  for (i = 0; i < 10; i++)
    digit_fifth_powers[i] = i * i * i * i * i;

  //随着位数的增大，会找不到满足条件的位数，我们必须先找出这种位数，才能确定遍历上限
  i = 1;
  max_i = 1;
  while (i * digit_fifth_powers[9] > max_i) {
    i++;
    max_i *= 10;
  }
  sum = 0;
  for (i = 2; i < max_i; i++) {
    digit_sum = 0;
    j = i;
    while (j) {
      digit_sum += digit_fifth_powers[j % 10];
      j /= 10;
    }
    if (digit_sum == i)
      sum += i;
  }

  printf("%" PRIu64 "\n", sum);
  return 0;
}
