/*
 *	程序名：euler25.cpp
 *	作者：陈源源
 *	日期：2014-11-17
 *	功能：解决eulerproject 25题(https://projecteuler.net/problem=25)
 */
#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main() {
  my_int a, b;
  uint64_t i;
  i = 2;
  a = 1;
  b = 1;
  while (1) {
    i++;
    a += b;
    if (a.digit_num() >= 1000)
      break;
    i++;
    b += a;
    if (b.digit_num() >= 1000)
      break;
  }
  cout << i << endl;
  return 0;
}
