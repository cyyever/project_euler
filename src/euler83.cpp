/*
 *	程序名：euler83.cpp
 *	作者：陈源源
 *	日期：2016-04-14
 *	功能：解决eulerproject 83题(https://projecteuler.net/problem=83)
 */
#include <iostream>
#include <fstream>
#include <cinttypes>
#include <list>

using namespace std;

uint64_t matrix[80][80];
uint64_t path_sum[80][80];

struct gird_coordinate
{
	size_t x;
	size_t y;
};
struct path
{
	gird_coordinate last_gird;
	uint64_t path_sum;
};

int main(int argc,char **argv)
{
	size_t i,j;
	char sep;
	path p;
	gird_coordinate next_gird,last_gird;
	list<path> all_paths;

	ifstream in_file("p083_matrix.txt");
	for(i=0;i<80;i++)
	{
		for(j=0;j<80;j++)
		{
			in_file>>matrix[i][j];
			if(j!=79)
				in_file>>sep;
		}
	}

	p.path_sum=matrix[0][0];
	p.last_gird={0,0};
	all_paths.push_back(p);

	for(i=0;i<80;i++)
		for(j=0;j<80;j++)
			path_sum[i][j]=UINT64_MAX;

	//我们依次迭代所有可能的路径
	while(all_paths.size()>0)
	{
		p=all_paths.front();
		all_paths.pop_front();

		//剪分支
		if(p.path_sum>=path_sum[79][79])
			continue;

		last_gird=p.last_gird;
		//生成上下左右四个格子
		for(i=0;i<4;i++)
		{
			//上格子
			if(i==0 && last_gird.y>0)
				next_gird={last_gird.x,last_gird.y-1};
			//下格子
			else if(i==1 && last_gird.y<79)
				next_gird={last_gird.x,last_gird.y+1};
			//左格子
			else if(i==2 && last_gird.x>0) 
				next_gird={last_gird.x-1,last_gird.y};
			//右格子
			else if(i==3 && last_gird.x<79) 
				next_gird={last_gird.x+1,last_gird.y};
			else
				continue;

			if(next_gird.x==79 && next_gird.y==79)
			{
				p.path_sum+=matrix[next_gird.x][next_gird.y];
				if(path_sum[79][79]>p.path_sum)
					path_sum[79][79]=p.path_sum;
				continue;
			}

			auto q=p;
			//我们的路径经过这个格子，如果没有更短，那么这个分支可以砍掉
			q.path_sum+=matrix[next_gird.x][next_gird.y];
			if(q.path_sum>path_sum[next_gird.x][next_gird.y])
				continue;
			
			path_sum[next_gird.x][next_gird.y]=q.path_sum;

			q.last_gird=next_gird;
			all_paths.push_back(q);
		}
	}
	cout<<path_sum[79][79]<<endl;
	return 0;
}
