/*
 *	程序名：euler48.c
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 48题(https://projecteuler.net/problem=48)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_arithmetic.h>

int main(int argc,char **argv)
{
	unsigned __int128 i,n,power,sum,res;

	sum=0;
	for(i=1;i<=1000;i++)
	{
		power=i;
		n=i;
		res=1;
		while(power)
		{
			if(power&1)
				res=(res*n)%10000000000;
			power>>=1;
			n=(n*n)%10000000000;
		}
		sum=(sum+res)%10000000000;
	}

	printf("%"PRIu64"\n",(uint64_t)sum);
	return 0;
}
