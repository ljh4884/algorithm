#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int find(int **array,int **save,int x,int y,int n)
{
	if(x==n-1&&y==n-1)
		return 1;
	if(x>n-1||y>n-1)
		return 0;
	else
	{
		if(save[x][y]!=-1)
			return save[x][y];
		else
		{
			save[x][y] = find(array,save,x+array[x][y],y,n)|find(array,save,x,y+array[x][y],n);
			return save[x][y];
		}
	}
}

int main()
{
	int c,n;
	scanf("%d",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		int **array;
		int **save;
		scanf("%d",&n);
		array = (int**)malloc(sizeof(int*)*n);
		save = (int**)malloc(sizeof(int*)*n);
		for(int i=0;i<n;i++)
		{
			array[i]=(int*)malloc(sizeof(int)*n);
			save[i] = (int*)malloc(sizeof(int)*n);
			for(int j=0;j<n;j++)
			{
				scanf("%d",&array[i][j]);
				save[i][j]=-1;
			}
		}
		if(find(array,save,0,0,n)==1)
			printf("YES\n");
		else
			printf("NO\n");



				
				
	}
}
