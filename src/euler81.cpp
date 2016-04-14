/*
 *	程序名：euler81.cpp
 *	作者：陈源源
 *	日期：2015-04-27
 *	功能：解决eulerproject 81题(https://projecteuler.net/problem=81)
 */
#include <iostream>
#include <fstream>
#include <cinttypes>

using namespace std;

uint64_t path_sum[80][80];
uint64_t matrix[80][80];

static uint64_t find_min_path_sum(size_t matrix_row_num,size_t matrix_col_num);

int main(int argc,char **argv)
{
	size_t i,j;
	char sep;

	ifstream in_file("p081_matrix.txt");
	for(i=0;i<80;i++)
	{
		for(j=0;j<80;j++)
		{
			in_file>>matrix[i][j];
			if(j!=79)
				in_file>>sep;
		}
	}

	cout<<find_min_path_sum(80,80)<<endl;
	return 0;
}

/*
 *	功能：获取指定矩阵下的从左上角到右下角的最小路径和
 *	参数：
 *		matrix_row_num：矩阵行数
 *		matrix_col_num：矩阵列数
 *	返回值：
 *		最小路径和
 */
static uint64_t find_min_path_sum(size_t matrix_row_num,size_t matrix_col_num)
{
	size_t i;
	uint64_t min_path_sum,tmp1,tmp2;

	if(path_sum[matrix_row_num-1][matrix_col_num-1]!=0)
		return path_sum[matrix_row_num-1][matrix_col_num-1];

	min_path_sum=0;
	if(matrix_row_num==1)
	{
		for(i=0;i<matrix_col_num;i++)
			min_path_sum+=matrix[0][i];
		path_sum[matrix_row_num-1][matrix_col_num-1]=min_path_sum;
		return min_path_sum;
	}

	if(matrix_col_num==1)
	{
		for(i=0;i<matrix_row_num;i++)
			min_path_sum+=matrix[i][0];
		path_sum[matrix_row_num-1][matrix_col_num-1]=min_path_sum;
		return min_path_sum;
	}
	tmp1=find_min_path_sum(matrix_row_num-1,matrix_col_num);
	tmp2=find_min_path_sum(matrix_row_num,matrix_col_num-1);
	min_path_sum=(tmp1>tmp2?tmp2:tmp1)+matrix[matrix_row_num-1][matrix_col_num-1];
	path_sum[matrix_row_num-1][matrix_col_num-1]=min_path_sum;
	return min_path_sum;
}
