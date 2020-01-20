#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define f struct food

struct food
{
	int price;
	int score;
	double st;
};
int compare(const void *a, const void *b)
{
	f *num1 = (f*)a;
	f *num2 = (f*)b;
	if(num1->st>num2->st)
		return -1;
	else if(num1->st==num2->st)
		return 0;
	else
		return 1;
}
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}
f array[20];
int n,m;

int main()
{
	int c;
	int sum;
	scanf("%d",&c);
	while(c--)
	{
		sum=0;
		scanf("%d %d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&array[i].price,&array[i].score);
			array[i].st = (double)array[i].score/(double)array[i].price;
		}
		qsort(array,n,sizeof(f),compare);
		for(int i=0;i<n-1;i++)
		{
			if(m==0)
				break;
			int temp=m/array[i].price;
			int temp2=m/array[i+1].price;
			if(temp*array[i].score>temp2*array[i+1].score)
			{
				m=m-temp*array[i].price;
				sum+=temp*array[i].score;
			}
			else
			{
				m=m-temp2*array[i+1].price;
				sum+=temp2*array[i+1].score;
			}
		}
		printf("%d\n",sum);
	}
}
