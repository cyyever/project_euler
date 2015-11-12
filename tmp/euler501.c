/*
 *	程序名：euler501.c
 *	作者：陈源源
 *	日期：2015-11-12
 *	功能：解决eulerproject 501题(https://projecteuler.net/problem=501)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_arithmetic.h>

#define N 1000000ul

int main(int argc,char **argv)
{
	uint8_t *primes;
	size_t num;
	int64_t i,j,k;
	int32_t cmp_res;
	uint8_t over_k_flag,over_j_flag;
	my_rat *a,*b,*c,*d,*limit;

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
	
	limit=my_rat_from_int64(NULL,N);
	if(!limit)
	{
		puts("my_rat_from_int64 failed");
		return -1;
	}
	num=0;

	//根据质数分解，如果要有8个因数，在一个质数的情况下必须是7次方，我们先计算这种情况
	//从2开始遍历
	for(i=2;i<=N;i++)
	{
		if(!primes[i])
			continue;

		a=my_rat_from_int64(NULL,i);
		if(!a)
		{
			puts("my_rat_from_int64 failed");
			return -1;
		}
		if(!my_rat_exp_uint64(a,7,MY_ARG_RES))
		{
			puts("my_rat_exp_uint64 failed");
			return -1;
		}

		if(my_rats_cmp(a,limit,&cmp_res)!=MY_SUCC)
		{
			puts("my_rats_cmp failed");
			return -1;
		}	

		my_rat_free(a);
		if(cmp_res<=0)
			num++;
		else
			break;
	}

	//在两个质数的情况下，必须一个是3次方，一个是1次方
	//从2开始遍历
	for(i=2;i<=N;i++)
	{
		if(!primes[i])
			continue;

		a=my_rat_from_int64(NULL,i);
		if(!a)
		{
			puts("my_rat_from_int64 failed");
			return -1;
		}
		if(!my_rat_exp_uint64(a,3,MY_ARG_RES))
		{
			puts("my_rat_exp_uint64 failed");
			return -1;
		}
		for(j=2;j<=N;j++)
		{
			if(j==i)
				continue;

			if(!primes[j])
				continue;

			b=my_rat_multiply_int64(a,j,MY_NEW_RES);
			if(!b)
			{
				puts("my_rat_from_int64 failed");
				return -1;
			}

			if(my_rats_cmp(b,limit,&cmp_res)!=MY_SUCC)
			{
				puts("my_rats_cmp failed");
				return -1;
			}	

			my_rat_free(b);
			if(cmp_res<=0)
				num++;
			else
				break;
		}
		my_rat_free(a);
		if(j==2)
			break;
	}

	//在三个质数的情况下，必须三个一次方
	//从2开始遍历
	for(i=2;i<=N;i++)
	{
		if(!primes[i])
			continue;

		a=my_rat_from_int64(NULL,i);
		if(!a)
		{
			puts("my_rat_from_int64 failed");
			return -1;
		}
		over_j_flag=1;
		for(j=i+1;j<=N;j++)
		{
			if(!primes[j])
				continue;

			b=my_rat_from_int64(NULL,j);
			if(!b)
			{
				puts("my_rat_from_int64 failed");
				return -1;
			}

			c=my_rats_multiply(a,b,MY_NEW_RES);
			if(!c)
			{
				puts("my_rats_multiply failed");
				return -1;
			}

			over_k_flag=1;
			for(k=j+1;k<=N;k++)
			{
				if(!primes[k])
					continue;

				d=my_rat_multiply_int64(c,k,MY_NEW_RES);
				if(!d)
				{
					puts("my_rat_multiply_int64 failed");
					return -1;
				}

				if(my_rats_cmp(d,limit,&cmp_res)!=MY_SUCC)
				{
					puts("my_rats_cmp failed");
					return -1;
				}	

				my_rat_free(d);
				if(cmp_res<=0)
				{
					num++;
					over_k_flag=0;
				}
				else
					break;
			}
			my_rat_free(c);
			my_rat_free(b);
			if(over_k_flag)
				break;
			else
				over_j_flag=0;
		}
		my_rat_free(a);
		if(over_j_flag)
			break;
	}


	free(primes);
	printf("%zu\n",num);
	return 0;
}
