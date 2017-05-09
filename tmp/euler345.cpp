/*
 *	程序名：euler345.cpp
 *	日期：2017-05-06
 *	功能：解决eulerproject 345题(https://projecteuler.net/problem=345)
 */

#include <algorithm>
#include <iostream>
#include <vector>

int main(void) {

constexpr size_t rows=5;
constexpr size_t cols=5;

uint64_t matrix[rows][cols]={
  { 7,53,183,439,863 },
  { 497,383,563,79,973},
  { 287,63,343,169,583},
  { 627,343,773,959,943},
  { 767,473,103,699,303}
};

uint64_t max_sum=0;
uint64_t sum=0;

std::vector<size_t>  col_idxs{0};

  while(true) {
    size_t row_idx=col_idxs.size()-1;
    sum+=matrix[row_idx][col_idxs.back()];
    if(row_idx==rows-1) {
      if(sum>max_sum) {
	max_sum=sum;
      }
    }



  }

  return 0;
}
