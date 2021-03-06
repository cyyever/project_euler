/*
 *	程序名：euler76.c
 *	日期：2015-09-18
 *	功能：解决eulerproject 76题(https://projecteuler.net/problem=76)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define N 100

int main() {
  size_t i, j;
  struct num_attr {
    uint64_t sum_num[N + 1]; //小于等于该数起始的和的数量
  };

  std::vector<num_attr> nums(N + 1, num_attr{});

  for (i = 1; i <= N; i++) {
    nums[i].sum_num[i] = 1;
    for (j = i - 1; j >= 1; j--) {
      if (j > i - j)
        nums[i].sum_num[j] = nums[i - j].sum_num[i - j];
      else
        nums[i].sum_num[j] = nums[i - j].sum_num[j];
    }
    for (j = 2; j <= i; j++)
      nums[i].sum_num[j] += nums[i].sum_num[j - 1];
  }
  printf("%" PRIu64 "\n", nums[N].sum_num[N] - 1);
  return 0;
}
