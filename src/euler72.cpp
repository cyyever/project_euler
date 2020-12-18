/*
 *	程序名：euler72.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 72题(https://projecteuler.net/problem=72)
 */
#include <cinttypes>
#include <cstdio>

#define D 1000000

int main() {
  uint64_t count;
  uint32_t d, i, j;
  uint32_t euler_totient[D + 1];

  //这题实质上是求2到D的欧拉函数的和
  count = 0;
  for (d = 2; d <= D; d++) {
    if (euler_totient[d] == 0) //还没初始值，那么d肯定是质数
    {
      euler_totient[d] = d - 1;
      //对于d的倍数，扣去对应的乘积
      for (i = d + d, j = 2; i <= D; i += d, j++) {
        if (euler_totient[i] == 0)
          // euler_totient[i]=i-i/d;
          euler_totient[i] = i - j;
        else
          euler_totient[i] -= (euler_totient[i]) / d;
      }
    }
    count += euler_totient[d];
  }

  printf("%" PRIu64 "\n", count);
  return 0;
}
