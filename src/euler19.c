/*
 *	程序名：euler19.c
 *	作者：陈源源
 *	日期：2016-03-05
 *	功能：解决eulerproject 19题(https://projecteuler.net/problem=19)
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define IS_LEAP_YEAR(year) (((year)%4==0 && (year)%100!=0) || ((year)%400)==0)
int main(int argc,char **argv)
{
	uint64_t day_of_week_of_first_day,year,month;
	size_t sunday_cnt;

	sunday_cnt=0;
	//1 Jan 1900 was a Monday.
	day_of_week_of_first_day=(1+365)%7;
	for(year=1901;year<=2000;year++)
	{
		for(month=1;month<=12;month++)
		{
			if(day_of_week_of_first_day==0)
				sunday_cnt++;
			if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12)
				day_of_week_of_first_day+=31;
			else if(month==2)
			{
				if(IS_LEAP_YEAR(year))
					day_of_week_of_first_day+=29;
				else
					day_of_week_of_first_day+=28;
			}
			else
					day_of_week_of_first_day+=30;
			day_of_week_of_first_day%=7;
		}
	}
	printf("%zu\n",sunday_cnt);
	return 0;
}
