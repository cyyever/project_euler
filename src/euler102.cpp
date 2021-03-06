/*!
 * \file euler102.cpp
 *
 * \brief 解决eulerproject 3题(https://projecteuler.net/problem=102)
 */

#include <cassert>
#include <cinttypes>
#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  std::ifstream is(std::filesystem::path(DATA_DIR) / "p102_triangles.txt");
  size_t cnt = 0;
  int64_t x1, x2, x3;
  int64_t y1, y2, y3;
  while (true) {
    char c;
    is >> x1 >> c >> y1 >> c >> x2 >> c >> y2 >> c >> x3 >> c >> y3;
    if (is.eof()) {
      break;
    }

    auto A31 = x2 * y3 - y2 * x3;
    auto A32 = x3 * y1 - y3 * x1;
    auto A33 = x1 * y2 - y1 * x2;
    if (A31 * (A32 + A33) >= 0 && A32 * (A31 + A33) >= 0 &&
        A33 * (A31 + A32) >= 0) {
      cnt++;
    }
  }
  std::cout << cnt << std::endl;
  return 0;
}
