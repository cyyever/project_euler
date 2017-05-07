/*
 *	程序名：euler74.cpp
 *	日期：2017-05-06
 *	功能：解决eulerproject 74题(https://projecteuler.net/problem=74)
 */

#include <algorithm>
#include <iostream>
#include <vector>

static std::vector<int> chain_len(1000000, -1);
static std::vector<uint64_t> factorials{1};

uint64_t get_sum_of_factorials(uint64_t n) {
  uint64_t sum = 0;
  while (n) {
    sum += factorials[n % 10];
    n /= 10;
  }
  return sum;
}

uint64_t get_chain_len(std::vector<uint64_t> &chain) {
  auto last_sum = chain.back();
  //如果已经算出来了
  if (chain_len[last_sum] >= 0) {
    auto last_chain_len = chain_len[last_sum];
    for (int j = chain.size() - 2, distance = 1; j >= 0; j--, distance++) {
      chain_len[chain[j]] = last_chain_len + distance;
    }
    return chain_len[chain[0]];
  }

  //检测是否有碰到重复数字
  auto next_sum = get_sum_of_factorials(chain.back());
  for (int j = chain.size() - 1, distance = 1; j >= 0; j--, distance++) {
    if (chain[j] == next_sum) {
      auto circle_chain_len = chain.size() - j;
      for (size_t k = j; k < chain.size(); k++) {
        chain_len[chain[k]] = circle_chain_len;
      }

      for (int i = j - 1, distance = 1; i >= 0; i--, distance++) {
        chain_len[chain[i]] = circle_chain_len + distance;
      }
      return chain_len[chain[0]];
    }
  }

  chain.push_back(next_sum);
  return get_chain_len(chain);
}

int main(void) {
  //初始化阶乘
  for (size_t i = 1; i <= 9; i++) {
    factorials.push_back(factorials.back() * i);
  }

  const size_t N = 1000000;
  size_t cnt = 0;
  for (size_t i = 1; i <= N; i++) {
    std::vector<uint64_t> chain{i};
    if (get_chain_len(chain) == 60) {
      cnt++;
    }
  }

  std::cout << cnt << std::endl;
  return 0;
}
