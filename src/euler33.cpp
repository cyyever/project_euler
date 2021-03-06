/*
 *	程序名：euler33.cpp
 *	日期：2015-07-17
 *	功能：解决eulerproject 33题(https://projecteuler.net/problem=33)
 */

#include <iostream>

#include <cyy/math/rational.hpp>

using namespace std;

int main() {
  int p, q, a, b, c, d;
  cyy::math::rational res(1, 1);

  for (p = 11, a = 1, b = 1; p <= 98; p++, b++) {
    if (p % 10 == 0) {
      a++;
      b = 0;
      continue;
    }
    for (q = p + 1, c = a, d = b + 1; q <= 99; q++, d++) {
      if (q % 10 == 0) {
        c++;
        d = 0;
        continue;
      }
      // p/q=b/d
      if (a == c) {
        if (p * d == b * q)
          res *= cyy::math::rational(b, d);
      }
      // p/q=b/c
      else if (a == d) {
        if (p * c == b * q)
          res *= cyy::math::rational(b, c);
      }
      // p/q=a/d
      else if (b == c) {
        if (p * d == a * q)
          res *= cyy::math::rational(a, d);
      }
      // p/q=a/c
      else if (b == d) {
        if (p * c == a * q)
          res *= cyy::math::rational(a, c);
      }
    }
  }

  cout << res.simplify().denominator() << endl;
  return 0;
}
