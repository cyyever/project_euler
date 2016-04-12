/*
 *	程序名：euler56.cpp
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 56题(https://projecteuler.net/problem=56)
 */

#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main(int argc,char **argv)
{
	uint64_t a,b,digit_sum,max_digit_sum;
	my_int power_int;
	string power_str;

	max_digit_sum=0;
	for(a=2;a<100;a++)
	{
		for(b=2,power_int=power(a,b);b<100;b++,power_int*=a)
		{
			digit_sum=0;
			power_str=static_cast<string>(power_int);
			for(auto it=power_str.begin();it!=power_str.end();it++)
				digit_sum+=(*it)-'0';
			if(digit_sum>max_digit_sum)
				max_digit_sum=digit_sum;
		}
	}
	cout<<max_digit_sum<<endl;
	return 0;
}
