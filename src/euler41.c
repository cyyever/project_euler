/*
 *	程序名：euler41.c
 *	作者：陈源源
 *	日期：2015-07-18
 *	功能：解决eulerproject 41题(https://projecteuler.net/problem=41)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define N 100000

static int get_prev_pandigital_num(uint8_t *digits,uint8_t max_digit);

int main(int argc,char **argv)
{
	uint8_t *primes;
	uint8_t digits[9];
	uint64_t number;
	size_t i,j,max_digit;

	primes=calloc(1,N+1);
	if(!primes)
	{
		printf("malloc failed:%m\n");
		return -1;
	}

	//找出质数
	memset(primes,1,N+1);
	for(i=2;i<=N;i++)
	{
		if(primes[i])
		{
			for(j=i*2;j<=N;j+=i)
				primes[j]=0;
		}
	}

	for(max_digit=9;max_digit>=1;max_digit--)
	{
		for(i=0;i<max_digit;i++)
			digits[i]=max_digit-i;
		do
		{
			//对于每个pandigital，判定是否是质数
			if((digits[0]%2)==0 || digits[0]==5)
				continue;
			number=0;
			for(i=0;i<max_digit;i++)
				number=number*10+digits[i];
			if(number<=N && primes[number])
			{
				printf("%"PRIu64"\n",number);
				return 0;
			}
			for(i=2;i<=N;i++)
			{
				if(primes[i])
				{
					if(number%i==0)
						break;
				}
			}
			if(i>N)
			{
				printf("%"PRIu64"\n",number);
				return 0;
			}
		}
		while(get_prev_pandigital_num(digits,max_digit));
	}
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
