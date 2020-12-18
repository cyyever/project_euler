/*
 *	程序名：euler9.c
 *	日期：2014-11-17
 *	功能：解决eulerproject 9题(https://projecteuler.net/problem=9)
 */

#include <cinttypes>
#include <cstdio>

size_t find_triangle_product(uint64_t perimeter);

int main() {
  printf("%zu\n", find_triangle_product(1000));
  return 0;
}

/*
 *	功能：获取指定周长下的第一个直角三角形的边的乘积
 *	参数：
 *		perimeter：周长
 *	返回值：
 *		0：没找到
 *		非0：边长的积
 */
size_t find_triangle_product(uint64_t perimeter) {
  uint64_t a, b, c, sum_b_c, a_square, distance_c_b;

  //我们对满足条件的所有直角三角形按照直角边的长度排序，从最短的直角边开始遍历，满足a<=b<=c，所以a+b+c=perimeter>=3a
  for (a = perimeter / 3; a >= 1; a--) {
    a_square = a * a;
    sum_b_c = perimeter - a;
    //(c-b)(c+b)=a*a
    // c-b=a_square/sum_b_c;
    // c+b=sum_b_c;
    // c=(a_square/sum_b_c+sum_b_c)/2
    // b=(sum_b_c-a_square/sum_b_c)/2

    if (a_square < sum_b_c)
      break;
    if (a_square % sum_b_c != 0)
      continue;
    distance_c_b = a_square / sum_b_c;
    b = sum_b_c - distance_c_b;
    if (b & 1)
      continue;
    b >>= 1;
    if (a > b)
      continue;
    c = (distance_c_b + sum_b_c) >> 1;
    return a * b * c;
  }
  return 0;
}
