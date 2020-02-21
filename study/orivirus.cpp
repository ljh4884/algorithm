#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;
int n,m;

int array[100][100];
int virus[100];
int check[100];
int start;
int last;

int func()
{
	int size=0;
	for(int i=start;i<last;i++)
	{
		for(int j=i+1;j<last;j++)
		{
			for(int k=0;k<n;k++)
			{
				if(check[k]==0)
				{
					if(array[k][virus[i]]==1&&array[k][virus[j]]==1)
					{
						virus[last+size]=k;
						check[k]=1;
						size++;
					}
				}
			}
		}
	}
	return size;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&array[i][j]);
			}
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++)
		{
			int v1,v2;
			for(int i=0;i<n;i++)
			{
				check[i]=0;
			}
			start=0;
			last =2;
			scanf("%d %d",&v1,&v2);
			virus[0]=v1-1;
			virus[1]=v2-1;
			check[v1-1]=1;
			check[v2-1]=1;
			
			while(1)
			{
				int size = func();
				if(size==0)
					break;
				last=last+size;
			}
			printf("%d ",last);
		}
		printf("\n");
	}
}
