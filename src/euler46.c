/*
 *	程序名：euler46.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 46题(https://projecteuler.net/problem=46)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 10000

int main(int argc,char **argv)
{
	uint8_t *primes;
	size_t *double_squares;
	size_t i,j,double_square_num;
	uint8_t flag;

	//我们先分配数字属性的数组
	primes=malloc(N+1);
	if(!primes)
	{
		printf("malloc failed:%m\n");
		return -1;
	}

	//我们先分配数字属性的数组
	double_squares=calloc(N,sizeof(size_t));
	if(!double_squares)
	{
		printf("calloc failed:%m\n");
		free(primes);
		return -1;
	}
	
	double_squares[0]=2;
	double_square_num=1;

	//遍历数字
	primes[1]=0;
	for(i=2;i<=N;i++)
		primes[i]=1;

	for(i=2;i<=N;i++)
	{
		if(primes[i]==0 && (i&1)==1)
		{
			flag=0;
			for(j=0;j<double_square_num;j++)
			{

				if(double_squares[j]>i)
					break;
				if(primes[i-double_squares[j]]==1)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
				printf("%zu\n",i);
				free(primes);
				free(double_squares);
				return 0;
			}
		}

		double_squares[double_square_num++]=i*i*2;
		if(primes[i])
		{
			for(j=i*2;j<=N;j+=i)
				primes[j]=0;
		}
	}

	free(primes);
	free(double_squares);
	return 0;

}
