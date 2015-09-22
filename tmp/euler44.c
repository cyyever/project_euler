/*
 *	程序名：euler44.c
 *	作者：陈源源
 *	日期：2015-07-12
 *	功能：解决eulerproject 44题(https://projecteuler.net/problem=44)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(int argc,char **argv)
{
	uint64_t i,j,k,l,P_i,P_j,P_k,P_l;

	for(j=1,P_j=1;;j++,P_j+=(3*j-2))
	{
		k=j+1;
		P_k=k*(3*k-1)/2;
		for(;;k++,P_k+=(3*k-2))
		{
			if(k-j>1000)
			{
			printf("j=%"PRIu64"\n",j);
			printf("k=%"PRIu64"\n",k);
			break;
			}
			//计算差
			i=k-j+3;
			if(i>=k)
				break;
			for(;i<k;i+=3)
			{
				P_i=i*(3*i-1)/2;
				if(P_i==P_k-P_j)
					break;
			}
			if(i>=k)
				continue;
				printf("j=%"PRIu64"\n",j);
				printf("k=%"PRIu64"\n",k);
				return 0;
			//计算和
			l=j+k-3;
			if(l<=k)
				break;
			for(;l>k;l-=3)
			{
				P_l=l*(3*l-1)/2;
				if(P_l==P_k+P_j)
					break;
			}
			if(l<=k)
				continue;
				printf("j=%"PRIu64"\n",j);
				printf("k=%"PRIu64"\n",k);
				return 0;
				break;
		}
	}
	return 0;
}
