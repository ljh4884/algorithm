#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define g struct graph
struct graph
{
	int size;
	int des[50];

};
g array[50];
double save[51][101];
int n,d,p,end;
void insert(int start,int des)
{
	array[start].des[array[start].size]=des;
	array[start].size++;
}
double func(int start,int day)
{
	if(day==0)
	{
		if(start==end)
			return 1;
		else
			return 0;
	}
	if(save[start][day]==-1)
	{
		double temp=0;
		for(int i = 0;i<array[start].size;i++)
		{
			temp = temp+func(array[start].des[i],day-1);
		}
		temp = temp/array[start].size;
		save[start][day]=temp;
	}
	return save[start][day];
}
int main()
{
	int c;
	int temp;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		int p;
		scanf("%d %d %d",&n,&d,&p);
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=d;j++)
				save[i][j]=-1;
		}
		for(int i=0;i<n;i++)
		{
			array[i].size=0;
			for(int j=0;j<n;j++)
			{
				scanf("%d",&temp);
				if(temp==1)
				{
					insert(i,j);
				}
			}
		}
		int count;
		scanf("%d",&count);
		for(int i=0;i<count;i++)
		{
			for(int i=0;i<=n;i++)
			{
				for(int j=0;j<=d;j++)
					save[i][j]=-1;
			}
			scanf("%d",&end);
			printf("%.20lf ",func(p,d));
		}
		printf("\n");


	}
}
