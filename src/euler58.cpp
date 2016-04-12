/*
 *	程序名：euler58.cpp
 *	作者：陈源源
 *	日期：2016-03-06
 *	功能：解决eulerproject 58题(https://projecteuler.net/problem=58)
 */
#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main(int argc,char **argv)
{
	uint64_t layer_num,side_length;
	size_t prime_cnt,num,i,num_cnt;

	prime_cnt=0;
	for(layer_num=2,side_length=3,num_cnt=5;;layer_num++,side_length+=2,num_cnt+=4)
	{
		num=side_length*side_length;
		for(i=0;i<3;i++)
		{
			num-=(side_length-1);
			if(is_prime(num))
				prime_cnt++;
		}
		if(prime_cnt*10<num_cnt)
			break;
	}
	cout<<side_length<<endl;
	return -1;
}
