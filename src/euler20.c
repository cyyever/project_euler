/*
 *	程序名：euler20.c
 *	作者：陈源源
 *	日期：2014-11-17
 *	功能：解决eulerproject 20题(https://projecteuler.net/problem=20)
 */
#include <stdio.h>
#include <inttypes.h>
#include <my_arithmetic.h>

int main(int argc,char **argv)
{
	my_rat *f;
	uint64_t digit_sum;

	f=my_factorial(100);
	if(!f)
	{
		printf("my_factorial failed");
		return -1;
	}

	if(my_rat_sum_digits(f,&digit_sum)!=MY_SUCC)
	{
		printf("my_rat_sum_digits failed");
		my_rat_free(f);
		return -1;
	}
	printf("%"PRIu64"\n",digit_sum);
	return 0;
}
