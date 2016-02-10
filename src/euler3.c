/*
 *	程序名：euler3.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 3题(https://projecteuler.net/problem=3)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_number_theory.h>

int main(int argc,char **argv)
{
	uint64_t *primes;
	size_t i;

	primes=my_primes(1000000);
	if(!primes)
	{
		puts("my_primes failed");
		return -1;
	}

	for(i=0;primes[i];i++)
		;
	i--;
	while(i>=0)
	{
		if(600851475143%primes[i]==0)
		{
			printf("%"PRIu64"\n",primes[i]);
			break;
		}
		i--;
	}
	free(primes);
	return 0;
}
