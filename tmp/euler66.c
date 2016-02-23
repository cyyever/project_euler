/*
 *	程序名：euler66.c
 *	作者：陈源源
 *	日期：2014-11-17
 *	功能：解决eulerproject 66题(https://projecteuler.net/problem=66)
 */
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_number_theory.h>
#include <string.h>

#define MAX_D			1000

static unsigned __int128 *squares;
static uint64_t min_square_root;

int main(int argc,char **argv)
{
	struct
	{
		uint64_t D;
		uint64_t max_prime_factor;
		uint64_t factor_of_prime_factor;
		uint64_t x;
		uint64_t y;
		size_t min_square_root;
	}*solutions;
	uint64_t *primes;
	size_t i,j,square_root,solution_num,max_square_root;
	uint64_t max_x;
	__int128 y_square;

	primes=my_primes(MAX_D);
	if(!primes)
	{
		puts("my_primes failed");
		return -1;
	}

	solutions=calloc(MAX_D,sizeof(*solutions));
	if(!solutions)
	{
		printf("calloc failed:%m");
		return -1;
	}

	squares=calloc(100000,sizeof(*squares));
	if(!squares)
	{
		printf("calloc failed:%m");
		return -1;
	}
	min_square_root=1;
	for(i=min_square_root;i<min_square_root+100000;i++)
		squares[i-min_square_root]=i*i;

	solution_num=0;
	square_root=0;
	for(i=1;i<=MAX_D;i++)
	{
		for(j=min_square_root;j<min_square_root+100000;j++)
		{
			if(squares[j-min_square_root]>=i)
				break;
		}
		if(squares[j-min_square_root]==i) //跳过平方
			continue;

		solutions[solution_num].D=i;
		//找出D的最大素因子
		for(j=0;primes[j];j++)
		{
			if(primes[j]>i)
				break;
		}
		j--;
		while(j>=0)
		{
			if(primes[j]==i || i%primes[j]==0)
				break;
			j--;
		}
		if(primes[j]==i)
			continue;
		solutions[solution_num].max_prime_factor=primes[j];
		if(i==2)
			solutions[solution_num].factor_of_prime_factor=1;
		else
			solutions[solution_num].factor_of_prime_factor=1;
	//	else
	//		solutions[solution_num].factor_of_prime_factor=solutions[solution_num].max_prime_factor;
		solutions[solution_num].y=1;
		solution_num++;
	}

	max_x=0;
	while(solution_num>1)
	{
		for(i=0;i<solution_num;i++)
		{
			if(solutions[i].D!=solutions[i].max_prime_factor && solutions[i].min_square_root!=100000)
				break;
		}
		if(i==solution_num)
		{
			min_square_root++;
			for(j=min_square_root;j<min_square_root+100000;j++)
				squares[j-min_square_root]=j*j;
			for(j=0;j<solution_num;j++)
				solutions[j].min_square_root=0;
			i=0;
		}

		//注意y^2=(x+1)(x-1)/D，那么x+1或者x-1是max_prime_factor的倍数，利用这点快速迭代x
		while(1)
		{

//			a(ad-1)=
//				a必须是平方数

		//			i(id-2)
	//		20(20*113-2)
	//
	//		i(id-2)

//			i(id+2)
//		id(id-2)
			//考虑x+1的情况，这边i是x+1的倍数
			solutions[i].x=solutions[i].factor_of_prime_factor*solutions[i].max_prime_factor-1;
		//	printf("solutions[solution_num].factor_of_prime_factor=%"PRIu64" x=%"PRIu64"\n",(uint64_t)(solutions[solution_num].factor_of_prime_factor),solutions[i].x);
			y_square=solutions[i].x*solutions[i].x-1;
			if(y_square!=0 && (solutions[i].max_prime_factor==solutions[i].D || y_square%solutions[i].D==0))
			{
				y_square/=solutions[i].D;
				if(y_square>squares[99999])
				{
					solutions[i].min_square_root=100000;
					break;
				}
				max_square_root=99999;
				while(solutions[i].min_square_root<=max_square_root)
				{
					square_root=(solutions[i].min_square_root+max_square_root)/2;
					if(squares[square_root]==y_square)
						break;
					else if(squares[square_root]<y_square)
						solutions[i].min_square_root=square_root+1;
					else
						max_square_root=square_root-1;
				}

				if(solutions[i].min_square_root<=max_square_root)
				{
					printf("--%"PRIu64"^2-%"PRIu64"*%"PRIu64"^2=1\n",(uint64_t)(solutions[i].x),(uint64_t)solutions[i].D,(uint64_t)square_root+min_square_root);
					printf("solutions[solution_num].factor_of_prime_factor=%"PRIu64"\n",(uint64_t)(solutions[i].factor_of_prime_factor));
					printf("solutions[solution_num].max_prime_factor=%"PRIu64"\n",(uint64_t)(solutions[i].max_prime_factor));
					if(solutions[i].x>max_x)
						max_x=solutions[i].x;
					memmove(solutions+i,solutions+i+1,(solution_num-i-1)*sizeof(*solutions));
					solution_num--;
					break;
				}
			}

			//考虑x-1的情况，这边i是x-1的倍数
			solutions[i].x+=2;
			y_square=solutions[i].x*solutions[i].x-1;
			if(solutions[i].max_prime_factor==solutions[i].D || y_square%solutions[i].D==0)
			{
				y_square/=solutions[i].D;
				if(y_square>squares[99999])
				{
					solutions[i].min_square_root=100000;
					break;
				}
				max_square_root=99999;
				while(solutions[i].min_square_root<=max_square_root)
				{
					square_root=(solutions[i].min_square_root+max_square_root)/2;
					if(squares[square_root]==y_square)
						break;
					else if(squares[square_root]<y_square)
						solutions[i].min_square_root=square_root+1;
					else
						max_square_root=square_root-1;
				}

				if(solutions[i].min_square_root<=max_square_root)
				{
					printf("%"PRIu64"^2-%"PRIu64"*%"PRIu64"^2=1\n",(uint64_t)(solutions[i].x),(uint64_t)solutions[i].D,(uint64_t)square_root+min_square_root);
					printf("solutions[solution_num].factor_of_prime_factor=%"PRIu64"\n",(uint64_t)(solutions[i].factor_of_prime_factor));
					if(solutions[i].x>max_x)
						max_x=solutions[i].x;
					memmove(solutions+i,solutions+i+1,(solution_num-i-1)*sizeof(*solutions));
					solution_num--;
					break;
				}
			}
			//如果D>2，那么由于y^2=factor_of_prime_factor*max_prime_factor(factor_of_prime_factor*max_prime_factor-2)或者factor_of_prime_factor*max_prime_factor(factor_of_prime_factor*max_prime_factor+2)				
			//那么factor_of_prime_factor必须是max_prime_factor的倍数，否则max_prime_factor找不到平方的可能
	//		if(solutions[i].D==2)
				solutions[i].factor_of_prime_factor++;
	//		else 
	//			solutions[i].factor_of_prime_factor+=solutions[i].max_prime_factor;
		}
	}

	printf("%"PRIu64"\n",solutions[0].D);
	return 0;
}
