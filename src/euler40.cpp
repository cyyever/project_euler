/*
 *	程序名：euler40.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 40题(https://projecteuler.net/problem=40)
 */
#include <cinttypes>
#include <cstdio>

/*
 *	功能：获取0.123456789101112131415161718192021...第n个位置的数字
 *	参数：
 *		n：位置
 *	返回值：
 *		对应的数字
 */
uint64_t d(uint64_t n);

int main() {
  printf("%" PRIu64 "\n",
         d(1) * d(10) * d(100) * d(1000) * d(10000) * d(100000) * d(1000000));
  return 0;
}

/*
 *	功能：获取0.123456789101112131415161718192021...第n个位置的数字
 *	参数：
 *		n：位置
 *	返回值：
 *		对应的数字
 */
uint64_t d(uint64_t n) {
  uint64_t base_num, cur_base_begin, next_base_begin, base, number, distance;

  //从个位数开始遍历
  cur_base_begin = 1;
  //我们计算出1，10，100等的起始位置，然后就可以通过在同一个位数下的模运算来处理
  for (base = 1, base_num = 1;; base_num++, base *= 10) {
    next_base_begin = cur_base_begin + 9 * base * base_num;
    if (n <= next_base_begin) {
      if (n == next_base_begin)
        return 1;
      distance = n - cur_base_begin;
      number = base + distance / base_num;
      distance %= base_num;
      while (distance) {
        number %= base;
        base /= 10;
        distance--;
      }
      return number / base;
    }
    cur_base_begin = next_base_begin;
  }
}
