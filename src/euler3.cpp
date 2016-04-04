/*
 *	程序名：euler3.cpp
 *	作者：陈源源
 *	日期：2014-11-20
 *	功能：解决eulerproject 3题(https://projecteuler.net/problem=3)
 */

#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main(int argc,char **argv)
{
	auto primes=get_primes(1000000);

	for(auto it=--primes.end();;it--)
	{
		if(600851475143%(*it)==0)
		{
			cout<<*it<<endl;
			break;
		}
	}
	return 0;
}