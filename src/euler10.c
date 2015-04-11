/*
 *	程序名：euler10.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 10题(https://projecteuler.net/problem=10)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 2000000

int main(int argc,char **argv)
{
	uint8_t *primes;
	size_t i,j;
	uint64_t sum;

	//我们先分配数字属性的数组
	primes=malloc(N+1);
	if(!primes)
	{
		printf("malloc failed:%m\n");
		return -1;
	}

	for(i=2;i<=N;i++)
		primes[i]=1;
	sum=0;
	for(i=2;i<=N;i++)
	{
		if(primes[i])
		{
			sum+=i;
			for(j=i*2;j<=N;j+=i)
				primes[j]=0;
		}
	}

	printf("%"PRIu64"\n",sum);
	return 0;
}
