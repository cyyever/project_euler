/*
 *	程序名：euler108.c
 *	作者：陈源源
 *	日期：2015-04-20
 *	功能：解决eulerproject 108题(https://projecteuler.net/problem=108)
 */

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

#define N 20000
static struct { uint8_t is_prime; } * num_attrs;

static struct {
  uint64_t prime;
  uint64_t power;
} * prime_attrs;

static uint64_t prime_num;

static void distribute_prime_powers(uint64_t min_divisor_num);

int main(void) {
  uint64_t i, j;
  uint64_t n;

  num_attrs = calloc(N + 1, sizeof(*num_attrs));
  if (!num_attrs) {
    printf("calloc failed:%m\n");
    return -1;
  }

  //找出质数
  for (i = 2; i <= N; i++)
    num_attrs[i].is_prime = 1;
  prime_num = 0;
  for (i = 2; i <= N; i++) {
    if (num_attrs[i].is_prime) {
      prime_num++;
      for (j = i * 2; j <= N; j += i)
        num_attrs[j].is_prime = 0;
    }
  }

  //重新分配内存，保证都是质数
  prime_attrs = calloc(prime_num, sizeof(*prime_attrs));
  if (!prime_attrs) {
    printf("calloc failed:%m\n");
    free(num_attrs);
    return -1;
  }
  j = 0;
  for (i = 2; i <= N; i++) {
    if (num_attrs[i].is_prime) {
      prime_attrs[j].prime = i;
      prime_attrs[j].power = 0;
      j++;
    }
  }
  free(num_attrs);
  //对于每个n，他的不同解的数量*2-1就是它的平方的除数数量，因此这题的实质是找出平方的除数数量超过1000*2-1的最小数字
  //考虑到每个数字都能唯一地分解成质数的指数的乘积，我们可以用构造法来找到这个数字
  //以下我们用动态规划来处理
  distribute_prime_powers(1999);
  n = 1;
  for (i = 0; i < prime_num; i++) {
    if (prime_attrs[i].power == 0)
      break;
    for (j = 0; j < prime_attrs[i].power; j++)
      n *= prime_attrs[i].prime;
  }
  printf("%" PRIu64 "\n", n);
  free(prime_attrs);
  return 0;
}
/*
 *	功能：通过调整质数的指数分布找出平方的除数数量超过指定数量的最小数字
 *	参数：
 *		min_divisor_num：必须大于这个除数数量
 *	返回值：
 *		无
 */
static void distribute_prime_powers(uint64_t min_divisor_num) {
  uint64_t prime_power, next_prime_power;
  uint64_t new_prime_powr;
  uint64_t i, j, k, flag, max_prime_index;
  uint64_t tmp, tmp2;

  //如果质数有这个指数，能保证除数数量，但是我们必须进一步优化
  if ((min_divisor_num - 1) % 2 == 0)
    prime_attrs[0].power = (min_divisor_num - 1) / 2 + 1;
  else
    prime_attrs[0].power = (min_divisor_num - 1) / 2 + 2;
  //不断地平摊指数，逐步扩大质数范围，直到达到fixed point
  for (max_prime_index = 1;; max_prime_index++) {
    while (1) {
      flag = 0;
      for (j = max_prime_index; j >= 1; j--) {
        for (i = j - 1;; i--) {
          if (i == UINT64_MAX)
            break;
          prime_power = prime_attrs[i].power;
          if (prime_power == 1)
            continue;
          next_prime_power = prime_attrs[j].power;

          //为了使得数字最小，我们尝试分摊一些指数到后面的质数
          while (next_prime_power < prime_attrs[j - 1].power) {
            next_prime_power++;
            tmp = next_prime_power * 2 + 1;
            for (k = 0; k <= max_prime_index; k++) {
              if (k != i && k != j)
                tmp *= (prime_attrs[k].power * 2 + 1);
            }

            new_prime_powr = ((min_divisor_num + 1) / tmp - 1) / 2;
            while ((2 * new_prime_powr + 1) * tmp <= min_divisor_num)
              new_prime_powr++;
            if (i == j - 1) {
              if (new_prime_powr < next_prime_power) {
                next_prime_power--;
                break;
              }
            } else {
              if (new_prime_powr < prime_attrs[i + 1].power) {
                next_prime_power--;
                break;
              }
            }

            //如果min_prime的减少量超过next_min_prime的增量，那值得分摊指数
            tmp = 1;
            for (k = 0; k < prime_power - new_prime_powr; k++) {
              tmp *= prime_attrs[i].prime;
              if (tmp > prime_attrs[j].prime)
                break;
            }

            if (tmp < prime_attrs[j].prime) //没收益，达到了平衡点
            {
              next_prime_power--;
              break;
            }
            prime_power = new_prime_powr;
            flag = 1;
          }
          prime_attrs[j].power = next_prime_power;
          prime_attrs[i].power = prime_power;
        }
      }

      //处理自身的指数
      for (i = 0; i <= max_prime_index; i++) {
        if (prime_attrs[i].power == 0)
          break;
      }
      i--;
      while (i != UINT64_MAX) {
        prime_attrs[i].power--;
        tmp = 1;
        for (j = 0; j <= max_prime_index; j++)
          tmp *= (prime_attrs[j].power * 2 + 1);

        if (tmp <= min_divisor_num) {
          prime_attrs[i].power++;
          while (i > 1 && prime_attrs[i - 1].power == prime_attrs[i].power)
            i--;
        } else
          flag = 1;
        i--;
      }

      if (flag == 0) //如果没有变化，则已经达到fixed point
        break;
    }

    //尝试从多个指数平摊
    while (prime_attrs[max_prime_index].power <
           prime_attrs[max_prime_index - 1].power) {
      prime_attrs[max_prime_index].power++;
      tmp2 = 1;
      i = max_prime_index - 1;
      while (i != UINT64_MAX) {
        tmp = 1;
        for (j = 0; j <= max_prime_index; j++) {
          if (j != i)
            tmp *= (prime_attrs[j].power * 2 + 1);
        }
        while (prime_attrs[i].power > prime_attrs[max_prime_index].power &&
               tmp * (2 * (prime_attrs[i].power - 1) + 1) > min_divisor_num) {
          prime_attrs[i].power--;
          tmp2 *= prime_attrs[i].prime;
        }
        i--;
      }
      if (tmp2 < prime_attrs[max_prime_index].prime) {
        prime_attrs[max_prime_index].power--;
        for (i = 0; i < max_prime_index; i++) {
          if (tmp2 == 1)
            break;
          while (tmp2 % prime_attrs[i].prime == 0) {
            tmp2 /= prime_attrs[i].prime;
            prime_attrs[i].power++;
          }
        }
        break;
      }
    }
    if (prime_attrs[max_prime_index].power == 0)
      break;
  }
  return;
}
