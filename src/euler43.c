/*
 *	程序名：euler43.c
 *	作者：陈源源
 *	日期：2014-11-19
 *	功能：解决eulerproject 43题(https://projecteuler.net/problem=43)
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct
{
	uint8_t is_3_dividable;
	uint8_t is_7_dividable;
}num_attr;

int main(int argc,char **argv)
{
	int digit_stack[10];
	size_t i,num_mask;
	int tmp_num,flag,divisor;
	num_attr num_attrs[1000];
	char num_str[11];
	uint64_t sum;

	memset(num_attrs,0,sizeof(num_attrs));
	//初始化属性
	for(i=3;i<1000;i+=3)
		num_attrs[i].is_3_dividable=1;
	for(i=7;i<1000;i+=7)
		num_attrs[i].is_7_dividable=1;

	//初始化digit栈
	for(i=0;i<10;i++)
		digit_stack[i]=-1;

	/*
	 * d2d3d4=406 is divisible by 2
	 * d3d4d5=063 is divisible by 3
	 * d4d5d6=635 is divisible by 5
	 * d5d6d7=357 is divisible by 7
	 * d6d7d8=572 is divisible by 11
	 * d7d8d9=728 is divisible by 13
	 * d8d9d10=289 is divisible by 17
	 */
	i=0;
	num_mask=0;
	sum=0;
	while(1)
	{
		if(i==0)	//遍历d6
		{
			if(digit_stack[i]==-1)	//刚开始，为了让5整除，只能取0和5
				digit_stack[i]=0;
			else if(digit_stack[i]==0)	
			{
				num_mask&=~(1<<(digit_stack[i]));	//清除之前的位数
				digit_stack[i]=5;
			}
			else //全部可能性遍历完毕
				break;
			num_mask|=(1<<(digit_stack[i]));
			i++;
		}
		else if(i==1)	//遍历d7 d8 
		{
			divisor=11;
			if(digit_stack[i]==-1)	//刚开始
			{
				for(tmp_num=divisor;tmp_num<digit_stack[i-1]*100;tmp_num+=divisor)
					;
			}
			else	//继续上次的迭代
			{
				//清除之前的位数
				num_mask&=~(1<<(digit_stack[i]));
				num_mask&=~(1<<(digit_stack[i+1]));
				tmp_num=digit_stack[i-1]*100+digit_stack[i]*10+digit_stack[i+1]+divisor;
			}
			//确保d6d7d8可以被divisor整除，但是还要确保d7d8不出现
			flag=0;
			while(tmp_num<(digit_stack[i-1]+1)*100)
			{
				digit_stack[i]=(tmp_num/10)%10;
				digit_stack[i+1]=tmp_num%10;
				if(digit_stack[i]!=digit_stack[i+1]
				&& (num_mask&(1<<digit_stack[i]))==0 && (num_mask&(1<<digit_stack[i+1]))==0)
				{
					flag=1;
					break;
				}
				tmp_num+=divisor;
			}
			if(flag==0)	//遍历完毕
			{
				digit_stack[i]=-1;
				digit_stack[i+1]=-1;
				i--;
			}
			else
			{
				num_mask|=(1<<(digit_stack[i]));
				num_mask|=(1<<(digit_stack[i+1]));
				i+=2;
			}
		}
		else if(i==3)	//处理d9 d10 因为这边必须被>10的数整除，因此只有一个可能
		{
			divisor=13;
			if(digit_stack[i]!=-1)	
			{
				//清除之前的位数
				num_mask&=~(1<<(digit_stack[i]));
				num_mask&=~(1<<(digit_stack[i+1]));
				digit_stack[i]=-1;
				digit_stack[i+1]=-1;
				i-=2;
				continue;
			}

			//先确定d9
			for(tmp_num=divisor;tmp_num<digit_stack[i-2]*100+(digit_stack[i-1]+1)*10;tmp_num+=divisor)
				;
			tmp_num-=divisor;
			if(tmp_num<digit_stack[i-2]*100+digit_stack[i-1]*10)
			{
				i-=2;
				continue;
			}

			if((num_mask&(1<<(tmp_num%10)))!=0)
			{
				i-=2;
				continue;
			}

			digit_stack[i]=tmp_num%10;
			//再确定d10
			divisor=17;
			for(tmp_num=divisor;tmp_num<digit_stack[i-1]*100+(digit_stack[i]+1)*10;tmp_num+=divisor)
				;
			tmp_num-=divisor;
			if(tmp_num<digit_stack[i-1]*100+digit_stack[i]*10)
			{
				digit_stack[i]=-1;
				i-=2;
				continue;
			}
			digit_stack[i+1]=tmp_num%10;
			if(digit_stack[i]==digit_stack[i+1] || (num_mask&(1<<digit_stack[i+1]))!=0)
			{
				digit_stack[i]=-1;
				digit_stack[i+1]=-1;
				i-=2;
				continue;
			}
			num_mask|=(1<<(digit_stack[i]));
			num_mask|=(1<<(digit_stack[i+1]));
			i+=2;
		}
		else if(i==5) //遍历d5
		{
			if(digit_stack[i]==-1)	//刚开始
				tmp_num=0;
			else	//继续上次的迭代
			{
				//清除之前的位数
				num_mask&=~(1<<(digit_stack[i]));
				tmp_num=digit_stack[i]+1;
			}
			//确保d5d6d7可以被divisor整除，但是还要确保d5不出现
			flag=0;
			while(tmp_num<10)
			{
				if(num_attrs[tmp_num*100+digit_stack[0]*10+digit_stack[1]].is_7_dividable)
				{
					if((num_mask&(1<<(tmp_num)))==0)
					{
						flag=1;
						break;
					}
				}
				tmp_num++;
			}
			if(flag==0)	//遍历完毕
			{
				digit_stack[i]=-1;
				i-=2;
			}
			else
			{
				digit_stack[i]=tmp_num;
				num_mask|=(1<<(digit_stack[i]));
				i++;
			}
		}
		else if(i==6) //遍历d4
		{
			if(digit_stack[i]==-1)	//刚开始
				tmp_num=0;
			else	//继续上次的迭代
			{
				//清除之前的位数
				num_mask&=~(1<<(digit_stack[i]));
				tmp_num=digit_stack[i]+2;
			}
			//由于我们已经为d6选择了0和5，我们只需要保证d4为偶数且不重复
			flag=0;
			while(tmp_num<10)
			{
				if((num_mask&(1<<(tmp_num)))==0)
				{
					flag=1;
					break;
				}
				tmp_num+=2;
			}
			if(flag==0)	//遍历完毕
			{
				digit_stack[i]=-1;
				i--;
			}
			else
			{
				digit_stack[i]=tmp_num;
				num_mask|=(1<<(digit_stack[i]));
				i++;
			}
		}
		else if(i==7) //遍历d3
		{
			if(digit_stack[i]==-1)	//刚开始
				tmp_num=0;
			else	//继续上次的迭代
			{
				//清除之前的位数
				num_mask&=~(1<<(digit_stack[i]));
				tmp_num=digit_stack[i]+1;
			}
			//确保d3d4d5可以被divisor整除，但是还要确保d3不出现
			flag=0;
			while(tmp_num<10)
			{
				if(num_attrs[tmp_num*100+digit_stack[i-1]*10+digit_stack[i-2]].is_3_dividable)
				{
					if((num_mask&(1<<tmp_num))==0)
					{
						flag=1;
						break;
					}
				}
				tmp_num++;
			}
			if(flag==0)	//遍历完毕
			{
				digit_stack[i]=-1;
				i--;
			}
			else
			{
				digit_stack[i]=tmp_num;
				num_mask|=(1<<(digit_stack[i]));
				i++;
			}
		}
		else if(i==8) //遍历d2
		{
			if(digit_stack[i]==-1)	//刚开始
				tmp_num=0;
			else	//继续上次的迭代
			{
				//清除之前的位数
				num_mask&=~(1<<(digit_stack[i]));
				tmp_num=digit_stack[i]+1;
			}
			//我们只需要保证d2不重复
			flag=0;
			while(tmp_num<10)
			{
				if((num_mask&(1<<(tmp_num)))==0)
				{
					flag=1;
					break;
				}
				tmp_num+=1;
			}
			if(flag==0)	//遍历完毕
			{
				digit_stack[i]=-1;
				i--;
			}
			else
			{
				digit_stack[i]=tmp_num;
				num_mask|=(1<<(digit_stack[i]));
				i++;
			}
		}
		else if(i==9) //遍历d1
		{
			for(tmp_num=0;tmp_num<10;tmp_num++)
			{
				if((num_mask&(1<<(tmp_num)))==0)
					break;
			}
			
			digit_stack[i]=tmp_num;
		//	printf("%d%d%d%d%d%d%d%d%d%d\n",digit_stack[9],digit_stack[8],digit_stack[7],digit_stack[6],digit_stack[5],digit_stack[0],digit_stack[1],digit_stack[2],digit_stack[3],digit_stack[4]);	
			sprintf(num_str,"%d%d%d%d%d%d%d%d%d%d",digit_stack[9],digit_stack[8],digit_stack[7],digit_stack[6],digit_stack[5],digit_stack[0],digit_stack[1],digit_stack[2],digit_stack[3],digit_stack[4]);	
			sum+=strtoul(num_str,NULL,10);
			i--;
		}
	}
	printf("%"PRIu64"\n",sum);
	return 0;
}
