/*!
 * \file euler99.cpp
 *
 * \brief 解决eulerproject 99题(https://projecteuler.net/problem=99)
 */
#include <cinttypes>
#include <cmath>
#include <filesystem>
#include <fstream>
#include <iostream>

int main() {
  std::ifstream is(std::filesystem::path(DATA_DIR) / "p099_base_exp.txt");
  double max_result = -1;
  size_t line_num = 0;
  size_t cur_line_num = 0;

  while (true) {
    uint64_t base;
    is >> base;
    if (is.eof()) {
      break;
    }
    char sep;
    is >> sep;
    uint64_t exp;
    is >> exp;
    cur_line_num++;
    auto res = exp * log(base);
    if (res > max_result) {
      max_result = res;
      line_num = cur_line_num;
    }
  }

  std::cout << line_num << std::endl;
  return 0;
}
