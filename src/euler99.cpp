/*
 *	程序名：euler99.cpp
 *	作者：陈源源
 *	日期：2016-03-09
 *	功能：解决eulerproject 99题(https://projecteuler.net/problem=99)
 */
#include <iostream>
#include <fstream>
#include <cinttypes>
#include <my_math.h>

using namespace std;
using namespace my_math;

struct p099_number
{
	uint64_t base;
	uint64_t exp;
	my_rat log_base;
	uint64_t line_num;
}number,max_number;

uint64_t cur_line_num;
uint64_t cur_log_digit_num;
my_rat delta(1,1);

istream &operator >>(istream &is,p099_number &number);

int main(int argc,char **argv)
{
	ifstream in_file("p099_base_exp.txt");

	in_file>>max_number;
	while(1)
	{
		if(!(in_file>>number))
		{
			if(!in_file.eof())
			{
				cout<<"read file failed"<<endl;
				return -1;
			}
			break;
		}
		while(number.log_base*number.exp>max_number.log_base*max_number.exp)
		{
			if(number.log_base*number.exp>(max_number.log_base+delta)*max_number.exp)
			{
				cout<<"dsadsadsadsa"<<endl;
				max_number=number;
				break;
			}
			else
			{
				cur_log_digit_num++;
				number.log_base=log(number.base,2,cur_log_digit_num);
				max_number.log_base=log(max_number.base,2,cur_log_digit_num);
				delta/=10;
				cout<<"cur_log_digit_num="<<cur_log_digit_num<<endl;
				cout<<"max_number.base="<<max_number.base<<endl;
				cout<<"max_number.exp="<<max_number.exp<<endl;
				cout<<"number.base="<<number.base<<endl;
				cout<<"number.exp="<<number.exp<<endl;
			}
		}
		cur_log_digit_num=0;
	}
	cout<<max_number.line_num<<endl;
	return 0;
}

istream &operator >>(istream &is,p099_number &number)
{
	char sep;

	is>>number.base;
	is>>sep;
	is>>number.exp;
	number.log_base=log(number.base,2,cur_log_digit_num);
	cur_line_num++;
	number.line_num=cur_line_num;
	cout<<cur_line_num<<endl;
	return is;
}
