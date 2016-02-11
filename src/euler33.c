/*
 *	程序名：euler33.c
 *	作者：陈源源
 *	日期：2015-07-17
 *	功能：解决eulerproject 33题(https://projecteuler.net/problem=33)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <my_number_theory.h>

typedef struct
{
	uint32_t numerator;
	uint32_t denominator;
}fraction;

static fraction simplify_fraction(fraction f);

int main(int argc,char **argv)
{
	uint32_t i,j;
	uint32_t a,b,c,d;
	fraction f1,f2,f3;

	f3.numerator=1;
	f3.denominator=1;
	i=99;
	a=9;
	b=9;
	while(i>=11)
	{
		j=i-1;
		c=j/10;
		d=j%10;
		while(j>=10)
		{
			f1.numerator=j;
			f1.denominator=i;
			if(a==c)
			{
				f2.numerator=d;
				f2.denominator=b;
			}
			else if(a==d)
			{
				f2.numerator=c;
				f2.denominator=b;
			}
			else if(b==c)
			{
				f2.numerator=d;
				f2.denominator=a;
			}
			else if(b==d)
			{
				f2.numerator=c;
				f2.denominator=a;
			}
			else
				goto end;
			f1=simplify_fraction(f1);
			f2=simplify_fraction(f2);
			if(memcmp(&f1,&f2,sizeof(f1))==0)
			{
				f3.numerator*=f1.numerator;
				f3.denominator*=f1.denominator;
			}

end:
			j--;
			if(d==1)
			{
				c--;
				d=9;
				j--;
			}
			else
				d--;
		}

		i--;
		if(b==1)
		{
			a--;
			b=9;
			i--;
		}
		else
			b--;

	}

	f3=simplify_fraction(f3);
	printf("%"PRIu32"\n",f3.denominator);
	return 0;
}

/*
 *	功能：简化分数
 *	参数：
 *		f：要简化的分数
 *	返回值：
 *		简化后的分数
 */
static fraction simplify_fraction(fraction f)
{
	static uint64_t *primes;
	size_t i;

	//找出100以内质数
	primes=my_primes(100);
	if(!primes)
	{
		puts("my_primes failed");
		exit(EXIT_FAILURE);
	}
	for(i=0;primes[i];i++)
	{
		while(f.numerator%primes[i]==0 && f.denominator%primes[i]==0)
		{
			f.numerator/=primes[i];
			f.denominator/=primes[i];
		}
	}
	return f;
}
