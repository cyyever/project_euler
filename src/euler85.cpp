/*
 *	程序名：euler85.cpp
 *	日期：2017-05-27
 *	功能：解决eulerproject 85题(https://projecteuler.net/problem=85)
 */

#include <algorithm>
#include <array>
#include <iostream>

int main() {
  //如果网格的长,宽是a,b那么矩阵数量是(a+1)*a/2*(b+1)*b/2
  const size_t N = 2000000;
  size_t min_abs = N;
  size_t area = 0;

  for (size_t i = 1; i <= 3000; i++) {
    auto tmp = i * (i + 1) / 2;
    for (size_t j = 1; j <= 3000; j++) {
      auto num = tmp * (j + 1) * j / 2;
      size_t distance = num > N ? (num - N) : (N - num);

      if (distance < min_abs) {
        min_abs = distance;
        area = i * j;
      }
      if (num > N) {
        break;
      }
    }
  }
  std::cout << area << std::endl;
  return 0;
}
