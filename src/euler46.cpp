/*
 *	程序名：euler46.c
 *	日期：2014-11-20
 *	功能：解决eulerproject 46题(https://projecteuler.net/problem=46)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define N 10000

int main() {
  size_t i, j, double_square_num;
  uint8_t flag;

  std::vector<bool> primes(N + 1, true);

  std::vector<uint64_t> double_squares(N);

  double_squares[0] = 2;
  double_square_num = 1;

  //遍历数字
  for (i = 2; i <= N; i++) {
    if (!primes[i] && (i & 1) == 1) {
      flag = 0;
      for (j = 0; j < double_square_num; j++) {

        if (double_squares[j] > i)
          break;
        if (primes[i - double_squares[j]]) {
          flag = 1;
          break;
        }
      }
      if (flag == 0) {
        printf("%zu\n", i);
        return 0;
      }
    }

    double_squares[double_square_num++] = i * i * 2;
    if (primes[i]) {
      for (j = i * 2; j <= N; j += i)
        primes[j] = false;
    }
  }

  return 0;
}
