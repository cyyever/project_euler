/*
 *	程序名：euler57.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 57题(https://projecteuler.net/problem=57)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_arithmetic.h>


int main(int argc,char **argv)
{
	my_rat *numerator,*denominator,*power,*tmp;
	uint64_t i,count;
	int32_t cmp_res;

	//1 + 1/2 = 3/2 = 1.5
	numerator=my_rat_from_int64(NULL,3);
	if(!numerator)
	{
		puts("my_rat_from_int64 failed");
		return -1;
	}

	denominator=my_rat_from_int64(NULL,2);
	if(!denominator)
	{
		puts("my_rat_from_int64 failed");
		my_rat_free(numerator);
		return -1;
	}

	power=my_rat_from_int64(NULL,10);
	if(!power)
	{
		puts("my_rat_from_int64 failed");
		my_rat_free(numerator);
		my_rat_free(denominator);
		return -1;
	}

	tmp=my_rat_from_int64(NULL,0);
	if(!tmp)
	{
		puts("my_rat_from_int64 failed");
		my_rat_free(numerator);
		my_rat_free(denominator);
		my_rat_free(power);
		return -1;
	}
	count=0;
	for(i=2;i<=1000;i++)
	{
		//类似计算1 + 1/(2 + 1/2) = 7/5 = 1.4
		if(!my_rat_copy(tmp,denominator))
		{
			puts("my_rat_copy failed");
			goto failed;
		}

		if(!my_rats_add(denominator,numerator,MY_ARG_RES))
		{
			puts("my_rats_add failed");
			goto failed;
		}

		my_rat_free(numerator);
		numerator=my_rats_add(denominator,tmp,MY_NEW_RES);
		if(!numerator)
		{
			puts("my_rats_add failed");
			goto failed;
		}

		//我们不需要计算位数，只需要保证分子超过分母的下一个界限
		while(1)
		{
			if(my_rats_cmp(denominator,power,&cmp_res)!=MY_SUCC)
			{
				puts("my_rats_cmp failed");
				goto failed;
			}
			if(cmp_res<0)
				break;
			if(!my_rat_multiply_int64(power,10,MY_ARG_RES))
			{
				puts("my_rat_multiply_int64 failed");
				goto failed;
			}
		}

		if(my_rats_cmp(numerator,power,&cmp_res)!=MY_SUCC)
		{
			puts("my_rats_cmp failed");
			goto failed;
		}

		if(cmp_res>=0)
			count++;
	}

	printf("%"PRIu64"\n",count);
	my_rat_free(numerator);
	my_rat_free(denominator);
	my_rat_free(power);
	my_rat_free(tmp);
	return 0;

failed:
	my_rat_free(numerator);
	my_rat_free(denominator);
	my_rat_free(power);
	my_rat_free(tmp);
	return -1;
}
