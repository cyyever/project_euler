/*
 *	程序名：euler97.c
 *	作者：陈源源
 *	日期：2014-11-17
 *	功能：解决eulerproject 97题(https://projecteuler.net/problem=97)
 */
int main(int argc,char **argv)
{
	size_t i;
	my_rat *a;

	a=my_rat_from_int64(NULL,1);
	if(!a)
	{
		puts("my_rat_from_int64 failed");
		return -1;
	}

	for(i=0;i<7830457;i++)
	{
	}
	while(1)
	{
		temp=copy_largenums(temp,j);
		multiply_largenums(j,temp,firstnumber);
		if(get_digitnum(j)>10)
			ln_truncate(j,3);
		b/=2;
		if(b==1)
			break;
		if(b%2!=0)
		{
			multiply_largenums(k,j,firstnumber);
			b--;
		}
	}
	free_largenum(temp);
	multiply_largenums(k,j,firstnumber);
	j=largenum_setval(j,28433);
	multiply_largenums(k,j,firstnumber);


	add_largenums(sum,k,firstnumber);

	show_largenum(sum);
	return 0;
}

