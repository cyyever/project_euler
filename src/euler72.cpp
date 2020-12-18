/*
 *	��������euler72.c
 *	���ߣ���ԴԴ
 *	���ڣ�2014-11-19
 *	���ܣ����eulerproject 72��(https://projecteuler.net/problem=72)
 */
#include <cinttypes>
#include <cstdio>

#define D 1000000

int main() {
  uint64_t count;
  uint32_t d, i, j;
  uint32_t euler_totient[D + 1];

  //����ʵ��������2��D��ŷ�������ĺ�
  count = 0;
  for (d = 2; d <= D; d++) {
    if (euler_totient[d] == 0) //��û��ʼֵ����ôd�϶�������
    {
      euler_totient[d] = d - 1;
      //����d�ı�������ȥ��Ӧ�ĳ˻�
      for (i = d + d, j = 2; i <= D; i += d, j++) {
        if (euler_totient[i] == 0)
          // euler_totient[i]=i-i/d;
          euler_totient[i] = i - j;
        else
          euler_totient[i] -= (euler_totient[i]) / d;
      }
    }
    count += euler_totient[d];
  }

  printf("%" PRIu64 "\n", count);
  return 0;
}
