/* 그리디의 기법을 사용하였다.
 * 사실 그리디 보단 주어진 입력을 0 ~ 2pi의 범위로 변환하는것과 그 예외처리가 주된 내용이였다.
 *
 */


#include <math.h>
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <vector>
#define _USE_MATH_DEFINES
#include <algorithm>



using namespace std;
typedef struct position
{
	double x,y;
	double r;
}pos;

int n;
pos array[100];
vector<pair<double,double>> check;

bool find()
{
	double r;
	double p_m;
	for(int i=0;i<n;i++)
	{
		if(array[i].x==0)
		{
			if(array[i].y>0)
			{
				r=M_PI/2.0;
			}
			else
			{
				r=(3*M_PI)/2;
			}
		}
		else if(array[i].x>0)
		{
			if(array[i].y==0)
			{
				r=0;
			}
			else if(array[i].y>0)
			{
				r = acos(array[i].x/8.0);
			}
			else
			{
				r = 2*M_PI - acos(array[i].x/8.0);
			}
		}
		else
		{
			if(array[i].y==0)
			{
				r=M_PI;
			}
			if(array[i].y>0)
			{
				r= M_PI-asin(array[i].y/8);
			}
			else
			{
				r= M_PI+atan(fabs(array[i].y)/fabs(array[i].x));
			}
		}
		if(array[i].r>=16.0)
		{
			return false;
		}
		else
		{
			p_m = 2*asin(array[i].r/16.0);
		}
		double x;
		x = (2*M_PI + r-p_m);
		while(x>2*M_PI)
			x-=2*M_PI;
		double y = (2*M_PI +r+p_m);
		while(y>2*M_PI)
			y -=2*M_PI;
		if(x>y)
			x -=2*M_PI;
		check.push_back(make_pair(x,y));
	}
	return true;
}


int func(int sel,int pre)
{
	double temp=-10;
	int tmp=0;
	for(int i=pre+1;i<n;i++)
	{
		if(check[i].first <= check[pre].second)
		{
			if(check[i].second>temp)
			{
				temp = check[i].second;
				tmp=i;
			}
		}
	}
	if(tmp==0)
		return n+1;
	if(check[tmp].second-check[sel].first>2*M_PI)
		return 1;
	return 1+func(sel,tmp);
	
}


int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int result = 101;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf %lf",&array[i].y,&array[i].x,&array[i].r);
			
		}
		check.clear();
		if(!find())
		{
			printf("1\n");
			continue;
		}
		sort(check.begin(),check.end());

		/*
		for(int i=0;i<n;i++)
		{
			printf("%lf %lf\n",check[i].first,check[i].second);
		}*/

		for(int i=0;i<n;i++)
		{
			if(check[i].first<=0)
			{
				result = min(result,func(i,i));
			}
			else
			{
				break;
			}
		}
		if(result>n)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n",result+1);

	}
}
