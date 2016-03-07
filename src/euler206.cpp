/*
 *	��������euler206.cpp
 *	���ߣ���ԴԴ
 *	���ڣ�2016-03-06
 *	���ܣ����eulerproject 206��(https://projecteuler.net/problem=206)
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
	for(auto part_root=begin(root);part_root!=end(root);part_root++)
	{
	cout<<*part_root<<endl;
	}
	return 0;
	if(root.size()!=1)
	{
		cout<<"get_root_of_square_form failed";
		return -1;
	}

	//cout<<root[0]<<endl;
	return 0;
}

/*
 *	���ܣ���ȡƽ������ģʽ��������
 *	������
 *		digit��ƽ����������digit_(digit+1)_(digit+2)...._0
 *	����ֵ��
 *		������������������vector�������ǿ�
 */
vector<uint64_t> get_root_of_square_form(uint8_t digit)
{
	uint64_t base,mod,pre_sum,number;
	ssize_t i,j;
	uint8_t digit2;
	vector<uint64_t> roots,part_roots;
	char square_str[50];

	mod=1000;
	for(i=8;i>=digit;i--)
		mod*=100;

	if(digit==9)
		part_roots.push_back(0);
	else
	{
		part_roots=get_root_of_square_form(digit+1);
		if(part_roots.size()==0)
			return roots;
	}

	for(auto part_root=begin(part_roots);part_root!=end(part_roots);part_root++)
	{
		base=1;
		while(base<=*part_root)
			base*=10;

		pre_sum=0;
		while(1)
		{
			number=(pre_sum+*part_root);
			pre_sum+=base;
			if(number>mod)
				break;
			//��ôҲ���ܳ���Sqrt[1929394959697989990]
			if(number>1389026623)
				break;
			sprintf(square_str,"%" PRIu64,number*number);
			digit2=0;
			for(j=strlen(square_str)-1;j>=0;j-=2)
			{
				if(square_str[j]!=('0'+digit2))
				{
					j=-1;
					break;
				}
				if(digit2==0)
					digit2=9;
				else
				{
					if(digit2==digit)
						break;
					digit2--;
				}
			}
			if(j<0)
				continue;
			
			if(find(roots.begin(),roots.end(),number)==roots.end())
				roots.push_back(number);
		}
	}
	return roots;
}
