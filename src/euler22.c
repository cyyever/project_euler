/*
 *	��������euler22.c
 *	���ߣ���ԴԴ
 *	���ڣ�2016-02-11
 *	���ܣ����eulerproject 22��(https://projecteuler.net/problem=22)
 */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <unistd.h>

#define N	5163
static int cmpstringp(const void *p1, const void *p2);

int main(int argc,char **argv)
{
	FILE *p22;
	char *p;
	char name[128];
	char *names[N];
	size_t i;
	uint64_t score,total_score;

	p22=fopen("p022_names.txt","r");
	if(!p22)
	{
		printf("fopen failed:%m");
		return -1;
	}
	i=0;
	while(1)
	{
		fscanf(p22,"%[^,]",name);
		name[strlen(name)-1]='\0';
		names[i]=strdup(name+1);
		if(!names[i])
		{
			printf("strdup failed:%m");
			return -1;
		}
		i++;
		if(feof(p22))
			break;
		fscanf(p22,",");
	}
	fclose(p22);

	qsort(names,N,sizeof(char*),cmpstringp);
	total_score=0;
	for(i=1;i<=N;i++)
	{
		p=names[i-1];
		score=0;
		while(*p)
		{
			score+=*p-'A'+1;
			p++;
		}
		total_score+=i*score;
	}
	printf("%"PRIu64"\n",total_score);
	return 0;
}

/*
 *	���ܣ���man page���ƣ����ڱȽ��ַ���
 *	������
 *		p1��p2��ָ��Ҫ�Ƚϵ��ַ���
 *	����ֵ��
 *		�ο�man page
 */
static int cmpstringp(const void *p1, const void *p2)
{
	return strcmp(* (char * const *) p1, * (char * const *) p2);
}
