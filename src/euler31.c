/*
 *	程序名：euler31.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 31题(https://projecteuler.net/problem=31)
 */
#include <stdio.h>
#include <inttypes.h>

/*
 *	功能：获取指定金额的构成方式
 *	参数：
 *		amount：待计算的金额
 *		coins：硬币数组
 *	返回值：
 *		构成方式
 */
size_t  coin_made_ways(uint64_t amount,uint8_t *coins);

int main(int argc,char **argv)
{
	//硬币
	uint8_t coins[]={200,100,50,20,10,5,2,1};

	printf("%zu\n",coin_made_ways(200,coins));
	return 0;
}

/*
 *	功能：获取指定金额的构成方式
 *	参数：
 *		amount：待计算的金额
 *		coins：硬币数组
 *	返回值：
 *		构成方式
 */
size_t  coin_made_ways(uint64_t amount,uint8_t *coins)
{
	size_t count;

	count=0;
	//我们把当前金额所有可能的组合按照最大币值的硬币数量从低到高进行排序，就可以用递归的方式来处理
	if(amount==0)
		return 1;
	else if(*coins==1)
		return 1;
	count+=coin_made_ways(amount,coins+1);	//相当于最大币值的硬币数量为0
	while(amount>=*coins)
	{
		amount-=*coins;		//逐渐消耗
		count+=coin_made_ways(amount,coins+1);
	}
	return count;
}
