/*
 *	程序名：euler357.c
 *	作者：陈源源
 *	日期：2016-03-09
 *	功能：解决eulerproject 357题(https://projecteuler.net/problem=357)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_number_theory.h>

int main(int argc,char **argv)
{
	uint64_t *primes,number;
	size_t i,j;

	primes=my_primes(1000000);
	if(!primes)
	{
		puts("my_primes failed");
		return -1;
	}

	for(i=3;primes[i];i++)
	{
		number=(primes[i]-1)/2;
		if(number%2==0)
			continue;
		for(j=1;primes[j];j++)
		{
			if(number%(primes[j]*primes[j])==0)
				break;
		}
		if(primes[j])
			continue;
		printf("%"PRIu64"\n",primes[i]-1);
	}
	free(primes);
	return 0;
}
