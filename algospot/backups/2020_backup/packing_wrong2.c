#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n,w;
int count;

char name[100][21];
int v[100];
int score[100];
int check[100];
int save[101][1001];

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}


int func(int pos, int sum)
{
	if(sum>w)
		return -999999999;
	if(pos==n)
		return 0;
	
	if(save[pos][sum]==-1)
		save[pos][sum] = max(func(pos+1,sum),score[pos]+func(pos+1,sum+v[pos]));
	return save[pos][sum];




}

void cont(int pos,int sum)
{
	int result;
	if(pos==n)
		return;
	if((result=func(pos,sum))==func(pos+1,sum))
	{
		cont(pos+1,sum);
		check[pos]=0;
	}
	else
	{
		cont(pos+1,sum+v[pos]);
		check[pos]=1;
		count++;
	}
	if(pos==0)
		printf("%d %d\n",result,count);
			
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
			scanf("%s %d %d",name[i],&v[i],&score[i]);
			for(int j=0;j<w;j++)
			{
				save[i][j]=-1;
			}
		}

		cont(0,0);
		for(int i=0;i<n;i++)
		{
			if(check[i]==1)
				printf("%s\n",name[i]);
		} 
	}
}

