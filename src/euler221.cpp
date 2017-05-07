/*
 *	程序名：euler221.cpp
 *	日期：2016-03-13
 *	功能：解决eulerproject 221题(https://projecteuler.net/problem=221)
 */

#include <cstdint>
#include <iostream>
#include <vector>

std::vector<uint64_t> get_p_module(uint64_t a);
int main() {
  //假设abs(p)<=abs(q)<=abs(r)，否则可以重新排列因子满足此要求
  //令n为{p,q,r}中正数的数量
  //如果n=0或者2，则A为负数，矛盾
  //如果n=3，则1/p+1/q+1/r的分子肯定不能为1，矛盾
  //所以n=1
  //那么p必须是正数，否则1/A为负数
  //那么我们令q=-(p+a),则r=(p*q-1)/a=-(p^2+1)/a-p

  /*
  std::map<uint64_t,std::vector<uint64_t>> p_module;
  std::map<uint64_t,uint64_t> p_factor;
  std::map<uint64_t,uint64_t> p;

  uint64_t next_a=1;
  */

  for (uint64_t a = 1; a <= 150; a++) {
    std::cout << "a= " << a << " size=" << get_p_module(a).size() << std::endl;
  }

  return -1;
}

// 获取能满足(p^2+1) mod a = 0的p的模
std::vector<uint64_t> get_p_module(uint64_t a) {
  std::vector<uint64_t> res;
  for (uint64_t i = 0; i < a; i++) {
    if ((i * i + 1) % a == 0) {
      res.push_back(i);
    }
  }
  return res;
}
