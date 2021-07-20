#include <stdio.h>
#include <iostream>

using namespace std;

int n;
int X[40];
int Y[40];
int V[40];
int check[40];

int g_ret = 40;

int func(int money,int count)
{
	int min_x = 1000001;
	int min_y = 1000001;
	int max_x = -1;
	int max_y = -1;
	if(count >= g_ret)
		return 40;
	for(int i=0;i<n;i++)
	{
		if(check[i] == -1)
		{
			max_x = max(max_x, X[i]);
			min_x = min(min_x, X[i]);
			max_y = max(max_y, Y[i]);
			min_y = min(min_y, Y[i]);
		}
	}

	
	int value = 2*(max_x - min_x) + 2*(max_y - min_y);
	if(value <= money)
	{
		if(count < g_ret)
			g_ret = count;
		return count;
	}
	int ret = 40;
	for(int i=0;i<n;i++)
	{
		if(check[i] == -1)
		{
			check[i] = 1;
			ret = min(ret, func(money + V[i], count+1));
			check[i] = -1;
		}
	}
	return ret;
}

int main()
{
	scanf("%d",&n);

	for(int i=0;i<n;i++)
	{
		scanf("%d %d %d",&X[i],&Y[i],&V[i]);
		check[i] = -1;
	}
	printf("%d\n",func(0,0));
}
