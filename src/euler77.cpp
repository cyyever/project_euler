/*
 *	程序名：euler77.c
 *	日期：2015-09-18
 *	功能：解决eulerproject 77题(https://projecteuler.net/problem=77)
 */

#include <cinttypes>
#include <iostream>
#include <vector>

int main() {
  constexpr size_t N = 1000;
  size_t i, j, k;
  struct num_attr {
    uint8_t is_prime;                  //是否质数
    uint64_t per_prime_sum_num[N + 1]; //每个质数起始的质数和的数量
  };

  std::vector<num_attr> nums(N + 1, num_attr{});

  //标识质数
  for (i = 2; i <= N; i++)
    nums[i].is_prime = 1;
  for (i = 2; i <= N; i++) {
    if (nums[i].is_prime) {
      for (j = i * 2; j <= N; j += i)
        nums[j].is_prime = 0;
    }
  }

  //从2开始遍历
  for (i = 2; i <= N; i++) {
    uint64_t prime_sum_num = 0;
    for (j = i; j >= 2; j--) {
      if (!nums[j].is_prime) //我们从大到小抽取出i的质数
        continue;
      if (j == i) // i本身是质数
      {
        nums[i].per_prime_sum_num[j] = 1;
        prime_sum_num++;
        continue;
      }
      for (k = j; k >= 2; k--) {
        if (!nums[k].is_prime) //我们从大到小抽取出i的质数
          continue;
        nums[i].per_prime_sum_num[j] += nums[i - j].per_prime_sum_num[k];
      }
      prime_sum_num += nums[i].per_prime_sum_num[j];
    }
    if (prime_sum_num > 5000) {
      std::cout << i << std::endl;
      break;
    }
  }

  return 0;
}
