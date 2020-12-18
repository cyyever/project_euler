/*
 *	程序名：euler36.c
 *	日期：2014-11-20
 *	功能：解决eulerproject 36题(https://projecteuler.net/problem=36)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <vector>

static uint64_t get_next_binary_palindromic_num();
static uint8_t is_palindromic(uint64_t num);

int main() {
  uint64_t n, sum;

  sum = 0;
  while (true) {
    n = get_next_binary_palindromic_num();
    if (n >= 1000000)
      break;
    if (is_palindromic(n))
      sum += n;
  }

  printf("%" PRIu64 "\n", sum);
  return 0;
}

/*
 *	功能：返回下一个二进制回文
 *	参数：
 *		无
 *	返回值：
 *		二进制回文
 */
static uint64_t get_next_binary_palindromic_num() {
  static std::vector<uint64_t> palindromic_array[2]; //奇数位数和偶数位数的回文
  static uint64_t palindromic_array_len[2];
  static uint64_t palindromic_digit_num = 1;
  static uint64_t i;
  uint64_t j;

  j = palindromic_digit_num & 1;

  if (palindromic_array[j].empty()) {
    palindromic_array_len[j] = 2;
    palindromic_array[j].resize(palindromic_array_len[j]);
    i = 0;
    palindromic_array[j][0] = 0;
    if (j == 1)
      palindromic_array[j][1] = 1; // 1位的回文是 0 1
    else
      palindromic_array[j][1] = 3; // 2位的回文是 00 11
  }

  if (i < palindromic_array_len[j]) {
    //跳过以0起始和结尾都回文，这个只用于内部构造下一级回文
    while ((palindromic_array[j][i] & 1) == 0)
      i++;
    return palindromic_array[j][i++];
  }

  //奇数或偶数组回文遍历完毕，构造下下组回文
  palindromic_array[j].resize(palindromic_array_len[j] * 2);
  //先构造 1回文1
  for (i = palindromic_array_len[j]; i < palindromic_array_len[j] * 2; i++) {
    palindromic_array[j][i] = palindromic_array[j][i - palindromic_array_len[j]]
                              << 1;
    palindromic_array[j][i] |= 1;
    palindromic_array[j][i] |= (1 << (palindromic_digit_num + 1));
  }
  //再构造 0回文0
  for (i = 0; i < palindromic_array_len[j]; i++)
    palindromic_array[j][i] <<= 1;
  palindromic_array_len[j] *= 2;

  //切换到下一组回文
  palindromic_digit_num++;
  i = 0;
  return get_next_binary_palindromic_num();
}

/*
 *	功能：判断指定数字是否是回文
 *	参数：
 *		num：要判断的数字
 *	返回值：
 *		1：回文
 *		0：不是回文
 */
uint8_t is_palindromic(uint64_t num) {
  static uint64_t base[10];
  uint64_t i, first_digit, last_digit, base_end;

  if (base[0] == 0) {
    base[0] = 1;
    for (i = 1; i < 10; i++)
      base[i] = base[i - 1] * 10;
  }

  if (num % 10 == 0)
    return 0;

  base_end = 0;
  for (i = 0; i < 10; i++) {
    if (base[i] <= num && base[i + 1] > num) {
      base_end = i;
      break;
    }
  }

  while (num) {
    last_digit = num / base[base_end];
    first_digit = num % 10;
    if (first_digit != last_digit)
      return 0;
    num = num % base[base_end];
    num = num / 10;
    base_end -= 2;
  }
  return 1;
}
