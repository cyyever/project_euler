/*
 *	程序名：euler45.c
 *	日期：2015-07-04
 *	功能：解决eulerproject 45题(https://projecteuler.net/problem=45)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>

int main() {
  uint64_t H_n, P_n, T_n, T_n_max, T_n_min;
  uint64_t H, P, T;

  H_n = 143;
  P_n = 165;
  H = 40755;
  P = 40755;

  //我们从285开始遍历
  while (true) {
    H_n++;
    //通过公式我们可以计算出增量
    H += 4 * (H_n)-3;
    while (P < H) {
      P_n++;
      //通过公式我们可以计算出增量
      P += 3 * P_n - 2;
    }
    if (P != H)
      continue;

    //使用二分查找
    T_n_min = P_n;
    T_n_max = P_n * 2;
    T = (T_n_max * (T_n_max + 1)) / 2;
    while (T < H) {
      T_n_max *= 2;
      T = (T_n_max * (T_n_max + 1)) / 2;
    }
    while (T_n_min <= T_n_max) {
      T_n = (T_n_min + T_n_max) / 2;
      T = (T_n * (T_n + 1)) / 2;
      if (T == H)
        break;
      else if (T < H)
        T_n_min = T_n + 1;
      else
        T_n_max = T_n - 1;
    }

    if (T == H)
      break;
  }
  printf("%" PRIu64 "\n", H);
  return 0;
}
