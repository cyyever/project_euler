/*
 *	程序名：euler15.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 15题(https://projecteuler.net/problem=15)
 */
#include <stdio.h>
#include <inttypes.h>


/*
 *	功能：获取指定grid由you左上角到右下角的路由数量
 *	参数：
 *		x：grid的水平方向格数
 *		y：grid的垂直方向格数
 *	返回值：
 *		路由数量
 */
uint64_t route_num_of_grid(uint64_t x,uint64_t y);

int main(int argc,char **argv)
{
	printf("%"PRIu64"\n",route_num_of_grid(20,20));
	return 0;
}

/*
 *	功能：获取指定grid由you左上角到右下角的路由数量
 *	参数：
 *		x：grid的水平方向格数
 *		y：grid的垂直方向格数
 *	返回值：
 *		路由数量
 */
uint64_t route_num_of_grid(uint64_t x,uint64_t y)
{
	uint64_t count;
	uint64_t i;

	//如果y为0，那么此时只能沿着一个方向走，那么路由数量为1
	//如果y为1，那么有x+1条路由使得y为0，那么路由数量为x+1
	//如果y为2，那么有x+1条路由使得y为1，同时x对应减少，使得总路由为x+1+...+1=(x+2)(x+1)/2
	//以此类推，根据二项式公式和数学归纳法可知，路由数为C(x+y,y)
	count=x+1;
	for(i=2;i<=y;i++)
	{
		count*=(x+i);
		count/=i;
	}
	return count;
}
