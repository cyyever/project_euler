/*
 *	程序名：euler190.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 190题(https://projecteuler.net/problem=190)
 */

#include <algorithm>
#include <cyy/math/rational.hpp>
#include <cyy/math/all.hpp>
#include <iostream>
#include <utility>


int main(void) {
  constexpr size_t max_m = 15;
  cyy::math::rational cof[max_m + 1];

  cof[1] =cyy::math::rational (1, 1);

  cyy::math::integer sum;
  for (size_t i = 2; i <= max_m; i++) {

    //令x[1]+..+x[i] = y
    //那麼max(Pi)=max(cof[i-1](y-x[i])*x[i]^i)
    //取導數爲 ix[i]^(i-1)*cof[i-1](y-x[i])-derivative(cof[i-1])(y-x[i])*x[i]^i
    //令其爲0，簡化得
    // i*cof[i-1](y-x[i])=derivative(cof[i-1])(y-x[i])*x[i]
    // x[i]/i=(cof[i-1]/derivative(cof[i-1]))(y-x[i])
    // x[i]/i=(y-x[i])/(i*(i-1)/2)
    // x[i]=2(y-x[i])/(i-1)
    // x[i](i-1)=2y-2x[i]
    // x[i]*(i+1)=2y
    // x[i]=2y/(i+1)
    // Pi=cof[i-1](y-x[i])*x[i]^i
    // Pi=cof[i-1]((i-1)/(i+1)y)*2^i*y^i/((i+1)^i)

    cof[i] =
        cyy::math::rational(cyy::math::exponent(i - 1, (i - 1) * i / 2),cyy::math::exponent(i + 1, (i - 1) * i / 2)) *
        cof[i - 1] *cyy::math::rational(cyy::math::integer(1ULL << i),cyy::math::exponent(i + 1, i));
    auto P =
        cof[i].numerator() *cyy::math::exponent(i, (i + 1) * i / 2) / cof[i].denominator();
    sum += P;
  }
  std::cout << sum << std::endl;
  return 0;
}
