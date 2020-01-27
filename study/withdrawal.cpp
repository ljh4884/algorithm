/*
 * c언어의 qsort보다 c++의 sort가 훨씬 빠르다.
 * func에서 gen = input*c -r의 식을 도출 해야하는데 혼자힘으로는 힘들것 같다.
 */ 

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
int r[1000];
int c[1000];

int compare(const void* a,const void *b)
{
	double num1 = *(double*)a;
	double num2 = *(double*)b;
	if(num1<num2)
		return -1;
	else if(num1==num2)
		return 0;
	else
		return 1;
}

bool func(double input)
{
	double gen[1000];
	double sum=0;
	for(int i=0;i<n;i++)
	{
		gen[i]=input*c[i]-r[i];
	}
	//qsort(&gen,n,sizeof(double),compare);
	sort(gen,gen+n);
	for(int i=n-k;i<n;i++)
	{
		sum+=gen[i];
	}
	return sum>=0;
}


double opt()
{
	double left=0;
	double right =1;
	for(int i=0;i<100;i++)
	{
		double mid = (left+right)/2.0;
		if(func(mid))
			right = mid;
		else
			left = mid;
	}
	return left;
}

int main()
{
	int cnt;
	scanf("%d",&cnt);
	while(cnt--)
	{
		scanf("%d %d\n",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d %d",r+i,c+i);
		printf("%.20lf\n",opt());
	}
}
