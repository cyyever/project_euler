/*
 *	程序名：euler50.c
 *	日期：2015-07-18
 *	功能：解决eulerproject 50题(https://projecteuler.net/problem=50)
 */

#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

int main() {
  size_t i, j;
  size_t max_length, max_length_prime;
  size_t tmp_length, tmp_prime;

  std::vector<bool> primes(1000000, true);
  for (i = 2; i <= primes.size(); i++) {
    if (primes[i]) {
      for (j = i * 2; j <= primes.size(); j += i)
        primes[j] = false;
    }
  }

  max_length = 2;
  max_length_prime = 5;
  //遍历质数
  for (i = 2; i <= 999999; i++) {
    if (!primes[i])
      continue;
    tmp_length = 1;
    tmp_prime = i;
    for (j = i + 1; j <= 999999; j++) {
      if (primes[j]) {
        tmp_length++;
        tmp_prime += j;
        if (tmp_prime > 999999)
          break;
        if (primes[tmp_prime] && tmp_length > max_length) {
          max_length = tmp_length;
          max_length_prime = tmp_prime;
        }
      }
    }
  }
  printf("%zu\n", max_length_prime);
  return 0;
}
