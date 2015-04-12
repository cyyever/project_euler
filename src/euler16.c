/*
 *	程序名：euler16.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 16题(https://projecteuler.net/problem=16)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_arithmetic.h>

int main(int argc,char **argv)
{
	uint64_t digit_sum;
	my_rat *base,*power;

	base=my_rat_from_int64(NULL,2);
	if(!base)
	{
		puts("my_rat_from_int64 failed");
		return -1;
	}

	power=my_rat_exp_uint64(base,1000,MY_NEW_RES);
	my_rat_free(base);
	if(!power)
	{
		puts("my_rat_exp_uint64 failed");
		return -1;
	}
	
	if(my_rat_sum_digits(power,&digit_sum)!=MY_SUCC)
	{
		my_rat_free(base);
		puts("my_rat_sum_digits failed");
		return -1;
	}

	my_rat_free(power);
	printf("%"PRIu64"\n",digit_sum);
	return 0;
}
