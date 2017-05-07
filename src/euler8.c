/*
 *	程序名：euler8.c
 *	日期：2014-11-18
 *	功能：解决eulerproject 8题(https://projecteuler.net/problem=8)
 */
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  uint32_t cur_run_begin, cur_run_next_digit, next_run_begin;
  uint64_t cur_cmp_product, next_cmp_product;
  size_t i, distance;
  unsigned char n[] = "73167176531330624919225119674426574742355349194934"
                      "96983520312774506326239578318016984801869478851843"
                      "85861560789112949495459501737958331952853208805511"
                      "12540698747158523863050715693290963295227443043557"
                      "66896648950445244523161731856403098711121722383113"
                      "62229893423380308135336276614282806444486645238749"
                      "30358907296290491560440772390713810515859307960866"
                      "70172427121883998797908792274921901699720888093776"
                      "65727333001053367881220235421809751254540594752243"
                      "52584907711670556013604839586446706324415722155397"
                      "53697817977846174064955149290862569321978468622482"
                      "83972241375657056057490261407972968652414535100474"
                      "82166370484403199890008895243450658541227588666881"
                      "16427171479924442928230863465674813919123162824586"
                      "17866458359124566529476545682848912883142607690042"
                      "24219022671055626321111109370544217506941658960408"
                      "07198403850962455444362981230987879927244284909188"
                      "84580156166097919133875499200524063689912560717606"
                      "05886116467109405077541002256983155200055935729725"
                      "71636269561882670428252483600823257530420752963450";

#define RUN_LEN 13
#define DIGIT_NUM (sizeof(n) - 1)

  //先把字符转换成数字
  for (i = 0; i < DIGIT_NUM; i++)
    n[i] -= '0';
  //起始游程
  cur_run_begin = 0;
  cur_run_next_digit = cur_run_begin;
  cur_cmp_product = 1;
  //下一个待比较的游程
  next_run_begin = cur_run_begin + 1;
  next_cmp_product = 1;
  while (next_run_begin <= DIGIT_NUM - RUN_LEN) {
    // next run新进来的digit是0，肯定比不过当前run，进行滑动
    if (n[next_run_begin + RUN_LEN - 1] == 0) {
      next_run_begin = next_run_begin + RUN_LEN;
      //检查新游程是否包含0
      while (next_run_begin <= DIGIT_NUM - RUN_LEN &&
             memchr(n + next_run_begin, 0, RUN_LEN))
        next_run_begin = next_run_begin + RUN_LEN;
      if (next_run_begin > DIGIT_NUM - RUN_LEN)
        break;

      //滑动时破坏了之前维护的cur_cmp_product以及next_cmp_product的关系，强制重新计算
      next_cmp_product = n[next_run_begin];
      for (i = next_run_begin + 1; i < next_run_begin + RUN_LEN; i++)
        next_cmp_product *= n[i];
      for (; cur_run_next_digit < cur_run_begin + RUN_LEN; cur_run_next_digit++)
        cur_cmp_product *= n[cur_run_next_digit];
    } else {
      //计算新游程和当前游程的距离
      distance = next_run_begin - cur_run_begin;
      if (distance <= RUN_LEN) //两个游程有共用的数字
      {
        next_cmp_product *= n[next_run_begin + RUN_LEN - 1];
        cur_cmp_product *= n[cur_run_next_digit];
        cur_run_next_digit++;
      } else
        next_cmp_product = next_cmp_product * n[next_run_begin + RUN_LEN - 1] /
                           n[next_run_begin - 1];
    }

    if (next_cmp_product > cur_cmp_product) {
      cur_run_begin = next_run_begin;
      cur_run_next_digit = cur_run_begin;
      cur_cmp_product = 1;
      next_cmp_product = 1;
    }
    next_run_begin++;
  }
  for (; cur_run_next_digit < cur_run_begin + RUN_LEN; cur_run_next_digit++)
    cur_cmp_product *= n[cur_run_next_digit];
  printf("%" PRIu64 "\n", cur_cmp_product);
  return 0;
}
