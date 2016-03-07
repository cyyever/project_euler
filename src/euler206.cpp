/*
 *	程序名：euler206.cpp
 *	作者：陈源源
 *	日期：2016-03-06
 *	功能：解决eulerproject 206题(https://projecteuler.net/problem=206)
 */
#include <iostream>
#include <vector>
#include <inttypes.h>
#include <algorithm>
#include <string.h>

using namespace std;

static vector<uint64_t> get_root_of_square_form(uint8_t digit);

int main(int argc,char **argv)
{
	vector<uint64_t> root;

	root=get_root_of_square_form(1);
	if(root.size()!=1)
	{
		cout<<"get_root_of_square_form failed";
		return -1;
	}

	cout<<root[0]<<endl;
	return 0;
}

/*
 *	功能：获取平方满足模式的正整数的模
 *	参数：
 *		digit：平方必须满足digit_(digit+1)_(digit+2)...._0
 *	返回值：
 *		满足条件的正整数的模的vector，可能是空
 */
vector<uint64_t> get_root_of_square_form(uint8_t digit)
{
	uint64_t base,digit_power,mod,pre_sum,number;
	size_t i;
	vector<uint64_t> roots,part_roots;

	mod=1000;
	for(i=8;i>=digit;i--)
		mod*=100;
	base=mod/100;
	digit_power=base*10;

	//我们先获取平方满足(digit+1)_(digit+2)...._0的数
	if(digit==9)
		part_roots={10,20,30,40,50,60,70,80,90};
	else
		part_roots=get_root_of_square_form(digit+1);

	for(auto part_root=begin(part_roots);part_root!=end(part_roots);part_root++)
	{
		//尝试在它前面加上位数
		for(pre_sum=0;;pre_sum+=base)
		{
			if(pre_sum>=mod)
				break;
			number=pre_sum+*part_root;
			//怎么也不能超过Sqrt[1929394959697989990]
			if(number>1389026623)
				break;
			if((number*number%mod)/digit_power==digit)
			{
				if(find(roots.begin(),roots.end(),number)==roots.end())
					roots.push_back(number);
			}
		}
	}
	return roots;
}
