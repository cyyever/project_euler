/*
 *	程序名：euler44.c
 *	作者：陈源源
 *	日期：2015-07-12
 *	功能：解决eulerproject 44题(https://projecteuler.net/problem=44)
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  uint64_t i, j, P_i, P_j;
  uint64_t k, last_k, P_k;
  uint64_t min_l, max_l, avg_l, P_avg_l;
  uint64_t d;

  d = UINT64_MAX;
  last_k = 3;
  k = 3;
  for (i = 1, P_i = i * (3 * i - 1) / 2; i < d; P_i += 3 * i + 1, i++) {
    for (j = i + 1, P_j = j * (3 * j - 1) / 2;; P_j += 3 * j + 1, j++) {
      if (j == i + 1)
        k = last_k;
      for (P_k = k * (3 * k - 1) / 2;; P_k += 3 * k + 1, k++) {
        if (P_k >= P_i + P_j)
          break;
      }

      if (j == i + 1)
        last_k = k;

      if (P_k > P_i + P_j) {
        if (k == j + 1)
          break;
      } else {
        // k-j=i
        min_l = k + 1;
        max_l = j + k - 1;
        while (min_l <= max_l) {
          avg_l = (min_l + max_l) / 2;
          P_avg_l = avg_l * (3 * avg_l - 1) / 2;
          if (P_avg_l == P_j + P_k) {
            d = i;
            goto end;
          } else if (P_avg_l > P_j + P_k)
            max_l = avg_l - 1;
          else
            min_l = avg_l + 1;
        }

        if (d <= j)
          continue;
        // k-i=j
        min_l = k + 1;
        max_l = i + k - 1;
        while (min_l <= max_l) {
          avg_l = (min_l + max_l) / 2;
          P_avg_l = avg_l * (3 * avg_l - 1) / 2;
          if (P_avg_l == P_i + P_k) {
            d = j;
            break;
          } else if (P_avg_l > P_i + P_k)
            max_l = avg_l - 1;
          else
            min_l = avg_l + 1;
        }
        if (d == j)
          break;
      }
    }
  }
end:
  printf("%" PRIu64 "\n", d * (3 * d - 1) / 2);
  return 0;
}
