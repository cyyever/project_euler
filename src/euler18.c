/*
 *	程序名：euler18.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 18题(https://projecteuler.net/problem=18)
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define N 15
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(void) {
  uint64_t triangle[N][N] = {
      {75},
      {95, 64},
      {17, 47, 82},
      {18, 35, 87, 10},
      {20, 4, 82, 47, 65},
      {19, 1, 23, 75, 3, 34},
      {88, 2, 77, 73, 7, 63, 67},
      {99, 65, 4, 28, 6, 16, 70, 92},
      {41, 41, 26, 56, 83, 40, 80, 70, 33},
      {41, 48, 72, 33, 47, 32, 37, 16, 94, 29},
      {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14},
      {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57},
      {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48},
      {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31},
      {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}};
  uint64_t i, j;
  uint64_t max_total;

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
