#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a,int b)
{
	if(a<b)
		return b;
	else
		return a;
}

int func(int **array,int **save,int x,int y,int n)
{
	if(x==n-1)
		return array[x][y];
	else
	{
		if(save[x][y]!=-1)
			return save[x][y];
		else
		{
			
			save[x][y] = array[x][y] + max(func(array,save,x+1,y,n),func(array,save,x+1,y+1,n));
			return save[x][y];
		}
		
	}
}

int main()
{
    int c,n;
	scanf("%d\n",&c);
	for(int cnt=0;cnt<c;cnt++)
	{
		int **array;
		int **save;
		scanf("%d",&n);
		array = (int**)malloc(sizeof(int*)*n);
		save = (int**)malloc(sizeof(int*)*n);
		for(int i=0;i<n;i++)
		{
			array[i] = (int*)malloc(sizeof(int)*(i+1));
			save[i] = (int*)malloc(sizeof(int)*(i+1));
			for(int j=0;j<i+1;j++)
			{
				scanf("%d",&array[i][j]);
				save[i][j]=-1;
			}
		}

		printf("%d\n",func(array,save,0,0,n));

	}
}
