/*
 *	程序名：euler7.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 7题(https://projecteuler.net/problem=7)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 2000000

int main(int argc,char **argv)
{
	uint8_t *primes;
	size_t i,j;
	uint64_t prime_num;

	primes=malloc(N+1);
	if(!primes)
	{
		printf("malloc failed:%m\n");
		return -1;
	}

	//标识质数
	for(i=2;i<=N;i++)
		primes[i]=1;
	prime_num=0;
	for(i=2;i<=N;i++)
	{
		if(primes[i])
		{
			prime_num++;
			if(prime_num==10001)
			{
				printf("%"PRIu64"\n",i);
				break;
			}
			for(j=i*2;j<=N;j+=i)
				primes[j]=0;
		}
	}

	free(primes);
	return 0;
}
