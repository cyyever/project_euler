/*
 *	程序名：euler37.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 37题(https://projecteuler.net/problem=37)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 1000000

typedef struct
{
	uint8_t is_prime;
	uint8_t is_left_truncatable;
	uint8_t is_right_truncatable;
}num_attr;

int main(int argc,char **argv)
{
	num_attr *num_attrs;
	uint64_t i,j;
	uint64_t power10,sum;

	num_attrs=calloc(N+1,sizeof(num_attr));
	if(!num_attrs)
	{
		printf("calloc failed:%m\n");
		return -1;
	}

	for(i=2;i<N;i++)
		num_attrs[i].is_prime=1;

	for(i=2;i<=10;i++)
	{
		if(num_attrs[i].is_prime)
		{
			num_attrs[i].is_left_truncatable=1;
			num_attrs[i].is_right_truncatable=1;
			for(j=i*2;j<N;j+=i)
				num_attrs[j].is_prime=0;
		}
	}

	sum=0;
	for(i=11;i<N;i++)
	{
		if(num_attrs[i].is_prime)
		{
			if(num_attrs[i/10].is_right_truncatable)
				num_attrs[i].is_right_truncatable=1;
			power10=10;
			while(power10*10<i)
				power10*=10;

			if(num_attrs[i%power10].is_left_truncatable)
				num_attrs[i].is_left_truncatable=1;

			if(num_attrs[i].is_right_truncatable && num_attrs[i].is_left_truncatable)
				sum+=i;
			for(j=i*2;j<N;j+=i)
				num_attrs[j].is_prime=0;
		}
	}

	printf("%"PRIu64"\n",sum);
	free(num_attrs);
	return 0;
}
