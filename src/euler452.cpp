/*!
 * \file euler452.cpp
 *
 * \brief  解决eulerproject 452题(https://projecteuler.net/problem=452)
 * \author cyy
 * \date 2017-12-02
 */

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <map>
#include <vector>

constexpr size_t M = 1000000000;
constexpr size_t N = 1000000000;

/*
constexpr size_t M = 10;
constexpr size_t N = 10;
*/

uint64_t get_C_mod_N(uint64_t a, uint64_t b);
static std::vector<uint64_t> is_prime(M + 1, {});

int main(void) {

  std::vector<uint64_t> F(M + 1, 1);

  for (size_t m = 2; m <= M; m++) {
    is_prime[m] = 1;
  }

  for (size_t m = 2; m <= M; m++) {
    if (!is_prime[m]) {
      continue;
    }

    for (size_t i = m + m; i <= M; i += m) {
      is_prime[i] = false;
    }
  }

  for (size_t m = 2; m <= M; m++) {
    if (!is_prime[m]) {
      continue;
    }

    F[m] = N;

    for (size_t i = m + m; i <= M; i += m) {
      uint64_t power = 0;
      auto tmp = i;
      is_prime[i] = false;
      while (tmp % m == 0) {
        power++;
        tmp /= m;
      }
      assert(power <= i);
      F[i] *= get_C_mod_N(power + N - 1,power);
      if (F[i] >= 1234567891) {
        F[i] %= 1234567891;
      }
    }
  }

  uint64_t sum = 0;
  for (size_t i = 1; i <= M; i++) {
  //  std::cout<<"F["<<i<<"]="<<F[i]<<std::endl;
    sum += F[i];
    if (sum >= 1234567891) {
      sum -= 1234567891;
    }
  }

  std::cout << sum << std::endl;
  return 0;
}

// \brief  計算C(a,b) mod N
uint64_t get_C_mod_N(uint64_t a, uint64_t b) {
  static std::map<std::pair<size_t, size_t>, uint64_t> c_map;
  static std::vector<uint64_t> numerator;

  assert(a>=b);
  if(b==0) {
    return 1;
  } else if(b==1) {
    return a;
  }
  assert(a>=b);

  auto &res = c_map[{a, b}];
  if (res != 0) {
    return res;
  }

  numerator.resize(b);

  for (size_t i = 0; i < b; i++) {
    numerator[i] = a-b+i+1;
  }

  for (size_t i = 2; i <= b; i++) {
    if (!is_prime[i]) {
      continue;
    }
    size_t power_cnt = 0;
    auto tmp = i;
    while (tmp <= b) {
      power_cnt += b / tmp;
      tmp *= i;
    }
    auto idx = (i - (a-b+1) % i);
    if (idx == i) {
      idx -= i;
    }
    //assert(numerator[idx] % i == 0);
    /*
    std::cout<<"b="<<b<<" idx="<<idx<<std::endl;
    std::cout<<"power_cnt="<<power_cnt<<std::endl;
    std::cout<<"a="<<a<<std::endl;
    std::cout<<"i="<<i<<std::endl;
    std::cout<<"numerator[0]="<<numerator[0]<<std::endl;
    */
    assert(idx<b);
    while (power_cnt > 0) {
     // std::cout<<"numerator[idx]="<<numerator[idx]<<std::endl;
      assert(idx<b);
      while (numerator[idx] % i == 0) {
        numerator[idx] /= i;
        power_cnt--;
	if(power_cnt==0) {
	  break;
	}
      }
      idx += i;
      //std::cout<<"b="<<b<<" idx="<<idx<<std::endl;
    }
  }

  uint64_t product = 1;
  for (size_t i = 0; i < b; i++) {
    product *= numerator[i];
    if (product >= 1234567891) {
      product %= 1234567891;
    }
  }

  res = product;
  return res;
}
