/*
 *	程序名：euler125.cpp
 *	日期：2017-05-07
 *	功能：解决eulerproject 125题(https://projecteuler.net/problem=125)
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <set>

bool is_palindromic(uint64_t a) {
  if (a < 10) {
    return true;
  }
  size_t limit = 10;
  while (true) {
    size_t next_limit = limit * 10;
    if (next_limit <= a) {
      limit = next_limit;
    } else {
      break;
    }
  }
  while (a) {
    if (a % 10 != a / limit) {
      return false;
    }
    a %= limit;
    a /= 10;
    limit /= 100;
  }
  return true;
}

int main() {
  std::list<uint64_t> sequences{1};

  uint64_t i = 2;
  size_t sum = 0;
  std::set<uint64_t> numbers;
  while (true) {
    auto square = i * i;
    i++;

    for (auto &seq : sequences) {
      seq += square;
    }
    while (!sequences.empty()) {
      if (sequences.front() >= 100000000) {
        sequences.pop_front();
      } else {
        break;
      }
    }

    if (sequences.empty()) {
      break;
    }

    for (auto &seq : sequences) {
      if (is_palindromic(seq)) {
        //由于3^2+4^2=5^2 可能有两个序列找到同一个数
        numbers.insert(seq);
      }
    }

    sequences.push_back(square);
  }

  for (auto &num : numbers) {
    sum += num;
  }
  std::cout << sum << std::endl;
  return 0;
}
