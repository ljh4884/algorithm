#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n,m;
char name[50][11];
int check[50][50]; //i th food j can eat
int person[50];
int minsum;
int find(char *input)
{
	for(int i=0;i<n;i++)
	{
		if(strcmp(name[i],input)==0)
			return i;
	}
	return -1;
}

int min(int a,int b)
{
	if(a<b)
		return a;
	else
		return b;
}

int func(int pos,int *new_p,int sum)
{
	int ret;
	int bre=0;
	for(int i=0;i<n;i++)
	{
		if(new_p[i]!=1)
		{
			bre=1;
		}
	}
	if(sum>minsum)
	{
		return 999999;
	}
	if(bre==0)
	{
		minsum = min(minsum,sum);
		return sum;
	}
	if(pos==m)
		return 999999;
	ret = func(pos+1,new_p,sum);
	int new_p2[50];
	for(int i=0;i<n;i++)
	{
		new_p2[i]=new_p[i];
	}
	for(int i=0;i<n;i++)
	{
		if(check[pos][i]==1)
		{
			new_p2[i]=1;
		}
	}
	ret = min(ret,func(pos+1,new_p2,sum+1));
	return ret;
}

int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		minsum = 9999999;
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;i++)
		{
			for(int j=0;j<n;j++)
			{
				check[i][j]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			scanf("%s",name[i]);
			person[i]=0;
		}
		for(int i=0;i<m;i++)
		{
			int cnt;
			scanf("%d",&cnt);
			for(int j=0;j<cnt;j++)
			{
				char temp[11];
				scanf("%s",temp);
				check[i][find(temp)]=1;
			}
		}
		printf("%d\n",func(0,person,0));
	}
}
