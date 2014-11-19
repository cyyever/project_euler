/*
 *	��������euler31.c
 *	���ߣ���ԴԴ
 *	���ڣ�2014-11-19
 *	���ܣ����eulerproject 31��(https://projecteuler.net/problem=31)
 */
#include <stdio.h>
#include <inttypes.h>

/*
 *	���ܣ���ȡָ�����Ĺ��ɷ�ʽ
 *	������
 *		amount��������Ľ��
 *		coins��Ӳ������
 *	����ֵ��
 *		���ɷ�ʽ
 */
size_t  coin_made_ways(uint64_t amount,uint8_t *coins);

int main(int argc,char **argv)
{
	//Ӳ��
	uint8_t coins[]={200,100,50,20,10,5,2,1};

	printf("%zu\n",coin_made_ways(200,coins));
	return 0;
}

/*
 *	���ܣ���ȡָ�����Ĺ��ɷ�ʽ
 *	������
 *		amount��������Ľ��
 *		coins��Ӳ������
 *	����ֵ��
 *		���ɷ�ʽ
 */
size_t  coin_made_ways(uint64_t amount,uint8_t *coins)
{
	size_t count;

	count=0;
	//���ǰѵ�ǰ������п��ܵ���ϰ�������ֵ��Ӳ�������ӵ͵��߽������򣬾Ϳ����õݹ�ķ�ʽ������
	if(amount==0)
		return 1;
	else if(*coins==1)
		return 1;
	count+=coin_made_ways(amount,coins+1);	//�൱������ֵ��Ӳ������Ϊ0
	while(amount>=*coins)
	{
		amount-=*coins;		//������
		count+=coin_made_ways(amount,coins+1);
	}
	return count;
}
