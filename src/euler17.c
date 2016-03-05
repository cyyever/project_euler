/*
 *	程序名：euler17.c
 *	作者：陈源源
 *	日期：2017-03-05
 *	功能：解决eulerproject 17题(https://projecteuler.net/problem=17)
 */

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

static const char * get_number_word(uint64_t num);

int main(int argc,char **argv)
{
	uint64_t num;
	const char *word,*p;
	size_t letter_cnt;

	letter_cnt=0;
	for(num=1;num<=1000;num++)
	{
		word=get_number_word(num);
		p=word;
		while(*p)
		{
			if(*p!=' ')
				letter_cnt++;
			p++;
		}
	}
	printf("%zu\n",letter_cnt);
	return 0;
}

/*
 *	功能：获取1到1000对应的英文
 *	参数：
 *		num：数字
 *	返回值：
 *		对应的英文
 */
static const char * get_number_word(uint64_t num)
{
	static char *words_0_20[]={"zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	static char *words_10_multiple[]={"zero","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety","hundred"};
	static char word[128];
	char *p;

	if(num==0 || num>1000)
		return NULL;

	if(num==1000)
		return "one thousand";
	strcpy(word,"");
	p=word;
	if(num>=100)
	{
		p+=sprintf(p,"%s %s",words_0_20[num/100],words_10_multiple[10]);
		num%=100;
		if(num!=0)
			p+=sprintf(p," and ");
		else
			return word;
	}
	if(num<=19)
	{
		p+=sprintf(p,"%s",words_0_20[num]);
		return word;
	}
	p+=sprintf(p,"%s",words_10_multiple[num/10]);
	num%=10;
	if(num>0)
		p+=sprintf(p," %s",words_0_20[num]);
	return word;
}
