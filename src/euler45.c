/*
 *	程序名：euler45.c
 *	作者：陈源源
 *	日期：2015-07-04
 *	功能：解决eulerproject 45题(https://projecteuler.net/problem=45)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(int argc,char **argv)
{
	uint64_t H_n,P_n,T_n,T_n_max,T_n_min;
	uint64_t H,P,T;
	
	H_n=143;
	P_n=165;
	T_n=285;
	H=40755;
	P=40755;
	T=40755;

	//我们从285开始遍历
	while(1)
	{
		H_n++;
		H+=4*(H_n)-3;
		while(P<H)
		{
			P_n++;
			P+=3*P_n-2;
		}
		if(P!=H)
			continue;

		T_n_min=P_n;
		T_n_max=P_n*2;
		T=(T_n_max*(T_n_max+1))/2;
		while(T<H)
		{
			T_n_max*=2;
			T=(T_n_max*(T_n_max+1))/2;
		}
		while(T_n_min<=T_n_max)
		{
			T_n=(T_n_min+T_n_max)/2;
			T=(T_n*(T_n+1))/2;
			if(T==H)
				break;
			else if(T<H)
				T_n_min=T_n+1;
			else
				T_n_max=T_n-1;
		}

		if(T==H)
			break;
	}
	printf("%"PRIu64"\n",H);
	return 0;
}
