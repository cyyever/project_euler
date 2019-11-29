/*
 *	程序名：euler67.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 67题(https://projecteuler.net/problem=67)
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#define N 100
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
  FILE *p67;
  char buf[32];
  uint64_t triangle[N][N];
  uint64_t i, j;
  uint64_t max_total;

  p67 = fopen(DATA_DIR "/p067_triangle.txt", "r");
  if (!p67) {
    printf("fopen failed:%m");
    return -1;
  }

  for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
      if (fscanf(p67, "%s", buf) != 1) {
        printf("fscanf failed:%m");
        return -1;
      }
      triangle[i][j] = strtoull(buf, NULL, 10);
    }
  }

  //这典型的用动态规划来做，我们从三角的顶端向下遍历，每一层更新成到该位置的最大长度
  for (i = 1; i < N; i++) {
    triangle[i][0] += triangle[i - 1][0];
    triangle[i][i] += triangle[i - 1][i - 1];
    for (j = 1; j < i; j++)
      triangle[i][j] += MAX(triangle[i - 1][j - 1], triangle[i - 1][j]);
  }

  //获取最底层的最大值
  max_total = 0;
  for (i = 0; i < N; i++) {
    if (triangle[N - 1][i] > max_total)
      max_total = triangle[N - 1][i];
  }
  printf("%" PRIu64 "\n", max_total);
  return 0;
}
