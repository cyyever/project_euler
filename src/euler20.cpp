/*
 *	程序名：euler20.cpp
 *	作者：陈源源
 *	日期：2014-11-17
 *	功能：解决eulerproject 20题(https://projecteuler.net/problem=20)
 */
#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main(int argc,char **argv)
{
	uint64_t digit_sum;
	string factorial_str=static_cast<string>(factorial(100));

	digit_sum=0;
	for(auto it=factorial_str.begin();it!=factorial_str.end();it++)
		digit_sum+=(*it)-'0';
	cout<<digit_sum<<endl;
	return 0;
}
