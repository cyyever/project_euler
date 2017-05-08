/*
 *	程序名：euler429.cpp
 *	日期：2017-05-08
 *	功能：解决eulerproject 429题(https://projecteuler.net/problem=429)
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <vector>

/*
 *	功能：计算(base^power)%modulus
 * 	参数：
 *		base：底数
 *		power：指数
 *		modulus：模数
 * 	返回值：
 * 		乘方
 */
static uint64_t power(uint64_t base, uint64_t power,uint64_t modulus) {
  uint64_t res = 1;
  uint64_t tmp_base = base;

  while (power) {
    if (power & 1) {
      res *= tmp_base;
      if(res>=modulus) {
	res%=modulus;
      }
    }
    power >>= 1;
    tmp_base *= tmp_base;
    if(tmp_base>=modulus) {
      tmp_base%=modulus;
    }
  }
  return res;
}

int main(void) {
 //constexpr uint64_t N = 4;
 constexpr uint64_t modulus = 1000000009;
  //constexpr uint64_t N = 100000000;
  constexpr uint64_t N = 100000;


  std::vector<bool> is_prime(N + 1, true);

  std::vector<uint64_t> prime_factors;
  std::list<std::pair<uint64_t,size_t>> products;


  for (uint64_t i = 2; i <= N; i++) {
    if (!is_prime[i]) {
      continue;
    }

    for (uint64_t j = i + i; j <= N; j += i) {
      is_prime[j] = false;
    }
    uint64_t cnt=0;
    uint64_t a = N;
    while (a) {
      a/=i;
      cnt +=a;
    }
    prime_factors.push_back(power(i,cnt*2,modulus));
  }

  /*
  for(auto &factor:prime_factors) {
    std::cout <<"prime factor"<<factor<< std::endl;
  }
  */

  //生成所有质数的乘积
  uint64_t sum=1; 
  for(size_t i=0;i<prime_factors.size();i++) {
    products.emplace_back(std::make_pair(prime_factors[i],i));
  }

  //这边可以进一步优化
  while(!products.empty()) {
    auto product=products.front();
    products.pop_front();
    sum+=product.first;
    if(sum>=modulus) {
      sum-=modulus;
    }

    for (size_t i=product.second+1; i<prime_factors.size();i++) {
      auto new_product=product;
      new_product.first*=prime_factors[i];
      if(new_product.first>=modulus) {
	new_product.first%=modulus;
      }
      new_product.second=i;
      products.push_back(new_product);
    }
  }


    std::cout <<sum<< std::endl;
  return 0;
}
