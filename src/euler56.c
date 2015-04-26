/*
 *	程序名：euler56.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 56题(https://projecteuler.net/problem=56)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_arithmetic.h>

int main(int argc,char **argv)
{
	uint64_t i,j,digit_sum,max_digit_sum;
	my_rat *base,*power;

	max_digit_sum=0;
	for(i=2;i<100;i++)
	{
		for(j=2;j<100;j++)
		{
			base=my_rat_from_int64(NULL,i);
			if(!base)
			{
				puts("my_rat_from_int64 failed");
				return -1;
			}

			power=my_rat_exp_uint64(base,j,MY_NEW_RES);
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
			if(digit_sum>max_digit_sum)
				max_digit_sum=digit_sum;
		}
	}
	printf("%"PRIu64"\n",max_digit_sum);
	return 0;
}
