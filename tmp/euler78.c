/*
 *	程序名：euler78.c
 *	作者：陈源源
 *	日期：2015-09-18
 *	功能：解决eulerproject 78题(https://projecteuler.net/problem=78)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 10000

int main(int argc,char **argv)
{
	size_t i,j;
	struct num_attr
	{
		__int128 *sum_num;	//小于等于该数起始的和的数量
	}*nums;

	nums=calloc(N+1,sizeof(*nums));
	if(!nums)
	{
		printf("calloc failed:%m\n");
		return -1;
	}

	for(i=1;i<=N;i++)
	{
		nums[i].sum_num=calloc(i+1,16);
		if(!nums[i].sum_num)
		{
			printf("calloc failed:%m\n");
			return -1;
		}

		nums[i].sum_num[i]=1;
		for(j=i-1;j>=1;j--)
		{
			if(j>i-j)
				nums[i].sum_num[j]=nums[i-j].sum_num[i-j];
			else
				nums[i].sum_num[j]=nums[i-j].sum_num[j];
		}
		for(j=2;j<=i;j++)
			nums[i].sum_num[j]+=nums[i].sum_num[j-1];

		if(i==100)
			printf("%zu\n",(size_t)nums[i].sum_num[i]);
		if(nums[i].sum_num[i]<0)
		{
			printf("i=%zu\n",i);
			puts("over flow");
			exit(0);
		}

		if(nums[i].sum_num[i]%1000000==0)
		{
			free(nums);
			printf("%zu\n",i);
			return 0;
		}
	}
	free(nums);
	return 0;
}
