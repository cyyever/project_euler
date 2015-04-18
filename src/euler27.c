/*
 *	程序名：euler27.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 27题(https://projecteuler.net/problem=27)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 200000

int main(int argc,char **argv)
{
	uint8_t *primes;
	int i,j,a,b,n,max_a,max_b,prime_num,max_prime_num,formula_res;

	primes=malloc(N+1);
	if(!primes)
	{
		printf("malloc failed:%m\n");
		return -1;
	}

	//标识质数
	for(i=2;i<=N;i++)
		primes[i]=1;
	for(i=2;i<=N;i++)
	{
		if(primes[i])
		{
			for(j=i*2;j<=N;j+=i)
				primes[j]=0;
		}
	}

	max_prime_num=0;
	max_a=-1000;
	max_b=3;
	for(a=-1000;a<=1000;a++)
	{
		//我们从3开始，因为n=0时为b，显然可以跳过非质数
		//如果b为2，那么n=2时显然不是质数
		for(b=3;b<=1000;b+=2)	
		{
			formula_res=b; //n=0时取b
			if(!primes[formula_res])	
				continue;

			prime_num=1;
			for(n=1;;n++)
			{
				formula_res+=a+2*n-1;
				if(formula_res<2)
					break;
				if(!primes[formula_res])
					break;
			}
			prime_num+=n-1;
			if(prime_num>max_prime_num)
			{
				max_a=a;
				max_b=b;
				max_prime_num=prime_num;
			}
		}
	}

	printf("%d\n",max_a*max_b);
	free(primes);
	return 0;
}
