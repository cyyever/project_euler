/*
 *	程序名：euler12.c
 *	作者：陈源源
 *	日期：2015-04-12
 *	功能：解决eulerproject 12题(https://projecteuler.net/problem=12)
 */

#include <stdio.h>
#include <inttypes.h>

#define N 500

static uint64_t get_factor_num(uint64_t num);

int main(int argc,char **argv)
{
	uint64_t i,sum,factor_num;

	i=1;
	sum=1;
	while(1)
	{
		i++;
		sum+=i;
		if(sum<N)
			continue;
		
		factor_num=get_factor_num(sum);
		if(factor_num>N)
		{
			printf("%"PRIu64"\n",sum);
			break;
		}
	}
	return 0;
}

/*
 *	功能：获取传入数字的因数数量
 *	参数：
 *		num：数字
 *	返回值：
 *		因数数量
 */
static uint64_t get_factor_num(uint64_t num)
{
	uint64_t factor_num,i,j;
	
	factor_num=2;
	j=num-1;
	for(i=2;i<j;i++)
	{
		if(num%i==0)
		{
			j=num/i;
			if(i==j)
			{
				factor_num++;
				break;
			}
			else
				factor_num+=2;
		}
	}
	return factor_num;
}
