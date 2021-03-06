/*
 *	程序名：euler78.cpp
 *	日期：2015-09-18
 *	功能：解决eulerproject 78题(https://projecteuler.net/problem=78)
 */

#include <cinttypes>
#include <cstring>
#include <iostream>
#include <vector>

#define N 60000

int main() {
  size_t i, j;
  std::vector<uint32_t> sum_nums(N + 1, 1);

  //把N个硬币分成不同的堆的次数相当于(1/1-x)(1/1-x^2)...(1/1-x^N)的生成函数对应的x^N的系数
  for (i = 2; i <= N; i++) {
    sum_nums[i] += sum_nums[0];
    if (sum_nums[i] >= 1000000)
      sum_nums[i] -= 1000000;
    if (sum_nums[i] == 0) {
      std::cout << i << std::endl;
      break;
    }
    for (j = i + 1; j <= N; j++) {
      sum_nums[j] += sum_nums[j - i];
      if (sum_nums[j] >= 1000000)
        sum_nums[j] -= 1000000;
    }
  }
  return 0;
}
