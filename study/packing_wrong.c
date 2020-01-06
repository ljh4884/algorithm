#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

p pa[101];
p sa[101];
int check[100];
int n,w;
int count;
int save[101][1001];
int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int func(int i,int sum)
{
	int sum1;
	int sum2;
	if(sum>w)
		return -99999999;
	if(i==n)
		return 0;

	if(save[i][sum]!=-1)
	{
		return save[i][sum];
	}

	sum1 = pa[i].score+func(i+1,sum+pa[i].v);
	sum2 = func(i+1,sum);
	if(sum1>sum2)
	{
			check[i]=1;
			memcpy(&sa[count],&pa[i],sizeof(p));
			count++;
		
		save[i][sum] = sum1;
		return save[i][sum];
	}
	else
	{
		check[i]=0;
		save[i][sum] = sum2;
		return save[i][sum];
	}

}

int main()
{
	int c;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		count = 0;
		scanf("%d %d",&n,&w);

		for(int i=0;i<n;i++)
		{
			scanf("%s %d %d",pa[i].name,&pa[i].v,&pa[i].score);
			check[i]=0;
			for(int j=0;j<w;j++)
			{
				save[i][j]=-1;
			}
		}
		printf("%d ",func(0,0));
		printf("%d\n",count);
		for(int i=0;i<count;i++)
		{
			printf("%s\n",sa[i].name);
		}

		for(int i=0;i<n;i++)
		{
			if(check[i]==1)
				printf("%d\n",i);
		}
	}
}
