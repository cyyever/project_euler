/*
 *	程序名：euler250.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 250题(https://projecteuler.net/problem=250)
 */

#include <algorithm>
#include <iostream>
#include <array>

/*
 *	功能：计算(base^power)%modulus
 * 	参数：
 *		base：底数
 *		power：指数
 *		modulus：模数，如果为0，则不取模
 * 	返回值：
 * 		乘方
 */
static uint64_t power(uint64_t base, uint64_t power, uint64_t modulus) {
  uint64_t res = 1;
  uint64_t tmp_base = base;

  while (power) {
    if (power & 1) {
      res *= tmp_base;
      if (modulus&& res >= modulus) {
        res %= modulus;
      }
    }
    power >>= 1;
    tmp_base *= tmp_base;
    if (modulus&& tmp_base >= modulus) {
      tmp_base %= modulus;
    }
  }
  return res;
}

int main(void) {
  std::array<uint64_t,251> sum{};

  uint64_t result_modulus=power(10,16,0);

  for (uint64_t i = 1; i <= 250250; i++) {
    auto res=power(i, i,250);
    if(res==0) {
      res=250;
    }

    auto next_sum=sum;

    for(size_t j=1;j<=250;j++) {
      auto k=j+res;
      if(k>250) {
	k-=250;
      }
      next_sum[k]=sum[j];
    }

    for(size_t j=1;j<=250;j++) {
      sum[j]+=next_sum[j];
      if(sum[j]>=result_modulus) {
	sum[j]%=result_modulus;
      }
    }
    sum[res]++;
  }

  std::cout <<sum[250]<< std::endl;
  return 0;
}
