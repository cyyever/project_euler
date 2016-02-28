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

int main(int argc,char **argv)
{
	uint64_t digit_num,replace_digit_num,num,prime,finded_prime;
	uint8_t *combination;
	ssize_t i;
	size_t count;
	char replace_digit;
	char *num_str;

	//0 n 2n 3n
	//由于我们要获得8个质数的家族，那么在0-9中，不管我们怎么分，至少有4个数是连续的，如果我们替换的digit数量不是3的倍数，总会出现一个数能被3整除，那么它肯定不是质数，矛盾，同时要替换的digit不能出现在最低位，不然4个连续的数有一个会被2整除，那么它肯定不是质数

	digit_num=4;
	prime=0;
	finded_prime=0;

	while(1)
	{
		num_str=malloc(digit_num+1);
		if(!num_str)
		{
			printf("malloc failed:%m\n");
			return -1;
		}
		num_str[digit_num]='\0';
		for(replace_digit_num=3;replace_digit_num<digit_num;replace_digit_num+=3)
		{
			combination=NULL;
			while(my_next_combination(digit_num-1,replace_digit_num,&combination))
			{
				memset(num_str,'0',digit_num);
				num_str[0]='1';
				num_str[digit_num-1]='1';
				while(1)
				{
					count=0;
					if(combination[0]==1)	//首位从1开始替换
						replace_digit='1';
					else
						replace_digit='0';
					while(replace_digit<='9' && count+'9'-replace_digit+1>=8)
					{
						for(i=0;i<digit_num-1;i++)
						{
							if(combination[i])
								num_str[i]=replace_digit;
						}

						num=strtoull(num_str,NULL,10);
						if(finded_prime!=0 && num>finded_prime)
							break;
						if(my_is_prime(num))
						{
							if(count==0)
								prime=num;
							count++;
						}
						replace_digit++;
					}
					if(count==8) //我们已经找到一个，但是无法确定它是不是最小的
					{
						if(finded_prime==0)
							finded_prime=prime;
						else if(prime<finded_prime)
							finded_prime=prime;
					}

					if(num_str[digit_num-1]<'8')
					{
						if(num_str[i]=='3')
							num_str[i]='7';
						else
							num_str[i]+=2;
						continue;
					}

					for(i=digit_num-2;i>=0;i--)
					{
						if(!combination[i]&&num_str[i]<'9')
						{
							num_str[i]++;
							memset(num_str+i+1,'0',digit_num-i-1);
							num_str[digit_num-1]='1';
							break;
						}
					}
					if(i<=0)
						break;
				}
			}
			free(combination);
		}
		free(num_str);
		if(finded_prime!=0)
			break;
		digit_num++;
	}
	printf("%"PRIu64"\n",finded_prime);
	return 0;
}
