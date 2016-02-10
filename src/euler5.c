/*
 *	程序名：euler5.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 5题(https://projecteuler.net/problem=5)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_number_theory.h>

#define N 20

int main(int argc,char **argv)
{
	uint64_t *primes;
	uint64_t product,factor;
	size_t i;

	primes=my_primes(N);
	if(!primes)
	{
		puts("my_primes failed");
		return -1;
	}

	product=1;
	for(i=0;primes[i];i++)
	{
		factor=primes[i];
		while(factor*primes[i]<=N)
			factor*=primes[i];
		product*=factor;
	}

	printf("%"PRIu64"\n",product);
	free(primes);
	return 0;
}
