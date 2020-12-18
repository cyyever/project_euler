/*
 *	程序名：euler21.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 21题(https://projecteuler.net/problem=21)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>

#define N 10000

using num_attr = struct {
  uint8_t is_prime;
  uint64_t prime_divisor1;
  uint64_t prime_divisor2;
  uint64_t sum_of_divisors;
};

int main() {
  num_attr *num_attrs;
  uint64_t i, power_prime1, power_prime2, j, k;
  uint64_t sum;

  num_attrs = calloc(N + 1, sizeof(num_attr));
  if (!num_attrs) {
    printf("malloc failed:%m\n");
    return -1;
  }

  //标识质数
  for (i = 2; i <= N; i++)
    num_attrs[i].is_prime = 1;
  sum = 0;
  for (i = 2; i <= N; i++) {
    if (num_attrs[i].is_prime) //质数的真除数和肯定是1，而且不是amicable number
    {
      num_attrs[i].sum_of_divisors = 1;
      //开始标识合数
      for (k = 2, j = i * 2; j <= N; j += i, k++) {
        num_attrs[j].is_prime = 0;
        if (num_attrs[j].prime_divisor1 ==
            0) //如果这个合数之前没标识过互斥的，我们开始标识
        {
          num_attrs[j].prime_divisor1 = i;
          num_attrs[j].prime_divisor2 = k;
        }
      }
      //因为我们要表示互斥，那么必须考虑质数的指数
      power_prime1 = i;
      while (true) {
        power_prime2 = power_prime1 * i;
        if (power_prime2 > N)
          break;
        num_attrs[power_prime2].sum_of_divisors =
            num_attrs[power_prime1].sum_of_divisors + power_prime1;
        for (k = 2, j = power_prime2 * 2; j <= N; j += power_prime2, k++) {
          if (num_attrs[j].prime_divisor1 == power_prime1) //迭代质数的指数
          {
            num_attrs[j].prime_divisor1 = power_prime2;
            num_attrs[j].prime_divisor2 = k;
          }
        }
        power_prime1 = power_prime2;
      }
    } else //考虑合数的质数表示，显然它的真除数和是两个互斥的除数的除数和的乘积减去它自己
    {
      if (num_attrs[i].sum_of_divisors == 0)
        num_attrs[i].sum_of_divisors =
            (num_attrs[num_attrs[i].prime_divisor1].sum_of_divisors +
             num_attrs[i].prime_divisor1) *
                (num_attrs[num_attrs[i].prime_divisor2].sum_of_divisors +
                 num_attrs[i].prime_divisor2) -
            i;
      if (num_attrs[i].sum_of_divisors < i &&
          num_attrs[num_attrs[i].sum_of_divisors].sum_of_divisors == i)
        sum += i + num_attrs[i].sum_of_divisors;
    }
  }

  printf("%" PRIu64 "\n", sum);
  free(num_attrs);
  return 0;
}
