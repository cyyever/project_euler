/*
 *	��������euler47.c
 *	���ߣ���ԴԴ
 *	���ڣ�2014-11-19
 *	���ܣ����eulerproject 47��(https://projecteuler.net/problem=47)
 */
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000000

typedef struct {
  uint8_t is_prime;
  uint64_t prime_num;
} num_attr;

int main(void) {
  num_attr *num_attrs;
  uint64_t i, j;

  num_attrs = calloc(N + 1, sizeof(num_attr));
  if (!num_attrs) {
    printf("malloc failed:%m\n");
    return -1;
  }

  //��ʶ����
  for (i = 2; i <= N; i++)
    num_attrs[i].is_prime = 1;

  for (i = 2; i <= N; i++) {
    if (num_attrs[i].is_prime) //������������Ϳ϶���1�����Ҳ���amicable number
    {
      //��ʼ��ʶ����
      for (j = i * 2; j <= N; j += i) {
        num_attrs[j].prime_num++;
        num_attrs[j].is_prime = 0;
      }
    } else if (i > 4) {
      if (num_attrs[i].prime_num == 4 && num_attrs[i - 1].prime_num == 4 &&
          num_attrs[i - 2].prime_num == 4 && num_attrs[i - 3].prime_num == 4) {
        printf("%" PRIu64 "\n", i - 3);
        break;
      }
    }
  }
  return 0;
}
