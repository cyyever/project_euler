/*
 *	程序名：euler111.c
 *	作者：陈源源
 *	日期：2016-02-06
 *	功能：解决eulerproject 111题(https://projecteuler.net/problem=111)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_number_theory.h>

int main(int argc,char **argv)
{
	uint64_t i;
	int64_t j;
	uint64_t count,*primes;
	uint64_t m[10],s[10],digit_num[11];
	char number[11];

	memset(m,0,sizeof(m));
	memset(s,0,sizeof(s));

	primes=my_primes(100000);
	if(!primes)
	{
		puts("my_primes failed");
		return -1;
	}

	i=1000000001;
	memset(digit_num,0,sizeof(digit_num));
	for(j=0;j<10;j++)
		digit_num[number[j]-'0']++;

	puts(number);
	while(i<10000000000)
	{
		for(j=0;j<10;j++)
		{	
			if(digit_num[j]>=m[j])
				break;
		}

		if(j>=10)
			goto end;

		for(j=0;primes[j];j++)
		{
			if(i%primes[j]==0)
				break;
		}

		//不是质数
		if(primes[j])
			goto end;

		for(j=0;j<10;j++)
		{	
			if(digit_num[j]>m[j])
			{
				m[j]=digit_num[j];
				s[j]=i;
			}
			else if(digit_num[j]==m[j])
				s[j]+=i;
		}
end:
		i+=2;
		digit_num[number[9]-'0']--;
		number[9]+=2;
		for(j=9;j>=0;j--)
		{
			if(number[j]>'9')
			{
				number[j]=number[j]-'9'+'0'-1;
				digit_num[number[j-1]-'0']--;
				digit_num[number[j]-'0']++;
				number[j-1]+=1;
			}
			else
			{
				digit_num[number[j]-'0']++;
				break;
			}
		}
	}
	count=0;
	for(i=0;i<10;i++)
		count+=s[i];
	printf("%"PRIu64"\n",count);
	return 0;
}

