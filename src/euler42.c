/*
 *	程序名：euler42.c
 *	作者：陈源源
 *	日期：2016-02-05
 *	功能：解决eulerproject 42题(https://projecteuler.net/problem=42)
 */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc,char **argv)
{
	FILE *p42;
	struct stat buf;
	char *words,*p;
	int word_value,n,triangle_num;
	size_t count;

	if(stat("p042_words.txt",&buf)!=0)
	{
		printf("stat failed:%m");
		return -1;
	}
	words=malloc(buf.st_size+1);
	if(!words)
	{
		printf("malloc failed:%m");
		return -1;
	}
	p42=fopen("p042_words.txt","r");
	if(!p42)
	{
		printf("fopen failed:%m");
		return -1;
	}
	fgets(words,buf.st_size+1,p42);
	p=words;
	count=0;
	while(1)
	{
		p=strchr(p,'"');
		if(!p)
			break;
		word_value=0;
		p++;
		while(*p!='"')
		{
			word_value+=*p-'A'+1;
			p++;
		}
		for(n=1;;n++)
		{
			triangle_num=n*(n+1)/2;
			if(triangle_num==word_value)
				count++;
			else if(triangle_num>word_value)
				break;
		}
		p++;
	}
	printf("%zu\n",count);
	return 0;
}
