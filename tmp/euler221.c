/*
 *	程序名：euler221.c
 *	作者：陈源源
 *	日期：2016-03-13
 *	功能：解决eulerproject 221题(https://projecteuler.net/problem=221)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

int main(int argc,char **argv)
{
	unsigned __int128 p,alexandrian;
	unsigned __int128 max_type_1_p,max_type_1_alexandrian;
	unsigned __int128 next_type_2_p,max_type_2_alexandrian,next_type_2_alexandrian;
	size_t i;
	char alexandrian_str[128];

		unsigned __int128 a;

		for(a=1;;a++)
		{
			max_type_1_alexandrian=a*(a+1);
			max_type_1_alexandrian=max_type_1_alexandrian*(max_type_1_alexandrian+1);
			if(max_type_1_alexandrian==772168278)
				printf("%"PRIu64"\na=%d",(uint64_t)max_type_1_alexandrian,(int)a);
			if(max_type_1_alexandrian>772168278)
				break;
		}
		for(a=3;;a+=2)
		{
			max_type_1_alexandrian=a*(a+2);
			max_type_1_alexandrian=max_type_1_alexandrian*((max_type_1_alexandrian+1)/2);
			if(max_type_1_alexandrian==772168278)
				printf("%"PRIu64"\n",(uint64_t)max_type_1_alexandrian);
			if(max_type_1_alexandrian>772168278)
				break;
		}
		return 1;
//	for(a=1;a<=1000;a++)
	//	a=10000 ;
	{
	//我们先算出生成a Alexandrian integer的p
	//p-1+(p-1)/2-1+1
	p=a*2/3+1;
	//为了避免舍入错误，我们再算算
	while((p-1)*3/2>a)
		p--;

	max_type_1_p=p;
	if(p%2==0)
		next_type_2_p=p+1;
	else
	{
		if((p-1)*3/2==a)
			next_type_2_p=p;
		else
			next_type_2_p=p+2;
	}
	max_type_2_alexandrian=0;
	//用下一个第二类型的Alexandrian integer不断去填充
	while(1)
	{
		next_type_2_alexandrian=next_type_2_p*(next_type_2_p+2);
		next_type_2_alexandrian=next_type_2_alexandrian*((next_type_2_alexandrian+1)/2);
		max_type_1_alexandrian=max_type_1_p*(max_type_1_p+1);
		max_type_1_alexandrian=max_type_1_alexandrian*(max_type_1_alexandrian+1);
		if(next_type_2_alexandrian>max_type_1_alexandrian)
		{
		printf("max_type_1_p=%"PRIu64"\n",(uint64_t)max_type_1_p);

			break;
		}
		max_type_1_p--;
		max_type_2_alexandrian=next_type_2_alexandrian;
		next_type_2_p+=2;
	}



	if(max_type_2_alexandrian>max_type_1_alexandrian)
	{
		puts("ccccccccc");
		alexandrian=max_type_2_alexandrian;
	}
	else
		alexandrian=max_type_1_alexandrian;

	memset(alexandrian_str,'\0',sizeof(alexandrian_str));
	i=126;
	while(alexandrian)
	{
		alexandrian_str[i]='0'+alexandrian%10;
		i--;
		alexandrian/=10;
	}
	printf("a=%d %s\n",(int)a,alexandrian_str+i+1);
	}
	return 0;
}
