#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;


int n,s;
int array[100];
int sum_array[101];
int max_num = 1000000000;
int save[100][10];

int score(int start, int end)
{
	double sum = (sum_array[end] - sum_array[start]);
	double mean = sum / (end - start);
	int int_mean = (int)(mean + 0.5);
	int V = 0;
	for(int i = start;i<end;i++)
	{
		V += ((array[i] - int_mean) * (array[i] - int_mean));
	}
	return V;


}



int func(int pos, int rest_s)
{

	if(rest_s == 1)
	{
		return score(pos,n);
	}
	if(pos == n-1)
		return 0;
	if(save[pos][rest_s-1] != -1)
		return save[pos][rest_s-1];

	int ret = max_num;

	for(int i=pos+1;i<n;i++)
	{
		ret = min(ret, score(pos,i) + func(i,rest_s - 1));
	}
	save[pos][rest_s-1] = ret;
	return ret;
}

int main()
{
	int c;
	scanf("%d",&c);

	while(c--)
	{
		scanf("%d %d",&n,&s);

		for(int i=0;i<n;i++)
		{
			scanf("%d",&array[i]);
			for(int j=0;j<s;j++)
				save[i][j] = -1;
		}
		
		sort(array,array+n);
		
		sum_array[0] = 0;
		for(int i=0;i<n;i++)
		{
			sum_array[i+1] = array[i] + sum_array[i];
		}
		printf("%d\n",func(0,s));

	}
}
