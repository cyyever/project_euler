/*
 *	程序名：euler49.c
 *	日期：2015-07-18
 *	功能：解决eulerproject 49题(https://projecteuler.net/problem=49)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

static uint16_t get_digit_mask(uint64_t number);

int main() {
  size_t i, j;

  std::vector<bool> primes(10000, true);

  for (i = 2; i <= primes.size(); i++) {
    if (primes[i]) {
      for (j = i * 2; j <= primes.size(); j += i)
        primes[j] = false;
    }
  }

  //遍历四位质数
  for (i = 1000; i <= 9999; i++) {
    if (!primes[i])
      continue;
    for (j = i + 1; j <= 9999; j++) {
      if (2 * j - i > 9999)
        break;
      if (primes[j]) {
        if (primes[2 * j - i]) {
          //看看是不是转置
          if (get_digit_mask(i) == get_digit_mask(j) &&
              get_digit_mask(i) == get_digit_mask(2 * j - i)) {
            printf("%zu%zu%zu\n", i, j, 2 * j - i);
          }
        }
      }
    }
  }
  return 0;
}

/*
 *	功能：获取位数掩码
 *	参数：
 *		number：要处理的数字
 *	返回值：
 *		位数掩码
 */
static uint16_t get_digit_mask(uint64_t number) {
  uint16_t mask;
  uint64_t digit;

  mask = 0;
  while (number) {
    digit = number % 10;
    mask |= (1 << digit);
    number /= 10;
  }
  return mask;
}
