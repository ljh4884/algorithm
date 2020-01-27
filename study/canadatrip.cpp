/*
 * left가 아닌 right를 반환해야 맞음
 * 지금까지 풀었던 문제들이 최적화 문제
 * 문제를 어떻게 최적화 할수 있을지 생각하자!
 */

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>

using namespace std;

int n,k;
int l[5000];
int m[5000];
int g[5000];
bool func(int d)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(d>=l[i]-m[i])
		{
			count += (min(d,l[i])-l[i]+m[i])/g[i]+1;
		}
	}
	return count>=k;
		
}

int opt()
{
	int left=-1;
	int right=8030001;
	while(left+1<right)
	{
		int mid = (left+right)/2;
		if(func(mid))
			right = mid;
		else
			left = mid;
	}
	return right;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		scanf("%d %d",&n,&k);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d %d",l+i,m+i,g+i);
		
		}
		printf("%d\n",opt());
	}
}
