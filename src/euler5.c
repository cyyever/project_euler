/*
 *	程序名：euler5.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 5题(https://projecteuler.net/problem=5)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 20

int main(int argc,char **argv)
{
	uint8_t *primes;
	uint64_t product,max_prime_product;
	size_t i,j;

	primes=malloc(N+1);
	if(!primes)
	{
		printf("malloc failed:%m\n");
		return -1;
	}

	//标识质数
	for(i=2;i<=N;i++)
		primes[i]=1;
	product=1;
	for(i=2;i<=N;i++)
	{
		if(primes[i])
		{
			max_prime_product=i;
			for(j=i*2;j<=N;j+=i)
				primes[j]=0;
			
			while(max_prime_product*i<=N)
				max_prime_product*=i;
			product*=max_prime_product;
		}
	}

	printf("%"PRIu64"\n",product);
	free(primes);
	return 0;
}
