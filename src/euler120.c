/*
 *	程序名：euler120.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 120题(https://projecteuler.net/problem=120)
 */

#include <inttypes.h>
#include <stdio.h>

/*
 *	功能：获取指定a下的((a−1)^n+(a+1)^n)/a^2的最大余数
 *	参数：
 *		a：待计算的a
 *	返回值：
 *		最大余数
 */
uint64_t rmax(uint64_t a);

int main(void) {
  uint64_t sum, a;

  sum = 0;
  for (a = 3; a <= 1000; a++)
    sum += rmax(a);
  printf("%" PRIu64 "\n", sum);
  return 0;
}

/*
 *	功能：获取指定a下的((a−1)^n+(a+1)^n)/a^2的最大余数
 *	参数：
 *		a：待计算的a
 *	返回值：
 *		最大余数
 */
uint64_t rmax(uint64_t a) {
  uint64_t a_distance;

  //由于(a-1)^n===(-1)^n+na*(-1)^(n-1) mod a^2 并且 (a+1)^n===(1)^n+na*(1)^(n-1)
  //mod a^2
  //所以当n为偶数时余数为2，否则余数为2na mod a^2
  //因此就归结为找出2 6
  //10开始的等差数列最靠近a的一个项，注意等差数列在超过a是必须减去n，导致数列重新开始遍历
  //接下来的数列可能更靠近a，以此类推
  //由于等差为4，那么起始数列靠近a的距离只能是[0,3]，然后进一步分析可以得出以下规律：

  a_distance = (a - 2) % 4;
  if (a_distance == 0 || a_distance == 2)
    return (a - 2) * a;
  else
    return (a - 1) * a;
}
