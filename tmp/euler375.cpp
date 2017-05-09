/*
 *	程序名：euler375.cpp
 *	日期：2017-05-09
 *	功能：解决eulerproject 375题(https://projecteuler.net/problem=375)
 */

#include <iostream>
#include <vector>
#include <utility>

int main() {
  uint64_t S=290797;
 //constexpr uint64_t N=2000000000;
  constexpr uint64_t N=10000;
  std::vector<std::pair<uint64_t,size_t>> mins;

  uint64_t sum=0;
  for(size_t i=1;i<=N;i++) {
    S=(S*S)%50515093;

    size_t cnt=1;

    while(!mins.empty() && mins.back().first>S) {
      cnt+= mins.back().second;
	  mins.pop_back();
    }

    mins.emplace_back(S,cnt);

    for(auto &min:mins) {
      sum+=min.first*min.second;
    }
  }

  std::cout <<sum << std::endl;
  return 0;
}
