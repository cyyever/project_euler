/*
 *	程序名：euler100.cpp
 *	日期：2017-05-10
 *	功能：解决eulerproject 100题(https://projecteuler.net/problem=100)
 */

#include <algorithm>
#include <iostream>
#include <utility>

#include <cyy/math/all.hpp>

static cyy::math::integer find_blue(const cyy::math::integer &total_number) {
  // find the smallest blue such that 2*blue*(blue-1)>=total(total_number-1)

  cyy::math::integer lower = 1;
  cyy::math::integer upper = total_number;
  cyy::math::integer limit = total_number * (total_number - 1);
  while (lower <= upper) {
    auto mid = (lower + upper) / 2;
    auto res = (mid * (mid - 1) * 2) <=> limit;
    if (res == std::strong_ordering::equal) {
      return mid;
    }
    if (res == std::strong_ordering::less) {
      lower = mid + 1;
    } else {
      upper = mid - 1;
    }
  }
  assert(lower * 2 * (lower - 1) > limit);
  --lower;
  assert(lower * 2 * (lower - 1) < limit);
  return lower;
}
/* static std::pair<uint64_t, cyy::math::integer> */
/* increase_blue(uint64_t blue, cyy::math::integer error) { */
/*   assert(error)>0; */
/*   cyy::math::rational =error /= 2; */
/*   cyy::math::integer B = blue * 2 - 1; */
/*   while(lower<=upper) { */
/*     auto mid=(lower+upper)/2; */

/*     if(mid) */
/*     if(lower<=up) */
/*   } */

/*   auto C = -std::move(error); */

/*   return {}; */
/* } */

int main() {
  uint64_t n = 1000000000000;

  auto blue = find_blue(n);
  auto total = cyy::math::integer(n) * (n - 1);
  auto lower = cyy::math::integer(blue) * ((blue - 1) * 2);

  assert((total - lower) >= 0);
  // we need to adjust lower
  while (true) {
    auto res = (total - lower);
    std::cout << "res=" << res.to_string() << std::endl;
    if (res > 0) {
      lower += blue * 4;
      blue++;
    } else if (res == 0) {
      std::cout << blue << std::endl;
      return 0;
    } else {
      total += n * 2;
      n++;
    }
  }
  return 0;
}
