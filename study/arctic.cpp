/*
 * darpa와 같은 방식으로 풀었다.
 * 왜 오래걸리는지는 잘모르겠다.
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
double x[100];
double y[100];
double dis[100][100];
int func(double d)
{
	int check[100];
	int count=1;
	for(int i=0;i<n;i++)
	{
		check[i]=0;
	}

	queue<int> q;
	q.push(0);
	check[0]=1;
	while(q.size()!=0)
	{
		int temp=q.front();
		q.pop();
		for(int i=0;i<n;i++)
		{
			if(dis[temp][i]<d&&check[i]!=1)
			{
				check[i]=1;
				q.push(i);
				count++;
			}
		}
		if(count==n)
			return 1;
	}
	if(count==n)
		return 1;
	else
		return 0;
	
}

double opt()
{
	double left = 0.0;
	double right = 1000*sqrt(2);
	for(int i=0;i<100;i++)
	{
		double mid = (left+right)/2.0;
		if(func(mid)==1)
		{
			right=mid;
		}
		else
		{
			left=mid;
		}
	}
	return left;
}

double cal(int des,int src)
{
	double a = x[des]-x[src];
	double b = y[des]-y[src];
	return sqrt(a*a+b*b);
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		double ret;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf %lf",&x[i],&y[i]);
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				dis[i][j]=cal(i,j);
			}
		}
		ret = opt()*100.0;
		ret = round(ret)/100.0;
		printf("%.2lf\n",ret);
	}
}
