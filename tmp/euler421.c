/*
 *	程序名：euler421.c
 *	作者：陈源源
 *	日期：2015-09-22
 *	功能：解决eulerproject 421题(https://projecteuler.net/problem=421)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_number_theory.h>
#include <my_arithmetic.h>

#define N 100000000

int main(int argc,char **argv)
{
	uint64_t *primes;
	//size_t i,j;
	size_t i;

	primes=my_primes(100000000);
	if(!primes)
	{
		puts("my_primes failed");
		return -1;
	}

	for(i=0;primes[i];i++)
	{
		printf("prime is %"PRIu64"\n",primes[i]);
	}

	return 0;
}
