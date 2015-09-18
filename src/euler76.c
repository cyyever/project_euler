/*
 *	程序名：euler76.c
 *	作者：陈源源
 *	日期：2015-09-18
 *	功能：解决eulerproject 76题(https://projecteuler.net/problem=76)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 100

int main(int argc,char **argv)
{
	size_t i,j,k;
	uint64_t sum_num;
	struct num_attr
	{
		uint64_t sum_num[N+1];	//每个数起始的和的数量
	}*nums;

	nums=calloc(N+1,sizeof(*nums));
	if(!nums)
	{
		printf("calloc failed:%m\n");
		return -1;
	}

	for(i=1;i<=N;i++)
	{
		nums[i].sum_num[i]=1;
		for(j=i-1;j>=1;j--)
		{
			for(k=j;k>=1;k--)
				nums[i].sum_num[j]+=nums[i-j].sum_num[k];
		}
	}
	sum_num=0;
	for(i=1;i<N;i++)
		sum_num+=nums[N].sum_num[i];
	free(nums);
	printf("%"PRIu64"\n",sum_num);
	return 0;
}
