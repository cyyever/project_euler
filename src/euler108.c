/*
 *	程序名：euler108.c
 *	作者：陈源源
 *	日期：2015-04-20
 *	功能：解决eulerproject 108题(https://projecteuler.net/problem=108)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define N 2000000
static struct
{
	uint8_t is_prime;
	uint64_t power;
}
*prime_attrs;

static void distribute_prime_powers(uint64_t min_divisor_num);

int main(int argc,char **argv)
{
	size_t i,j;
	uint64_t n;

	prime_attrs=calloc(N+1,sizeof(*prime_attrs));
	if(!prime_attrs)
	{
		printf("calloc failed:%m\n");
		return -1;
	}

	//标识质数
	for(i=2;i<=N;i++)
		prime_attrs[i].is_prime=1;
	for(i=2;i<=N;i++)
	{
		if(prime_attrs[i].is_prime)
		{
			for(j=i*2;j<=N;j+=i)
				prime_attrs[j].is_prime=0;
		}
	}

	//对于每个n，它的除数的数量就是不同解的数量，因此这题的实质是找出除数数量超过1000的最小数字
	//考虑到每个数字都能唯一地分解成质数的指数的乘积，我们可以用构造法来找到这个数字
	//以下我们用动态规划来处理
	distribute_prime_powers(1000);
	n=1;
	for(i=2;i<=N;i++)
	{
		if(prime_attrs[i].is_prime)
		{
			if(prime_attrs[i].power==0)
				break;
			for(j=0;j<prime_attrs[i].power;j++)
				n*=i;
			printf("i=%d power=%d \n",(int)i,(int)prime_attrs[i].power);
		}
	}
	printf("%"PRIu64"\n",n);
	free(prime_attrs);
	return 0;
}

/*
 *	功能：获取指定质数的下一个质数
 *	参数：
 *		prime：质数
 *	返回值：
 *		下一个质数
 */
static uint64_t get_next_prime(uint64_t prime)
{
	uint64_t i;

	for(i=prime+1;i<=N;i++)
	{
		if(prime_attrs[i].is_prime)
			return i;
	}
	puts("can't find next prime");
	exit(EXIT_FAILURE);
}

/*
 *	功能：通过调整质数的指数分布找出除数数量超过指定数量的最小数字
 *	参数：
 *		min_divisor_num：必须大于这个除数数量
 *	返回值：
 *		无
 */
static void distribute_prime_powers(uint64_t min_divisor_num)
{
	uint64_t prime,next_prime,prime_power,next_prime_power;
	uint64_t new_prime_powr;
	uint64_t i,tmp,flag;

	prime_attrs[2].power=min_divisor_num;
	
	//不断地平摊指数
	while(1)
	{
		prime=2;
		flag=0;
		while(1)
		{
			printf("%d\n",(int)prime);
			prime_power=prime_attrs[prime].power;
			next_prime=get_next_prime(prime);
			next_prime_power=prime_attrs[next_prime].power;
			printf("before %d=%d %d=%d\n",(int)prime,(int)prime_power,(int)next_prime,(int)next_prime_power);

			//为了使得数字最小，我们尝试分摊一些指数到下一个质数，以此找到一个平衡点
			while(1)
			{
				next_prime_power++;
				tmp=next_prime_power+1;
				for(i=2;i<=N;i++)
				{
					if(prime_attrs[i].is_prime && i!=next_prime && i!=prime)
					{
						if(prime_attrs[i].power==0)
							break;
						tmp*=(prime_attrs[i].power+1);
						printf("i=%d tmp=%d \n",(int)i,(int)tmp);
					}
				}

				if((min_divisor_num+1)%tmp==0)
					new_prime_powr=(min_divisor_num+1)/tmp-1;
				else
					new_prime_powr=(min_divisor_num+1)/tmp;

				//如果min_prime的减少量超过next_min_prime的增量，那值得分摊指数
				tmp=1;
				for(i=0;i<prime_power-new_prime_powr;i++)
				{
					tmp*=prime;
					if(tmp>next_prime)
						break;
				}

				if(tmp<next_prime)	//没收益，达到了平衡点
				{
					next_prime_power--;
					break;
				}
				flag=1;
				prime_power=new_prime_powr;
			}
			printf("after %d=%d %d=%d\n",(int)prime,(int)prime_power,(int)next_prime,(int)next_prime_power);
			prime_attrs[prime].power=prime_power;
			prime_attrs[next_prime].power=next_prime_power;
			if(next_prime_power==0)
				break;
			prime=next_prime;
		}

		if(flag==0)
			break;
	}
	return;
}

