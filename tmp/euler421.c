/*
 *	程序名：euler421.c
 *	作者：陈源源
 *	日期：2015-09-22
 *	功能：解决eulerproject 421题(https://projecteuler.net/problem=421)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_arithmetic.h>

#define N 100000000

uint64_t  get_power_of_15(uint64_t n);
uint64_t  get_power_of_15_remainder(uint64_t n,uint64_t modulus);
int main(int argc,char **argv)
{
	uint8_t *primes;
	size_t i,j;
	unsigned __int128 sum;
	my_rat **cached_powers;
	uint64_t power;
	uint8_t has_over_flowed;

	primes=malloc(N+1);
	if(!primes)
	{
		printf("malloc failed:%m\n");
		return -1;
	}

	//标识质数
	for(i=2;i<=N;i++)
		primes[i]=1;
	for(i=3;i<=N;i+=2)
	{
		if(primes[i])
		{
			for(j=i*2;j<=N;j+=i)
				primes[j]=0;
		}
	}

	//找出最后一个质数，计算其模的指数
	for(i=N;i>=3;i--)
	{
		if(primes[i])
		{
			cached_powers=malloc(i*sizeof(*cached_powers));
			if(!cached_powers)
			{
				printf("malloc failed:%m\n");
				return -1;
			}
			for(j=2;j<=i-2;j++)
			{
				printf("j=%zu\n",j);
				cached_powers[i]=my_rat_from_int64(NULL,(int64_t)j);
				if(!cached_powers[i])
				{
					printf("my_rat_from_int64 failed\n");
					return -1;
				}
				if(my_rat_exp_uint64(cached_powers[i],15,MY_ARG_RES)==NULL)
				{
					printf("my_rat_exp_uint64 failed\n");
					return -1;
				}
			}
			break;
		}
	}
	return 0;

	/*
	has_over_flowed=0;
	//我们先算出可以被2整除的n^15+1的数量
	sum=(100000000000-1)/2+1;
	//从3开始遍历每个质数开始迭代
	for(i=3;i<=N;i+=2)
	{
		if(!primes[i])
			continue;

		printf("i=%zu\n",i);
		sum+=(100000000000-(i-1))/i+1;
		//遍历质数i的模，判断模^15+1能否被i整除，如果可以，加入计数
		for(j=2;j<=i-2;j++)
		{
			power=0;
			if(cached_powers[j]==0)	//还没缓存
			{
				if(cached_powers[i-j]!=0)
				{
					if(cached_powers[i-j]%i==1)
						sum+=(100000000000-j)/i+1;
					continue;
				}
				if(has_over_flowed==0)
				{
					cached_powers[j]=get_power_of_15(j);
					if(cached_powers[j]==0)
						has_over_flowed=1;
					else
						power=cached_powers[j];
				}
			}
			if(power!=0)	//我们计算一下
			{
				if(power%i==i-1)
					sum+=(100000000000-j)/i+1;
			}
			else
			{
				if(get_power_of_15_remainder(j,i)==i-1)
					sum+=(100000000000-j)/i+1;
			}
		}
	}


	free(primes);
	return 0;
	*/
}

/*
 *	功能：计算指定正整数的15次方
 *	参数：
 *		n：要计算的正整数
 *	返回值：
 *		>0：15次方
 *		0：溢出
 */
uint64_t  get_power_of_15(uint64_t n)
{
	unsigned __int128 power;
	unsigned __int128 tmp;
	uint8_t exp;
	power=1;
	exp=15;
	tmp=n;
	while(exp)
	{
		if(exp&1)
			power*=tmp;
		tmp*=tmp;
		if(tmp>UINT64_MAX)
			return 0;
		exp>>=1;
	}
	return (uint64_t)power;
}

/*
 *	功能：计算指定正整数的15次方模另一个正整数
 *	参数：
 *		n：要计算的正整数
 *		modulus：模
 *	返回值：
 *		>0：15次方
 *		0：溢出
 */
uint64_t  get_power_of_15_remainder(uint64_t n,uint64_t modulus)
{
	unsigned __int128 power;
	unsigned __int128 tmp;
	uint8_t exp;
	power=1;
	exp=15;
	tmp=n;
	while(exp)
	{
		if(exp&1)
		{
			power*=tmp;
			if(power>UINT64_MAX)
				power%=modulus;
		}
		tmp*=tmp;
		if(tmp>UINT64_MAX)
			tmp%=modulus;
		exp>>=1;
	}
	power%=modulus;
	return (uint64_t)power;
}
