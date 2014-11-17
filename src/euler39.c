/*
 *	程序名：euler39.c
 *	作者：陈源源
 *	日期：2014-11-17
 *	功能：解决eulerproject 39题(https://projecteuler.net/problem=39)
 */

#include <stdio.h>
#include <inttypes.h>

/*
 *	功能：获取指定周长下的直角三角形数量
 *	参数：
 *		perimeter：周长
 *	返回值：
 *		直角三角形数量
 */
size_t find_triangle(uint64_t perimeter);

int main(int argc,char **argv)
{
	size_t find,max_find;
	uint64_t i,the_perimeter;

	max_find=0;
	for(i=1;i<=1000;i++)
	{
		find=find_triangle(i);
		if(find>max_find)
		{
			max_find=find;
			the_perimeter=i;
		}
	}
	printf("%zu",the_perimeter);
	return 0;
}


/*
 *	功能：获取指定周长下的直角三角形数量
 *	参数：
 *		perimeter：周长
 *	返回值：
 *		直角三角形数量
 */
size_t find_triangle(uint64_t perimeter)
{
	uint64_t a,b,c,sum_b_c,a_square,distance_c_b;
	size_t count;

	count=0;

	//我们对满足条件的所有直角三角形按照直角边的长度排序，从最短的直角边开始遍历，满足a<=b<=c，所以a+b+c=perimeter>=3a
	for(a=perimeter/3;a>=1;a--)	
	{
		a_square=a*a;
		sum_b_c=perimeter-a;
		//(c-b)(c+b)=a*a
		//c-b=a_square/sum_b_c;
		//c+b=sum_b_c;
		//c=(a_square/sum_b_c+sum_b_c)/2
		//b=(sum_b_c-a_square/sum_b_c)/2

		if(a_square<sum_b_c)
			break;
		if(a_square%sum_b_c!=0)
			continue;
		distance_c_b=a_square/sum_b_c;
		b=sum_b_c-distance_c_b;
		if(b&1)
			continue;
		b>>=1;
		if(a>b)
			continue;
		c=(distance_c_b+sum_b_c)>>1;
		printf("a=%"PRIu64" b=%"PRIu64" c=%"PRIu64"\n",a,b,c);
		count++;
	}
	return count;
}
