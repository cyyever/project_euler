/*
 *	��������euler42.c
 *	���ߣ���ԴԴ
 *	���ڣ�2016-02-05
 *	���ܣ����eulerproject 42��(https://projecteuler.net/problem=42)
 */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>

int main(int argc,char **argv)
{
	FILE *p42;
	char *p;
	char word[128];
	uint64_t word_value,n,triangle_num;
	size_t count;

	p42=fopen("p042_words.txt","r");
	if(!p42)
	{
		printf("fopen failed:%m");
		return -1;
	}
	count=0;
	while(1)
	{
		fscanf(p42,"%[^,]",word);
		p=word+1;
		word_value=0;
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
		if(feof(p42))
			break;
		fscanf(p42,",");
	}
	fclose(p42);
	printf("%zu\n",count);
	return 0;
}
