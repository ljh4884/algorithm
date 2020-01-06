#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#define p struct pack
#define ch struct chart

struct pack
{
	char name[21];
	int v;
	int score;
};

struct chart
{
	int check[100];
	int score;
};

p pa[100];
ch sa[100][1001];
int n,w;

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

ch func(int i,int sum,ch check)
{
	ch sum1;
	ch sum2;
	if(sum>w)
	{
		ch temp;
		temp.score = -999999999;
		return temp;
	}

	if(i==n)
	{
		return check;
	}
	if(sa[i][sum].score!=-1)
		return sa[i][sum];

	sum1 = func(i+1,sum+pa[i].v,check);
	sum2 = func(i+1,sum,check);
	sum1.score += pa[i].score;
	sum1.check[i]=1;

	if(sum1.score>sum2.score)
	{
		sa[i][sum] = sum1;
		return sum1;
	}
	else
	{
		sa[i][sum] = sum2;
		return sum2;
	}
	
}

int main()
{
	int c;

	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		ch temp;
		int count=0;
		scanf("%d %d",&n,&w);

		for(int i=0;i<n;i++)
		{
			temp.check[i]=0;
			scanf("%s %d %d",pa[i].name,&pa[i].v,&pa[i].score);
			for(int j=0;j<=w;j++)
			{
				sa[i][j].score=-1;
			}
		}
		temp.score=0;

		temp = func(0,0,temp);

		for(int i=0;i<n;i++)
		{
			if(temp.check[i]==1)
			{
				count++;
			}
		}
		printf("%d %d\n",temp.score,count);
		for(int i=0;i<n;i++)
		{
			if(temp.check[i]==1)
			{
				printf("%s\n",pa[i].name);
			}
		}
		
	}
}
