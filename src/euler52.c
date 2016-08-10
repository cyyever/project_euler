/*
 *	��������euler52.c
 *	���ߣ���ԴԴ
 *	���ڣ�2014-11-19
 *	���ܣ����eulerproject 52��(https://projecteuler.net/problem=52)
 */
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int get_num_mask(uint64_t num, uint64_t *num_mask);

int main(void) {
  uint64_t i, j, res, num_mask, num_mask2, find_flag;

  for (i = 100; i; i++) //����Ҫ��3λ����ʼ�Ż���6����ͬ˳���digit
  {
    res = i;
    if (get_num_mask(res, &num_mask) != 0)
      continue;

    find_flag = 1;
    for (j = 0; j < 5; j++) {
      res += i;
      if (get_num_mask(res, &num_mask2) != 0) {
        find_flag = 0;
        break;
      }

      if (num_mask != num_mask2) {
        find_flag = 0;
        break;
      }
    }
    if (find_flag)
      break;
  }
  printf("%" PRIu64 "\n", i);
  return 0;
}

/*
 *	���ܣ���ȡָ�����ֵ�����
 *	������
 *		num������
 *		num_mask����������
 *	����ֵ��
 *		1���������ظ�λ��
 *		0���ɹ�
 */
int get_num_mask(uint64_t num, uint64_t *num_mask) {
  uint64_t digit;

  *num_mask = 0;

  while (num) {
    digit = num % 10;
    if (((*num_mask) & (1 << digit)) != 0)
      return 1;
    (*num_mask) |= (1 << digit);
    num /= 10;
  }
  return 0;
}
