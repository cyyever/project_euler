/*
 *	程序名：euler111.c
 *	作者：陈源源
 *	日期：2016-02-28
 *	功能：解决eulerproject 111题(https://projecteuler.net/problem=111)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <my_number_theory.h>

int main(int argc,char **argv)
{
	uint64_t repeated_digit_num,num;
	uint8_t *combination;
	ssize_t i,j;
	uint64_t S[10],sum;
	char d,lowest_digit;
	char num_str[11];

	num_str[10]='\0';
	sum=0;
	for(d='0';d<='9';d++)
	{
		S[d-'0']=0;
		if(d=='0')
			lowest_digit='1';
		else
			lowest_digit='0';
		for(repeated_digit_num=9;repeated_digit_num>=2;repeated_digit_num--)
		{
			combination=NULL;
			while(my_next_combination(10,repeated_digit_num,&combination))
			{
				if(combination[0] && d=='0')
					continue;
				if(combination[9])
				{
					if(((d-'0')&1)==0)
						continue;
					else if(d=='5')
						continue;
				}
				for(i=0;i<10;i++)
				{
					if(combination[i])
						num_str[i]=d;
					else
						num_str[i]=lowest_digit;
				}
				if(!combination[0])
				{
					if(d!='1')
						num_str[0]='1';
					else
						num_str[0]='2';
				}

				while(1)
				{
					num=strtoull(num_str,NULL,10);
					if(my_is_prime(num))
					{
						S[d-'0']+=num;

					}
					for(i=9;i>=0;i--)
					{
						if(combination[i])
							continue;
						if(num_str[i]<'9')
						{
							num_str[i]++;
							if(num_str[i]==d)
								num_str[i]++;
							if(num_str[i]<='9')
							{
								for(j=i+1;j<10;j++)
								{
									if(combination[j])
										num_str[j]=d;
									else
										num_str[j]=lowest_digit;
								}
								break;
							}
						}
					}
					if(i<0)
						break;
				}
			}
			free(combination);
			if(S[d-'0']!=0)
			{
				sum+=S[d-'0'];
				break;
			}
		}
	}

	printf("%"PRIu64"\n",sum);
	return 0;
}
