/*
 *	程序名：euler28.c
 *	日期：2015-04-12
 *	功能：解决eulerproject 28题(https://projecteuler.net/problem=28)
 */
#include <cinttypes>
#include <cstdio>

static uint64_t get_spiral_diagonal_sum(uint64_t edge_len);

int main() {
  printf("%" PRIu64 "\n", get_spiral_diagonal_sum(1001));
  return 0;
}

/*
 *	功能：获取指定螺旋线的边的对角线的数字和
 *	参数：
 *		edge_len：边长
 *	返回值：
 *		对角线数字和
 */
static uint64_t get_spiral_diagonal_sum(uint64_t edge_len) {
  if (edge_len == 1)
    return 1;
  else
    return get_spiral_diagonal_sum(edge_len - 2) +
           ((edge_len - 2) * (edge_len - 2) + edge_len - 1) * 4 +
           6 * (edge_len - 1);
}
