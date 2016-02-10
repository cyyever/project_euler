/*
 *	程序名：euler7.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 7题(https://projecteuler.net/problem=7)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_number_theory.h>

#define N 2000000

int main(int argc,char **argv)
{
	uint64_t *primes;

	primes=my_primes(N);
	if(!primes)
	{
		puts("my_primes failed");
		return -1;
	}

	printf("%"PRIu64"\n",primes[10000]);
	free(primes);
	return 0;
}
