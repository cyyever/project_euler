/*
 *	程序名：euler53.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 53题(https://projecteuler.net/problem=53)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>


int main(int argc,char **argv)
{
	uint64_t C[101][101],n,r,count;;

	for(n=1;n<=100;n++)
	{
		C[n][0]=1;
		C[n][n]=1;
	}

	count=0;
	for(n=2;n<=100;n++)
	{
		for(r=1;r<=n-1;r++)
		{
			C[n][r]=C[n-1][r]+C[n-1][r-1];
			if(C[n][r]>1000000)
				count++;
		}
	}

	printf("%"PRIu64"\n",count);
	return 0;
}
