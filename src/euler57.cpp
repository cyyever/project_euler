/*
 *	程序名：euler57.cpp
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 57题(https://projecteuler.net/problem=57)
 */
#include <iostream>

#include <cyy/math/all.hpp>

using namespace std;

int main() {
  cyy::math::rational root;
  size_t i, count;

  // 1 + 1/2 = 3/2
  root = cyy::math::rational(3, 2);
  count = 0;
  for (i = 2; i <= 1000; i++) {
    //√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
    //我们迭代到下一个值
    root += 1;
    root = root.reciprocal();
    root += 1;

    if (root.numerator().to_string().size() >
        root.denominator().to_string().size())
      count++;
  }

  cout << count << endl;
  return 0;
}
