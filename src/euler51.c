/*
 *	程序名：euler51.c
 *	作者：陈源源
 *	日期：2016-02-23
 *	功能：解决eulerproject 51题(https://projecteuler.net/problem=51)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <my_number_theory.h>

typedef struct prime_pattern_s
{
	uint64_t pattern;
	size_t num;
	struct prime_pattern_s *next;
}prime_pattern;

prime_pattern *patterns,*checked_patterns;

uint64_t *get_primes_in_range(uint64_t lower_bound,uint64_t upper_bound);

int main(int argc,char **argv)
{
	prime_pattern *pattern;
	uint64_t *primes,prime_pattern;
	size_t i,j,k,base;
	char digit,digit2;
	char prime_str[2][10];
	uint8_t digit_cnt[10];

	base=100;
	while(1)
	{
		primes=get_primes_in_range(base,base*10);
		if(!primes)
		{
			puts("can't find prime");
			return -1;
		}
		patterns=NULL;

		for(i=0;primes[i];i++)
		{
			//0 n 2n 3n
			//由于我们要获得8个质数的家族，那么在0-9中，不管我们怎么分，至少有4个数是连续的，如果我们替换的digit数量不是3的倍数，总会出现一个数能被3整除，那么它肯定不是质数，矛盾，同时要替换的digit不能出现在最低位，不然4个连续的数有一个会被2整除，那么它肯定不是质数
			memset(digit_cnt,0,sizeof(digit_cnt));
			sprintf(prime_str[1],"%"PRIu64,primes[i]);
			for(j=0;prime_str[1][j+1];j++)
				digit_cnt[prime_str[1][j]-'0']++;

			for(j=0;j<10;j++)
			{
				if(digit_cnt[j]>=3)
					break;
			}
			if(j==10)
				continue;

			for(j=i+1;primes[j];j++)
			{
				sprintf(prime_str[0],"%"PRIu64,primes[j]);
				digit='\0';
				digit2='\0';
				for(k=0;prime_str[0][k];k++)
				{
					if(prime_str[0][k]!=prime_str[1][k])
					{
						if(digit=='\0')
							digit=prime_str[0][k];
						else if(prime_str[0][k]!=digit)
							break;
						prime_str[0][k]='1';
						if(digit2=='\0')
							digit2=prime_str[1][k];
						else if(prime_str[1][k]!=digit2)
							break;
					}
					else
						prime_str[0][k]='0';
				}
				if(prime_str[0][k])
					continue;
				prime_pattern=strtoull(prime_str[0],NULL,10);

				pattern=patterns;
				while(pattern)
				{
					if(pattern->pattern==prime_pattern)
					{
						pattern->num++;
						break;
					}
					pattern=pattern->next;
				}

				//找不到，新增质数模式
				if(!pattern)
				{
					pattern=malloc(sizeof(*pattern));
					if(!pattern)
					{
						printf("malloc failed:%m");
						return -1;
					}
					pattern->pattern=prime_pattern;
					pattern->num=2;
					pattern->next=patterns;
					patterns=pattern;
				}
			}

			if(patterns)
			{
				pattern=patterns;
				while(1)
				{
					if(pattern->num==8)
					{
						printf("%"PRIu64"\n",primes[i]);
						return 0;
					}
					if(pattern->next)
						pattern=pattern->next;
					else
						break;
				}
				pattern->next=checked_patterns;
				checked_patterns=patterns;
				patterns=NULL;
			}
			while(checked_patterns)
			{
				pattern=checked_patterns;
				checked_patterns=pattern->next;
				free(pattern);
			}
		}
		free(primes);
		base*=10;
	}
	return 0;
}

/*
 *	功能：获取指定返回内的质数
 *	参数：
 *		lower_bound,upper_bound：标识范围
 *	返回值：
 *		非NULL：质数数组，以0结尾
 *		NULL：没有质数
 */
uint64_t *get_primes_in_range(uint64_t lower_bound,uint64_t upper_bound)
{
	static uint64_t *primes,prime;
	static size_t prime_num,primes_size;
	uint64_t *prime_range,*tmp,prime_test_limit;
	size_t i,j;
	uint8_t is_prime;

	if(lower_bound>=upper_bound)
	{
		puts("invalid arguments");
		exit(EXIT_FAILURE);
	}
	if(upper_bound<2)
		return NULL;

	if(!primes)
	{
		//找出100000以内质数
		//primes=my_primes(100000);
		primes=my_primes(100);
		if(!primes)
		{
			puts("my_primes failed");
			exit(EXIT_FAILURE);
		}
		for(i=0;primes[i];i++)
			;
		prime_num=i;
		primes_size=prime_num;
		//prime=100001;
		prime=101;
		prime_test_limit=3;
	}

	for(;prime<=upper_bound;prime+=2)
	{
		if(primes_size==prime_num)
		{
			tmp=realloc(primes,primes_size*2*sizeof(*primes));
			if(!tmp)
			{
				printf("realloc failed:%m");
				exit(EXIT_FAILURE);
			}
			primes=tmp;
			primes_size*=2;
		}
		is_prime=1;
		for(i=1;primes[i]<=prime_test_limit;i++)
		{
			if(prime%primes[i]==0)
			{
				is_prime=0;
				break;
			}
		}
		if(!is_prime)
			continue;
		while(primes[i]*primes[i]<=prime)
		{
			if(prime%primes[i]==0)
			{
				is_prime=0;
				break;
			}
			i++;
		}
		if(!is_prime)
			continue;
		prime_test_limit=primes[i];
		primes[prime_num++]=prime;
	}
	for(i=0;i<prime_num;i++)
	{
		if(primes[i]>=lower_bound)
			break;
	}
	for(j=prime_num-1;j>0;j--)
	{
		if(primes[j]<=upper_bound)
			break;
	}
	prime_range=calloc(j-i+2,sizeof(*prime_range));
	if(!prime_range)
	{
		printf("calloc failed:%m");
		exit(EXIT_FAILURE);
	}
	memcpy(prime_range,primes+i,(j-i+1)*sizeof(*prime_range));
	return prime_range;
}
