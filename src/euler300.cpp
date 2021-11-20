/*!
 * \file euler303.cpp
 *
 * \brief https://projecteuler.net/problem=303
 */

#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>

#include <cyy/math/all.hpp>

#include "dynamic_programming.hpp"

int main() {
  constexpr uint64_t n = 1000000000;
  constexpr uint64_t modulo = 77777777;
  std::vector<uint64_t> A;
  std::vector<int64_t> B;
  A.resize(n + 1);
  B.resize(n + 1);
  A[0] = 1;
  B[0] = -1;

  uint64_t factorial = 1;
  std::vector<uint64_t> binomial_coefficients;
  uint64_t B_constant = 1;

  for (uint64_t i = 1; i <= n; i++) {
    factorial *= i;
    factorial %= modulo;
    cyy::euler::get_binomial_coefficients(i,binomial_coefficients, modulo);
    A[i] = 0;
    B[i] = 0;
    for (uint64_t j = 0; j < i; j++) {
      A[i] += A[j] * binomial_coefficients[j];
      B[i] += B[j] * binomial_coefficients[j];
    }
    A[i] += factorial;
    B_constant = (i * B_constant + 1) % modulo;
    /* std::cout << "A="<<A[i] << std::endl; */
    B[i] -= B_constant;
    std::cout << "i="<<i << std::endl;
  }
  std::cout << A.back() << std::endl;
  std::cout << B.back() << std::endl;
}
