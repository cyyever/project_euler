/*
 *	程序名：euler14.c
 *	作者：陈源源
 *	日期：2015-04-14
 *	功能：解决eulerproject 14题(https://projecteuler.net/problem=14)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 1000000

static uint64_t get_collatz_sequence_len(uint64_t start_num);

int main(int argc,char **argv)
{
	uint64_t i,max_sequence_len,sequence_len,max_i;

	max_sequence_len=0;
	max_i=0;
	for(i=1;i<=N;i++)
	{
		sequence_len=get_collatz_sequence_len(i);
		if(sequence_len>max_sequence_len)
		{
			max_sequence_len=sequence_len;
			max_i=i;
		}
	}
	printf("%"PRIu64"\n",max_i);
	return 0;
}

/*
 *	功能：获取Collatz序列长度
 *	参数：
 *		start_num：起始数字
 *	返回值：
 *		序列长度
 */
static uint64_t get_collatz_sequence_len(uint64_t start_num)
{
	static uint64_t *sequence_lens;
	uint64_t len,num;
	
	if(!sequence_lens)
	{
		sequence_lens=calloc(N+1,sizeof(*sequence_lens));
		if(!sequence_lens)
		{
			printf("calloc failed:%m\n");
			return 0;
		}
	}
	
	len=1;
	num=start_num;
	while(num!=1)
	{
		if(num%2==0)
			num/=2;
		else
			num=num*3+1;
		if(num<=N&&sequence_lens[num])
		{
			sequence_lens[start_num]=len+sequence_lens[num];
			return sequence_lens[start_num];
		}
		len++;
	}
	sequence_lens[start_num]=len;
	return len;
}
