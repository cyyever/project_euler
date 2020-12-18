/*
 *	程序名：euler47.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 47题(https://projecteuler.net/problem=47)
 */
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

#define N 1000000

struct num_attr {
  uint8_t is_prime;
  uint64_t prime_num;
};

int main() {
  uint64_t i, j;

  std::vector<num_attr> num_attrs(N + 1);

  //标识质数
  for (i = 2; i <= N; i++)
    num_attrs[i].is_prime = 1;

  for (i = 2; i <= N; i++) {
    if (num_attrs[i].is_prime) //质数的真除数和肯定是1，而且不是amicable number
    {
      //开始标识合数
      for (j = i * 2; j <= N; j += i) {
        num_attrs[j].prime_num++;
        num_attrs[j].is_prime = 0;
      }
    } else if (i > 4) {
      if (num_attrs[i].prime_num == 4 && num_attrs[i - 1].prime_num == 4 &&
          num_attrs[i - 2].prime_num == 4 && num_attrs[i - 3].prime_num == 4) {
        printf("%" PRIu64 "\n", i - 3);
        break;
      }
    }
  }
  return 0;
}
