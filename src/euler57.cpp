/*
 *	��������euler57.cpp
 *	���ߣ���ԴԴ
 *	���ڣ�2014-11-19
 *	���ܣ����eulerproject 57��(https://projecteuler.net/problem=57)
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
    //�� 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
    //���ǵ�������һ��ֵ
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
