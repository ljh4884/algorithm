#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array[100][100];
int save[100][100];
int save2[100][100];
int n;

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

int func(int x, int y)
{
	if(x==n-1)
	{
		save[x][y] = array[x][y];
		return array[x][y];
	}
	if(save[x][y]==-1)
		save[x][y]=array[x][y]+max(func(x+1,y),func(x+1,y+1));
	return save[x][y];
	
}
int find(int x,int y)
{
	if(x==n-1)
		return 1;
	if(save2[x][y]!=-1)
		return save2[x][y];
	else if(save[x+1][y]==save[x+1][y+1])
	{
		save2[x][y] = find(x+1,y+1)+find(x+1,y);
	}
	else if(save[x+1][y]>save[x+1][y+1])
	{
		save2[x][y] = find(x+1,y);
	}
	else
	{
		save2[x][y] = find(x+1,y+1);
	}
	return save2[x][y];
}

int main()
{
	int c;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i+1;j++)
			{
				scanf("%d",&array[i][j]);
				save[i][j]=-1;
				save2[i][j]=-1;
			}
		}
		func(0,0);
		printf("%d\n",find(0,0));

	}
}
