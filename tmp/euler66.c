/*
 *	程序名：euler66.c
 *	作者：陈源源
 *	日期：2014-11-17
 *	功能：解决eulerproject 66题(https://projecteuler.net/problem=66)
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define MAX_D			80
#define MAX_SQUARE_ROOT 	9999999

uint8_t prime_nums[MAX_D+1];
unsigned __int128 squares[MAX_D+1];

int main(int argc,char **argv)
{
	uint8_t find_flag;
	unsigned __int128 D,x,y,y_square,i,next_D_square_root;

	//首先初始化平方数组
	for(x=1;x<=MAX_D;x++)
		squares[x]=x*x;

	//接下来我们找出1000以内的质数
	for(D=2;D<=MAX_D/2;D++)
	{
		if(prime_nums[D]!=0)
			continue;
		for(x=D+D;x<=MAX_D;x+=D)
			prime_nums[x]=1;
	}

	next_D_square_root=2;
	for(D=2;D<=MAX_D;D++)
	{
		//如果D是平方，肯定无解，跳过去
		if(D==squares[next_D_square_root])
		{
			next_D_square_root++;
			continue;
		}

		if(D==109)
			continue;

		//否则的话一定存在，剩下的只是时间问题
		find_flag=0;
		y=1;

		//如果D是质数，注意y^2=(x+1)(x-1)/D，那么x+1或者x-1是D的必须是D的倍数，利用这点快速迭代x
		if(prime_nums[D]==0)	
		{
			for(i=1;i;i++)
			{
				//考虑x+1的情况，这边i是x+1的倍数
				y_square=(i*D-2)*i;
				while(y)
				{
					if(y*y==y_square)
					{
						find_flag=1;
						break;
					}
					else if(y*y>y_square)
						break;
					else 
						y++;
				}
				if(find_flag)
				{
					printf("++i=%"PRIu64"\n",(uint64_t)i);
					printf("++%"PRIu64"^2-%"PRIu64"*%"PRIu64"^2=1\n",(uint64_t)(i*D-1),(uint64_t)D,(uint64_t)y);
				if(i*D!=(uint64_t)(i*D))
						puts("截断x");
				if(y!=(uint64_t)y)
						puts("截断y");
					break;
				}
				//考虑x-1的情况，这边i是x-1的倍数
				y_square+=4*i;
				while(y)
				{
					if(y*y==y_square)
					{
						find_flag=1;
						break;
					}
					else if(y*y>y_square)
						break;
					else 
						y++;
				}
				if(find_flag)
				{
					printf("--%"PRIu64"^2-%"PRIu64"*%"PRIu64"^2=1\n",(uint64_t)(i*D+1),(uint64_t)D,(uint64_t)y);
					break;
				}
				else
					y--;
			}
		}
		else
		{
			for(x=2;x;x++)
			{
				if((x*x-1)%D!=0)
					continue;
				y_square=(x*x-1)/D;
				while(y)
				{
					if(y*y==y_square)
					{
						find_flag=1;
						break;
					}
					else if(y*y>y_square)
						break;
					else 
						y++;
				}
				if(find_flag)
					break;
			}

			if(find_flag)
			{
				if(x!=(uint64_t)x)
						puts("截断x");
				if(y!=(uint64_t)y)
						puts("截断y");
				printf("%"PRIu64"^2-%"PRIu64"*%"PRIu64"^2=1\n",(uint64_t)x,(uint64_t)D,(uint64_t)y);
			}
		}

		if(!find_flag)
			printf("can't find solution for D %"PRIu64,(uint64_t)D);
	}
	return 0;
}
