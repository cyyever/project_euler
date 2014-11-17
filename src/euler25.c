/*
 *	程序名：euler25.c
 *	作者：陈源源
 *	日期：2014-11-17
 *	功能：解决eulerproject 25题(https://projecteuler.net/problem=25)
 */
#include <stdio.h>
#include <inttypes.h>
#include <my_arithmetic.h>

int main(int argc,char **argv)
{
	my_rat *a,*b;
	uint64_t i,digit_num;
	i=2;
	a=my_rat_from_int64(NULL,1);
	if(!a)
	{
		puts("my_rat_from_int64 failed");
		return -1;
	}
	b=my_rat_from_int64(NULL,1);
	if(!b)
	{
		puts("my_rat_from_int64 failed");
		my_rat_free(a);
		return -1;
	}
	while(1)
	{
		i++;
		if(my_rats_add(a,b,MY_ARG_RES)==NULL)
		{
			puts("my_rats_add failed");
			my_rat_free(a);
			my_rat_free(b);
			return -1;
		}

		if(my_rat_digit_num(a,&digit_num)!=MY_SUCC)
		{
			puts("my_rat_digit_num failed");
			my_rat_free(a);
			my_rat_free(b);
			return -1;
		}

		if(digit_num>=1000)
			break;

		if(my_rats_add(b,a,MY_ARG_RES)==NULL)
		{
			puts("my_rats_add failed");
			my_rat_free(a);
			my_rat_free(b);
			return -1;
		}
		i++;
		if(my_rat_digit_num(b,&digit_num)!=MY_SUCC)
		{
			puts("my_rat_digit_num failed");
			my_rat_free(a);
			my_rat_free(b);
			return -1;
		}

		if(digit_num>=1000)
			break;
	}
	my_rat_free(a);
	my_rat_free(b);
	printf("%"PRIu64"\n",i);
	return 0;
}
