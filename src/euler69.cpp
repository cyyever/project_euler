/*
 *	程序名：euler69.cpp
 *	日期：2017-05-04
 *	功能：解决eulerproject 69题(https://projecteuler.net/problem=69)
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {
  const size_t N = 1000000;
  std::vector<bool> is_prime(N + 1, true);
  std::vector<double> result(N + 1, 1.0);

  //参看https://en.wikipedia.org/wiki/Euler%27s_totient_function 获取函数公式

  for (size_t i = 2; i <= N; i++) {
    if (is_prime[i]) {
      for (size_t j = i; j <= N; j += i) {
        is_prime[j] = false;
        result[j] *= static_cast<double>(i) / (i - 1);
      }
    }
  }

  std::cout << std::distance(result.begin(),
                             std::max_element(result.begin(), result.end()))
            << std::endl;
  return 0;
}
