/*
 *	程序名：euler3.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 3题(https://projecteuler.net/problem=3)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


int main(int argc,char **argv)
{
	uint8_t *primes;
	size_t i,j;
	uint64_t num,prime_num;

	num=600851475143;
	prime_num=999999;

	primes=malloc(prime_num+1);
	if(!primes)
	{
		printf("malloc failed:%m\n");
		return -1;
	}

	//标识质数
	for(i=2;i<=prime_num;i++)
		primes[i]=1;
	for(i=2;i<=prime_num;i++)
	{
		if(primes[i])
		{
			while(num%i==0)
				num/=i;
			if(num==1)
			{
				printf("%"PRIu64"\n",i);
				break;
			}
			for(j=i*2;j<=num&&j<=prime_num;j+=i)
				primes[j]=0;
		}
	}

	free(primes);
	return 0;
}
