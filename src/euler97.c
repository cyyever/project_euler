/*
 *	程序名：euler97.c
 *	作者：陈源源
 *	日期：2014-11-17
 *	功能：解决eulerproject 97题(https://projecteuler.net/problem=97)
 */
#include <stdio.h>
#include <inttypes.h>

int main(int argc,char **argv)
{
	unsigned __int128 total_power,power_of_2,cur_res;

	//先计算2^7830457的后10位
	//由于7830457的二进制表示为b[n]b[n-1]b[n-2]..b0
	//所以2^7830457=2^b[n]*2^b[n-1]*..*2^b0
	//而我们能快速算出2^0到2^b[n]
	
	cur_res=1;
	total_power=7830457;
	power_of_2=2;
	while(total_power)
	{
		if(total_power&1)
		{
			cur_res*=power_of_2;
			if(cur_res>10000000000)
				cur_res%=10000000000;
		}
		total_power>>=1;
		power_of_2*=power_of_2;
		if(power_of_2>10000000000)
			power_of_2%=10000000000;
	}
	//接下来十分简单。。
	cur_res=(cur_res*28433+1)%10000000000;

	printf("%"PRIu64"\n",(uint64_t)cur_res);
	return 0;
}

