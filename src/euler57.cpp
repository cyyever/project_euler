/*
 *	程序名：euler57.cpp
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 57题(https://projecteuler.net/problem=57)
 */
#include <iostream>
#include <my_math.h>

using namespace my_math;
using namespace std;

int main(int argc,char **argv)
{
	my_rat root;
	size_t i,count;

	//1 + 1/2 = 3/2
	root=my_rat(3,2);
	count=0;
	for(i=2;i<=1000;i++)
	{
		//√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...
		//我们迭代到下一个值
		root+=1;
		root=1/root;
		root+=1;
		if(root.numerator().digit_num()>root.denominator().digit_num())
			count++;
	}

	cout<<count<<endl;
	return 0;
}
