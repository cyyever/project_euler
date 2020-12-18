/*
 *	程序名：euler24.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 24题(https://projecteuler.net/problem=24)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>

#define N 10

int main() {
  uint8_t i, j, digits[N];
  uint64_t count, num_mask;

  for (i = 0; i < N; i++)
    digits[i] = i;

  count = 1;
  //开始生成转置
  while (true) {
    //先获取最右边的逆
    i = N - 1;
    num_mask = 0;
    while (i > 0 && digits[i] < digits[i - 1]) {
      num_mask |= (1 << (digits[i]));
      i--;
    }
    if (i == 0)
      break;
    num_mask |= (1 << (digits[i]));
    i--;
    num_mask |= (1 << (digits[i]));

    //增加到下一个数
    j = digits[i] + 1;
    while (j < N) {
      if ((num_mask & (1 << j)) != 0)
        break;
      j++;
    }
    digits[i] = j;
    num_mask &= (~(1 << j));
    i++;
    j = 0;
    while (i < N) {
      while (num_mask) {
        if (num_mask & 1)
          break;
        j++;
        num_mask >>= 1;
      }
      digits[i++] = j++;
      num_mask >>= 1;
    }
    count++;
    if (count == 1000000)
      break;
  }

  for (i = 0; i < N; i++)
    printf("%d", (int)digits[i]);
  puts("");
  return 0;
}
