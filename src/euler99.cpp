/*
 *	程序名：euler99.c
 *	作者：陈源源
 *	日期：2016-03-09
 *	功能：解决eulerproject 99题(https://projecteuler.net/problem=99)
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cinttypes>
#include <my_math.h>

using namespace std;
using namespace my_math;

int main(int argc,char **argv)
{
	typedef struct
	{
		uint64_t base;
		uint64_t exp;
		uint64_t line_num;
	}p099_number;
	ifstream in_file("p099_base_exp.txt");
	vector<p099_number> numbers;
	p099_number number;
	uint64_t max_base;
	char sep;

	number.line_num=0;
	max_base=0;
	while(1)
	{
		if(!(in_file>>number.base))
			break;
		number.line_num++;
		in_file>>sep;
		in_file>>number.exp;
	}
	if(!in_file.eof())
	{
		cout<<"read file failed"<<endl;
		return -1;
	}
	return 0;
}

