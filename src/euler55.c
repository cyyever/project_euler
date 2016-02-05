/*
 *	程序名：euler55.c
 *	作者：陈源源
 *	日期：2016-02-05
 *	功能：解决eulerproject 55题(https://projecteuler.net/problem=55)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

static uint8_t is_palindromic(unsigned __int128 num);
static unsigned __int128 reverse_number(unsigned __int128 num);

int main(int argc,char **argv)
{
	int i,j;
	unsigned __int128 num;
	size_t count;

	count=0;
	for(i=1;i<10000;i++)
	{
		num=i;
		for(j=1;j<50;j++)
		{
			num=num+reverse_number(num);
			if(is_palindromic(num))
				break;
		}
		if(j==50)
			count++;
	}
	printf("%zu\n",count);
	return 0;
}


/*
 *	功能：反转数字
 *	参数：
 *		num：数字
 *	返回值：反转后的数字
 */
unsigned __int128 reverse_number(unsigned __int128 num)
{
	unsigned __int128 reversed_num;
	
	reversed_num=0;
	while(num)
	{
		reversed_num=reversed_num*10+num%10;
		num/=10;
	}
	return reversed_num;
}

/*
 *	功能：判断指定数字是否是回文
 *	参数：
 *		num：要判断的数字
 *	返回值：
 *		1：回文
 *		0：不是回文
 */
uint8_t is_palindromic(unsigned __int128 num)
{
	static unsigned __int128 base[30];
	unsigned __int128 i,first_digit,last_digit,base_end;

	if(base[0]==0)
	{
		base[0]=1;
		for(i=1;i<30;i++)
			base[i]=base[i-1]*10;
	}

	if(num%10==0)
		return 0;

	base_end=0;
	for(i=0;i<30;i++)
	{
		if(base[i]<=num&&base[i+1]>num)
		{
			base_end=i;
			break;
		}
	}

	while(num)
	{
		last_digit=num/base[base_end];
		first_digit=num%10;
		if(first_digit!=last_digit)
			return 0;
		num=num%base[base_end];
		num=num/10;
		base_end-=2;
	}
	return 1;
}
