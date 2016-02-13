/*
 *	程序名：euler78.c
 *	作者：陈源源
 *	日期：2015-09-18
 *	功能：解决eulerproject 78题(https://projecteuler.net/problem=78)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <my_arithmetic.h>

#define N 10

int main(int argc,char **argv)
{
	size_t i,j;
static	struct
	{
		struct sum_num_s {
			union{
			uint64_t small_sum_num;
			my_rat *large_sum_num;	
			}sum_num;
			uint8_t type;
			struct sum_num_s *next;
		}*sum_num; //大于等于该数起始的和的数量
	}*ways;
	struct sum_num_s *p,*q,**tmp_buf;
	uint32_t remainder;

	ways=calloc(N+1,sizeof(*ways));
	if(!ways)
	{
		printf("calloc failed:%m\n");
		return -1;
	}

	size_t alloc_cnt=0;
	for(i=2;i<=N;i++)
	{
		for(j=1,p=ways[i].sum_num;j<=i-j;j++)
		{
			q=ways[i-j].sum_num;
			if(q)
			{
				ways[i-j].sum_num=q->next;
				q->next=NULL;
		//		printf("fetch node i=%d j=%d \n",(int)i,(int)j);
			}
			else
			{
				q=calloc(1,sizeof(*q));
				if(!q)
				{
					printf("calloc failed:%m\n");
					return -1;
				}
				q->sum_num.small_sum_num=1;
			}
			if(!p)
				ways[i].sum_num=q;
			else
				p->next=q;
			p=q;
			alloc_cnt++;
		}
		for(;j<i && ways[i-j].sum_num;j++)
		{
			while(ways[i-j].sum_num)
			{
				q=ways[i-j].sum_num;
				ways[i-j].sum_num=q->next;
				free(q);
				alloc_cnt--;
			}
		}
		if(i==20)
		{
			for(j=0;j<i;j++)
			{
				if(ways[j].sum_num)
				{
					printf("还有 j=%d",(int)j);
					break;
				}
			}
		}
		printf("alloc cnt=%zu \n",alloc_cnt);

		tmp_buf=malloc((i/2)*sizeof(*tmp_buf));
		if(!tmp_buf)
		{
			printf("malloc failed:%m");
			return -1;
		}
		for(j=0,p=ways[i].sum_num;p;p=p->next,j++)
			tmp_buf[j]=p;
		j--;
		p=tmp_buf[j];
		p->sum_num.small_sum_num+=1;
		while(j>=1)
		{
			j--;
			p=tmp_buf[j];

			my_rat *tmp;
			if(p->type==0 && p->next->type==0)
			{
				if(p->sum_num.small_sum_num+p->next->sum_num.small_sum_num<=INT64_MAX)
				{
					p->sum_num.small_sum_num+=p->next->sum_num.small_sum_num;
					continue;
				}
			}

			if(p->next->type==1)
				tmp=p->next->sum_num.large_sum_num;
			else
			{
				tmp=my_rat_from_int64(NULL,p->next->sum_num.small_sum_num);
				if(!tmp)
				{
					puts("my_rat_from_int64 failed");
					return -1;
				}
			}

			if(p->type==0)
			{
				p->sum_num.large_sum_num=my_rat_from_int64(NULL,p->sum_num.small_sum_num);
				if(!p->sum_num.large_sum_num)
				{
					puts("my_rat_from_int64 failed");
					return -1;
				}
				p->type=1;
			}

			if(my_rats_add(p->sum_num.large_sum_num,tmp,MY_ARG_RES)==NULL)
			{
				puts("my_rats_add failed");
				return -1;
			}
			if(p->next->type==0)
				my_rat_free(tmp);
		}
		free(tmp_buf);

		for(j=1,p=ways[i].sum_num;p;p=p->next,j++)
		{
			if(p->type==1)
			{
				char *str;
				str=my_rat_to_str(p->sum_num.large_sum_num);
				printf("i=%zu  j=%zu  %s\n",i,j,str);
				free(str);
			}
			else
				printf("i=%zu j=%zu %"PRIu64"\n",i,j,(p->sum_num.small_sum_num));
	//		break;
		}
		if(ways[i].sum_num->type==1)
		{
			if(my_mod_uint32(ways[i].sum_num->sum_num.large_sum_num,1000000,&remainder)!=MY_SUCC)
			{
				puts("my_mod_uint32 failed");
				return -1;
			}
		}
		else
			remainder=ways[i].sum_num->sum_num.small_sum_num%1000000;
		if(remainder==0)
		{
			printf("%zu\n",i);
			break;
		}
	}
	return 0;
}
