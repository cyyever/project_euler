/*
 *	程序名：euler10.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 10题(https://projecteuler.net/problem=10)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_number_theory.h>

#define N 2000000

int main(int argc,char **argv)
{
	uint64_t *primes;
	size_t i;
	uint64_t sum;

	primes=my_primes(N);
	if(!primes)
	{
		puts("my_primes failed");
		return -1;
	}

	//标识质数
	sum=0;
	for(i=0;primes[i];i++)
		sum+=primes[i];

	printf("%"PRIu64"\n",sum);
	free(primes);
	return 0;
}
