/*
 *	程序名：euler38.c
 *	作者：陈源源
 *	日期：2015-07-13
 *	功能：解决eulerproject 38题(https://projecteuler.net/problem=38)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

static int get_prev_pandigital_num(uint8_t *digits,uint8_t max_digit);

int main(int argc,char **argv)
{
	uint8_t digits[]={9,8,7,6,5,4,3,2,1};
	uint64_t integer,tmp,tmp2;
	uint8_t flag;
	size_t i,j,k;

	do
	{
		//对于每个pandigital，我们通过切割位数来判定它是否满足条件
		for(i=1;i<5;i++)
		{
			integer=0;
			for(j=0;j<i;j++)
				integer=integer*10+digits[j];
			tmp=integer;
			flag=1;
			j=2;
			k=i+1;
			while(1)
			{
				integer=tmp*j;
				tmp2=0;
				for(;k<=9;k++)
				{
					tmp2=tmp2*10+digits[k-1];
					if(tmp2>=integer)
						break;
				}
				if(tmp2!=integer)
				{
					flag=0;
					break;
				}
				if(k==9)
					break;
				k++;
				j++;
			}
			if(flag)
			{
				tmp=0;
				for(i=0;i<9;i++)
					tmp=tmp*10+digits[i];
				printf("%"PRIu64"\n",tmp);
				return 0;
			}
		}
	}
	while(get_prev_pandigital_num(digits,9));
	return 0;
}

/*
 *	功能：获取上一个pandigital数
 *	参数：
 *		digits：当前pandigital数
 *		max_digit：最大位数
 *	返回值：
 *		1：成功
 *		0：已经到达最大数
 */
static int get_prev_pandigital_num(uint8_t *digits,uint8_t max_digit)
{
	uint8_t i,j;
	uint64_t num_mask;

	while(1)
	{
		//先获取最右边的逆
		i=max_digit-1;
		j=0;
		num_mask=0;
		while(i>0 && digits[i]>digits[i-1])
		{
			num_mask|=(1<<(digits[i]));
			i--;
		}
		if(i==0)
			break;
		num_mask|=(1<<(digits[i]));
		i--;
		num_mask|=(1<<(digits[i]));

		//减少到上一个数
		j=digits[i]-1;
		while(j>0)
		{
			if((num_mask&(1<<j))!=0)
				break;
			j--;
		}
		digits[i]=j;
		num_mask&=(~(1<<j));
		i++;
		j=max_digit;
		while(i<max_digit)
		{
			while(j>0)
			{
				if((num_mask&(1<<j))!=0)
					break;
				j--;
			}
			num_mask&=(~(1<<j));
			digits[i++]=j--;
		}
		return 1;
	}
	return 0;
}
