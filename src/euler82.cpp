/*
 *	程序名：euler82.cpp
 *	日期：2015-04-27
 *	功能：解决eulerproject 82题(https://projecteuler.net/problem=82)
 */

#include <cinttypes>
#include <fstream>
#include <iostream>

using namespace std;

static uint64_t path_sum[80][80];
static uint64_t matrix[80][80];

static void find_min_path_sum(size_t matrix_row_num, size_t matrix_col_num);

int main() {
  size_t i, j;
  uint64_t min_path_sum;
  char sep;

  ifstream in_file("p082_matrix.txt");
  for (i = 0; i < 80; i++) {
    for (j = 0; j < 80; j++) {
      in_file >> matrix[i][j];
      if (j != 79)
        in_file >> sep;
    }
  }

  find_min_path_sum(80, 80);

  min_path_sum = path_sum[0][79];
  for (i = 1; i < 80; i++) {
    if (path_sum[i][79] < min_path_sum)
      min_path_sum = path_sum[i][79];
  }
  cout << min_path_sum << endl;
  return 0;
}

/*
 *	功能：获取指定矩阵下的到最右边列的每个元素的最小路径和
 *	参数：
 *		matrix_row_num：矩阵行数
 *		matrix_col_num：矩阵列数
 *	返回值：
 *		无
 *	注意：
 *		计算出来的最小路径和保存在path_sum
 */
static void find_min_path_sum(size_t matrix_row_num, size_t matrix_col_num) {
  size_t i, j, k;
  uint64_t min_path_sum, tmp;

  if (matrix_col_num == 1) {
    for (i = 0; i < matrix_row_num; i++)
      path_sum[i][0] = matrix[i][0];
    return;
  }
  find_min_path_sum(matrix_row_num, matrix_col_num - 1);

  for (i = 0; i < matrix_row_num; i++) {
    min_path_sum =
        path_sum[i][matrix_col_num - 2] + matrix[i][matrix_col_num - 1];
    //先计算上面下来的
    for (j = 0; j < i; j++) {
      tmp = path_sum[j][matrix_col_num - 2];
      for (k = j; k <= i; k++)
        tmp += matrix[k][matrix_col_num - 1];
      if (tmp < min_path_sum)
        min_path_sum = tmp;
    }
    //再计算下面上去的
    for (j = i + 1; j < matrix_row_num - 1; j++) {
      tmp = path_sum[j][matrix_col_num - 2];
      for (k = i; k <= j; k++)
        tmp += matrix[k][matrix_col_num - 1];
      if (tmp < min_path_sum)
        min_path_sum = tmp;
    }
    path_sum[i][matrix_col_num - 1] = min_path_sum;
  }
  return;
}
